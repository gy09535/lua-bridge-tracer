#pragma once

#include "lua_class_description.h"

#include <opentracing/tracer.h>

namespace lua_bridge_tracer {
class LuaSpan {
 public:
  explicit LuaSpan(const std::shared_ptr<opentracing::Span>& span)
      : span_{span} {}

  static const LuaClassDescription description;

 private:
  std::shared_ptr<opentracing::Span> span_;
  std::vector<opentracing::LogRecord> log_records_;

  static int free(lua_State* L) noexcept;

  static int finish(lua_State* L) noexcept;

  static int context(lua_State* L) noexcept;

  static int set_tag(lua_State* L) noexcept;

  static int log(lua_State* L) noexcept;
};
}  // namespace lua_bridge_tracer
