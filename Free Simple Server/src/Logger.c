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

Online license:
http://www.gnu.org/licenses/
http://www.gnu.org/licenses/gpl.html

*/

#include "Logger.h"

void Logger(const char * filename, const char * message)
{
	FILE * logfile;
	if((logfile = fopen(filename,"a")) == NULL)
	{
		perror("Unable to open log file to append. Check folder permissions.");
		return;
	}
	time_t rawtime;
	time(&rawtime);
	fprintf(logfile,"%s%s\r\n",ctime(&rawtime),message);
	fclose(logfile);
}

void LogError(const char * message)
{
	perror(message);
	Logger("error.log", message);
}

void LogErrorAndExit(const char * message)
{
	LogError(message);
	exit(1);
}

void LogThread(const char * message)
{
	Logger("thread.log", message);
}

void LogConnection(const char * message)
{
	Logger("connection.log", message);
}
