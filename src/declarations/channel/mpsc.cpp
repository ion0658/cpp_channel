#include <cstdint>
#include <string>
#include <vector>

#include "cpp_channel_export.hpp"

#include "core/mpsc_channnel.hpp"

template class CPP_CHANNEL_EXPORT channel::MpscChannel<bool>;

template class CPP_CHANNEL_EXPORT channel::MpscChannel<uint8_t>;
template class CPP_CHANNEL_EXPORT channel::MpscChannel<uint16_t>;
template class CPP_CHANNEL_EXPORT channel::MpscChannel<uint32_t>;
template class CPP_CHANNEL_EXPORT channel::MpscChannel<uint64_t>;

template class CPP_CHANNEL_EXPORT channel::MpscChannel<int8_t>;
template class CPP_CHANNEL_EXPORT channel::MpscChannel<int16_t>;
template class CPP_CHANNEL_EXPORT channel::MpscChannel<int32_t>;
template class CPP_CHANNEL_EXPORT channel::MpscChannel<int64_t>;

template class CPP_CHANNEL_EXPORT channel::MpscChannel<std::string>;
template class CPP_CHANNEL_EXPORT channel::MpscChannel<std::wstring>;

template class CPP_CHANNEL_EXPORT channel::MpscChannel<std::vector<bool>>;
template class CPP_CHANNEL_EXPORT channel::MpscChannel<std::vector<uint8_t>>;
template class CPP_CHANNEL_EXPORT channel::MpscChannel<std::vector<int8_t>>;
