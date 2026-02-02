#include <stdio.h>
#include <windows.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
int file_exists(const char* filename) {
#ifdef _WIN32
	// Windows implementation
	WIN32_FIND_DATAA find_data;
	HANDLE handle = FindFirstFileA(filename, &find_data);
	if (handle != INVALID_HANDLE_VALUE) {
		FindClose(handle);
		return 1;
	}
	return 0;
#else
	// Linux implementation
	struct stat buffer;
	return (stat(filename, &buffer) == 0);
#endif
}
int check_requirements(void) {
	// Check for start.mp3 file
	if (!file_exists("start.mp3")) {
		printf("start.mp3 file does not exist, please provide it\n");
		return -1;
	}

	// Check for stop.mp3 file
	if (!file_exists("stop.mp3")) {
		printf("stop.mp3 file does not exist, please provide it\n");
		return -1;
	}

	return 1; // everything is good
}
