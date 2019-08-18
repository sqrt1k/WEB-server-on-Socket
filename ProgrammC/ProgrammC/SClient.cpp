#pragma once
#include "stdafx.h"
#include "includes.h"
#include "SClient.h"

SClient::SClient(SOCKET s, SOCKADDR_IN sock_in)
{

	c_sock = s;
	c_addr = sock_in;
	printf("Client created\n");
	handle();
}

SClient::~SClient()
{
}

void SClient::handle()
{
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	const int max_client_buffer_size = 1024;
char buf[max_client_buffer_size];

result = recv(c_sock, buf, max_client_buffer_size, 0);

std::stringstream response; 
std::stringstream response_body; 
if (result == SOCKET_ERROR) {
    // ошибка получения данных
    cerr << "recv failed: " << result << "\n";
    closesocket(c_sock);
} else if (result == 0) {
    // соединение закрыто клиентом
    cerr << "connection closed...\n";
} else if (result > 0) {
  
    buf[result] = '\0';

    // формируем тело ответа (HTML)
    response_body << "<title>Test</title>\n"
        << "<h1>Test page</h1>\n"
        << "<p>This is body of the test page...</p>\n"
        << "<h2>Request headers</h2>\n"
        << "<pre>" << buf << "</pre>\n"
        << "<em><small>Test</small></em>\n"
		<< "<a href = '/data'>Send Data</a>\n";
	

    // Формируем весь ответ вместе с заголовками
    response << "HTTP/1.1 200 OK\r\n"
        << "Version: HTTP/1.1\r\n"
        << "Content-Type: text/html; charset=utf-8\r\n"
        << "Content-Length: " << response_body.str().length()
        << "\r\n\r\n"
        << response_body.str();

    // Отправляем ответ клиенту с помощью функции send
    result = send(c_sock, response.str().c_str(),
        response.str().length(), 0);

    if (result == SOCKET_ERROR) {
        cerr << "send failed: " << WSAGetLastError() << "\n";
    }
	closesocket(c_sock);
	}
}
