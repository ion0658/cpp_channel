#include <cstdint>
#include <string>
#include <vector>

#include "cpp_channel_export.hpp"

#include "channel/broadcast_channel.hpp"

template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<bool>;

template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<uint8_t>;
template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<uint16_t>;
template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<uint32_t>;
template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<uint64_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<int8_t>;
template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<int16_t>;
template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<int32_t>;
template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<int64_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<size_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<std::string>;
template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<std::wstring>;

template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<std::vector<bool>>;
template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<std::vector<uint8_t>>;
template class CPP_CHANNEL_EXPORT channel::BroadcastChannel<std::vector<int8_t>>;
