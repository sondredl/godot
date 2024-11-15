add_subdirectory(2d)
add_subdirectory(3d)
add_subdirectory(animation)
add_subdirectory(audio)
add_subdirectory(debugger)
add_subdirectory(gui)
add_subdirectory(main)
add_subdirectory(resources)
add_subdirectory(theme)

add_library(SCENE PRIVATE)

target_sources(
  SCENE
  PRIVATE # property_list_helper.h property_utils.h register_scene_types.h
          # scene_string_names.h
          property_list_helper.cpp
          property_utils.cpp
          register_scene_types.cpp
          scene_string_names.cpp
          CMakeLists.txt
          # SCsub
)
