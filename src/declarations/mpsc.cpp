#include <cstdint>
#include <string>
#include <vector>

#include "mpsc.hpp"

template class channel::Mpsc<bool>;

template class channel::Mpsc<uint8_t>;
template class channel::Mpsc<uint16_t>;
template class channel::Mpsc<uint32_t>;
template class channel::Mpsc<uint64_t>;

template class channel::Mpsc<int8_t>;
template class channel::Mpsc<int16_t>;
template class channel::Mpsc<int32_t>;
template class channel::Mpsc<int64_t>;

template class channel::Mpsc<std::string>;
template class channel::Mpsc<std::wstring>;

template class channel::Mpsc<std::vector<bool>>;
template class channel::Mpsc<std::vector<uint8_t>>;
template class channel::Mpsc<std::vector<int8_t>>;
