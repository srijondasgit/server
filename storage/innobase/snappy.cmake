# Copyright (C) 2015, MariaDB Corporation. All Rights Reserved.
#
# This program is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation; version 2 of the License.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin St, Fifth Floor, Boston, MA 02110-1335 USA

SET(WITH_INNODB_SNAPPY AUTO CACHE STRING
  "Build with snappy. Possible values are 'ON', 'OFF', 'AUTO' and default is 'AUTO'")

MACRO (MYSQL_CHECK_SNAPPY)
  IF (WITH_INNODB_SNAPPY STREQUAL "ON" OR WITH_INNODB_SNAPPY STREQUAL "AUTO")
    ADD_DEFINITIONS(-DHAVE_SNAPPY=1)
  ENDIF()
ENDMACRO()
