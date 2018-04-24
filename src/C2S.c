#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include "C2S.h"
#include "Queue.h"
#include "server.h"
#include "common.h"



void C2S_CMD(unsigned char *dareal,unsigned short rlen)
{
	unsigned char *da;
	unsigned short len;
	
	da=dareal;
	len=strlen((char *)dareal);

	
	/* Send back Client's Data, so save to tx DB first */
	printf(LIGHT_GREEN"Start save data to TX DB %s\n"NONE,da);

	tcp_send_flag = 1;
	Queue_TX_Write(da,len);

}

