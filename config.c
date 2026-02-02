#include <stdio.h>
void config(void) {
	//this function reset file.txt 
	FILE* file = fopen("file.txt", "w"); //open or create file.txt for write in that
	//malloc();
	char arr[] = "start_music:start.mp3\n"
		"duration_work:5 minute // only number and minimum is one minute;\n"
		"break_music :stop.mp3\n"
		"duration_break :1 minute 1 minute // only number and minimum is one minute;\n";
	fprintf(file, arr);  //write arr on file.txt
	fclose(file); //close file.txt

	// if user remove file.txt
	//create a new file.txt or replaced with file.txt
}