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
         authors.gen.h
         core_bind.h
         core_constants.h
         core_globals.h
         core_string_names.h
         disabled_classes.gen.h
         doc_data.h
         donors.gen.h
         license.gen.h
         register_core_types.h
         typedefs.h
         version.h
         version_generated.gen.h
         ../platform/windows/platform_config.h
         ../platform/android/platform_config.h
         ../platform/web/platform_config.h
         ../platform/linuxbsd/platform_config.h
         ../platform/macos/platform_config.h
         ../platform/ios/platform_config.h
         ../../platform/windows/platform_config.h
         ../../platform/android/platform_config.h
         ../../platform/web/platform_config.h
         ../../platform/linuxbsd/platform_config.h
         ../../platform/macos/platform_config.h
         ../../platform/ios/platform_config.h
         core_bind.cpp
         core_constants.cpp
         core_globals.cpp
         core_string_names.cpp
         doc_data.cpp
         register_core_types.cpp
         script_encryption_key.gen.cpp
         version_hash.gen.cpp
         # SCsub core_bind.compat.inc
         core_builders.py)

target_link_libraries(
  CORE
  PUBLIC config
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
