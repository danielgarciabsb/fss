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

#include "CreateThread.h"

void * Thread(void * Threadargs)
{
    pthread_detach(pthread_self());

    PacketDealer(Threadargs);

	LogThread("Thread(): Thread exit."); /*UNLOAD CLIENT quando sair*/

}

void * CreateThread(ServerAtts * ServerAt, ThreadArgs * Threadargs) /*Otimizar para somente threadargs*/
{
	if (pthread_create(ServerAt->ThreadID + ServerAt->Pcount, NULL, Thread, (void *) Threadargs) != 0)
		LogErrorAndExit("CreateThread(): pthread_create() failed");

	LogThread("CreateThread(): Thread created.");
}
