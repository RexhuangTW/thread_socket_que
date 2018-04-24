#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include "S2C.h"
#include "Queue.h"
#include "server.h"
#include "common.h"



void S2C_CMD(unsigned char *dareal,unsigned short rlen)
{
	unsigned char *da;
	unsigned short len;
	
	da=dareal;
	len=strlen((char *)dareal);

	tcp_send_flag = 1;
	tcp_server_send(da);			
	
}

