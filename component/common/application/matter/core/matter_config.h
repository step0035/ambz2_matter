#pragma once

#include <app/data-model/Nullable.h>

/* Replace these with IDs from submodule whenever they are implemented */
#define AMEBA_MATTER_ROOT_NODE_DEVICE_TYPE_ID 0x0016
#define AMEBA_MATTER_ROOT_NODE_DEVICE_TYPE_VERSION 1
#define AMEBA_MATTER_AGGREGATOR_DEVICE_TYPE_ID 0x000E
#define AMEBA_MATTER_AGGREGATOR_DEVICE_TYPE_VERSION 1
#define AMEBA_MATTER_BRIDGED_NODE_DEVICE_TYPE_ID 0x0013
#define AMEBA_MATTER_BRIDGED_NODE_DEVICE_TYPE_VERSION 1

#define AMEBA_MATTER_ON_OFF_LIGHT_DEVICE_TYPE_ID 0x0100
#define AMEBA_MATTER_ON_OFF_LIGHT_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_DIMMABLE_LIGHT_DEVICE_TYPE_ID 0x0101
#define AMEBA_MATTER_DIMMABLE_LIGHT_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_COLOR_TEMPERATURE_LIGHT_DEVICE_TYPE_ID 0x010C
#define AMEBA_MATTER_COLOR_TEMPERATURE_LIGHT_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_EXTENDED_COLOR_LIGHT_DEVICE_TYPE_ID 0x010D
#define AMEBA_MATTER_EXTENDED_COLOR_LIGHT_DEVICE_TYPE_VERSION 2

#define AMEBA_MATTER_ON_OFF_SWITCH_DEVICE_TYPE_ID 0x0103
#define AMEBA_MATTER_ON_OFF_SWITCH_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_DIMMER_SWITCH_DEVICE_TYPE_ID 0x0104
#define AMEBA_MATTER_DIMMER_SWITCH_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_COLOR_DIMMER_SWITCH_DEVICE_TYPE_ID 0x0105
#define AMEBA_MATTER_COLOR_DIMMER_SWITCH_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_GENERIC_SWITCH_DEVICE_TYPE_ID 0x000F
#define AMEBA_MATTER_GENERIC_SWITCH_DEVICE_TYPE_VERSION 1

#define AMEBA_MATTER_ON_OFF_PLUGIN_UNIT_DEVICE_TYPE_ID 0x010A
#define AMEBA_MATTER_ON_OFF_PLUGIN_UNIT_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_DIMMABLE_PLUGIN_UNIT_DEVICE_TYPE_ID 0x010B
#define AMEBA_MATTER_DIMMABLE_PLUGIN_UNIT_DEVICE_TYPE_VERSION 2

#define AMEBA_MATTER_TEMPERATURE_SENSOR_DEVICE_TYPE_ID 0x0302
#define AMEBA_MATTER_TEMPERATURE_SENSOR_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_OCCUPANCY_SENSOR_DEVICE_TYPE_ID 0x0107
#define AMEBA_MATTER_OCCUPANCY_SENSOR_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_CONTACT_SENSOR_DEVICE_TYPE_ID 0x0015
#define AMEBA_MATTER_CONTACT_SENSOR_DEVICE_TYPE_VERSION 1

#define AMEBA_MATTER_FAN_DEVICE_TYPE_ID 0x002B
#define AMEBA_MATTER_FAN_DEVICE_TYPE_VERSION 1
#define AMEBA_MATTER_THERMOSTAT_DEVICE_TYPE_ID 0x0301
#define AMEBA_MATTER_THERMOSTAT_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_DOOR_LOCK_DEVICE_TYPE_ID 0x000A
#define AMEBA_MATTER_DOOR_LOCK_DEVICE_TYPE_VERSION 2
#define AMEBA_MATTER_WINDOW_COVERING_DEVICE_TYPE_ID 0x0202
#define AMEBA_MATTER_WINDOW_COVERING_DEVICE_TYPE_VERSION 2

template <typename T>
class nullable {

/** NOTE: GetNullValue is taken from src/app/util/attribute-storage-null-handling.h */
private:
    template <typename U = T, typename std::enable_if_t<std::is_floating_point<U>::value, int> = 0>
    static constexpr T GetNullValue()
    {
        return std::numeric_limits<T>::quiet_NaN();
    }

    template <typename U = T, typename std::enable_if_t<std::is_integral<U>::value, int> = 0>
    static constexpr T GetNullValue()
    {
        return std::is_signed<T>::value ? std::numeric_limits<T>::min() : std::numeric_limits<T>::max();
    }

    template <typename U = T, typename std::enable_if_t<std::is_enum<U>::value, int> = 0>
    static constexpr T GetNullValue()
    {
        static_assert(!std::is_signed<std::underlying_type_t<T>>::value, "Enums must be unsigned");
        return static_cast<T>(std::numeric_limits<std::underlying_type_t<T>>::max());
    }

public:
    nullable(T value)
    {
        if (chip::app::NumericAttributeTraits<T>::IsNullValue(value)) {
            chip::app::NumericAttributeTraits<T>::SetNull(val);
        } else {
            val = value;
        }
    }

    nullable()
    {
        chip::app::NumericAttributeTraits<T>::SetNull(val);
    }

    T value()
    {
        if (is_null()) {
            return GetNullValue();
        } else {
            return val;
        }

    }

    T value_or(T ret)
    {
        return is_null() ? ret : val;
    }

    bool is_null()
    {
        return chip::app::NumericAttributeTraits<T>::IsNullValue(val);
    }

    void operator=(T value)
    {
        if (chip::app::NumericAttributeTraits<T>::IsNullValue(value)) {
            chip::app::NumericAttributeTraits<T>::SetNull(this->val);
        } else {
            this->val = value;
        }
    }

    void operator=(std::nullptr_t)
    {
        chip::app::NumericAttributeTraits<T>::SetNull(this->val);
    }
private:
    T val;
};

/* Clusters config */
// TODO: add featuremap and commands

typedef struct basic_information {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    char node_label[32];
    basic_information() : cluster_revision(1), node_label("\0") {}
} basic_information_t;

typedef struct general_commissioning {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    uint64_t breadcrumb;
    general_commissioning() : cluster_revision(1), breadcrumb(0) {}
} general_commissioning_t;

typedef struct network_commissioning {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    network_commissioning() : cluster_revision(1) {}
} network_commissioning_t;

typedef struct general_diagnostics {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    general_diagnostics() : cluster_revision(1) {}
} general_diagnostics_t;

typedef struct administrator_commissioning {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    administrator_commissioning() : cluster_revision(1) {}
} administrator_commissioning_t;

typedef struct operational_credentials {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    operational_credentials() : cluster_revision(1) {}
} operational_credentials_t;

typedef struct diagnostics_network_thread {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    diagnostics_network_thread() : cluster_revision(1) {}
} diagnostics_network_thread_t;

typedef struct diagnostics_network_wifi {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    diagnostics_network_wifi() : cluster_revision(1) {}
} diagnostics_network_wifi_t;

typedef struct identify {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    uint16_t identify_time;
    uint8_t identify_type;
    identify() : cluster_revision(1), identify_time(0), identify_type(0) {}
}identify_t;

typedef struct groups {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    uint8_t group_name_support;
    groups() : cluster_revision(1), group_name_support(0) {}
}groups_t;

typedef struct scenes {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    uint8_t scene_count;
    uint8_t current_scene;
    uint16_t current_group;
    bool scene_valid;
    uint8_t scene_name_support;
    scenes() : cluster_revision(4), scene_count(0), current_scene(0), current_group(0), scene_valid(false), scene_name_support(0) {}
} scenes_t;

typedef struct on_off {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    bool onoff;
    // feature::lighting::config_t lighting;
    on_off() : cluster_revision(4), onoff(false) {}
}on_off_t;

typedef struct level_control {
    bool enabled = false;
    bool server = true;
    uint16_t cluster_revision;
    nullable<uint8_t> current_level;
    nullable<uint8_t> on_level;
    uint8_t options;
    // feature::lighting::config_t lighting;
    level_control() : cluster_revision(5), current_level(0xFE), on_level(0xFE), options(0) {}
} level_control_t;

/* Endpoint configs */
typedef struct general_endpoint {
    basic_information_t basic_information;
    general_commissioning_t general_commissioning;
    network_commissioning_t network_commissioning;
    general_diagnostics_t general_diagnostics;
    administrator_commissioning_t administrator_commissioning;
    operational_credentials_t operational_credentials;
    diagnostics_network_wifi_t diagnostics_network_wifi;
    diagnostics_network_thread_t diagnostics_network_thread;
    identify_t identify;
    groups_t groups;
    scenes_t scenes;
    on_off_t on_off;
    level_control_t level_control;
} config_t;

typedef struct root_node {
    basic_information_t basic_information;
    general_commissioning_t general_commissioning;
    network_commissioning_t network_commissioning;
    general_diagnostics_t general_diagnostics;
    administrator_commissioning_t administrator_commissioning;
    operational_credentials_t operational_credentials;
    diagnostics_network_wifi_t diagnostics_network_wifi;
    diagnostics_network_thread_t diagnostics_network_thread;
} root_node_t;

typedef struct on_off_light {
    identify_t identify;
    groups_t groups;
    scenes_t scenes;
    on_off_t on_off;
} on_off_light_t;

typedef struct dimmable_light {
    identify_t identify;
    groups_t groups;
    scenes_t scenes;
    on_off_t on_off;
    level_control_t level_control;
} dimmable_light_t;


/* Nullable base for nullable attribute */
#define AMEBA_MATTER_VAL_NULLANLE_BASE 0x80

/** AMEBA Matter Attribute Value type */
typedef enum {
    /** Invalid */
    AMEBA_MATTER_VAL_TYPE_INVALID = 0,
    /** Boolean */
    AMEBA_MATTER_VAL_TYPE_BOOLEAN = 1,
    /** Integer. Mapped to a 32 bit signed integer */
    AMEBA_MATTER_VAL_TYPE_INTEGER = 2,
    /** Floating point number */
    AMEBA_MATTER_VAL_TYPE_FLOAT = 3,
    /** Array Eg. [1,2,3] */
    AMEBA_MATTER_VAL_TYPE_ARRAY = 4,
    /** Char String Eg. "123" */
    AMEBA_MATTER_VAL_TYPE_CHAR_STRING = 5,
    /** Octet String Eg. [0x01, 0x20] */
    AMEBA_MATTER_VAL_TYPE_OCTET_STRING = 6,
    /** 8 bit signed integer */
    AMEBA_MATTER_VAL_TYPE_INT8 = 7,
    /** 8 bit unsigned integer */
    AMEBA_MATTER_VAL_TYPE_UINT8 = 8,
    /** 16 bit signed integer */
    AMEBA_MATTER_VAL_TYPE_INT16 = 9,
    /** 16 bit unsigned integer */
    AMEBA_MATTER_VAL_TYPE_UINT16 = 10,
    /** 32 bit signed integer */
    AMEBA_MATTER_VAL_TYPE_INT32 = 11,
    /** 32 bit unsigned integer */
    AMEBA_MATTER_VAL_TYPE_UINT32 = 12,
    /** 64 bit signed integer */
    AMEBA_MATTER_VAL_TYPE_INT64 = 13,
    /** 64 bit unsigned integer */
    AMEBA_MATTER_VAL_TYPE_UINT64 = 14,
    /** 8 bit enum */
    AMEBA_MATTER_VAL_TYPE_ENUM8 = 15,
    /** 8 bit bitmap */
    AMEBA_MATTER_VAL_TYPE_BITMAP8 = 16,
    /** 16 bit bitmap */
    AMEBA_MATTER_VAL_TYPE_BITMAP16 = 17,
    /** 32 bit bitmap */
    AMEBA_MATTER_VAL_TYPE_BITMAP32 = 18,
    /** nullable types **/
    AMEBA_MATTER_VAL_TYPE_NULLABLE_INTEGER = AMEBA_MATTER_VAL_TYPE_INTEGER + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_FLOAT = AMEBA_MATTER_VAL_TYPE_FLOAT + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_INT8 = AMEBA_MATTER_VAL_TYPE_INT8 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_UINT8 = AMEBA_MATTER_VAL_TYPE_UINT8 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_INT16 = AMEBA_MATTER_VAL_TYPE_INT16 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_UINT16 = AMEBA_MATTER_VAL_TYPE_UINT16 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_INT32 = AMEBA_MATTER_VAL_TYPE_INT32 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_UINT32 = AMEBA_MATTER_VAL_TYPE_UINT32 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_INT64 = AMEBA_MATTER_VAL_TYPE_INT64 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_UINT64 = AMEBA_MATTER_VAL_TYPE_UINT64 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_ENUM8 = AMEBA_MATTER_VAL_TYPE_ENUM8 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_BITMAP8 = AMEBA_MATTER_VAL_TYPE_BITMAP8 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_BITMAP16 = AMEBA_MATTER_VAL_TYPE_BITMAP16 + AMEBA_MATTER_VAL_NULLANLE_BASE,
    AMEBA_MATTER_VAL_TYPE_NULLABLE_BITMAP32= AMEBA_MATTER_VAL_TYPE_BITMAP32 + AMEBA_MATTER_VAL_NULLANLE_BASE,
} ameba_matter_val_type_t;

/** AMEBA Matter Value */
typedef union {
    /** Boolean */
    bool _b;
    /** Integer */
    int _i;
    /** Float */
    float _f;
    /** 8 bit signed integer */
    int8_t _i8;
    /** 8 bit unsigned integer */
    uint8_t _u8;
    /** 16 bit signed integer */
    int16_t _i16;
    /** 16 bit unsigned integer */
    uint16_t _u16;
    /** 32 bit signed integer */
    int32_t _i32;
    /** 32 bit unsigned integer */
    uint32_t _u32;
    /** 64 bit signed integer */
    int64_t _i64;
    /** 64 bit unsigned integer */
    uint64_t _u64;
    /** Array */
    struct {
        /** Buffer */
        uint8_t *_b;
        /** Data size */
        uint16_t _s;
        /** Data count */
        uint16_t _n;
        /** Total size */
        uint16_t _t;
    } _a;
    /** Pointer */
    void *_p;
} ameba_matter_val_t;

/** AMEBA Matter Attribute Value */
typedef struct {
    /** Type of Value */
    ameba_matter_val_type_t type;
    /** Actual value. Depends on the type */
    ameba_matter_val_t val;
} ameba_matter_attr_val_t;

/** AMEBA Matter Attribute Bounds */
typedef struct ameba_matter_attr_bounds {
    /** Minimum Value */
    ameba_matter_attr_val_t min;
    /** Maximum Value */
    ameba_matter_attr_val_t max;
    /** TODO: Step Value might be needed here later */
} ameba_matter_attr_bounds_t;

/* attribute utils declaration */
ameba_matter_attr_val_t ameba_matter_invalid(void *val);
ameba_matter_attr_val_t ameba_matter_bool(bool val);
ameba_matter_attr_val_t ameba_matter_int(int val);
ameba_matter_attr_val_t ameba_matter_nullable_int(nullable<int> val);
ameba_matter_attr_val_t ameba_matter_float(float val);
ameba_matter_attr_val_t ameba_matter_nullable_float(nullable<float> val);
ameba_matter_attr_val_t ameba_matter_int8(int8_t val);
ameba_matter_attr_val_t ameba_matter_nullable_int8(nullable<int8_t> val);
ameba_matter_attr_val_t ameba_matter_uint8(uint8_t val);
ameba_matter_attr_val_t ameba_matter_nullable_uint8(nullable<uint8_t> val);
ameba_matter_attr_val_t ameba_matter_int16(int16_t val);
ameba_matter_attr_val_t ameba_matter_nullable_int16(nullable<int16_t> val);
ameba_matter_attr_val_t ameba_matter_uint16(uint16_t val);
ameba_matter_attr_val_t ameba_matter_nullable_uint16(nullable<uint16_t> val);
ameba_matter_attr_val_t ameba_matter_int32(int32_t val);
ameba_matter_attr_val_t ameba_matter_nullable_int32(nullable<int32_t> val);
ameba_matter_attr_val_t ameba_matter_uint32(uint32_t val);
ameba_matter_attr_val_t ameba_matter_nullable_uint32(nullable<uint32_t> val);
ameba_matter_attr_val_t ameba_matter_int64(int64_t val);
ameba_matter_attr_val_t ameba_matter_nullable_int64(nullable<int64_t> val);
ameba_matter_attr_val_t ameba_matter_uint64(uint64_t val);
ameba_matter_attr_val_t ameba_matter_nullable_uint64(nullable<uint64_t> val);
ameba_matter_attr_val_t ameba_matter_enum8(uint8_t val);
ameba_matter_attr_val_t ameba_matter_nullable_enum8(nullable<uint8_t> val);
ameba_matter_attr_val_t ameba_matter_bitmap8(uint8_t val);
ameba_matter_attr_val_t ameba_matter_nullable_bitmap8(nullable<uint8_t> val);
ameba_matter_attr_val_t ameba_matter_bitmap16(uint16_t val);
ameba_matter_attr_val_t ameba_matter_nullable_bitmap16(nullable<uint16_t> val);
ameba_matter_attr_val_t ameba_matter_bitmap32(uint32_t val);
ameba_matter_attr_val_t ameba_matter_nullable_bitmap32(nullable<uint32_t> val);
ameba_matter_attr_val_t ameba_matter_char_str(char *val, uint16_t data_size);
ameba_matter_attr_val_t ameba_matter_octet_str(uint8_t *val, uint16_t data_size);
ameba_matter_attr_val_t ameba_matter_array(uint8_t *val, uint16_t data_size, uint16_t count);
