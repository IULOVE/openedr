//
// edrav2.libcore project
//
// Declaration of EDR events
//
// Author: Yury Kroshin (13.02.2019)
// Reviewer: Denis Bogdanov (14.02.2019)
//
#pragma once
#include "crypt.hpp"

// TODO: Move this file to separate EDR-related project

namespace cmd {

//
// LLE identifiers
//
enum class Event : uint64_t
{
	// LLE events has 62 and 63 bits clear
	LLE_NONE						= 0x0000000000000000L,
	LLE_PROCESS_CREATE				= 0x0000000000000001L,
	LLE_PROCESS_DELETE				= 0x0000000000000002L,
	LLE_FILE_CREATE					= 0x0000000000000003L,
	LLE_FILE_DELETE					= 0x0000000000000004L,
	LLE_FILE_CLOSE					= 0x0000000000000005L,
	LLE_FILE_DATA_CHANGE			= 0x0000000000000006L,
	LLE_FILE_DATA_READ_FULL			= 0x0000000000000007L,	// Internal
	LLE_FILE_DATA_WRITE_FULL		= 0x0000000000000008L,	// Internal
	LLE_REGISTRY_KEY_CREATE			= 0x0000000000000009L,
	LLE_REGISTRY_KEY_NAME_CHANGE	= 0x000000000000000AL,
	LLE_REGISTRY_KEY_DELETE			= 0x000000000000000BL,
	LLE_REGISTRY_VALUE_SET			= 0x000000000000000CL,
	LLE_REGISTRY_VALUE_DELETE		= 0x000000000000000DL,
	LLE_PROCESS_OPEN				= 0x000000000000000EL,
	LLE_PROCESS_MEMORY_READ			= 0x000000000000000FL,
	LLE_PROCESS_MEMORY_WRITE		= 0x0000000000000010L,
	LLE_WINDOW_PROC_GLOBAL_HOOK		= 0x0000000000000011L,
	LLE_KEYBOARD_GLOBAL_READ		= 0x0000000000000012L,
	LLE_DISK_RAW_WRITE_ACCESS		= 0x0000000000000013L,
	LLE_VOLUME_RAW_WRITE_ACCESS		= 0x0000000000000014L,
	LLE_DEVICE_RAW_WRITE_ACCESS		= 0x0000000000000015L,
	LLE_DISK_LINK_CREATE			= 0x0000000000000016L,
	LLE_VOLUME_LINK_CREATE			= 0x0000000000000017L,
	LLE_DEVICE_LINK_CREATE			= 0x0000000000000018L,
	LLE_INJECTION_ACTIVITY			= 0x0000000000000019L,	// Internal
	LLE_KEYBOARD_BLOCK				= 0x000000000000001AL,
	LLE_CLIPBOARD_READ				= 0x000000000000001BL,
	//MLE_FILE_COPY_TO_USB			= 0x400000000000001CL,
	//MLE_FILE_COPY_TO_SHARE			= 0x400000000000001DL,
	//MLE_FILE_COPY_FROM_USB			= 0x400000000000001EL,
	//MLE_FILE_COPY_FROM_SHARE		= 0x400000000000001FL,
	LLE_KEYBOARD_GLOBAL_WRITE		= 0x0000000000000020L,
	LLE_MICROPHONE_ENUM				= 0x0000000000000021L,
	LLE_MICROPHONE_READ				= 0x0000000000000022L,
	LLE_MOUSE_GLOBAL_WRITE			= 0x0000000000000023L,
	LLE_WINDOW_DATA_READ			= 0x0000000000000024L,
	LLE_DESKTOP_WALLPAPER_SET		= 0x0000000000000025L,
	LLE_MOUSE_BLOCK					= 0x0000000000000026L,
	LLE_NETWORK_CONNECT_IN			= 0x0000000000000027L,
	LLE_NETWORK_CONNECT_OUT			= 0x0000000000000028L,
	LLE_NETWORK_LISTEN				= 0x0000000000000029L,
	//MLE_FILE_COPY					= 0x400000000000002AL, // Internal
	LLE_USER_LOGON					= 0x000000000000002BL, // Internal
	LLE_USER_IMPERSONATION			= 0x000000000000002CL,
	LLE_NETWORK_REQUEST_DNS			= 0x000000000000002DL,
	LLE_NETWORK_REQUEST_DATA		= 0x000000000000002EL, 



	// MLE events has 62 bit set and 63 bit clear
	MLE_MASK = 0x4000000000000000L,
	// External MLE events has 63 bit set
	MLE_EXT_MASK = 0x8000000000000000L,
};

///
/// Get event type name string by given code
///
/// @param eventType a code of the event type
/// @return Returns a string with a name of the event type corresponding to a given code.
///
const char* getEventTypeString(Event eventType);

//
//
//
inline uint64_t createMle(Event eLleId, std::string sMleId = "")
{
	if (!sMleId.empty())
	{
		uint64_t nHash = crypt::xxh::getHash(sMleId);
		return nHash | (uint64_t)Event::MLE_EXT_MASK;
	}
	return (uint64_t)eLleId | (uint64_t)Event::MLE_MASK;
}

//
//
//
inline uint64_t createRaw(ClassId eClsid, uint32_t nEvent)
{
	return (uint64_t)eClsid << 32 | nEvent;
}

} // namespace cmd