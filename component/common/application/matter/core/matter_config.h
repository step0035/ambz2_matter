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

#define AMEBA_MATTER_IDENTIFY_CLUSTER_ID 0x0003
#define AMEBA_MATTER_GROUPS_CLUSTER_ID 0x0004
#define AMEBA_MATTER_SCENES_CLUSTER_ID 0x0005
#define AMEBA_MATTER_ON_OFF_CLUSTER_ID 0x0006
#define AMEBA_MATTER_LEVEL_CONTROL_CLUSTER_ID 0x0008
#define AMEBA_MATTER_BASIC_INFORMATION_CLUSTER_ID 0x0028
#define AMEBA_MATTER_GENERAL_COMMISSIONING_CLUSTER_ID 0x0030
#define AMEBA_MATTER_NETWORK_COMMISSIONING_CLUSTER_ID 0x0031
#define AMEBA_MATTER_GENERAL_DIAGNOSTICS_CLUSTER_ID 0x0033
#define AMEBA_MATTER_DIAGNOSTICS_NETWORK_THREAD_CLUSTER_ID 0x0035
#define AMEBA_MATTER_DIAGNOSTICS_NETWORK_WIFI_CLUSTER_ID 0x0036
#define AMEBA_MATTER_ADMINISTRATOR_COMMISSIONING_CLUSTER_ID 0x003C
#define AMEBA_MATTER_OPERATIONAL_CREDENTIALS_CLUSTER_ID 0x003E

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
typedef struct basic_information {
    bool enabled = false;
    uint16_t cluster_revision;
    char node_label[32];
    basic_information() : cluster_revision(1), node_label("\0") {}
} basic_information_t;

typedef struct general_commissioning {
    bool enabled = false;
    uint16_t cluster_revision;
    uint64_t breadcrumb;
    general_commissioning() : cluster_revision(1), breadcrumb(0) {}
} general_commissioning_t;

typedef struct network_commissioning {
    bool enabled = false;
    uint16_t cluster_revision;
    network_commissioning() : cluster_revision(1) {}
} network_commissioning_t;

typedef struct general_diagnostics {
    bool enabled = false;
    uint16_t cluster_revision;
    general_diagnostics() : cluster_revision(1) {}
} general_diagnostics_t;

typedef struct administrator_commissioning {
    bool enabled = false;
    uint16_t cluster_revision;
    administrator_commissioning() : cluster_revision(1) {}
} administrator_commissioning_t;

typedef struct operational_credentials {
    bool enabled = false;
    uint16_t cluster_revision;
    operational_credentials() : cluster_revision(1) {}
} operational_credentials_t;

typedef struct diagnostics_network_thread {
    bool enabled = false;
    uint16_t cluster_revision;
    diagnostics_network_thread() : cluster_revision(1) {}
} diagnostics_network_thread_t;

typedef struct diagnostics_network_wifi {
    bool enabled = false;
    uint16_t cluster_revision;
    diagnostics_network_wifi() : cluster_revision(1) {}
} diagnostics_network_wifi_t;

typedef struct identify {
    bool enabled = false;
    uint16_t cluster_revision;
    uint16_t identify_time;
    uint8_t identify_type;
    identify() : cluster_revision(1), identify_time(0), identify_type(0) {}
}identify_t;

typedef struct groups {
    bool enabled = false;
    uint16_t cluster_revision;
    uint8_t group_name_support;
    groups() : cluster_revision(1), group_name_support(0) {}
}groups_t;

typedef struct scenes {
    bool enabled = false;
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
    uint16_t cluster_revision;
    bool onoff;
    // feature::lighting::config_t lighting;
    on_off() : cluster_revision(4), onoff(false) {}
}on_off_t;

typedef struct level_control {
    bool enabled = false;
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

/* Endpoint config wrapper */
// typedef struct config {
//     root_node_t root_node;
//     on_off_light_t on_off_light;
//     dimmable_light_t dimmable_light;
// } config_t;
