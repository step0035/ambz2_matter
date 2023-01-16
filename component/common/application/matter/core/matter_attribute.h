#include <platform_stdlib.h>
#include <app/util/attribute-storage.h>
#include "matter_config.h"

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
        attr_val.val.u64 = val.value();
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
        chip::app::NumericAttributeTraits<uint16_t>::SetNull(attr_val.val.u16);
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
        chip::app::NumericAttributeTraits<uint32_t>::SetNull(attr_val.val.u32);
    } else {
        attr_val.val.u32 = val.value();
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

class Attribute
{
public:
    Attribute(uint8_t value, uint16_t length, uint16_t count); // create
    ~ Attribute(); // destroy

private:
    uint32_t attribute_id;
    uint16_t flags;
    ameba_matter_attr_val_t val;
    ameba_matter_attr_bounds_t *bounds;
    EmberAfDefaultOrMinMaxAttributeValue default_value;
    uint16_t default_value_size;
    // Callback override_callback;
    Attribute *next;
};
