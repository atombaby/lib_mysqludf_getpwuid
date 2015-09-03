USE mysql;

DROP FUNCTION IF EXISTS lib_mysqludf_getpwuid;
CREATE FUNCTION lib_mysqludf_getpwuid RETURNS STRING SONAME 'lib_mysqludf_getpwuid.so';
