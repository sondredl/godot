# __pycache__/
add_subdirectory(debugger)
add_subdirectory(export)
add_subdirectory(gui)
add_subdirectory(icons)
add_subdirectory(import)
add_subdirectory(plugins)
add_subdirectory(project_manager)
add_subdirectory(themes)
add_subdirectory(translations)

add_library(EDITOR STATIC)
target_sources(
  EDITOR
  PRIVATE action_map_editor.cpp
          add_metadata_dialog.cpp
          animation_bezier_editor.cpp
          animation_track_editor.cpp
          animation_track_editor_plugins.cpp
          audio_stream_preview.cpp
          code_editor.cpp
          connections_dialog.cpp
          create_dialog.cpp
          dependency_editor.cpp
          directory_create_dialog.cpp
          doc_tools.cpp
          editor_about.cpp
          editor_asset_installer.cpp
          editor_atlas_packer.cpp
          editor_audio_buses.cpp
          editor_autoload_settings.cpp
          editor_build_profile.cpp
          editor_command_palette.cpp
          editor_data.cpp
          editor_dock_manager.cpp
          editor_feature_profile.cpp
          editor_file_system.cpp
          editor_folding.cpp
          editor_help.cpp
          editor_help_search.cpp
          editor_inspector.cpp
          editor_interface.cpp
          editor_layouts_dialog.cpp
          editor_locale_dialog.cpp
          editor_log.cpp
          editor_main_screen.cpp
          editor_native_shader_source_visualizer.cpp
          editor_node.cpp
          editor_paths.cpp
          editor_properties.cpp
          editor_properties_array_dict.cpp
          editor_properties_vector.cpp
          editor_property_name_processor.cpp
          editor_resource_picker.cpp
          editor_resource_preview.cpp
          editor_run.cpp
          editor_run_native.cpp
          editor_script.cpp
          editor_sectioned_inspector.cpp
          editor_settings.cpp
          editor_settings_dialog.cpp
          editor_string_names.cpp
          editor_translation.cpp
          editor_translation_parser.cpp
          editor_undo_redo_manager.cpp
          editor_vcs_interface.cpp
          engine_update_label.cpp
          event_listener_line_edit.cpp
          fbx_importer_manager.cpp
          file_info.cpp
          filesystem_dock.cpp
          find_in_files.cpp
          group_settings_editor.cpp
          groups_editor.cpp
          history_dock.cpp
          import_defaults_editor.cpp
          import_dock.cpp
          input_event_configuration_dialog.cpp
          inspector_dock.cpp
          localization_editor.cpp
          multi_node_edit.cpp
          node_dock.cpp
          pot_generator.cpp
          progress_dialog.cpp
          project_converter_3_to_4.cpp
          project_manager.cpp
          project_settings_editor.cpp
          property_selector.cpp
          register_editor_types.cpp
          register_exporters.gen.cpp
          rename_dialog.cpp
          renames_map_3_to_4.cpp
          reparent_dialog.cpp
          run_instances_dialog.cpp
          scene_create_dialog.cpp
          scene_tree_dock.cpp
          script_create_dialog.cpp
          shader_create_dialog.cpp
          shader_globals_editor.cpp
          surface_upgrade_tool.cpp
          window_wrapper.cpp
          CMakeLists.txt)

# SCsub editor_builders.py editor_inspector.compat.inc
# editor_interface.compat.inc template_builders.py

# action_map_editor.h add_metadata_dialog.h animation_bezier_editor.h
# animation_track_editor.h animation_track_editor_plugins.h
# audio_stream_preview.h code_editor.h connections_dialog.h create_dialog.h
# dependency_editor.h directory_create_dialog.h doc_data_class_path.gen.h
# doc_data_compressed.gen.h doc_tools.h doc_translations.gen.h editor_about.h
# editor_asset_installer.h editor_atlas_packer.h editor_audio_buses.h
# editor_autoload_settings.h editor_build_profile.h editor_command_palette.h
# editor_data.h editor_dock_manager.h editor_feature_profile.h
# editor_file_system.h editor_folding.h editor_help.h editor_help_search.h
# editor_inspector.h editor_interface.h editor_layouts_dialog.h
# editor_locale_dialog.h editor_log.h editor_main_screen.h
# editor_native_shader_source_visualizer.h editor_node.h editor_paths.h
# editor_properties.h editor_properties_array_dict.h editor_properties_vector.h
# editor_property_name_processor.h editor_resource_picker.h
# editor_resource_preview.h editor_run.h editor_run_native.h editor_script.h
# editor_sectioned_inspector.h editor_settings.h editor_settings_dialog.h
# editor_string_names.h editor_translation.h editor_translation_parser.h
# editor_translations.gen.h editor_undo_redo_manager.h editor_vcs_interface.h
# engine_update_label.h event_listener_line_edit.h
# extractable_translations.gen.h fbx_importer_manager.h file_info.h
# filesystem_dock.h find_in_files.h group_settings_editor.h groups_editor.h
# history_dock.h import_defaults_editor.h import_dock.h
# input_event_configuration_dialog.h inspector_dock.h localization_editor.h
# multi_node_edit.h node_dock.h pot_generator.h progress_dialog.h
# project_converter_3_to_4.h project_manager.h project_settings_editor.h
# property_selector.h property_translations.gen.h register_editor_types.h
# register_exporters.h rename_dialog.h renames_map_3_to_4.h reparent_dialog.h
# run_instances_dialog.h scene_create_dialog.h scene_tree_dock.h
# script_create_dialog.h shader_create_dialog.h shader_globals_editor.h
# surface_upgrade_tool.h window_wrapper.h
