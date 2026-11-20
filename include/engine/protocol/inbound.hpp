#pragma once

#include <cstddef>
#include <cstdint>
#include <engine/types.hpp>
#include <type_traits>

namespace engine::protocol::inbound {

template <types::MessageType Tag> struct OrderMessage {
    static constexpr types::MessageType kType{Tag};

    types::MessageType type{Tag};
    types::Side side{};
    types::TimeInForce tif{};
    std::byte _reserved0[1]{};
    std::uint32_t clientId{};
    std::uint64_t clientOrderId{};
    std::uint32_t instrumentId{};
    std::uint32_t quantity{};
    std::int64_t price{};
};

using NewOrder = OrderMessage<types::MessageType::New>;
using ModifyOrder = OrderMessage<types::MessageType::Modify>;

static_assert(offsetof(NewOrder, type) == 0);
static_assert(offsetof(NewOrder, side) == 1);
static_assert(offsetof(NewOrder, tif) == 2);
static_assert(offsetof(NewOrder, clientId) == 4);
static_assert(offsetof(NewOrder, clientOrderId) == 8);
static_assert(offsetof(NewOrder, instrumentId) == 16);
static_assert(offsetof(NewOrder, quantity) == 20);
static_assert(offsetof(NewOrder, price) == 24);
static_assert(std::is_standard_layout_v<NewOrder>);
static_assert(std::has_unique_object_representations_v<NewOrder>);
static_assert(std::is_standard_layout_v<ModifyOrder>);
static_assert(std::has_unique_object_representations_v<ModifyOrder>);
static_assert(std::is_trivially_copyable_v<NewOrder>);
static_assert(std::is_trivially_copyable_v<ModifyOrder>);
static_assert(sizeof(NewOrder) == 32);
static_assert(sizeof(ModifyOrder) == 32);

struct CancelOrder {
    types::MessageType type{types::MessageType::Cancel};
    std::byte _reserved0[3]{};
    std::uint32_t clientId{};
    std::uint64_t clientOrderId{};
    std::uint32_t instrumentId{};
    std::byte _reserved1[12]{};
};

static_assert(offsetof(CancelOrder, type) == 0);
static_assert(offsetof(CancelOrder, clientId) == 4);
static_assert(offsetof(CancelOrder, clientOrderId) == 8);
static_assert(offsetof(CancelOrder, instrumentId) == 16);
static_assert(std::is_standard_layout_v<CancelOrder>);
static_assert(std::has_unique_object_representations_v<CancelOrder>);
static_assert(std::is_trivially_copyable_v<CancelOrder>);
static_assert(sizeof(CancelOrder) == 32);

struct SnapshotRequest {
    types::MessageType type{types::MessageType::SnapshotRequest};
    std::byte _reserved0[3]{};
    std::uint32_t instrumentId{};
    std::byte _reserved1[24]{};
};

static_assert(offsetof(SnapshotRequest, type) == 0);
static_assert(offsetof(SnapshotRequest, instrumentId) == 4);
static_assert(std::is_standard_layout_v<SnapshotRequest>);
static_assert(std::has_unique_object_representations_v<SnapshotRequest>);
static_assert(std::is_trivially_copyable_v<SnapshotRequest>);
static_assert(sizeof(SnapshotRequest) == 32);
} // namespace engine::protocol::inbound