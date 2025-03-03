#include <cstdint>
#include <string>
#include <vector>

#include "broadcast.hpp"

template class channel::Receiver<bool>;

template class channel::Receiver<uint8_t>;

template class channel::Receiver<uint16_t>;

template class channel::Receiver<uint32_t>;

template class channel::Receiver<uint64_t>;

template class channel::Receiver<int8_t>;

template class channel::Receiver<int16_t>;

template class channel::Receiver<int32_t>;

template class channel::Receiver<int64_t>;

template class channel::Receiver<std::string>;

template class channel::Receiver<std::wstring>;

template class channel::Receiver<std::vector<bool>>;

template class channel::Receiver<std::vector<uint8_t>>;

template class channel::Receiver<std::vector<int8_t>>;

template class channel::BroadcastReceiver<bool>;

template class channel::BroadcastReceiver<uint8_t>;

template class channel::BroadcastReceiver<uint16_t>;

template class channel::BroadcastReceiver<uint32_t>;

template class channel::BroadcastReceiver<uint64_t>;

template class channel::BroadcastReceiver<int8_t>;

template class channel::BroadcastReceiver<int16_t>;

template class channel::BroadcastReceiver<int32_t>;

template class channel::BroadcastReceiver<int64_t>;

template class channel::BroadcastReceiver<std::string>;

template class channel::BroadcastReceiver<std::wstring>;

template class channel::BroadcastReceiver<std::vector<bool>>;

template class channel::BroadcastReceiver<std::vector<uint8_t>>;

template class channel::BroadcastReceiver<std::vector<int8_t>>;
