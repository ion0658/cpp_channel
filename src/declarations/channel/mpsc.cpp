#include <cstdint>
#include <string>
#include <vector>

#include "core/mpsc_channnel.hpp"

template class channel::MpscChannel<bool>;

template class channel::MpscChannel<uint8_t>;
template class channel::MpscChannel<uint16_t>;
template class channel::MpscChannel<uint32_t>;
template class channel::MpscChannel<uint64_t>;

template class channel::MpscChannel<int8_t>;
template class channel::MpscChannel<int16_t>;
template class channel::MpscChannel<int32_t>;
template class channel::MpscChannel<int64_t>;

template class channel::MpscChannel<std::string>;
template class channel::MpscChannel<std::wstring>;

template class channel::MpscChannel<std::vector<bool>>;
template class channel::MpscChannel<std::vector<uint8_t>>;
template class channel::MpscChannel<std::vector<int8_t>>;
