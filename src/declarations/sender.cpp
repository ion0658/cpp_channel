#include <cstdint>
#include <string>
#include <vector>

#include "sender.hpp"

template class channel::Sender<bool>;

template class channel::Sender<uint8_t>;

template class channel::Sender<uint16_t>;

template class channel::Sender<uint32_t>;

template class channel::Sender<uint64_t>;

template class channel::Sender<int8_t>;

template class channel::Sender<int16_t>;

template class channel::Sender<int32_t>;

template class channel::Sender<int64_t>;

template class channel::Sender<std::string>;

template class channel::Sender<std::wstring>;

template class channel::Sender<std::vector<bool>>;

template class channel::Sender<std::vector<uint8_t>>;

template class channel::Sender<std::vector<int8_t>>;
