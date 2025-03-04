#include <cstdint>
#include <string>
#include <vector>

#include "cpp_channel_export.hpp"

#include "mpsc.hpp"

template class CPP_CHANNEL_EXPORT channel::Mpsc<bool>;

template class CPP_CHANNEL_EXPORT channel::Mpsc<uint8_t>;
template class CPP_CHANNEL_EXPORT channel::Mpsc<uint16_t>;
template class CPP_CHANNEL_EXPORT channel::Mpsc<uint32_t>;
template class CPP_CHANNEL_EXPORT channel::Mpsc<uint64_t>;

template class CPP_CHANNEL_EXPORT channel::Mpsc<int8_t>;
template class CPP_CHANNEL_EXPORT channel::Mpsc<int16_t>;
template class CPP_CHANNEL_EXPORT channel::Mpsc<int32_t>;
template class CPP_CHANNEL_EXPORT channel::Mpsc<int64_t>;

template class CPP_CHANNEL_EXPORT channel::Mpsc<std::string>;
template class CPP_CHANNEL_EXPORT channel::Mpsc<std::wstring>;

template class CPP_CHANNEL_EXPORT channel::Mpsc<std::vector<bool>>;
template class CPP_CHANNEL_EXPORT channel::Mpsc<std::vector<uint8_t>>;
template class CPP_CHANNEL_EXPORT channel::Mpsc<std::vector<int8_t>>;
