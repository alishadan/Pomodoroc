#include <stdio.h>
#include <stdlib.h>

void open_image(void) {
#ifdef _WIN32
    // Windows
    system("start image.png");
#elif __APPLE__
    // macOS
    system("open image.png");
#else
    // Linux/Unix
    system("xdg-open image.png 2>/dev/null || "
        "gnome-open image.png 2>/dev/null || "
        "eog image.png 2>/dev/null &");
#endif
}