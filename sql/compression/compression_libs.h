/* Copyright (c) 2021, MariaDB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1335  USA */

// #include <compression/bzlib.h>
// #include <compression/lz4.h>
// #include <compression/lz4hc.h>
#include <compression/lzma.h>
// #include <compression/lzo/lzo1x.h>
// #include <compression/snappy-c.h>
// #include <compression/zstd.h>

// #define COMPRESSION_BZIP2   (1ULL << 0)
// #define COMPRESSION_LZ4     (1ULL << 1)
#define COMPRESSION_LZMA    (1ULL << 0)
// #define COMPRESSION_LZO     (1ULL << 3)
// #define COMPRESSION_SNAPPY  (1ULL << 4)
// #define COMPRESSION_ZLIB    (1ULL << 5)
// #define COMPRESSION_ZSTD    (1ULL << 6)


void init_compression(
//    struct compression_service_bzip2_st  *,
//    struct compression_service_lz4_st    *,
    struct compression_service_lzma_st   *
//    struct compression_service_lzo_st    *,
//    struct compression_service_snappy_st *,
//    struct compression_service_zstd_st   *
);

//void init_bzip2  (struct compression_service_bzip2_st  *, bool);
//void init_lz4    (struct compression_service_lz4_st    *, bool);
void init_lzma   (struct compression_service_lzma_st   *, bool);
//void init_lzo    (struct compression_service_lzo_st    *, bool);
//void init_snappy (struct compression_service_snappy_st *, bool);
//void init_zstd   (struct compression_service_zstd_st   *, bool);
