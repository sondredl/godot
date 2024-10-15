/**************************************************************************/
/*  typed_array.h                                                         */
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

#ifndef TYPED_ARRAY_H
#define TYPED_ARRAY_H

#include "core/object/object.h"
#include "core/variant/array.h"
#include "core/variant/binder_common.h"
#include "core/variant/method_ptrcall.h"
#include "core/variant/type_info.h"
#include "core/variant/variant.h"

template <typename T>
class TypedArray : public Array {
public:
	_FORCE_INLINE_ void operator=(const Array &p_array) {
		(!is_same_typed(p_array), "Cannot assign an array with a different element type.");
		_ref(p_array);
	}
	_FORCE_INLINE_ explicit TypedArray(const Variant &p_variant) :
			TypedArray(Array(p_variant)) {
	}
	_FORCE_INLINE_ explicit TypedArray(const Array &p_array) {
		set_typed(Variant::OBJECT, T::get_class_static(), Variant());
		if (is_same_typed(p_array)) {
			_ref(p_array);
		} else {
			assign(p_array);
		}
	}
	_FORCE_INLINE_ TypedArray() {
		set_typed(Variant::OBJECT, T::get_class_static(), Variant());
	}
};

template <typename T>
struct VariantInternalAccessor<TypedArray<T>> {
	static _FORCE_INLINE_ TypedArray<T> get(const Variant *v) { return *VariantInternal::get_array(v); }
	static _FORCE_INLINE_ void set(Variant *v, const TypedArray<T> &p_array) { *VariantInternal::get_array(v) = p_array; }
};
template <typename T>
struct VariantInternalAccessor<const TypedArray<T> &> {
	static _FORCE_INLINE_ TypedArray<T> get(const Variant *v) { return *VariantInternal::get_array(v); }
	static _FORCE_INLINE_ void set(Variant *v, const TypedArray<T> &p_array) { *VariantInternal::get_array(v) = p_array; }
};

//specialization for the rest of variant types

#define MAKE_TYPED_ARRAY(m_type, m_variant_type)                                                                 \
	template <>                                                                                                  \
	class TypedArray<m_type> : public Array {                                                                    \
	public:                                                                                                      \
		_FORCE_INLINE_ void operator=(const Array &p_array) {                                                    \
			ERR_FAIL_COND_MSG(!is_same_typed(p_array), "Cannot assign an array with a different element type."); \
			_ref(p_array);                                                                                       \
		}                                                                                                        \
		_FORCE_INLINE_ TypedArray(const Variant &p_variant) :                                                    \
				TypedArray(Array(p_variant)) {                                                                   \
		}                                                                                                        \
		_FORCE_INLINE_ TypedArray(const Array &p_array) {                                                        \
			set_typed(m_variant_type, StringName(), Variant());                                                  \
			if (is_same_typed(p_array)) {                                                                        \
				_ref(p_array);                                                                                   \
			} else {                                                                                             \
				assign(p_array);                                                                                 \
			}                                                                                                    \
		}                                                                                                        \
		_FORCE_INLINE_ TypedArray() {                                                                            \
			set_typed(m_variant_type, StringName(), Variant());                                                  \
		}                                                                                                        \
	};

// All Variant::OBJECT types are intentionally omitted from this list because they are handled by
// the unspecialized TypedArray definition.
(bool, Variant::BOOL)(uint8_t, Variant::INT)(int8_t, Variant::INT)(uint16_t, Variant::INT)(int16_t, Variant::INT)(uint32_t, Variant::INT)(int32_t, Variant::INT)(uint64_t, Variant::INT)(int64_t, Variant::INT)(float, Variant::FLOAT)(double, Variant::FLOAT)(String, Variant::STRING)(Vector2, Variant::VECTOR2)(Vector2i, Variant::VECTOR2I)(Rect2, Variant::RECT2)(Rect2i, Variant::RECT2I)(Vector3, Variant::VECTOR3)(Vector3i, Variant::VECTOR3I)(Transform2D, Variant::TRANSFORM2D)(Vector4, Variant::VECTOR4)(Vector4i, Variant::VECTOR4I)(Plane, Variant::PLANE)(Quaternion, Variant::QUATERNION)(AABB, Variant::AABB)(Basis, Variant::BASIS)(Transform3D, Variant::TRANSFORM3D)(Projection, Variant::PROJECTION)(Color, Variant::COLOR)(StringName, Variant::STRING_NAME)(NodePath, Variant::NODE_PATH)(RID, Variant::RID)(Callable, Variant::CALLABLE)(Signal, Variant::SIGNAL)(Dictionary, Variant::DICTIONARY)(Array, Variant::ARRAY)(PackedByteArray, Variant::PACKED_BYTE_ARRAY)(PackedInt32Array, Variant::PACKED_INT32_ARRAY)(PackedInt64Array, Variant::PACKED_INT64_ARRAY)(PackedFloat32Array, Variant::PACKED_FLOAT32_ARRAY)(PackedFloat64Array, Variant::PACKED_FLOAT64_ARRAY)(PackedStringArray, Variant::PACKED_STRING_ARRAY)(PackedVector2Array, Variant::PACKED_VECTOR2_ARRAY)(PackedVector3Array, Variant::PACKED_VECTOR3_ARRAY)(PackedColorArray, Variant::PACKED_COLOR_ARRAY)(PackedVector4Array, Variant::PACKED_VECTOR4_ARRAY)(IPAddress, Variant::STRING)

		template <typename T>
		struct PtrToArg<TypedArray<T>> {
	_FORCE_INLINE_ static TypedArray<T> convert(const void *p_ptr) {
		return TypedArray<T>(*reinterpret_cast<const Array *>(p_ptr));
	}
	typedef Array EncodeT;
	_FORCE_INLINE_ static void encode(TypedArray<T> p_val, void *p_ptr) {
		*(Array *)p_ptr = p_val;
	}
};

template <typename T>
struct PtrToArg<const TypedArray<T> &> {
	typedef Array EncodeT;
	_FORCE_INLINE_ static TypedArray<T> convert(const void *p_ptr) {
		return TypedArray<T>(*reinterpret_cast<const Array *>(p_ptr));
	}
};

template <typename T>
struct GetTypeInfo<TypedArray<T>> {
	static const Variant::Type VARIANT_TYPE = Variant::ARRAY;
	static const GodotTypeInfo::Metadata METADATA = GodotTypeInfo::METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return PropertyInfo(Variant::ARRAY, String(), PROPERTY_HINT_ARRAY_TYPE, T::get_class_static());
	}
};

template <typename T>
struct GetTypeInfo<const TypedArray<T> &> {
	static const Variant::Type VARIANT_TYPE = Variant::ARRAY;
	static const GodotTypeInfo::Metadata METADATA = GodotTypeInfo::METADATA_NONE;
	static inline PropertyInfo get_class_info() {
		return PropertyInfo(Variant::ARRAY, String(), PROPERTY_HINT_ARRAY_TYPE, T::get_class_static());
	}
};

#define MAKE_TYPED_ARRAY_INFO(m_type, m_variant_type)                                                                        \
	template <>                                                                                                              \
	struct GetTypeInfo<TypedArray<m_type>> {                                                                                 \
		static const Variant::Type VARIANT_TYPE = Variant::ARRAY;                                                            \
		static const GodotTypeInfo::Metadata METADATA = GodotTypeInfo::METADATA_NONE;                                        \
		static inline PropertyInfo get_class_info() {                                                                        \
			return PropertyInfo(Variant::ARRAY, String(), PROPERTY_HINT_ARRAY_TYPE, Variant::get_type_name(m_variant_type)); \
		}                                                                                                                    \
	};                                                                                                                       \
	template <>                                                                                                              \
	struct GetTypeInfo<const TypedArray<m_type> &> {                                                                         \
		static const Variant::Type VARIANT_TYPE = Variant::ARRAY;                                                            \
		static const GodotTypeInfo::Metadata METADATA = GodotTypeInfo::METADATA_NONE;                                        \
		static inline PropertyInfo get_class_info() {                                                                        \
			return PropertyInfo(Variant::ARRAY, String(), PROPERTY_HINT_ARRAY_TYPE, Variant::get_type_name(m_variant_type)); \
		}                                                                                                                    \
	};

MAKE_TYPED_ARRAY_INFO(bool, Variant::BOOL)
MAKE_TYPED_ARRAY_INFO(uint8_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(int8_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(uint16_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(int16_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(uint32_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(int32_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(uint64_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(int64_t, Variant::INT)
MAKE_TYPED_ARRAY_INFO(float, Variant::FLOAT)
MAKE_TYPED_ARRAY_INFO(double, Variant::FLOAT)
MAKE_TYPED_ARRAY_INFO(String, Variant::STRING)
MAKE_TYPED_ARRAY_INFO(Vector2, Variant::VECTOR2)
MAKE_TYPED_ARRAY_INFO(Vector2i, Variant::VECTOR2I)
MAKE_TYPED_ARRAY_INFO(Rect2, Variant::RECT2)
MAKE_TYPED_ARRAY_INFO(Rect2i, Variant::RECT2I)
MAKE_TYPED_ARRAY_INFO(Vector3, Variant::VECTOR3)
MAKE_TYPED_ARRAY_INFO(Vector3i, Variant::VECTOR3I)
MAKE_TYPED_ARRAY_INFO(Transform2D, Variant::TRANSFORM2D)
MAKE_TYPED_ARRAY_INFO(Vector4, Variant::VECTOR4)
MAKE_TYPED_ARRAY_INFO(Vector4i, Variant::VECTOR4I)
MAKE_TYPED_ARRAY_INFO(Plane, Variant::PLANE)
MAKE_TYPED_ARRAY_INFO(Quaternion, Variant::QUATERNION)
MAKE_TYPED_ARRAY_INFO(AABB, Variant::AABB)
MAKE_TYPED_ARRAY_INFO(Basis, Variant::BASIS)
MAKE_TYPED_ARRAY_INFO(Transform3D, Variant::TRANSFORM3D)
MAKE_TYPED_ARRAY_INFO(Projection, Variant::PROJECTION)
MAKE_TYPED_ARRAY_INFO(Color, Variant::COLOR)
MAKE_TYPED_ARRAY_INFO(StringName, Variant::STRING_NAME)
MAKE_TYPED_ARRAY_INFO(NodePath, Variant::NODE_PATH)
MAKE_TYPED_ARRAY_INFO(RID, Variant::RID)
MAKE_TYPED_ARRAY_INFO(Callable, Variant::CALLABLE)
MAKE_TYPED_ARRAY_INFO(Signal, Variant::SIGNAL)
MAKE_TYPED_ARRAY_INFO(Dictionary, Variant::DICTIONARY)
MAKE_TYPED_ARRAY_INFO(Array, Variant::ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedByteArray, Variant::PACKED_BYTE_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedInt32Array, Variant::PACKED_INT32_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedInt64Array, Variant::PACKED_INT64_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedFloat32Array, Variant::PACKED_FLOAT32_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedFloat64Array, Variant::PACKED_FLOAT64_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedStringArray, Variant::PACKED_STRING_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedVector2Array, Variant::PACKED_VECTOR2_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedVector3Array, Variant::PACKED_VECTOR3_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedColorArray, Variant::PACKED_COLOR_ARRAY)
MAKE_TYPED_ARRAY_INFO(PackedVector4Array, Variant::PACKED_VECTOR4_ARRAY)
MAKE_TYPED_ARRAY_INFO(IPAddress, Variant::STRING)

#undef MAKE_TYPED_ARRAY
#undef MAKE_TYPED_ARRAY_INFO

#endif // TYPED_ARRAY_H
