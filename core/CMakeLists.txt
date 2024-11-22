add_subdirectory(config)
add_subdirectory(crypto)
add_subdirectory(debugger)
add_subdirectory(error)
add_subdirectory(extension)
add_subdirectory(input)
add_subdirectory(io)
add_subdirectory(math)
add_subdirectory(object)
add_subdirectory(os)
add_subdirectory(string)
add_subdirectory(templates)
add_subdirectory(variant)

add_library(CORE STATIC)

target_sources(
  CORE
  PUBLIC # CMakeLists.txt
         ${CMAKE_CURRENT_LIST_DIR}/authors.gen.h
         ${CMAKE_CURRENT_LIST_DIR}/core_bind.h
         ${CMAKE_CURRENT_LIST_DIR}/core_constants.h
         ${CMAKE_CURRENT_LIST_DIR}/core_globals.h
         ${CMAKE_CURRENT_LIST_DIR}/core_string_names.h
         ${CMAKE_CURRENT_LIST_DIR}/disabled_classes.gen.h
         ${CMAKE_CURRENT_LIST_DIR}/doc_data.h
         ${CMAKE_CURRENT_LIST_DIR}/donors.gen.h
         ${CMAKE_CURRENT_LIST_DIR}/license.gen.h
         ${CMAKE_CURRENT_LIST_DIR}/register_core_types.h
         ${CMAKE_CURRENT_LIST_DIR}/typedefs.h
         ${CMAKE_CURRENT_LIST_DIR}/version.h
         ${CMAKE_CURRENT_LIST_DIR}/version_generated.gen.h
         # ${CMAKE_CURRENT_LIST_DIR}../platform/windows/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../platform/android/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../platform/web/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../platform/linuxbsd/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../platform/macos/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../platform/ios/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../../platform/windows/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../../platform/android/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../../platform/web/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../../platform/linuxbsd/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../../platform/macos/platform_config.h
         # ${CMAKE_CURRENT_LIST_DIR}../../platform/ios/platform_config.h
         ${CMAKE_CURRENT_LIST_DIR}/core_bind.cpp
         ${CMAKE_CURRENT_LIST_DIR}/core_constants.cpp
         ${CMAKE_CURRENT_LIST_DIR}/core_globals.cpp
         ${CMAKE_CURRENT_LIST_DIR}/core_string_names.cpp
         ${CMAKE_CURRENT_LIST_DIR}/doc_data.cpp
         ${CMAKE_CURRENT_LIST_DIR}/register_core_types.cpp
         ${CMAKE_CURRENT_LIST_DIR}/script_encryption_key.gen.cpp
         ${CMAKE_CURRENT_LIST_DIR}/version_hash.gen.cpp
         ${CMAKE_CURRENT_LIST_DIR}/error/error_list.h
         ${CMAKE_CURRENT_LIST_DIR}/error/error_macros.h
         ${CMAKE_CURRENT_LIST_DIR}/error/error_list.cpp
         ${CMAKE_CURRENT_LIST_DIR}/error/error_macros.cpp
         ${CMAKE_CURRENT_LIST_DIR}/error/CMakeLists.txt
         ${CMAKE_CURRENT_LIST_DIR}/error/SCsub
         ${CMAKE_CURRENT_LIST_DIR}/error/error_list.linuxbsd.editor.x86_64.o
         ${CMAKE_CURRENT_LIST_DIR}/error/error_macros.linuxbsd.editor.x86_64.o
         # SCsub core_bind.compat.inc
         core_builders.py)

target_link_libraries(
  CORE
  PUBLIC PLATFORM
         config
         crypto
         debugger
         error
         extension
         input
         io
         math
         object
         os
         string
         templates
         variant)
target_include_directories(
  CORE PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../platform/linuxbsd)
