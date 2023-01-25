#pragma once

#include <app-common/zap-generated/att-storage.h>

/** Endpoint flags */
typedef enum endpoint_flags {
    /** No specific flags */
    ENDPOINT_FLAG_NONE = 0x00,
    /** The endpoint can be destroyed using destructor */
    ENDPOINT_FLAG_DESTROYABLE = 0x01,
    /** The endpoint is a bridged node */
    ENDPOINT_FLAG_BRIDGE = 0x02,
} endpoint_flags_t;

/** Cluster flags */
typedef enum cluster_flags {
    /** No specific flags */
    CLUSTER_FLAG_NONE = 0x00,
    /** The cluster has an init function (function_flag) */
    CLUSTER_FLAG_INIT_FUNCTION = CLUSTER_MASK_INIT_FUNCTION, /* 0x01 */
    /** The cluster has an attribute changed function (function_flag) */
    CLUSTER_FLAG_ATTRIBUTE_CHANGED_FUNCTION = CLUSTER_MASK_ATTRIBUTE_CHANGED_FUNCTION, /* 0x02 */
    /** The cluster has a default response function (function_flag) */
    CLUSTER_FLAG_DEFAULT_RESPONSE_FUNCTION = CLUSTER_MASK_DEFAULT_RESPONSE_FUNCTION, /* 0x04 */
    /** The cluster has a message sent function (function_flag) */
    CLUSTER_FLAG_MESSAGE_SENT_FUNCTION = CLUSTER_MASK_MESSAGE_SENT_FUNCTION, /* 0x08 */
    /** The cluster has a manufacturer specific attribute changed function (function_flag) */
    CLUSTER_FLAG_MANUFACTURER_SPECIFIC_ATTRIBUTE_CHANGED_FUNCTION =
                                            CLUSTER_MASK_MANUFACTURER_SPECIFIC_ATTRIBUTE_CHANGED_FUNCTION, /* 0x10 */
    /** The cluster has a pre attribute changed function (function_flag) */
    CLUSTER_FLAG_PRE_ATTRIBUTE_CHANGED_FUNCTION = CLUSTER_MASK_PRE_ATTRIBUTE_CHANGED_FUNCTION, /* 0x20 */
    /** The cluster is a server cluster */
    CLUSTER_FLAG_SERVER = CLUSTER_MASK_SERVER, /* 0x40 */
    /** The cluster is a client cluster */
    CLUSTER_FLAG_CLIENT = CLUSTER_MASK_CLIENT, /* 0x80 */
} cluster_flags_t;

/** Attribute flags */
typedef enum attribute_flags {
    /** No specific flags */
    ATTRIBUTE_FLAG_NONE = 0x00,
    /** The attribute is writable and can be directly changed by clients */
    ATTRIBUTE_FLAG_WRITABLE = ATTRIBUTE_MASK_WRITABLE, /* 0x01 */
    /** The attribute is non volatile and its value will be stored in NVS */
    ATTRIBUTE_FLAG_NONVOLATILE = ATTRIBUTE_MASK_NONVOLATILE, /* 0x02 */
    /** The attribute has bounds */
    ATTRIBUTE_FLAG_MIN_MAX = ATTRIBUTE_MASK_MIN_MAX, /* 0x04 */
    ATTRIBUTE_FLAG_MUST_USE_TIMED_WRITE = ATTRIBUTE_MASK_MUST_USE_TIMED_WRITE, /* 0x08 */
    /** The attribute uses external storage for its value. If the Ameba Matter data model is used, all the attributes
    have this flag enabled, as all of them are stored in the Ameba Matter database. */
    ATTRIBUTE_FLAG_EXTERNAL_STORAGE = ATTRIBUTE_MASK_EXTERNAL_STORAGE, /* 0x10 */
    ATTRIBUTE_FLAG_SINGLETON = ATTRIBUTE_MASK_SINGLETON, /* 0x20 */
    ATTRIBUTE_FLAG_NULLABLE = ATTRIBUTE_MASK_NULLABLE, /* 0x40 */
    /** The attribute read and write are overridden. The attribute value will be fetched from and will be updated using
    the override callback. The value of this attribute is not maintained internally. */
    ATTRIBUTE_FLAG_OVERRIDE = ATTRIBUTE_FLAG_NULLABLE << 1, /* 0x100 */
} attribute_flags_t;

/** Command flags */
typedef enum command_flags {
    /** No specific flags */
    COMMAND_FLAG_NONE = 0x00,
    /** The command is not a standard command */
    COMMAND_FLAG_CUSTOM = 0x01,
    /** The command is client generated */
    COMMAND_FLAG_ACCEPTED = 0x02,
    /** The command is server generated */
    COMMAND_FLAG_GENERATED = 0x04,
} command_flags_t;
