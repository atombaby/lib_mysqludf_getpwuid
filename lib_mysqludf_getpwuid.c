/*
 * Skeleton libary for MySQL.
 * A set of MySQL user defined functions (UDF) to [DESCRIPTION]
 *
 * Copyright (C) [YYYY YOUR NAME <YOU@EXAMPLE.COM>]
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "mysqludf.h"

/* For Windows, define PACKAGE_STRING in the VS project */
#ifndef __WIN__
#include "config.h"
#endif

/* These must be right or mysqld will not find the symbol! */
#ifdef	__cplusplus
extern "C" {
#endif
	DLLEXP my_bool getpwuid_init(
            UDF_INIT *initid, UDF_ARGS *args, char *message
            );
	DLLEXP void getpwuid_deinit(UDF_INIT *initid);
	DLLEXP char *getpwuid(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error);

#ifdef	__cplusplus
}
#endif


#include <pwd.h>

my_bool getpwuid_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
	return 0;
}

void getpwuid_deinit(UDF_INIT *initid)
{
}

/* For functions that return STRING or DECIMAL */ 
char* getpwuid(UDF_INIT *initid, UDF_ARGS *args, char* result, unsigned long* length,	char *is_null, char *error)
{
    struct passwd *pwd;
    pwd = getpwuid( args->args[0] );
	strcpy(result, pwd->pw_name);
	*length = strlen(pwd->pw_name);
	return result;
}

