# ==== Usage ====
#
# let $test_engine  = [innodb | mroonga | rocksdb];
# let $test_library = [bzip2 | lz4 | lz4hc | lzma | lzo | snappy | zstd];
# source test_library.inc;

--echo #
--echo # Test --use-compression=$test_library on storage engine "$test_engine"
--echo #

if (`select not find_in_set("$test_library", @@use_compression)`) {
    skip Library "$test_library" is not loaded;
}

eval set global innodb_compression_algorithm = $test_library;
let $table_create_parameters = page_compressed = 1;
call mtr.add_suppression("InnoDB: Background Page read failed to read or decrypt \\[page id: space=\\d+, page number=\\d+\\]");
call mtr.add_suppression("InnoDB: Table `test`.`t1` is corrupted. Please drop the table and recreate.");

eval CREATE TABLE t1 (a int, b text)
  engine = $test_engine
  $table_create_parameters;

insert t1 (a, b) values (0, repeat("abc", 100));
insert t1 (a, b) values (1, repeat("def", 1000));
insert t1 (a, b) values (2, repeat("ghi", 10000));
select a, left(b, 9), length(b) from t1;

--echo # Restart server with no compression libraries

let $restart_parameters = --use_compression=;
source include/restart_mysqld.inc;

error ER_NO_SUCH_TABLE_IN_ENGINE;
eval SELECT * FROM t1;
drop table t1;

let $restart_parameters =;
source include/restart_mysqld.inc;
