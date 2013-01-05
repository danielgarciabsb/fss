/*

	Free Simple Server

	Copyright (C) 2013

Authors:
	Daniel Garcia <contato@danielgarciaweb.com>

Licence:

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

Online license:
http://www.gnu.org/licenses/
http://www.gnu.org/licenses/gpl.html

*/

#include "ConfigFromFile.h"

/*

  * Signature:		static char IsAlpha(char c)
  * Description:	Check if the given char is an alphanumeric character

  * @todo			Optimize performance in a new version
  * @example		IsAlpha('A'); // returns 1 (True)
  * @parameter		char c
  * @return			char (True or false)

*/

static char IsAlpha(char c)
{
	if(( c >= '0' && c <= '9') || ( c >= 'A' && c <= 'Z' ) || ( c >= 'a' && c <= 'z' ))
		return 1;
	return 0;
}

/*

  * Signature:		char ReadBinaryConfigFromFile(const char * filename, ServerAtts * ServerAt)
  * Description:	Check if the given char is an alphanumeric character

  * @todo			Optimize performance in a new version
  * @example		IsAlpha('A'); // returns 1 (True)
  * @parameter		char c
  * @return			char (True or false)

*/

static char ReadBinaryConfigFromFile(const char * filename, ServerAtts * ServerAt)
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

static char WriteBinaryConfigToFile(const char * filename, ServerAtts * ServerAt)
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

/*

	* Signature:	static char SetServerConf(const char * key, const char * value)
	* Description:	Set the server configuration from
					given keys and values

	* @todo			Implement
	* @example		SetServerConf("Port", "9000")
	* @parameter	const char * parameter, const char * value
	* @return		char

*/

static char SetServerConf(const char * key, const char * value)
{
	printf("Parameter: [%s] Value:[%s]\n", parameter, value);
}

/*

	* Signature:	static void GetParameterFromFile(const char * filename)
	* Description:	Reads the configuration file
					Get the alphanumeric parameters key and value
					Call SetServerConf with parameter and value

	* Input file type:
	* Note: No spaces, slashes, dots.. Only 0..9, A..Z, a..z

		[Key] = Value
		[OtherKey] = OtherValue

	* @todo			Optimize performance in a new version
	* @example		GetParameterFromFile("config.cfg");
	* @parameter	const char * filename
	* @return		void

*/

static char GetParameterFromFile(const char * filename)
{
	FILE * file;

	if((file = fopen(filename, "r")) == NULL) return 0;

	unsigned char buffer, count = 0, parameter[32], value[32];

	while(!feof(file))
	{
		fread(&buffer, sizeof(unsigned char), 1, file);

		if(buffer == '[')
		{
			while(!feof(file))
			{
				if(count == 31 || buffer == ']')
				{
					parameter[count] = '\0';

					count = 0;

					while(!feof(file) && buffer != '\n' && count < 31)
					{
						fread(&buffer, sizeof(unsigned char), 1, file);

						if(IsAlpha(buffer))
						{
							value[count] = buffer;
							if(!feof(file)) count++;
						}
					}

					value[count] = '\0';

					SetServerConf(parameter, value);

					count = 0;
					break;
				}

				fread(&buffer, sizeof(unsigned char), 1, file);

				if(IsAlpha(buffer))
				{
					parameter[count] = buffer;
					count++;
				}
			}
		}
	}
	fclose(file);
	return 1;
}