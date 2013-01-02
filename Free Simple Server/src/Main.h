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

#ifndef CONFIG_FILE
#define CONFIG_FILE "server.cfg"
#endif

#ifndef INCLUDE_STANDARD_LIBRARIES
#define INCLUDE_STANDARD_LIBRARIES

#include "StandardLibraries.h"

#endif

#ifndef INCLUDE_SOCKET_STRUCTS
#define INCLUDE_SOCKET_STRUCTS

#include "SocketLibraries.h"

#endif

#ifndef INCLUDE_SERVER_STRUCTS
#define INCLUDE_SERVER_STRUCTS

#include "ServerStructs.h"

#endif

#ifndef INCLUDE_THREAD_STRUCTS
#define INCLUDE_THREAD_STRUCTS

#include "ThreadStructs.h"

#endif

#ifndef INCLUDE_CREATE_THREAD
#define INCLUDE_CREATE_THREAD

#include "CreateThread.h"

#endif
