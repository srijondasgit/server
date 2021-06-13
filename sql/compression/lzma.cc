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
  return 0;
}
