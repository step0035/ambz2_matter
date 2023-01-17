#include "matter_config.h"

/* attribute utils */
ameba_matter_attr_val_t ameba_matter_invalid(void *val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_INVALID,
        .val = {
            ._p = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_bool(bool val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_BOOLEAN,
        .val = {
            ._b = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_int(int val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_INTEGER,
        .val = {
            ._i = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_int(nullable<int> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_INTEGER,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<int>::SetNull(attr_val.val._i);
    } else {
        attr_val.val._i = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_float(float val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_FLOAT,
        .val = {
            ._f = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_float(nullable<float> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_FLOAT,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<float>::SetNull(attr_val.val._f);
    } else {
        attr_val.val._i = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_int8(int8_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_INT8,
        .val = {
            ._i8 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_int8(nullable<int8_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_INT8,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<int8_t>::SetNull(attr_val.val._i8);
    } else {
        attr_val.val._i8 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_uint8(uint8_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_UINT8,
        .val = {
            ._u8 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_uint8(nullable<uint8_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_UINT8,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<uint8_t>::SetNull(attr_val.val._u8);
    } else {
        attr_val.val._u8 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_int16(int16_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_INT16,
        .val = {
            ._i16 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_int16(nullable<int16_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_INT16,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<int16_t>::SetNull(attr_val.val._i16);
    } else {
        attr_val.val._i16 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_uint16(uint16_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_UINT16,
        .val = {
            ._u16 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_uint16(nullable<uint16_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_UINT16,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<uint16_t>::SetNull(attr_val.val._u16);
    } else {
        attr_val.val._u16 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_int32(int32_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_INT32,
        .val = {
            ._i32 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_int32(nullable<int32_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_INT32,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<int32_t>::SetNull(attr_val.val._i32);
    } else {
        attr_val.val._i32 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_uint32(uint32_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_UINT32,
        .val = {
            ._u32 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_uint32(nullable<uint32_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_UINT32,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<uint32_t>::SetNull(attr_val.val._u32);
    } else {
        attr_val.val._u32 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_int64(int64_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_INT64,
        .val = {
            ._i64 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_int64(nullable<int64_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_INT64,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<int64_t>::SetNull(attr_val.val._i64);
    } else {
        attr_val.val._i64 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_uint64(uint64_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_UINT64,
        .val = {
            ._u64 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_uint64(nullable<uint64_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_UINT64,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<uint64_t>::SetNull(attr_val.val._u64);
    } else {
        attr_val.val._u64 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_enum8(uint8_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_ENUM8,
        .val = {
            ._u8 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_enum8(nullable<uint8_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_ENUM8,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<uint8_t>::SetNull(attr_val.val._u8);
    } else {
        attr_val.val._u8 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_bitmap8(uint8_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_BITMAP8,
        .val = {
            ._u8 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_bitmap8(nullable<uint8_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_BITMAP8,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<uint8_t>::SetNull(attr_val.val._u8);
    } else {
        attr_val.val._u8 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_bitmap16(uint16_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_BITMAP16,
        .val = {
            ._u16 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_bitmap16(nullable<uint16_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_BITMAP16,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<uint16_t>::SetNull(attr_val.val._u16);
    } else {
        attr_val.val._u16 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_bitmap32(uint32_t val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_BITMAP32,
        .val = {
            ._u32 = val,
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_nullable_bitmap32(nullable<uint32_t> val)
{
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_NULLABLE_BITMAP32,
    };
    if (val.is_null()) {
        chip::app::NumericAttributeTraits<uint32_t>::SetNull(attr_val.val._u32);
    } else {
        attr_val.val._u32 = val.value();
    }
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_char_str(char *val, uint16_t data_size)
{
    uint16_t data_size_len = 1; /* Number of bytes used to store the length */
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_CHAR_STRING,
        .val = {
            ._a = {
                ._b = (uint8_t *)val,
                ._s = data_size,
                ._n = data_size,
                ._t = (uint16_t)(data_size + data_size_len),
            },
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_octet_str(uint8_t *val, uint16_t data_size)
{
    uint16_t data_size_len = 1; /* Number of bytes used to store the length */
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_OCTET_STRING,
        .val = {
            ._a = {
                ._b = val,
                ._s = data_size,
                ._n = data_size,
                ._t = (uint16_t)(data_size + data_size_len),
            },
        },
    };
    return attr_val;
}

ameba_matter_attr_val_t ameba_matter_array(uint8_t *val, uint16_t data_size, uint16_t count)
{
    uint16_t data_size_len = 2; /* Number of bytes used to store the length */
    ameba_matter_attr_val_t attr_val = {
        .type = AMEBA_MATTER_VAL_TYPE_ARRAY,
        .val = {
            ._a = {
                ._b = val,
                ._s = data_size,
                ._n = count,
                ._t = (uint16_t)(data_size + data_size_len),
            },
        },
    };
    return attr_val;
}
