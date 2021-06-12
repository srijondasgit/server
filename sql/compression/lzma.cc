#include "compression_libs.h"

DEFINE_lzma_stream_buffer_decode(DUMMY_lzma_stream_buffer_decode)
{
  return LZMA_PROG_ERROR;
}

DEFINE_lzma_easy_buffer_encode(DUMMY_lzma_easy_buffer_encode)
{
  return LZMA_PROG_ERROR;
}

bool init_lzma(compression_service_lzma_st *h)
{
  h->lzma_stream_buffer_decode_ptr= DUMMY_lzma_stream_buffer_decode;
  h->lzma_easy_buffer_encode_ptr= DUMMY_lzma_easy_buffer_encode;

  if (!(enabled_compression_libraries & COMPRESSION_LZMA))
    return 0;

  const char *dlname= "liblzma." IF_WIN("dll", "so.5");
  void *dl= dlopen(dlname, RTLD_LAZY);
  if (!dl)
  {
    sql_print_error("Cannot enable LZMA: %s", dlerror());
    return 1;
  }

  void *lzma_stream_buffer_decode_ptr= dlsym(dl, "lzma_stream_buffer_decode");
  void *lzma_easy_buffer_encode_ptr= dlsym(dl, "lzma_easy_buffer_encode");
  if (!lzma_stream_buffer_decode_ptr || !lzma_easy_buffer_encode_ptr)
  {
    sql_print_error("Cannot enable LZMA: invalid %s", dlname);
    return 1;
  }

  h->lzma_stream_buffer_decode_ptr= (PTR_lzma_stream_buffer_decode)lzma_stream_buffer_decode_ptr;
  h->lzma_easy_buffer_encode_ptr= (PTR_lzma_easy_buffer_encode)lzma_easy_buffer_encode_ptr;
  return 0;
}
