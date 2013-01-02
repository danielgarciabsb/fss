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

#ifndef SERVER_ATTRIBUTES
#define SERVER_ATTRIBUTES

typedef struct ServerAttsType
{
	unsigned int Sock, * Players, Pcount, MaxPlayers;
	unsigned short Port;
	char Type, * Connected;
	struct sockaddr_in SocketAtts;
	struct sockaddr_in * ClientAtts;
	pthread_t * ThreadID;

} ServerAtts;

#endif
