add_subdirectory(core)
add_subdirectory(data)
add_subdirectory(python_build)
add_subdirectory(scene)
add_subdirectory(servers)

add_library(TESTS STATIC)
target_sources(
  TESTS
  PRIVATE # display_server_mock.h test_macros.h test_main.h test_tools.h
          # test_utils.h test_validate_testing.h
          test_macros.cpp test_main.cpp test_utils.cpp CMakeLists.txt)
# create_test.py* SCsub
