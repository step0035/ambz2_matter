#include "matter_attribute.h"

Attribute::Attribute(ameba_matter_attr_val_t attribute_value, uint32_t _attribute_id)
{
    // TODO: add bounds, kvs
    val = attribute_value;
    attribute_id = _attribute_id;
    // flags = attribute_flags;
}

Attribute *Attribute::get_next()
{
    return next;
}

void Attribute::set_next(Attribute *attribute)
{
    next = attribute;
}
