#include <stdio.h>
#include <string.h>
#include "functions.h"
// Define a portable strcpy_s-like function
int portable_strcpy_s(char* dest, size_t dest_size, const char* src) {
	if (dest == NULL || src == NULL) {
		return -1;
	}

	size_t src_len = strlen(src);
	if (src_len >= dest_size) {
		// Truncate or handle error
		if (dest_size > 0) {
			strncpy(dest, src, dest_size - 1);
			dest[dest_size - 1] = '\0';
		}
		return -1; // Buffer too small
	}

	strcpy(dest, src);
	return 0;
}
void read_file(char arr2[4][100]) {
	//this function read file.txt and saved their data in arr2
	FILE* file = fopen("file.txt", "r"); // open file.txt and pointer to that with name file
	char arr[4][100]; //  array for save data from file.txt 
	//arr[0] is name of start sound, arr[1] is work time, arr[2] is name of stop sound and arr[3] is break time
	if (file != NULL) {
		for (int i = 0; i < 4; i++) { //this for loop is for full arr
			if (fgets(arr[i], 100, file) != NULL) {  //read data from file.txt and saved in arr[i]
				char* temp; temp = strchr(arr[i], '\n'); *temp = '\0'; //ENTER is last element of arr[i], we removed that
				char* p = strstr(arr[i], ":"); // in file.txt in each line is amount:value, we need to value
				if (p == NULL) {
					printf("p is null\n");
					printf("file.txt encountered with erorr\nthis file repair automitically\n"
						"file.txt set to default values\n"
						"please do not remove ':' in file.txt\n\n");
					config(); // repair file.txt


				}
				else {

					portable_strcpy_s(arr2[i], sizeof(arr2[i]), p + 1); //we full arr2[i] with value only, p point to : in arr[i]
				}
			}
		}
		fclose(file);
	}
	else {
		printf("Error reading input.");
	}


}