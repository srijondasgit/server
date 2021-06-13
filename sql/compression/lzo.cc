#include "compression_libs.h"

DEFINE_lzo1x_1_15_compress(DUMMY_lzo1x_1_15_compress)
{
  return LZO_E_INTERNAL_ERROR;
}

DEFINE_lzo1x_decompress_safe(DUMMY_lzo1x_decompress_safe)
{
  return LZO_E_INTERNAL_ERROR;
}

bool init_lzo(struct compression_service_lzo_st *h)
{
  h->lzo1x_1_15_compress_ptr= DUMMY_lzo1x_1_15_compress;
  h->lzo1x_decompress_safe_ptr= DUMMY_lzo1x_decompress_safe;
  return 0;
}
