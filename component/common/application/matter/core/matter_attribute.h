#pragma once

#include <platform_stdlib.h>
#include <app/util/attribute-storage.h>
#include "matter_config.h"

class Attribute
{
public:
    Attribute(ameba_matter_attr_val_t attribute_value, uint32_t _attribute_id, uint32_t _cluster_id, uint32_t _endpoint_id, uint16_t attribute_flags); // create
    ~ Attribute(); // destroy
    uint32_t attribute_id;
    uint32_t cluster_id;
    // TODO: endpoint_id is 16bits
    uint32_t endpoint_id;
    uint16_t flags;
    Attribute *get_next(void);
    void set_next(Attribute *attribute);
    int8_t get_from_nvs(const char* key, ameba_matter_attr_val_t *value);
    int8_t set_in_nvs(const char* key, ameba_matter_attr_val_t *value);
    ameba_matter_attr_val_t val;
    ameba_matter_attr_bounds_t *bounds;
    // EmberAfDefaultOrMinMaxAttributeValue default_value;
    uint16_t default_value_size;
    // Callback override_callback;
    Attribute *next = NULL;
};
