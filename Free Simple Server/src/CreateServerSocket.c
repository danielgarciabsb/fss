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

#include "CreateServerSocket.h"

void CreateServerSocket(ServerAtts * ServerAt)
{
	if((ServerAt->Sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		LogErrorAndExit("CreateServerSocket(): socket() failed.");

	memset(&ServerAt->SocketAtts, 0, sizeof(ServerAt->SocketAtts));
	ServerAt->SocketAtts.sin_family = AF_INET;
	ServerAt->SocketAtts.sin_addr.s_addr = htonl(INADDR_ANY);
	ServerAt->SocketAtts.sin_port = htons(ServerAt->Port);

	if(bind(ServerAt->Sock, (struct sockaddr *) &ServerAt->SocketAtts, sizeof(ServerAt->SocketAtts)) < 0)
	{
		close(ServerAt->Sock);
		LogErrorAndExit("CreateServerSocket(): bind() failed.");
	}

	if(listen(ServerAt->Sock, MAXPENDING) < 0)
	{
		close(ServerAt->Sock);
		LogErrorAndExit("CreateServerSocket: listen() failed");
	}
	LogConnection("CreateServerSocket(): Success!");
}
