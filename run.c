#include <stdio.h>
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio/miniaudio.h" 
#include <windows.h>
#include "functions.h"
void run_menu(void);
#ifdef _WIN32
#include <windows.h>
#define SLEEP_MS(ms) Sleep(ms)
#else
#include <unistd.h>
#define SLEEP_MS(ms) usleep((ms) * 1000)
#endif

void run(int w_time, int b_time) {
    char arr2[4][100];
    read_file(arr2);
    int duration_work = w_time * 60000;
    int duration_break = b_time * 60000;

    ma_engine engine;
    ma_result result;
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine.");
        return;
    }

    run_menu();
    //int a = getchar();

    while (1) {
        // Work time
        //open_image();
        printf("work time is started for %i minutes\n", w_time);
        ma_engine_play_sound(&engine, arr2[0], NULL);
        SLEEP_MS(duration_work);
        printf("work time is finished\n");

        // Break time
        open_image();
        printf("break time is started for %i minutes \n", b_time);
        ma_engine_play_sound(&engine, arr2[2], NULL);
        SLEEP_MS(duration_break);
        printf("break time is finished\n");
    }
}
void run_menu(void) {
	system("cls");
	printf(
		"########################\n"
		"# S (start program)    #\n"
		"# ctrl+c (end program) #\n"
		"########################\n"
	);
}


