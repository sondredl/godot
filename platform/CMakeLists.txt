add_subdirectory(android)
add_subdirectory(ios)
add_subdirectory(linuxbsd)
add_subdirectory(macos)
add_subdirectory(web)
add_subdirectory(windows)

add_library(PLATFORM STATIC)

target_sources(
  PLATFORM
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/crash_handler_linuxbsd.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/dbus-so_wrap.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/fontconfig-so_wrap.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/freedesktop_portal_desktop.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/freedesktop_screensaver.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/joypad_linux.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/libudev-so_wrap.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/os_linuxbsd.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/platform_config.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/platform_gl.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/speechd-so_wrap.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/tts_linux.h
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/xkbcommon-so_wrap.h
         ${CMAKE_CURRENT_LIST_DIR}/register_platform_apis.h
         ${CMAKE_CURRENT_LIST_DIR}/register_platform_apis.gen.cpp
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/dbus-so_wrap.c
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/fontconfig-so_wrap.c
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/libudev-so_wrap.c
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/speechd-so_wrap.c
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/xkbcommon-so_wrap.c
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/crash_handler_linuxbsd.cpp
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/freedesktop_portal_desktop.cpp
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/freedesktop_screensaver.cpp
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/godot_linuxbsd.cpp
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/joypad_linux.cpp
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/os_linuxbsd.cpp
         ${CMAKE_CURRENT_LIST_DIR}/linuxbsd/tts_linux.cpp)
