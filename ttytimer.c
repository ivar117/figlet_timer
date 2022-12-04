#include <stdio.h>
#include <assuan.h> /* usleep funktion */
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ncurses.h>

 /*
  *TODO: gör att minuter variabeln lagras i en fil och om man skriver senast i inmatningen så används den filen som inmatning till minuter varen
  *Gör så läsa in timmar också maybe och sekunder
  *Om har ifen med EOF så quittar den när jag matar in minuter varen, fixa så att om man skriver textsträngar och annat dåligt så quittar den utan att printa ut Klart!
	*Kanske ändra till unsigned ints men hur då skanna in och ge error när minus xd 
	*Göra om till cmd line options ist fö scanf. Fast du blir det svårt med ifen. Du måste den exita direkt bara.
  */

int min; 
int sek;
int tid_kvar;
int sk; 
int mk;

void indata(void)
{
	do {
		if (min > 59)
			printf("Minuter högre än 59!\n");
		else if (min < 0)
			printf("Icke korrekt!\n");

		printf("Hur många minuter?\n");
		scanf("%d", &min);
	}
	while (min > 59 || min < 0);

	do {
		if (sek > 59)
			printf("Sekunder högre än 59!\n");
		else if (sek < 0)
			printf("Icke korrekt!\n");

		printf("Hur många sekunder?\n");
		scanf("%d", &sek);
	}
	while (sek > 59 || sek < 0);
}

void klart(void)
{
	system("clear"); /* Clear screen */
	printf("\n");
	system("figlet KLART!");
}

int
main(int argc, char *argv[])
{
	indata();
	system("clear"); /* Clear screen */

	for (tid_kvar = min * 60 + sek; tid_kvar > 0; tid_kvar--) {
		sk = tid_kvar % 60;
		mk = (tid_kvar - sk) / 60;
		printf("\r%02d:%02d", mk, sk);

		fflush(stdout);
		usleep(1000000);
	}
	klart();
	return 0;
}
