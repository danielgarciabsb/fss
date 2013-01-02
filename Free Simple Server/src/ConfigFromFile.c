/*

	Free Simple Server

	Copyright (C) 2013

Authors:
	Daniel Garcia <contato@danielgarciaweb.com>

This file is part of Free Simple Server

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
Or access: <http://www.gnu.org/licenses/>

*/

#include "ConfigFromFile.h"

char ReadConfigFromFile(const char * filename, ServerAtts * ServerAt)
{
	FILE * file;
	if((file = fopen(filename, "rb")) != NULL)
	{
		if(!fread(ServerAt,sizeof(ServerAtts),1,file))
			LogErrorAndExit("ReadConfigFromFile(): Failed to read from file");

		fclose(file);
		return 1;
	}
	
	return 0;
}

char WriteConfigToFile(const char * filename, ServerAtts * ServerAt)
{
	FILE * file;
	if((file = fopen(filename, "wb")) != NULL)
	{
		if(!fwrite(ServerAt,sizeof(ServerAtts),1,file))
			LogErrorAndExit("WriteConfigToFile(): Failed to write to file");

		fclose(file);
		return 1;
	}
	
	LogErrorAndExit("WriteConfigToFile(): Failed to open file to write");
	return 0;
}
