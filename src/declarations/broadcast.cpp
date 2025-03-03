#include <cstdint>
#include <string>
#include <vector>

#include "broadcast.hpp"

template class channel::Broadcast<bool>;

template class channel::Broadcast<uint8_t>;
template class channel::Broadcast<uint16_t>;
template class channel::Broadcast<uint32_t>;
template class channel::Broadcast<uint64_t>;

template class channel::Broadcast<int8_t>;
template class channel::Broadcast<int16_t>;
template class channel::Broadcast<int32_t>;
template class channel::Broadcast<int64_t>;

template class channel::Broadcast<std::string>;
template class channel::Broadcast<std::wstring>;

template class channel::Broadcast<std::vector<bool>>;
template class channel::Broadcast<std::vector<uint8_t>>;
template class channel::Broadcast<std::vector<int8_t>>;
