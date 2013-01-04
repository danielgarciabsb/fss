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

char ReadBinaryConfigFromFile(const char * filename, ServerAtts * ServerAt)
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

char WriteBinaryConfigToFile(const char * filename, ServerAtts * ServerAt)
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

  * Signature:    static char IsAlpha(char buffer)
  * Description:  Check if the given char is an alphanumeric character

  * @todo         Optimize performance in a new version
  * @example      IsAlpha('A'); // returns 1 (True)
  * @parameter    char buffer
  * @return       char (True or false)

*/

static char IsAlpha(char buffer)
{
  if(( buffer >= '0' && buffer <= '9') || ( buffer >= 'A' && buffer <= 'Z' ) || ( buffer >= 'a' && buffer <= 'z' ))
    return 1;
  return 0;
}

/*

  * Signature:    static void GetParameterValueFromFile(FILE * file, char * parameter)
  * Description:  Reads the configuration file from a given position and
                  get the parameter value.

  * @todo         Optimize performance in a new version
  * @example      GetParameterValueFromFile(FILE, "Port");
  * @parameter    FILE * file, char * parameter
  * @return       void

*/

static void GetParameterValueFromFile(FILE * file, char * parameter)
{
  unsigned char buffer, count = 0, * value;
  value = (unsigned char *) calloc (32, sizeof(unsigned char));
  while(buffer != '\n')
  {
    if(feof(file) || count == 32) return;
    fread(&buffer, sizeof(unsigned char), 1, file);

    if(IsAlpha(buffer))
    {
      value[count] = buffer;
      count++;
    }
  }
}

/*

  * Signature:    static void GetParameterFromFile(const char * filename)
  * Description:  Reads the configuration file from start and
                  get the parameter name, passes the parameter
                  name to GetParameterFromFile().

  * @todo         Optimize performance in a new version
  * @example      GetParameterFromFile("config.cfg");
  * @parameter    const char * filename
  * @return       void

*/

static void GetParameterFromFile(const char * filename)
{
  FILE * file;

  if((file = fopen(filename, "r")) != NULL)
  {
    unsigned char buffer, count = 0, * parameter;

    while(!feof(file))
    {
      fread(&buffer, sizeof(unsigned char), 1, file);
      if(buffer == '[')
      {
        parameter = (unsigned char *) calloc (32, sizeof(unsigned char));
        while(!feof(file))
        {
          fread(&buffer, sizeof(unsigned char), 1, file);

          if( count == 32 || buffer == ']' )
          {
            GetParameterValueFromFile(file, parameter);
            count = 0;
            break;
          }

          if(IsAlpha(buffer))
          {
            parameter[count] = buffer;
            count++;
          }
        }
      }
    }
  }
}

/*

  * Signature:    static char IsAlpha(char buffer)
  * Description:  Set the server configuration ...

  * @todo         Implement
  * @example      SetServerConf("Port", "9000")
  * @parameter    const char * parameter, const char * value
  * @return       char

*/

static char SetServerConf(const char * parameter, const char * value)
{

}