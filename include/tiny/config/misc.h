// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 *   This file includes miscellaneous compile-time configuration constants for Tiny.
 */

#ifndef CONFIG_MISC_H_
#define CONFIG_MISC_H_

/**
 * @addtogroup config-misc
 *
 * @brief
 *   This module includes configuration variables for Miscellaneous constants.
 *
 * @{
 */

/**
 * @def TINY_CONFIG_STACK_VENDOR_OUI
 *
 * The Organizationally Unique Identifier for the Thread stack.
 */
#ifndef TINY_CONFIG_STACK_VENDOR_OUI
#define TINY_CONFIG_STACK_VENDOR_OUI 0x18b430
#endif

/**
 * @def TINY_CONFIG_STACK_VERSION_REV
 *
 * The Stack Version Revision for the Thread stack.
 */
#ifndef TINY_CONFIG_STACK_VERSION_REV
#define TINY_CONFIG_STACK_VERSION_REV 0
#endif

/**
 * @def TINY_CONFIG_STACK_VERSION_MAJOR
 *
 * The Stack Version Major for the Thread stack.
 */
#ifndef TINY_CONFIG_STACK_VERSION_MAJOR
#define TINY_CONFIG_STACK_VERSION_MAJOR 0
#endif

/**
 * @def TINY_CONFIG_STACK_VERSION_MINOR
 *
 * The Stack Version Minor for the Thread stack.
 */
#ifndef TINY_CONFIG_STACK_VERSION_MINOR
#define TINY_CONFIG_STACK_VERSION_MINOR 1
#endif

/**
 * @def TINY_CONFIG_DEVICE_POWER_SUPPLY
 *
 * Specifies the default device power supply config. This config MUST use values from `otPowerSupply` enumeration.
 *
 * Device manufacturer can use this config to set the power supply config used by the device. This is then used as part
 * of default `otDeviceProperties` to determine the Leader Weight used by the device.
 */
#ifndef TINY_CONFIG_DEVICE_POWER_SUPPLY
#define TINY_CONFIG_DEVICE_POWER_SUPPLY OT_POWER_SUPPLY_EXTERNAL
#endif

/**
 * @def TINY_CONFIG_ECDSA_ENABLE
 *
 * Define to 1 to enable ECDSA support.
 */
#ifndef TINY_CONFIG_ECDSA_ENABLE
#define TINY_CONFIG_ECDSA_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_DETERMINISTIC_ECDSA_ENABLE
 *
 * Define to 1 to generate ECDSA signatures deterministically
 * according to RFC 6979 instead of randomly.
 */
#ifndef TINY_CONFIG_DETERMINISTIC_ECDSA_ENABLE
#define TINY_CONFIG_DETERMINISTIC_ECDSA_ENABLE 1
#endif

/**
 * @def TINY_CONFIG_UPTIME_ENABLE
 *
 * Define to 1 to enable tracking the uptime of Tiny instance.
 *
 * On FTD/MTD builds this feature is now mandatory and MUST be enabled. This config is therefore only applicable for
 * RADIO/RCP builds.
 *
 */
#ifndef TINY_CONFIG_UPTIME_ENABLE
#define TINY_CONFIG_UPTIME_ENABLE (TINY_FTD || TINY_MTD)
#endif

/**
 * @def TINY_CONFIG_JAM_DETECTION_ENABLE
 *
 * Define to 1 to enable the Jam Detection service.
 */
#ifndef TINY_CONFIG_JAM_DETECTION_ENABLE
#define TINY_CONFIG_JAM_DETECTION_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_VERHOEFF_CHECKSUM_ENABLE
 *
 * Define to 1 to enable Verhoeff checksum utility module.
 */
#ifndef TINY_CONFIG_VERHOEFF_CHECKSUM_ENABLE
#define TINY_CONFIG_VERHOEFF_CHECKSUM_ENABLE TINY_CONFIG_BORDER_AGENT_EPHEMERAL_KEY_ENABLE
#endif

/**
 * @def TINY_CONFIG_MULTIPLE_INSTANCE_ENABLE
 *
 * Define to 1 to enable multiple instance support.
 */
#ifndef TINY_CONFIG_MULTIPLE_INSTANCE_ENABLE
#define TINY_CONFIG_MULTIPLE_INSTANCE_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_MULTIPAN_RCP_ENABLE
 *
 * Define to 1 to enable multipan RCP support.
 */
#ifndef TINY_CONFIG_MULTIPAN_RCP_ENABLE
#define TINY_CONFIG_MULTIPAN_RCP_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_REFERENCE_DEVICE_ENABLE
 *
 * Define to 1 to enable Thread Test Harness reference device support.
 */
#ifndef TINY_CONFIG_REFERENCE_DEVICE_ENABLE
#define TINY_CONFIG_REFERENCE_DEVICE_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_UDP_FORWARD_ENABLE
 *
 * Define to 1 to enable UDP forward support.
 */
#ifndef TINY_CONFIG_UDP_FORWARD_ENABLE
#define TINY_CONFIG_UDP_FORWARD_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_MESSAGE_USE_HEAP_ENABLE
 *
 * Whether use heap allocator for message buffers.
 *
 * @note If this is set, TINY_CONFIG_NUM_MESSAGE_BUFFERS is ignored.
 */
#ifndef TINY_CONFIG_MESSAGE_USE_HEAP_ENABLE
#define TINY_CONFIG_MESSAGE_USE_HEAP_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_NUM_MESSAGE_BUFFERS
 *
 * The number of message buffers in the buffer pool.
 */
#ifndef TINY_CONFIG_NUM_MESSAGE_BUFFERS
#define TINY_CONFIG_NUM_MESSAGE_BUFFERS 44
#endif

/**
 * @def TINY_CONFIG_MESSAGE_BUFFER_SIZE
 *
 * The size of a message buffer in bytes.
 *
 * Message buffers store pointers which have different sizes on different
 * system. Setting message buffer size according to the CPU word length
 * so that message buffer size will be doubled on 64bit system compared
 * to that on 32bit system. As a result, the first message always have some
 * bytes left for small packets.
 *
 * Some configuration options can increase the buffer size requirements, including
 * TINY_CONFIG_MLE_MAX_CHILDREN and TINY_CONFIG_COAP_BLOCKWISE_TRANSFER_ENABLE.
 */
#ifndef TINY_CONFIG_MESSAGE_BUFFER_SIZE
#define TINY_CONFIG_MESSAGE_BUFFER_SIZE (sizeof(void *) * 32)
#endif

/**
 * @def TINY_CONFIG_DEFAULT_TRANSMIT_POWER
 *
 * The default IEEE 802.15.4 transmit power (dBm).
 */
#ifndef TINY_CONFIG_DEFAULT_TRANSMIT_POWER
#define TINY_CONFIG_DEFAULT_TRANSMIT_POWER 0
#endif

/**
 * @def TINY_CONFIG_JOINER_UDP_PORT
 *
 * The default Joiner UDP port.
 */
#ifndef TINY_CONFIG_JOINER_UDP_PORT
#define TINY_CONFIG_JOINER_UDP_PORT 1000
#endif

/**
 * @def TINY_CONFIG_MAX_STATECHANGE_HANDLERS
 *
 * The maximum number of state-changed callback handlers (set using `otSetStateChangedCallback()`).
 */
#ifndef TINY_CONFIG_MAX_STATECHANGE_HANDLERS
#define TINY_CONFIG_MAX_STATECHANGE_HANDLERS 1
#endif

/**
 * @def TINY_CONFIG_STORE_FRAME_COUNTER_AHEAD
 *
 * The value ahead of the current frame counter for persistent storage.
 */
#ifndef TINY_CONFIG_STORE_FRAME_COUNTER_AHEAD
#define TINY_CONFIG_STORE_FRAME_COUNTER_AHEAD 1000
#endif

/**
 * @def TINY_CONFIG_ENABLE_BUILTIN_MBEDTLS
 *
 * Define as 1 to enable builtin-mbedtls.
 *
 * Note that the TINY_CONFIG_ENABLE_BUILTIN_MBEDTLS determines whether to use builtin-mbedtls as well as
 * whether to manage mbedTLS internally, such as memory allocation and debug.
 */
#ifndef TINY_CONFIG_ENABLE_BUILTIN_MBEDTLS
#define TINY_CONFIG_ENABLE_BUILTIN_MBEDTLS 1
#endif

/**
 * @def TINY_CONFIG_ENABLE_BUILTIN_MBEDTLS_MANAGEMENT
 *
 * Define as 1 to enable builtin mbedtls management.
 *
 * TINY_CONFIG_ENABLE_BUILTIN_MBEDTLS_MANAGEMENT determines whether to manage mbedTLS memory
 * allocation and debug config internally.  If not configured, the default is to enable builtin
 * management if builtin mbedtls is enabled and disable it otherwise.
 */
#ifndef TINY_CONFIG_ENABLE_BUILTIN_MBEDTLS_MANAGEMENT
#define TINY_CONFIG_ENABLE_BUILTIN_MBEDTLS_MANAGEMENT TINY_CONFIG_ENABLE_BUILTIN_MBEDTLS
#endif

/**
 * @def TINY_CONFIG_HEAP_INTERNAL_SIZE
 *
 * The size of heap buffer when DTLS is enabled.
 */
#ifndef TINY_CONFIG_HEAP_INTERNAL_SIZE
#if TINY_CONFIG_SRP_SERVER_ENABLE
// Internal heap doesn't support size larger than 64K bytes.
#define TINY_CONFIG_HEAP_INTERNAL_SIZE (63 * 1024)
#elif TINY_CONFIG_COAP_SECURE_API_ENABLE
#define TINY_CONFIG_HEAP_INTERNAL_SIZE (3136 * sizeof(void *))
#else
#define TINY_CONFIG_HEAP_INTERNAL_SIZE (1616 * sizeof(void *))
#endif
#endif

/**
 * @def TINY_CONFIG_HEAP_INTERNAL_SIZE_NO_DTLS
 *
 * The size of heap buffer when DTLS is disabled.
 */
#ifndef TINY_CONFIG_HEAP_INTERNAL_SIZE_NO_DTLS
#if TINY_CONFIG_SRP_SERVER_ENABLE
// Internal heap doesn't support size larger than 64K bytes.
#define TINY_CONFIG_HEAP_INTERNAL_SIZE_NO_DTLS (63 * 1024)
#elif TINY_CONFIG_ECDSA_ENABLE
#define TINY_CONFIG_HEAP_INTERNAL_SIZE_NO_DTLS 2600
#else
#define TINY_CONFIG_HEAP_INTERNAL_SIZE_NO_DTLS 384
#endif
#endif

/**
 * @def TINY_CONFIG_HEAP_EXTERNAL_ENABLE
 *
 * Enable the external heap.
 */
#ifndef TINY_CONFIG_HEAP_EXTERNAL_ENABLE
#define TINY_CONFIG_HEAP_EXTERNAL_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_DTLS_APPLICATION_DATA_MAX_LENGTH
 *
 * The size of dtls application data when the CoAP Secure API is enabled.
 */
#ifndef TINY_CONFIG_DTLS_APPLICATION_DATA_MAX_LENGTH
#define TINY_CONFIG_DTLS_APPLICATION_DATA_MAX_LENGTH 1400
#endif

/**
 * @def TINY_CONFIG_ASSERT_ENABLE
 *
 * Define as 1 to enable assert function `OT_ASSERT()` within Tiny code and its libraries.
 */
#ifndef TINY_CONFIG_ASSERT_ENABLE
#define TINY_CONFIG_ASSERT_ENABLE 1
#endif

/**
 * @def TINY_CONFIG_ASSERT_CHECK_API_POINTER_PARAM_FOR_NULL
 *
 * Define as 1 to enable assert check of pointer-type API input parameters against null.
 *
 * Enabling this feature can increase code-size significantly due to many assert checks added for all API pointer
 * parameters. It is recommended to enable and use this feature during debugging only.
 */
#ifndef TINY_CONFIG_ASSERT_CHECK_API_POINTER_PARAM_FOR_NULL
#define TINY_CONFIG_ASSERT_CHECK_API_POINTER_PARAM_FOR_NULL 0
#endif

/**
 * @def TINY_CONFIG_ENABLE_DEBUG_UART
 *
 * Enable the "Debug Uart" platform feature.
 *
 * In the embedded world, the CLI application uses a UART as a console
 * and the NCP application can be configured to use either a UART or
 * a SPI type device to transfer data to the host.
 *
 * The Debug UART is or requires a second uart on the platform.
 *
 * The Debug Uart has two uses:
 *
 * Use #1 - for random 'debug printf' type messages a developer may need
 * Use #2 (selected via DEBUG_LOG_OUTPUT) is a log output.
 *
 * See #include <tiny/platform/debug_uart.h> for more details
 */
#ifndef TINY_CONFIG_ENABLE_DEBUG_UART
#define TINY_CONFIG_ENABLE_DEBUG_UART 0
#endif

/**
 * @def TINY_CONFIG_POSIX_SETTINGS_PATH
 *
 * The settings storage path on posix platform.
 */
#ifndef TINY_CONFIG_POSIX_SETTINGS_PATH
#define TINY_CONFIG_POSIX_SETTINGS_PATH "tmp"
#endif

/**
 * @def TINY_CONFIG_PLATFORM_FLASH_API_ENABLE
 *
 * Define to 1 to enable otPlatFlash* APIs to support non-volatile storage.
 *
 * When defined to 1, the platform MUST implement the otPlatFlash* APIs instead of the otPlatSettings* APIs.
 */
#ifndef TINY_CONFIG_PLATFORM_FLASH_API_ENABLE
#define TINY_CONFIG_PLATFORM_FLASH_API_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_FAILED_CHILD_TRANSMISSIONS
 *
 * This setting configures the number of consecutive MCPS.DATA-Confirms having Status NO_ACK
 * that cause a Child-to-Parent link to be considered broken.
 */
#ifndef TINY_CONFIG_FAILED_CHILD_TRANSMISSIONS
#define TINY_CONFIG_FAILED_CHILD_TRANSMISSIONS 4
#endif

/**
 * @def TINY_CONFIG_DEFAULT_SED_BUFFER_SIZE
 *
 * Specifies the value used in emitted Connectivity TLV "Rx-off Child Buffer Size" field which indicates the
 * guaranteed buffer capacity for all IPv6 datagrams destined to a given rx-off-when-idle child.
 *
 * Changing this config does not automatically adjust message buffers. Vendors should ensure their device can support
 * the specified value based on the message buffer model used:
 *  - OT internal message pool (refer to `TINY_CONFIG_NUM_MESSAGE_BUFFERS` and `MESSAGE_BUFFER_SIZE`), or
 *  - Heap allocated message buffers (refer to `TINY_CONFIG_MESSAGE_USE_HEAP_ENABLE),
 *  - Platform-specific message management (refer to`TINY_CONFIG_PLATFORM_MESSAGE_MANAGEMENT`).
 */
#ifndef TINY_CONFIG_DEFAULT_SED_BUFFER_SIZE
#define TINY_CONFIG_DEFAULT_SED_BUFFER_SIZE 1280
#endif

/**
 * @def TINY_CONFIG_DEFAULT_SED_DATAGRAM_COUNT
 *
 * Specifies the value used in emitted Connectivity TLV "Rx-off Child Datagram Count" field which indicates the
 * guaranteed queue capacity in number of IPv6 datagrams destined to a given rx-off-when-idle child.
 *
 * Similar to `TINY_CONFIG_DEFAULT_SED_BUFFER_SIZE`, vendors should ensure their device can support the specified
 * value based on the message buffer model used.
 */
#ifndef TINY_CONFIG_DEFAULT_SED_DATAGRAM_COUNT
#define TINY_CONFIG_DEFAULT_SED_DATAGRAM_COUNT 1
#endif

/**
 * @def TINY_CONFIG_PLATFORM_RADIO_PROPRIETARY_SUPPORT
 *
 * Define to 1 to support proprietary radio configurations defined by platform.
 *
 * @note If this setting is set to 1, the channel range is defined by the platform. Choosing this option requires
 * the following configuration options to be defined by Platform:
 * TINY_CONFIG_PLATFORM_RADIO_PROPRIETARY_CHANNEL_PAGE,
 * TINY_CONFIG_PLATFORM_RADIO_PROPRIETARY_CHANNEL_MIN,
 * TINY_CONFIG_PLATFORM_RADIO_PROPRIETARY_CHANNEL_MAX and,
 * TINY_CONFIG_PLATFORM_RADIO_PROPRIETARY_CHANNEL_MASK.
 *
 * @def TINY_CONFIG_RADIO_915MHZ_OQPSK_SUPPORT
 *
 * Define to 1 to support OQPSK modulation in 915MHz frequency band. The physical layer parameters are defined in
 * section 6 of IEEE802.15.4-2006.
 *
 * @note If this setting is set to 1, the IEEE 802.15.4 channel range is 1 to 10.
 *
 * @def TINY_CONFIG_RADIO_2P4GHZ_OQPSK_SUPPORT
 *
 * Define to 1 to support OQPSK modulation in 2.4GHz frequency band. The physical layer parameters are defined in
 * section 6 of IEEE802.15.4-2006.
 *
 * @note If this settings is set to 1, the IEEE 802.15.4 channel range is 11 to 26.
 *
 * @note At least one of these settings must be set to 1. The platform must support the modulation and frequency
 *       band configured by the setting.
 */
#ifndef TINY_CONFIG_PLATFORM_RADIO_PROPRIETARY_SUPPORT
#ifndef TINY_CONFIG_RADIO_915MHZ_OQPSK_SUPPORT
#ifndef TINY_CONFIG_RADIO_2P4GHZ_OQPSK_SUPPORT
#define TINY_CONFIG_PLATFORM_RADIO_PROPRIETARY_SUPPORT 0
#define TINY_CONFIG_RADIO_915MHZ_OQPSK_SUPPORT 0
#define TINY_CONFIG_RADIO_2P4GHZ_OQPSK_SUPPORT 1
#endif
#endif
#endif

/**
 * @def TINY_CONFIG_DEFAULT_CHANNEL
 *
 * The default IEEE 802.15.4 channel.
 */
#ifndef TINY_CONFIG_DEFAULT_CHANNEL
#if TINY_CONFIG_RADIO_2P4GHZ_OQPSK_SUPPORT
#define TINY_CONFIG_DEFAULT_CHANNEL 11
#else
#if TINY_CONFIG_RADIO_915MHZ_OQPSK_SUPPORT
#define TINY_CONFIG_DEFAULT_CHANNEL 1
#endif // TINY_CONFIG_RADIO_915MHZ_OQPSK_SUPPORT
#endif // TINY_CONFIG_RADIO_2P4GHZ_OQPSK_SUPPORT
#endif // TINY_CONFIG_DEFAULT_CHANNEL

/**
 * @def TINY_CONFIG_DEFAULT_WAKEUP_CHANNEL
 *
 * The default IEEE 802.15.4 wake-up channel.
 */
#ifndef TINY_CONFIG_DEFAULT_WAKEUP_CHANNEL
#define TINY_CONFIG_DEFAULT_WAKEUP_CHANNEL 11
#endif

/**
 * @def TINY_CONFIG_OTNS_ENABLE
 *
 * Define to 1 to enable OTNS interactions.
 */
#ifndef TINY_CONFIG_OTNS_ENABLE
#define TINY_CONFIG_OTNS_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_DUA_ENABLE
 *
 * Define as 1 to support Thread 1.2 Domain Unicast Address feature.
 */
#ifndef TINY_CONFIG_DUA_ENABLE
#define TINY_CONFIG_DUA_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_MLR_ENABLE
 *
 * Define as 1 to support Thread 1.2 Multicast Listener Registration feature.
 */
#ifndef TINY_CONFIG_MLR_ENABLE
#define TINY_CONFIG_MLR_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_NEIGHBOR_DISCOVERY_AGENT_ENABLE
 *
 * Define as 1 to enable support for Neighbor Discover Agent.
 */
#ifndef TINY_CONFIG_NEIGHBOR_DISCOVERY_AGENT_ENABLE
#define TINY_CONFIG_NEIGHBOR_DISCOVERY_AGENT_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_MULTIPLE_STATIC_INSTANCE_ENABLE
 *
 * Define to 1 to enable multiple static instance support.
 */
#ifndef TINY_CONFIG_MULTIPLE_STATIC_INSTANCE_ENABLE
#define TINY_CONFIG_MULTIPLE_STATIC_INSTANCE_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_MULTIPLE_INSTANCE_NUM
 *
 * Define number of Tiny instance for static allocation buffer.
 */
#ifndef TINY_CONFIG_MULTIPLE_INSTANCE_NUM
#define TINY_CONFIG_MULTIPLE_INSTANCE_NUM 3
#endif

/**
 * @def TINY_CONFIG_ALLOW_EMPTY_NETWORK_NAME
 *
 * Define as 1 to enable support for an empty network name (zero-length: "")
 */
#ifndef TINY_CONFIG_ALLOW_EMPTY_NETWORK_NAME
#define TINY_CONFIG_ALLOW_EMPTY_NETWORK_NAME 0
#endif

/**
 * @def TINY_CONFIG_OPERATIONAL_DATASET_AUTO_INIT
 *
 * Define as 1 to enable support for locally initializing an Active Operational Dataset.
 *
 * @note This functionality is deprecated and not recommended.
 */
#ifndef TINY_CONFIG_OPERATIONAL_DATASET_AUTO_INIT
#define TINY_CONFIG_OPERATIONAL_DATASET_AUTO_INIT 0
#endif

/**
 * @def TINY_CONFIG_BLE_TCAT_ENABLE
 *
 * Define to 1 to enable TCAT over BLE support.
 */
#ifndef TINY_CONFIG_BLE_TCAT_ENABLE
#define TINY_CONFIG_BLE_TCAT_ENABLE 0
#endif

/**
 * @def TINY_CONFIG_PLATFORM_LOG_CRASH_DUMP_ENABLE
 *
 * Define to 1 to enable crash dump logging.
 *
 * On platforms that support crash dump logging, this feature will log a crash dump using the OT Debug Log service.
 *
 * Logging a crash dump requires the platform to implement the `otPlatLogCrashDump()` function.
 */
#ifndef TINY_CONFIG_PLATFORM_LOG_CRASH_DUMP_ENABLE
#define TINY_CONFIG_PLATFORM_LOG_CRASH_DUMP_ENABLE 0
#endif

/**
 * @}
 */

#endif // CONFIG_MISC_H_
