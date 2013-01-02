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

#include "Main.h"

/*TODO: Fazer load de atributos ServerAtts, arquivo 
		Fail safe 'log error and exit'
		Renomear Player para Client
		Criar thread principal para Fila de pacotes a enviar para todos
*/

int main(int argc, char * argv[])
{
	ServerAtts ServerAt;
	ThreadArgs threadargs;

	threadargs.ServerAt = &ServerAt;

	ServerAt.Port = 7777;
	ServerAt.Pcount = 0;
	ServerAt.Players = NULL;
	ServerAt.MaxPlayers = 200;
	ServerAt.ClientAtts = NULL;
	ServerAt.ThreadID = NULL;
	
	if(!(ReadConfigFromFile(CONFIG_FILE, &ServerAt))
		LogError("Main(): Could not read config file, assuming default arguments.");
	WriteConfigToFile(CONFIG_FILE, &ServerAt);

	if((ServerAt.Connected = (char *) calloc(ServerAt.MaxPlayers, sizeof(char))) == NULL)
		LogErrorAndExit("Main(): Failed to malloc(ServerAt.Connected)"); 

	if((ServerAt.Players = (int *) malloc(ServerAt.MaxPlayers * sizeof(int))) == NULL)
		LogErrorAndExit("Main(): Failed to malloc(ServerAt.Players)");

	if((ServerAt.ClientAtts = (struct sockaddr_in *) malloc(ServerAt.MaxPlayers * sizeof(struct sockaddr_in))) == NULL)
		LogErrorAndExit("Main(): Failed to malloc(ServerAt.ClientAtts)");

	if((ServerAt.ThreadID = (pthread_t *) malloc(ServerAt.MaxPlayers * sizeof(pthread_t))) == NULL)
		LogErrorAndExit("Main(): Failed to malloc(ServerAt.ThreadID)");

	CreateServerSocket(&ServerAt);

	while(1)
	{
		if(AcceptConnection(&ServerAt))
		{
			CreateThread(&ServerAt, &threadargs);
			ServerAt.Connected[ServerAt.Pcount] = 1; /* Fazer funcao LOAD/UNLOAD client */
			ServerAt.Pcount++;
		}
	}
}
