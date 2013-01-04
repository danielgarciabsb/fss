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

#include "PacketManager.h"

static void AddPacket(QPCont * Controll, unsigned char PacketID, unsigned int Destination)
{
	QPNode NewPacket;

	NewPacket = (QPNode) malloc(sizeof(QPNode));
	NewPacket->PacketID = PacketID;
	NewPacket->Destination = Destination;
	NewPacket->NextPacket = NULL;

	if(*(Controll->LastPacket) != NULL)
		(*(Controll->LastPacket))->NextPacket = NewPacket;
	else *(Controll->FirstPacket) = NewPacket;

	*(Controll->LastPacket) = NewPacket;
}

static void RemovePacket(QPNode * FirstPacket)
{
	QPNode * NextPacket;
	NextPacket = &(*FirstPacket)->NextPacket;
	free(*FirstPacket);
	*FirstPacket = *NextPacket;
}

static void ClearQueue(QPCont * Controll)
{
	QPNode * NextPacket;

	while(*(Controll->FirstPacket) != NULL)
	{
		NextPacket = &(*(Controll->FirstPacket))->NextPacket;
		free(*(Controll->FirstPacket));
		*(Controll->FirstPacket) = *NextPacket;
	}

	*(Controll->FirstPacket) = NULL;
	*(Controll->LastPacket) = NULL;
}

static void ShowPackets(QPNode * FirstPacket)
{
	QPNode * Run;
	Run = FirstPacket;

	while(1)
	{
		fprintf(stderr, "Packet: %p, ID: %u, DES: %d, NextPacket: %p\n", *Run, (*Run)->PacketID, (*Run)->Destination,(*Run)->NextPacket);
		Run = &(*Run)->NextPacket;
		if((*Run)->NextPacket == NULL) break;
	}
	
	fprintf(stderr, "Packet: %p, ID: %u, DES: %d, NextPacket: %p\n", *Run, (*Run)->PacketID, (*Run)->Destination,(*Run)->NextPacket);

}

