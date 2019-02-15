#ifndef __SESSION_UV_H
#define __SESSION_UV_H


#define RECV_LEN 4096
//enum server type
enum
{
	TCP_SOCKET,
	WS_SOCKET,
};
class uv_session:session
{
public:
	uv_tcp_t tcp_handler;//�ͻ��˼����������ľ��
	char c_address[32];
	int c_port;

	uv_shutdown_t shutdown;
	uv_write_t w_req;
	uv_buf_t w_buf;
public:
	char recv_buf[RECV_LEN];
	int recved;
	int socket_type;
private:
	void init();
	void exit();
public:
	static uv_session* create();
	static void destroy(uv_session* s);
public:
	virtual void close();
	virtual void send_data(unsigned char* body,int len);
	virtual const char* get_address(int* client_port);
};

#endif