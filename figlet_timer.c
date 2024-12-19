#include <stdio.h>
#include <unistd.h> /* sleep() func */
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
/*#include <ncurses.h>*/

void
read_time_input(int *input_number, int low, int high, char *input_name)
{
	do {
		if (*input_number > high)
            printf("Invalid input: the number of %s is higher than %d!\n", input_name, high);
		else if (*input_number < low)
            printf("Invalid input: the number of %s is lower than %d!\n", input_name, low);

		printf("How many %s? ", input_name);
		scanf("%d", input_number);
	}
	while (*input_number > high || *input_number < low);
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
    int minutes = 0, seconds = 0;
    int time_left;
    int seconds_left, minutes_left;
    char figlet_command[100];

    read_time_input(&minutes, 0, 59, "minutes");
    read_time_input(&seconds, 0, 59, "seconds");
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
