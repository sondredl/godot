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

add_library(CORE PRIVATE)

library_add_sources(
  CORE
  PRIVATE
  # CMakeLists.txt
  # authors.gen.h core_bind.h core_constants.h core_globals.h
  # core_string_names.h disabled_classes.gen.h doc_data.h donors.gen.h
  # license.gen.h register_core_types.h typedefs.h version.h
  # version_generated.gen.h
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
