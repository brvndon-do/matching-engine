#pragma once

#include <cstdint>

namespace engine::types {
enum class Side : std::uint8_t { Buy, Sell };

enum class TimeInForce : std::uint8_t {
    Gfd,
    Ioc,
};

enum class MessageType : char {
    New = 'N',
    Modify = 'M',
    Cancel = 'X',
    SnapshotRequest = 'S'
};

enum class RejectReason : std::uint8_t {
    UnknownInstrument,
    UnknownOrder,
    InvalidModify,
    ZeroQuantity,
    DuplicateOrderId,
    PriceInvalid,
    PriceOutOfBand,
    PoolFull
};

enum class CancelReason : std::uint8_t { UserRequest, IocRemainder };

// TODO: move when phase 2 starts
struct Order {
    std::int64_t price{};
    std::uint64_t clientOrderId{};
    std::uint64_t orderId{};
    std::uint32_t instrumentId{};
    std::uint32_t quantity{};
    std::uint32_t clientId{};
    Side side{};
};

static_assert(sizeof(Order) == 40);

} // namespace engine::types