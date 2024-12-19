#include <stdio.h>
#include <unistd.h> /* sleep() func */
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
/*#include <ncurses.h>*/

void
read_time_input(unsigned int *minutes, unsigned int *seconds)
{
	do {
		if (*minutes > 59)
            printf("The number of minutes is higher than 59!\n");
		else if (*minutes < 0)
            printf("Invalid input! Please enter a valid number.\n");

		printf("How many minutes? ");
		scanf("%u", minutes);
	}
	while (*minutes > 59 || *minutes < 0);

	do {
		if (*seconds > 59)
            printf("The number of seconds is higher than 59!\n");
		else if (*seconds < 0)
            printf("Invalid input! Please enter a valid number.\n");

		printf("How many seconds? ");
		scanf("%u", seconds);
	}
	while (*seconds > 59 || *seconds < 0);
}

void
done(void)
{
	system("clear"); /* Clear screen */
	printf("\n");
	system("figlet DONE!");
}

int
main(int argc, char *argv[])
{
    unsigned int minutes = 0, seconds = 0;
    int time_left;
    int seconds_left, minutes_left;
    char figlet_command[100];

	read_time_input(&minutes, &seconds);
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

	for (time_left = minutes * 60 + seconds; time_left > 0; time_left--) {
		seconds_left = time_left % 60;
		minutes_left = (time_left - seconds_left) / 60;

        snprintf(figlet_command, sizeof(figlet_command), "figlet %02d:%02d", minutes_left, seconds_left);

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        system(figlet_command);
		fflush(stdout);

		sleep(1);
	}
	done();
	return 0;
}
