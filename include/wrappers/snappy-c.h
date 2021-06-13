/**
  @file snappy-c.h
  This service provides dynamic access to Snappy as a C header.
*/

#ifndef SNAPPY_C_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#ifndef MYSQL_ABI_CHECK
#include <stddef.h>
#include <stdbool.h>
#endif

#ifndef SNAPPY_C
typedef enum
{
  SNAPPY_OK                 = 0,
  SNAPPY_INVALID_INPUT      = 1,
  SNAPPY_BUFFER_TOO_SMALL   = 2
} snappy_status;

#define snappy_max_compressed_length(...) wrapper_service_snappy->snappy_max_compressed_length_ptr (__VA_ARGS__)
#define snappy_compress(...)              wrapper_service_snappy->snappy_compress_ptr              (__VA_ARGS__)
#define snappy_uncompressed_length(...)   wrapper_service_snappy->snappy_uncompressed_length_ptr   (__VA_ARGS__)
#define snappy_uncompress(...)            wrapper_service_snappy->snappy_uncompress_ptr            (__VA_ARGS__)
#endif

#define DEFINE_snappy_max_compressed_length(NAME) NAME( \
    size_t source_length                                \
)

#define DEFINE_snappy_compress(NAME) NAME( \
    const char *input,                     \
    size_t input_length,                   \
    char *compressed,                      \
    size_t *compressed_length              \
)

#define DEFINE_snappy_uncompressed_length(NAME) NAME( \
    const char *compressed,                           \
    size_t compressed_length,                         \
    size_t *result                                    \
)

#define DEFINE_snappy_uncompress(NAME) NAME(  \
    const char *compressed,                   \
    size_t compressed_length,                 \
    char *uncompressed,                       \
    size_t *uncompressed_length               \
)

struct wrapper_service_snappy_st
{
  size_t DEFINE_snappy_max_compressed_length((*snappy_max_compressed_length_ptr));
  snappy_status DEFINE_snappy_compress((*snappy_compress_ptr));
  snappy_status DEFINE_snappy_uncompressed_length((*snappy_uncompressed_length_ptr));
  snappy_status DEFINE_snappy_uncompress((*snappy_uncompress_ptr));
};

extern struct wrapper_service_snappy_st *wrapper_service_snappy;

#ifdef __cplusplus
}
#endif

#define SNAPPY_C_INCLUDED
#endif
