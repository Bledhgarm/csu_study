#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

void default_msg_handler(char* msg) {
	*msg = '\0';
}

/*
+, -, /, *
*/
void calculator_msg_handler(char* msg) {
	const RADIX = 10;

	char* msg_ptr = msg;

	int operand1 = 0, operand2 = 0;
	char operation = 0;
	char* op1 = msg;
	char* op2 = NULL;

	// search operation and op2
	++msg;
	while (isdigit(*msg)) ++msg;
	while (isspace(*msg)) ++msg;
	operation = *(msg++);
	while (isspace(*msg)) ++msg;
	op2 = msg;

	printf("%s, %s", op1, op2);

	// TODO errors handling
	operand1 = atoi(op1);
	operand2 = atoi(op2);

	int result = 0;
	switch (operation) {
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case '*':
		result = operand1 * operand2;
		break;
	case '/':
		result = operand1 / operand2;
		break;

	}
	_itoa(result, msg_ptr, RADIX);
}

void messages(SOCKET s, void (*msg_handler)(char*)) {
	WSAEventSelect(s, 0, FD_READ);
	char mess[200];
	do {
		if ((GetKeyState(VK_F1) < 0) && (GetForegroundWindow() == GetConsoleWindow())) {
			printf("You: ");
			while (_getch() != 0);
			scanf("\n%200[0-9a-zA-Z.,! +-*/]", mess);
			send(s, mess, sizeof(mess), 0);
		}
		if (recv(s, mess, sizeof(mess), 0) > 0) {
			printf("%s\n", mess);
			msg_handler(mess);
			if (strlen(mess) > 0) send(s, mess, sizeof(mess), 0);
		}
	} while (1);
}

int main(int argc, char** argv) {
	FILE* file;
	WSADATA ws;
	int err;
	errno_t error;
	err = WSAStartup(MAKEWORD(2, 2), &ws);
	if (err != 0) {
		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}
	SOCKET s;
	s = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN sa;
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(1234);
	//unsigned char buf[sizeof(struct in6_addr)];
	int counter = 0;
	error = fopen_s(&file, "C:/Users/kurut/Desktop/csu_study/sem2/Network/Network/choice.txt", "r");
	if (error == 0) {
		fscanf(file, "%d", &counter);
		fclose(file);
	}
	else {
		printf("The file wasn't opened");
	}
	if (counter % 2 == 0) {
		counter++;
		error = fopen_s(&file, "C:/Users/kurut/Desktop/csu_study/sem2/Network/Network/choice.txt", "w");
		if (error == 0) {
			fprintf(file, "%d", counter);
			fclose(file);
		}
		else {
			printf("The file wasn't opened");
		}
		/*	sa.sin_addr.S_un.S_addr = inet_pton(AF_INET, "127.0.0.1", buf);*/
		printf("Calculator client\n");
		sa.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		connect(s, &sa, sizeof(sa));
		messages(s, calculator_msg_handler);
	}
	if (counter % 2 == 1) {
		counter++;
		error = fopen_s(&file, "C:/Users/kurut/Desktop/csu_study/sem2/Network/Network/choice.txt", "w");
		if (error == 0) {
			fprintf(file, "%d", counter);
			fclose(file);
		}
		else {
			printf("The file wasn't opened");
		}
		bind(s, &sa, sizeof(sa));
		listen(s, 100);
		char buf[200];
		memset(buf, 0, sizeof(buf));
		printf("Enter F1 to start message\n");
		SOCKET client_socket;
		SOCKADDR_IN client_addr;
		int client_addr_size = sizeof(client_addr);
		while (client_socket = accept(s, &client_addr, &client_addr_size)) {
			messages(client_socket, default_msg_handler);
		}
	}

	closesocket(s);
	return 0;
}