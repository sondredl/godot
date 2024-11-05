// SPDX-License-Identifier: MIT OR MPL-2.0 OR LGPL-2.1-or-later OR GPL-2.0-or-later
// Copyright 2011, SIL International, All rights reserved.

// JSON debug logging
// Author: Tim Eves

#if !defined GRAPHITE2_NTRACING

#include <cstdio>
#include <limits>
#include "inc/json.h"

#if defined(_MSC_VER)
#define FORMAT_INTMAX "%lli"
#define FORMAT_UINTMAX "%llu"
#else
#define FORMAT_INTMAX "%ji"
#define FORMAT_UINTMAX "%ju"
#endif

using namespace graphite2;

namespace
{
    enum
    {
        seq = ',',
        obj='}', member=':', empty_obj='{',
        arr=']', empty_arr='['
    };
}

const std::nullptr_t json::null = nullptr;

inline
void json::context(const char current) noexcept
{
    fprintf(_stream, "%c", *_context);
    indent();
    *_context = current;
}


void json::indent(const int d) noexcept
{
    if (*_context == member || (_flatten  && _flatten < _context)) {
        fputc(' ', _stream);
    } else {
        fprintf(_stream,  "\n%*s",  4*int(_context - _contexts + d), "");
}
}


inline
void json::push_context(const char prefix, const char suffix) noexcept
{
    assert(_context - _contexts < ptrdiff_t(sizeof _contexts));

    if (_context == _contexts) {
        *_context = suffix;
    } else {
        context(suffix);
}
    *++_context = prefix;
}


void json::pop_context() noexcept
{
    assert(_context > _contexts);

    if (*_context == seq) {   indent(-1);
    } else {                    fputc(*_context, _stream);
}

    fputc(*--_context, _stream);
    if (_context == _contexts) {  fputc('\n', _stream);
}
    fflush(_stream);

    if (_flatten >= _context) {   _flatten = 0;
}
    *_context = seq;
}


// These four functions cannot be inlined as pointers to these
// functions are needed for operator << (_context_t) to work.
void json::flat(json & j) noexcept   { if (!j._flatten) {  j._flatten = j._context;
}}
void json::close(json & j) noexcept  { j.pop_context(); }
void json::object(json & j) noexcept { j.push_context('{', '}'); }
void json::array(json & j) noexcept  { j.push_context('[', ']'); }
void json::item(json & j) noexcept
{
    while (j._context > j._contexts+1 && j._context[-1] != arr) {
        j.pop_context();
}
}


json & json::operator << (json::string s) noexcept
{
    const char ctxt = _context[-1] == obj ? *_context == member ? seq : member : seq;
    context(ctxt);
    fprintf(_stream, "\"%s\"", s);
    if (ctxt == member) { fputc(' ', _stream);
}

    return *this;
}

json & json::operator << (json::number f) noexcept
{
    context(seq);
    if (std::numeric_limits<json::number>::infinity() == f) {
        fputs("Infinity", _stream);
    } else if (-std::numeric_limits<json::number>::infinity() == f) {
        fputs("-Infinity", _stream);
    } else if (std::numeric_limits<json::number>::quiet_NaN() == f ||
            std::numeric_limits<json::number>::signaling_NaN() == f) {
        fputs("NaN", _stream);
    } else {
        fprintf(_stream, "%g", f);
}
    return *this;
}
json & json::operator << (json::integer d) noexcept  { context(seq); fprintf(_stream, FORMAT_INTMAX, intmax_t(d)); return *this; }
json & json::operator << (json::integer_u d) noexcept  { context(seq); fprintf(_stream, FORMAT_UINTMAX, uintmax_t(d)); return *this; }
json & json::operator << (json::boolean b) noexcept  { context(seq); fputs(b ? "true" : "false", _stream); return *this; }
json & json::operator << (std::nullptr_t)  noexcept  { context(seq); fputs("null",_stream); return *this; }

#endif
