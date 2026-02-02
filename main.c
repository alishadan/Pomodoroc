#include <stdlib.h>
#include "functions.h"
#include <stdio.h>
int main() {
	check_requirements();
	char arr2[4][100];  //array for save data saved in file.txt, times and sounds
	read_file(arr2);
	int w_time = atoi(arr2[1]);  //time for work time
	int b_time = atoi(arr2[3]);  //time for break time
	run(w_time, b_time);
	printf("okay\n");
	pause_console();
	return 0;
}