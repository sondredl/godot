add_subdirectory(android)
add_subdirectory(ios)
add_subdirectory(linuxbsd)
add_subdirectory(macos)
add_subdirectory(web)
add_subdirectory(windows)

add_library(PLATFORM STATIC)

target_sources(
  PLATFORM
  PUBLIC register_platform_apis.h
         register_platform_apis.gen.cpp
         CMakeLists.txt
         linuxbsd/crash_handler_linuxbsd.h
         linuxbsd/dbus-so_wrap.h
         linuxbsd/fontconfig-so_wrap.h
         linuxbsd/freedesktop_portal_desktop.h
         linuxbsd/freedesktop_screensaver.h
         linuxbsd/joypad_linux.h
         linuxbsd/libudev-so_wrap.h
         linuxbsd/os_linuxbsd.h
         linuxbsd/platform_config.h
         linuxbsd/platform_gl.h
         linuxbsd/speechd-so_wrap.h
         linuxbsd/tts_linux.h
         linuxbsd/xkbcommon-so_wrap.h
         linuxbsd/dbus-so_wrap.c
         linuxbsd/fontconfig-so_wrap.c
         linuxbsd/libudev-so_wrap.c
         linuxbsd/speechd-so_wrap.c
         linuxbsd/xkbcommon-so_wrap.c
         linuxbsd/crash_handler_linuxbsd.cpp
         linuxbsd/freedesktop_portal_desktop.cpp
         linuxbsd/freedesktop_screensaver.cpp
         linuxbsd/godot_linuxbsd.cpp
         linuxbsd/joypad_linux.cpp
         linuxbsd/os_linuxbsd.cpp
         linuxbsd/tts_linux.cpp
         CMakeLists.txt
  # README.md SCsub detect.py platform_linuxbsd_builders.py
)
