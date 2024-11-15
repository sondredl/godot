add_subdirectory(android)
add_subdirectory(ios)
add_subdirectory(linuxbsd)
add_subdirectory(macos)
add_subdirectory(web)
add_subdirectory(windows)

add_library(PLATFORM STATIC)

target_sources(
  PLATFORM PRIVATE # register_platform_apis.h
                   register_platform_apis.gen.cpp CMakeLists.txt # SCsub
)
