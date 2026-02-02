#include <stdlib.h>
void pause_console(void) {
#ifdef _WIN32
	system("pause");
#else
	system("read -p \"press enter to continue... \" dummy");
#endif
}