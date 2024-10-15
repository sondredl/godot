/**************************************************************************/
/*  animation_track_editor_plugins.h                                      */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef ANIMATION_TRACK_EDITOR_PLUGINS_H
#define ANIMATION_TRACK_EDITOR_PLUGINS_H

#include "core/input/input_event.h"
#include "core/math/rect2.h"
#include "core/math/vector2.h"
#include "core/object/object.h"
#include "core/object/object_id.h"
#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "editor/animation_track_editor.h"
#include "scene/resources/texture.h"

class AnimationTrackEditBool : public AnimationTrackEdit {
	GDCLASS(AnimationTrackEditBool, AnimationTrackEdit);
	Ref<Texture2D> icon_checked;
	Ref<Texture2D> icon_unchecked;

public:
	int get_key_height() const override;
	Rect2 get_key_rect(int p_index, float p_pixels_sec) override;
	bool is_key_selectable_by_distance() const override;
	void draw_key(int p_index, float p_pixels_sec, int p_x, bool p_selected, int p_clip_left, int p_clip_right) override;
};

class AnimationTrackEditColor : public AnimationTrackEdit {
	GDCLASS(AnimationTrackEditColor, AnimationTrackEdit);

public:
	int get_key_height() const override;
	Rect2 get_key_rect(int p_index, float p_pixels_sec) override;
	bool is_key_selectable_by_distance() const override;
	void draw_key(int p_index, float p_pixels_sec, int p_x, bool p_selected, int p_clip_left, int p_clip_right) override;
	void draw_key_link(int p_index, float p_pixels_sec, int p_x, int p_next_x, int p_clip_left, int p_clip_right) override;
};

class AnimationTrackEditAudio : public AnimationTrackEdit {
	GDCLASS(AnimationTrackEditAudio, AnimationTrackEdit);

	ObjectID id;

	void _preview_changed(ObjectID p_which);

public:
	int get_key_height() const override;
	Rect2 get_key_rect(int p_index, float p_pixels_sec) override;
	bool is_key_selectable_by_distance() const override;
	void draw_key(int p_index, float p_pixels_sec, int p_x, bool p_selected, int p_clip_left, int p_clip_right) override;

	void set_node(Object *p_object);

	AnimationTrackEditAudio();
};

class AnimationTrackEditSpriteFrame : public AnimationTrackEdit {
	GDCLASS(AnimationTrackEditSpriteFrame, AnimationTrackEdit);

	ObjectID id;
	bool is_coords = false;

public:
	int get_key_height() const override;
	Rect2 get_key_rect(int p_index, float p_pixels_sec) override;
	bool is_key_selectable_by_distance() const override;
	void draw_key(int p_index, float p_pixels_sec, int p_x, bool p_selected, int p_clip_left, int p_clip_right) override;

	void set_node(Object *p_object);
	void set_as_coords();

	AnimationTrackEditSpriteFrame() {}
};

class AnimationTrackEditSubAnim : public AnimationTrackEdit {
	GDCLASS(AnimationTrackEditSubAnim, AnimationTrackEdit);

	ObjectID id;

public:
	int get_key_height() const override;
	Rect2 get_key_rect(int p_index, float p_pixels_sec) override;
	bool is_key_selectable_by_distance() const override;
	void draw_key(int p_index, float p_pixels_sec, int p_x, bool p_selected, int p_clip_left, int p_clip_right) override;

	void set_node(Object *p_object);
};

class AnimationTrackEditTypeAudio : public AnimationTrackEdit {
	GDCLASS(AnimationTrackEditTypeAudio, AnimationTrackEdit);

	void _preview_changed(ObjectID p_which);

	bool len_resizing = false;
	bool len_resizing_start = false;
	int len_resizing_index = 0;
	float len_resizing_from_px = 0.0F;
	float len_resizing_rel = 0.0F;
	bool over_drag_position = false;

public:
	void gui_input(const Ref<InputEvent> &p_event) override;

	bool can_drop_data(const Point2 &p_point, const Variant &p_data) const override;
	void drop_data(const Point2 &p_point, const Variant &p_data) override;

	int get_key_height() const override;
	Rect2 get_key_rect(int p_index, float p_pixels_sec) override;
	bool is_key_selectable_by_distance() const override;
	void draw_key(int p_index, float p_pixels_sec, int p_x, bool p_selected, int p_clip_left, int p_clip_right) override;

	CursorShape get_cursor_shape(const Point2 &p_pos) const override;

	AnimationTrackEditTypeAudio();
};

class AnimationTrackEditTypeAnimation : public AnimationTrackEdit {
	GDCLASS(AnimationTrackEditTypeAnimation, AnimationTrackEdit);

	ObjectID id;

public:
	int get_key_height() const override;
	Rect2 get_key_rect(int p_index, float p_pixels_sec) override;
	bool is_key_selectable_by_distance() const override;
	void draw_key(int p_index, float p_pixels_sec, int p_x, bool p_selected, int p_clip_left, int p_clip_right) override;

	void set_node(Object *p_object);
	AnimationTrackEditTypeAnimation();
};

class AnimationTrackEditVolumeDB : public AnimationTrackEdit {
	GDCLASS(AnimationTrackEditVolumeDB, AnimationTrackEdit);

public:
	void draw_bg(int p_clip_left, int p_clip_right) override;
	void draw_fg(int p_clip_left, int p_clip_right) override;
	int get_key_height() const override;
	void draw_key_link(int p_index, float p_pixels_sec, int p_x, int p_next_x, int p_clip_left, int p_clip_right) override;
};

class AnimationTrackEditDefaultPlugin : public AnimationTrackEditPlugin {
	GDCLASS(AnimationTrackEditDefaultPlugin, AnimationTrackEditPlugin);

public:
	AnimationTrackEdit *create_value_track_edit(Object *p_object, Variant::Type p_type, const String &p_property, PropertyHint p_hint, const String &p_hint_string, int p_usage) override;
	AnimationTrackEdit *create_audio_track_edit() override;
	AnimationTrackEdit *create_animation_track_edit(Object *p_object) override;
};

#endif // ANIMATION_TRACK_EDITOR_PLUGINS_H
