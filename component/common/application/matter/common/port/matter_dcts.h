/**
 * @brief High resolution sleep.
 *
 * http://pubs.opengroup.org/onlinepubs/9699919799/functions/nanosleep.html
 *
 * @note rmtp is ignored, as signals are not implemented.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <wifi_conf.h>
/*
   module size is 4k, we set max module number as 12;
   if backup enabled, the total module number is 12 + 1*12 = 24, the size is 96k;
   if wear leveling enabled, the total module number is 12 + 2*12 + 3*12 = 36, the size is 288k"
*/
#define DCT_BEGIN_ADDR_MATTER   DCT_BEGIN_ADDR    /*!< DCT begin address of flash, ex: 0x100000 = 1M */
#define MODULE_NUM              13                /*!< max number of module */
#define VARIABLE_NAME_SIZE      32                /*!< max size of the variable name */
#define VARIABLE_VALUE_SIZE     64 + 4          /*!< max size of the variable value */
                                                  /*!< max value number in moudle = 4024 / (32 + 1860+4) = 2 */

#define DCT_BEGIN_ADDR_MATTER2  DCT_BEGIN_ADDR2
#define MODULE_NUM2             6 
#define VARIABLE_NAME_SIZE2     32
#define VARIABLE_VALUE_SIZE2    400 + 4

#define ENABLE_BACKUP           0
#define ENABLE_WEAR_LEVELING    0

s32 initPref(void);
s32 deinitPref(void);
s32 registerPref(void);
s32 registerPref2(void);
s32 clearPref(void);
s32 clearPref2(void);
s32 deleteKey(const char *domain, const char *key);
bool checkExist(const char *domain, const char *key);
s32 setPref_new(const char *domain, const char *key, u8 *value, size_t byteCount);
s32 getPref_bool_new(const char *domain, const char *key, u8 *val);
s32 getPref_u32_new(const char *domain, const char *key, u32 *val);
s32 getPref_u64_new(const char *domain, const char *key, u64 *val);
s32 getPref_str_new(const char *domain, const char *key, char * buf, size_t bufSize, size_t *outLen);
s32 getPref_bin_new(const char *domain, const char *key, u8 * buf, size_t bufSize, size_t *outLen);

#ifdef __cplusplus
}
#endif
