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

#include "HandleClient.h"

/*
typedef struct PacketSignType
{
	unsigned char PacketID;
	unsigned int Destination;

} PacketSign;

#endif

*/

static void PrepareToReceive(unsigned int Client, PacketSign Sign)
{
	switch(Sign.PacketID)
	{
		case 1:
		{
		
			break;
		}
		
	}
}

static void WaitForSignalPacket(unsigned int Client)
{
	int PacketSize = 0;

	PacketSign Sign;

	if ((PacketSize = recv(Client, &Sign, sizeof(Sign), 0)) < 0 || PacketSize != sizeof(Sign))
		LogErrorAndExit("WaitForSignalPacket(): failed");
	
	PrepareToReceive(Client, Sign);

}

void PacketDealer(ThreadArgs * Targs) /*SEND ENVIARA A TODOS SEM BLOCK? */
{
	QPCont Controll;
	QPNode First = NULL, Last = NULL;

	Controll.FirstPacket = &First;
	Controll.LastPacket = &Last;
	sleep(1);
	fprintf(stderr, "Port: %u",Targs->ServerAt->Port);
	fprintf(stderr, "Pcount: %d\n",Targs->ServerAt->Pcount);

	/*typedef struct ServerAttsType
{
	unsigned int Sock, * Players, Pcount;
	unsigned short Port;
	char Type;
	struct sockaddr_in SocketAtts;
	struct sockaddr_in * ClientAtts;
	pthread_t * ThreadID;

} ServerAtts;

typedef struct ThreadArgsType
{
	ServerAtts * ServerAt;

} ThreadArgs;

	
	WaitForSignalPacket();*/
}







