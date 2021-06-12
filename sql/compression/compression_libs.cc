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

#include <my_global.h>
#include "compression_libs.h"
//#include <mariadb.h>
#include <mysqld.h>

void init_compression(
//    struct compression_service_bzip2_st  *bzip2_handler,
//    struct compression_service_lz4_st    *lz4_handler,
    struct compression_service_lzma_st   *lzma_handler
//    struct compression_service_lzo_st    *lzo_handler,
//    struct compression_service_snappy_st *snappy_handler,
//    struct compression_service_zstd_st   *zstd_handler
){
    // TODO: Print an error message if library fails to load.

    // TODO: Use the correct platform extension(dll/so) while loading the
    // library.

    // TODO: Handle different versions of the library (liblzma.so.5.2.4,
    // liblzma.so.5.2.5, etc)

    //init_bzip2  (bzip2_handler,  (enabled_compression_libraries & COMPRESSION_BZIP2));
    //init_lz4    (lz4_handler,    (enabled_compression_libraries & COMPRESSION_LZ4));
    init_lzma   (lzma_handler,   (enabled_compression_libraries & COMPRESSION_LZMA));
    //init_lzo    (lzo_handler,    (enabled_compression_libraries & COMPRESSION_LZO));
    //init_snappy (snappy_handler, (enabled_compression_libraries & COMPRESSION_SNAPPY));
    //init_zstd   (zstd_handler,   (enabled_compression_libraries & COMPRESSION_ZSTD));
}
