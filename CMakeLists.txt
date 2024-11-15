cmake_minimum_required(VERSION 3.16)
project(GodotEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define build options
option(GODOT_DEBUG "Enable debugging" OFF)
option(GODOT_EDITOR "Build with editor support" ON)
option(GODOT_PLATFORM
       "Specify target platform (e.g., x11, windows, android, ios)" "x11")

# Set up source files and directories
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PLATFORM_DIR ${ROOT_DIR}/platform)
set(CORE_DIR ${ROOT_DIR}/core)
set(SCENE_DIR ${ROOT_DIR}/scene)
set(MODULES_DIR ${ROOT_DIR}/modules)
set(THIRDPARTY_DIR ${ROOT_DIR}/thirdparty)

# Collect all source files
file(GLOB_RECURSE GODOT_SRC ${CORE_DIR}/*.cpp ${SCENE_DIR}/*.cpp
     ${MODULES_DIR}/*/*.cpp ${PLATFORM_DIR}/${GODOT_PLATFORM}/*.cpp)

# Include directories
include_directories(${ROOT_DIR} ${CORE_DIR} ${SCENE_DIR} ${MODULES_DIR}
                    ${THIRDPARTY_DIR} ${PLATFORM_DIR}/${GODOT_PLATFORM})

# Define the executable
add_executable(godot ${GODOT_SRC})

add_subdirectory(core)
add_subdirectory(drivers)
add_subdirectory(editor)
add_subdirectory(main)
add_subdirectory(misc)
add_subdirectory(modules)
add_subdirectory(platform)
add_subdirectory(scene)
add_subdirectory(servers)
add_subdirectory(tests)
add_subdirectory(thirdparty)
# Link third-party libraries (example)
find_package(OpenGL REQUIRED)
target_link_libraries(godot PRIVATE OpenGL::GL MAIN EDITOR)

# Platform-specific settings
if(GODOT_PLATFORM STREQUAL "x11")
  find_package(X11 REQUIRED)
  target_link_libraries(godot PRIVATE X11)
elseif(GODOT_PLATFORM STREQUAL "windows")
  target_link_libraries(godot PRIVATE user32 gdi32)
elseif(GODOT_PLATFORM STREQUAL "android")
  # Android-specific setup
  message(FATAL_ERROR "Android build is not yet supported in this CMake setup.")
elseif(GODOT_PLATFORM STREQUAL "ios")
  # iOS-specific setup
  message(FATAL_ERROR "iOS build is not yet supported in this CMake setup.")
endif()

# Editor support
if(GODOT_EDITOR)
  add_definitions(-DTOOLS_ENABLED)
endif()

# Debugging options
if(GODOT_DEBUG)
  add_definitions(-DDEBUG_ENABLED)
  set(CMAKE_BUILD_TYPE Debug)
else()
  set(CMAKE_BUILD_TYPE Release)
endif()

# Output settings
set_target_properties(
  godot PROPERTIES OUTPUT_NAME "godot" RUNTIME_OUTPUT_DIRECTORY
                                       ${CMAKE_BINARY_DIR}/bin)

# Custom targets or post-build steps can be added here
