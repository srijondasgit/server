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

  if (!(enabled_compression_libraries & COMPRESSION_LZO))
    return 0;

  const char *dlname= "liblzo2." IF_WIN("dll", "so.2");
  void *dl= dlopen(dlname, RTLD_LAZY);
  if (!dl)
  {
    sql_print_error("Cannot enable LZO: %s", dlerror());
    return 1;
  }

  void *lzo1x_1_15_compress_ptr= dlsym(dl, "lzo1x_1_15_compress");
  void *lzo1x_decompress_safe_ptr= dlsym(dl, "lzo1x_decompress_safe");
  if(!lzo1x_1_15_compress_ptr || !lzo1x_decompress_safe_ptr)
  {
    sql_print_error("Cannot enable LZO: invalid %s", dlname);
    return 1;
  }

  h->lzo1x_1_15_compress_ptr= (PTR_lzo1x_1_15_compress)lzo1x_1_15_compress_ptr;
  h->lzo1x_decompress_safe_ptr= (PTR_lzo1x_decompress_safe)lzo1x_decompress_safe_ptr;
  return 0;
}
