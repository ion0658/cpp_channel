#include <cstdint>
#include <string>
#include <vector>

#include "core/broadcast_channel.hpp"

template class channel::BroadcastChannel<bool>;

template class channel::BroadcastChannel<uint8_t>;
template class channel::BroadcastChannel<uint16_t>;
template class channel::BroadcastChannel<uint32_t>;
template class channel::BroadcastChannel<uint64_t>;

template class channel::BroadcastChannel<int8_t>;
template class channel::BroadcastChannel<int16_t>;
template class channel::BroadcastChannel<int32_t>;
template class channel::BroadcastChannel<int64_t>;

template class channel::BroadcastChannel<std::string>;
template class channel::BroadcastChannel<std::wstring>;

template class channel::BroadcastChannel<std::vector<bool>>;
template class channel::BroadcastChannel<std::vector<uint8_t>>;
template class channel::BroadcastChannel<std::vector<int8_t>>;
