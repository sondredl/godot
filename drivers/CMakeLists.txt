add_subdirectory(alsa)
add_subdirectory(alsamidi)
add_subdirectory(backtrace)
add_subdirectory(coreaudio)
add_subdirectory(coremidi)
add_subdirectory(d3d12)
add_subdirectory(egl)
add_subdirectory(gl_context)
add_subdirectory(gles3)
add_subdirectory(metal)
add_subdirectory(png)
add_subdirectory(pulseaudio)
add_subdirectory(unix)
add_subdirectory(vulkan)
add_subdirectory(wasapi)
add_subdirectory(windows)
add_subdirectory(winmidi)
add_subdirectory(xaudio2)

add_library(DRIVERS STATIC)
target_sources(
  DRIVERS
  PRIVATE # register_driver_types.h
          register_driver_types.cpp
          CMakeLists.txt
          # SCsub libdrivers.linuxbsd.editor.x86_64.a
          # register_driver_types.linuxbsd.editor.x86_64.o
)
