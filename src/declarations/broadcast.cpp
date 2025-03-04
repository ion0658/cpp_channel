#include <cstdint>
#include <string>
#include <vector>

#include "cpp_channel_export.hpp"

#include "broadcast.hpp"

template class CPP_CHANNEL_EXPORT channel::Broadcast<bool>;

template class CPP_CHANNEL_EXPORT channel::Broadcast<uint8_t>;
template class CPP_CHANNEL_EXPORT channel::Broadcast<uint16_t>;
template class CPP_CHANNEL_EXPORT channel::Broadcast<uint32_t>;
template class CPP_CHANNEL_EXPORT channel::Broadcast<uint64_t>;

template class CPP_CHANNEL_EXPORT channel::Broadcast<int8_t>;
template class CPP_CHANNEL_EXPORT channel::Broadcast<int16_t>;
template class CPP_CHANNEL_EXPORT channel::Broadcast<int32_t>;
template class CPP_CHANNEL_EXPORT channel::Broadcast<int64_t>;

template class CPP_CHANNEL_EXPORT channel::Broadcast<std::string>;
template class CPP_CHANNEL_EXPORT channel::Broadcast<std::wstring>;

template class CPP_CHANNEL_EXPORT channel::Broadcast<std::vector<bool>>;
template class CPP_CHANNEL_EXPORT channel::Broadcast<std::vector<uint8_t>>;
template class CPP_CHANNEL_EXPORT channel::Broadcast<std::vector<int8_t>>;
