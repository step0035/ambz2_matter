#include "matter_attribute.h"
#include "matter_flags.h"
#include "chip_porting.h"

Attribute::Attribute(ameba_matter_attr_val_t attribute_value, uint32_t _attribute_id, uint16_t attribute_flags)
{
    // TODO: add bounds, kvs
    val = attribute_value;
    attribute_id = _attribute_id;
    flags = attribute_flags | ATTRIBUTE_FLAG_EXTERNAL_STORAGE;

    /* store non-volatile attributes in kvs */
    if (flags & ATTRIBUTE_FLAG_NONVOLATILE)
    {
        // setup key (endpoint_id/cluster_id/attribute_id)
        // char *key = (char *) pvPortMalloc(VARIABLE_NAME_SIZE);
        // setPref_new
        // attempt to get from kvs
        // if get from kvs success, set the attribute_value to the value gotten from kvs
        // else, set the attribute_value to the value passed in, then store in kvs
    }
    else
    {
        // set the attribute_value to the value passed in, don't need to store in kvs
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
