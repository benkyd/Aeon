#ifndef AEON_ENTITY_ENTITY_H_
#define AEON_ENTITY_ENTITY_H_

#include <entt/entity/registry.hpp>
#include <entt/entt.hpp>

namespace EC
{
using Entity = entt::entity;
using Registry = entt::registry;
using Handle = entt::handle;

template <typename... Components>
using View = entt::basic_view<entt::entity, entt::exclude_t<>, Components...>;

using Dispatcher = entt::dispatcher;

static constexpr auto null = entt::null;
} // namespace EC

#endif
