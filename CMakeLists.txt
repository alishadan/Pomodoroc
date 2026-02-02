cmake_minimum_required(VERSION 3.10)
project(PomodoroTimer)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add executable with all source files
add_executable(PomodoroTimer
    main.c
    functions.c
    requirements.c
    read_file.c
    config.c
    run.c
    image.c
    miniaudio/miniaudio.c
)

# Include directories
target_include_directories(PomodoroTimer PRIVATE . miniaudio)

# Platform-specific libraries
if(WIN32)
    # Windows libraries for miniaudio
    target_link_libraries(PomodoroTimer PRIVATE ole32 user32)
    # Add Windows specific compiler flags if needed
    target_compile_definitions(PomodoroTimer PRIVATE MA_NO_WASAPI=1)
elseif(UNIX AND NOT APPLE)
    # Linux libraries
    target_link_libraries(PomodoroTimer PRIVATE m pthread dl)
elseif(APPLE)
    # macOS libraries
    target_link_libraries(PomodoroTimer PRIVATE
        "-framework AudioToolbox"
        "-framework CoreAudio"
        "-framework CoreFoundation"
    )
endif()

# Optional: Enable better warnings
if(MSVC)
    target_compile_options(PomodoroTimer PRIVATE /W4)
else()
    target_compile_options(PomodoroTimer PRIVATE -Wall -Wextra)
endif()