#include <cstdint>
#include <string>
#include <vector>

#include "cpp_channel_export.hpp"

#include "broadcast.hpp"

template class CPP_CHANNEL_EXPORT channel::Receiver<bool>;

template class CPP_CHANNEL_EXPORT channel::Receiver<uint8_t>;

template class CPP_CHANNEL_EXPORT channel::Receiver<uint16_t>;

template class CPP_CHANNEL_EXPORT channel::Receiver<uint32_t>;

template class CPP_CHANNEL_EXPORT channel::Receiver<uint64_t>;

template class CPP_CHANNEL_EXPORT channel::Receiver<int8_t>;

template class CPP_CHANNEL_EXPORT channel::Receiver<int16_t>;

template class CPP_CHANNEL_EXPORT channel::Receiver<int32_t>;

template class CPP_CHANNEL_EXPORT channel::Receiver<int64_t>;

template class CPP_CHANNEL_EXPORT channel::Receiver<std::string>;

template class CPP_CHANNEL_EXPORT channel::Receiver<std::wstring>;

template class CPP_CHANNEL_EXPORT channel::Receiver<std::vector<bool>>;

template class CPP_CHANNEL_EXPORT channel::Receiver<std::vector<uint8_t>>;

template class CPP_CHANNEL_EXPORT channel::Receiver<std::vector<int8_t>>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<bool>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<uint8_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<uint16_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<uint32_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<uint64_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<int8_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<int16_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<int32_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<int64_t>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<std::string>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<std::wstring>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<std::vector<bool>>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<std::vector<uint8_t>>;

template class CPP_CHANNEL_EXPORT channel::BroadcastReceiver<std::vector<int8_t>>;
