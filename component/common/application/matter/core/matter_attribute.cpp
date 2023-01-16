#include "matter_attribute.h"

Attribute::Attribute(ameba_matter_attr_val_t attribute_value)
{
    // TODO: add bounds, attribute_id
    val.type = attribute_value.type;
    val.val = attribute_value.val;
}
