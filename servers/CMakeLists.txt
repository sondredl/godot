add_subdirectory(audio)
add_subdirectory(camera)
add_subdirectory(debugger)
add_subdirectory(display)
add_subdirectory(extensions)
add_subdirectory(movie_writer)
add_subdirectory(navigation)
add_subdirectory(rendering)
add_subdirectory(text)
add_subdirectory(xr)

add_library(SERVERS PRIVATE)

target_sources(
  SERVERS
  PRIVATE # audio_server.h camera_server.h display_server.h
          # display_server_headless.h navigation_server_2d.h
          # navigation_server_2d_dummy.h navigation_server_3d.h
          # navigation_server_3d_dummy.h physics_server_2d.h
          # physics_server_2d_dummy.h physics_server_2d_wrap_mt.h
          # physics_server_3d.h physics_server_3d_dummy.h
          # physics_server_3d_wrap_mt.h register_server_types.h
          # rendering_server.h server_wrap_mt_common.h text_server.h xr_server.h
          audio_server.cpp
          camera_server.cpp
          display_server.cpp
          navigation_server_2d.cpp
          navigation_server_3d.cpp
          physics_server_2d.cpp
          physics_server_2d_wrap_mt.cpp
          physics_server_3d.cpp
          physics_server_3d_wrap_mt.cpp
          register_server_types.cpp
          rendering_server.cpp
          text_server.cpp
          xr_server.cpp
          CMakeLists.txt)
# SCsub

# rendering_server.compat.inc text_server.compat.inc xr_server.compat.inc
