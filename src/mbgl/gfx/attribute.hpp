#pragma once

#include <mbgl/util/type_list.hpp>
#include <mbgl/util/indexed_tuple.hpp>

#include <array>

#define MBGL_DEFINE_ATTRIBUTE(type_, n_, name_)                                                    \
    struct name_ {                                                                                 \
        using ValueType = type_;                                                                   \
        static constexpr size_t Dimensions = n_;                                                   \
        using Value = std::array<type_, n_>;                                                       \
        static auto name() {                                                                       \
            return #name_;                                                                         \
        }                                                                                          \
    }

namespace mbgl {
namespace gfx {

// Attribute binding requires member offsets. The only standard way to
// obtain an offset is the offsetof macro. The offsetof macro has defined
// behavior only for standard layout types. That rules out std::tuple and
// any other solution that relies on chained inheritance. Manually implemented
// variadic specialization looks like the only solution. Fortunately, we
// only use a maximum of five attributes.

template <class>
class Vertex;

template <>
class Vertex<TypeList<>> {
public:
    using VertexType = Vertex<TypeList<>>;
};

template <class A1>
class Vertex<TypeList<A1>> {
public:
    typename A1::Value a1;

    using VertexType = Vertex<TypeList<A1>>;
    static const std::size_t attributeOffsets[1];
};

template <class A1, class A2>
class Vertex<TypeList<A1, A2>> {
public:
    typename A1::Value a1;
    typename A2::Value a2;

    using VertexType = Vertex<TypeList<A1, A2>>;
    static const std::size_t attributeOffsets[2];
};

template <class A1, class A2, class A3>
class Vertex<TypeList<A1, A2, A3>> {
public:
    typename A1::Value a1;
    typename A2::Value a2;
    typename A3::Value a3;

    using VertexType = Vertex<TypeList<A1, A2, A3>>;
    static const std::size_t attributeOffsets[3];
};

template <class A1, class A2, class A3, class A4>
class Vertex<TypeList<A1, A2, A3, A4>> {
public:
    typename A1::Value a1;
    typename A2::Value a2;
    typename A3::Value a3;
    typename A4::Value a4;

    using VertexType = Vertex<TypeList<A1, A2, A3, A4>>;
    static const std::size_t attributeOffsets[4];
};

template <class A1, class A2, class A3, class A4, class A5>
class Vertex<TypeList<A1, A2, A3, A4, A5>> {
public:
    typename A1::Value a1;
    typename A2::Value a2;
    typename A3::Value a3;
    typename A4::Value a4;
    typename A5::Value a5;

    using VertexType = Vertex<TypeList<A1, A2, A3, A4, A5>>;
    static const std::size_t attributeOffsets[5];
};

template <class A1>
const std::size_t Vertex<TypeList<A1>>::attributeOffsets[1] = {
    offsetof(VertexType, a1)
};

template <class A1, class A2>
const std::size_t Vertex<TypeList<A1, A2>>::attributeOffsets[2] = {
    offsetof(VertexType, a1),
    offsetof(VertexType, a2)
};

template <class A1, class A2, class A3>
const std::size_t Vertex<TypeList<A1, A2, A3>>::attributeOffsets[3] = {
    offsetof(VertexType, a1),
    offsetof(VertexType, a2),
    offsetof(VertexType, a3)
};

template <class A1, class A2, class A3, class A4>
const std::size_t Vertex<TypeList<A1, A2, A3, A4>>::attributeOffsets[4] = {
    offsetof(VertexType, a1),
    offsetof(VertexType, a2),
    offsetof(VertexType, a3),
    offsetof(VertexType, a4)
};

template <class A1, class A2, class A3, class A4, class A5>
const std::size_t Vertex<TypeList<A1, A2, A3, A4, A5>>::attributeOffsets[5] = {
    offsetof(VertexType, a1),
    offsetof(VertexType, a2),
    offsetof(VertexType, a3),
    offsetof(VertexType, a4),
    offsetof(VertexType, a5)
};

} // namespace gfx
} // namespace mbgl
