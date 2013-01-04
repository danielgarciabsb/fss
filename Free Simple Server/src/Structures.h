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

#ifndef PACKET_SIGN
#define PACKET_SIGN

typedef struct PacketSignType
{
	unsigned char PacketID;
	unsigned int Destination;

} PacketSign;

#endif

#ifndef PLAYER_GAME_INFO
#define PLAYER_GAME_INFO

typedef struct PlayerGameInfo
{
	unsigned char PacketID;
	int Player;
	char x, y;

} PGInfo;

#endif

#ifndef PLAYER_INFO
#define PLAYER_INFO

typedef struct PlayerInfo
{
	unsigned char PacketID;
	char * name;

} PInfo;

#endif
