#include "matter_attribute.h"
#include "matter_flags.h"
#include "chip_porting.h"

Attribute::Attribute(ameba_matter_attr_val_t attribute_value, uint32_t _attribute_id, uint32_t _cluster_id, uint32_t _endpoint_id, uint16_t attribute_flags)
{
    // TODO: add bounds, kvs
    val = attribute_value;
    endpoint_id = _endpoint_id;
    cluster_id = _cluster_id;
    attribute_id = _attribute_id;
    flags = attribute_flags | ATTRIBUTE_FLAG_EXTERNAL_STORAGE;

    /* store non-volatile attributes in kvs */
    if (flags & ATTRIBUTE_FLAG_NONVOLATILE)
    {
        // setup key (endpoint_id/cluster_id/attribute_id)
        char *key = (char *) pvPortMalloc(VARIABLE_NAME_SIZE);
        sprintf(key, "%d/%d/%d", endpoint_id, cluster_id, attribute_id);
        // attempt to get from kvs
        ameba_matter_attr_val_t *ptemp_val = (ameba_matter_attr_val_t *) pvPortMalloc(sizeof(ameba_matter_attr_val_t));
        if (!ptemp_val)
        {
            printf("failed to allocate for attribute value, aborting\n");
            return;
        }

        err = get_from_nvs(key, ptemp_val);
        if (err == 0)
        {
            // if get from kvs success, set the attribute_value to the value gotten from kvs
            memcpy(&val, ptemp_val, sizeof(ameba_matter_attr_val_t));
        }
        else
        {
            // else (not found), set the attribute_value to the value passed in, then store in kvs
            // TODO: only enter here if error is "not found"
            memcpy(&val, &attribute_value, sizeof(ameba_matter_attr_val_t));
            set_in_nvs(key, &val);
        }
        vPortFree(ptemp_val);
    }
    else
    {
        // set the attribute_value to the value passed in, don't need to store in kvs
        memcpy(&val, &attribute_value, sizeof(ameba_matter_attr_val_t));
    }
}

Attribute *Attribute::get_next()
{
    return next;
}

void Attribute::set_next(Attribute *attribute)
{
    next = attribute;
}

int8_t Attribute::get_from_nvs(const char *key, ameba_matter_attr_val_t *value)
{
    // TODO: should we pass in outlen?
    int8_t err;
    uint8_t *buf = (uint8_t *) pvPortMalloc(sizeof(ameba_matter_attr_val_t));
    size_t outlen;
    err = getPref_bin_new(key, key, buf, sizeof(ameba_matter_attr_val_t), &outlen);
    if (err == DCT_SUCCESS)
    {
        memcpy(value, buf, sizeof(ameba_matter_attr_val_t));
    }
    vPortFree(buf);
    return err;
}

int8_t Attribute::set_in_nvs(const char *key, ameba_matter_attr_val_t *value)
{
    // just set the value with key
    return setPref_new(key, key, value);
}
