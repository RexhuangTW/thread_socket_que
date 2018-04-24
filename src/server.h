


void tcp_server_start(void);
void * Task_tcp_server_listen(void* arg);
void tcp_server_send(char *s);

extern int client_connect_flag;
extern int tcp_send_flag ;
