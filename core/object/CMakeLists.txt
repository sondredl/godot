add_library(CORE_OBJECTS STATIC)

# __pycache__/
target_sources(
  CORE_OBJECTS
  PRIVATE callable_method_pointer.h
          class_db.h
          message_queue.h
          method_bind.h
          object.h
          object_id.h
          ref_counted.h
          script_instance.h
          script_language.h
          script_language_extension.h
          undo_redo.h
          worker_thread_pool.h
          callable_method_pointer.cpp
          class_db.cpp
          message_queue.cpp
          method_bind.cpp
          object.cpp
          ref_counted.cpp
          script_instance.cpp
          script_language.cpp
          script_language_extension.cpp
          undo_redo.cpp
          worker_thread_pool.cpp
          CMakeLists.txt
          # SCsub gdvirtual.gen.inc make_virtuals.py
)
