# __pycache__/

add_library(MAIN PRIVATE)
target_sources(
  MAIN
  PRIVATE # app_icon.gen.h main.h main_timer_sync.h performance.h splash.gen.h
          # steam_tracker.h
          main.cpp
          main_timer_sync.cpp
          performance.cpp
          steam_tracker.cpp
          CMakeLists.txt)

# SCsub app_icon.png main_builders.py splash.png
