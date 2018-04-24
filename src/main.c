// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include "server.h"
#include "Queue.h"
#include "common.h"

//Thread Ptr
pthread_t tcp_server_listen;
pthread_t mqtt_client_received;
pthread_t thdQueue;


int main(int argc, char *argv[])
{
	int res;
	
	tcp_server_start();

	// Thread for TCP Server listen to client
	res = pthread_create(&tcp_server_listen,NULL,Task_tcp_server_listen,NULL);

	// Thread for que Z->A data
	res = pthread_create(&thdQueue, NULL, Task_Queue, NULL);

	
	while(1)
	{
		usleep(1000);
	}

	return 0;

}
