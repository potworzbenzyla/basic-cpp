#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int perform_operation(char op, int a, int b) {
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

void handle_client_connection(int client_socket) {
    char buffer[MAX_BUFFER_SIZE];
    int num_bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);

    if (num_bytes_received == -1) {
        fprintf(stderr, "Blad w trakcie odbierania danych.");
        close(client_socket);
        return;
    }

    buffer[num_bytes_received] = '\0';

    if (strlen(buffer) >= 3 && (buffer[1] == '+' || buffer[1] == '-' || buffer[1] == '*' || buffer[1] == '/')) {
        int a, b, result;
        sscanf(buffer, "%d %c %d", &a, &buffer[1], &b);
        result = perform_operation(buffer[1], a, b);
        snprintf(buffer, MAX_BUFFER_SIZE, "%d", result);
    } else if (atoi(buffer) != 0) {
        int num = atoi(buffer);
        snprintf(buffer, MAX_BUFFER_SIZE, "%d", num * 2);
    } else {
        int len = strlen(buffer);
        for (int i = 0; i < len / 2; i++) {
            char tmp = buffer[i];
            buffer[i] = buffer[len - i - 1];
            buffer[len - i - 1] = tmp;
        }
    }

    int num_bytes_sent = send(client_socket, buffer, strlen(buffer), 0);

    if (num_bytes_sent == -1) {
        fprintf(stderr, "Blad, nie wyslano danych.\n");
    } else {
        printf("Wyslano odpowiedz do: %s\n", buffer);
    }
    close(client_socket);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Polaczenie: %s <port>\n", argv[0]);
        return 1;
    }
    int port = atoi(argv[1]);

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        fprintf(stderr, "Blad: nie utworzono socketa.\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr, &server_addr, sizeof(server_addr)) == -1) {
	fprintf(stderr, "Blad socketa\n");
	return 1;
    }

    if (listen(server_socket, 5) == -1) {
        fprintf(stderr, "Blad w trakcie nasluchu\n");
        return 1;
    }

    printf("Serwer nasluchuje na porcie: %d...\n", port);

    for (;;) {
        socklen_t client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            fprintf(stderr, "Blad, nie zatwierdzono polaczenia.\n");
            continue;
        }

	printf("Zaakceptowano polaczenie klienta: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

	pid_t pid = fork();

	if (pid == -1) {
		fprintf(stderr, "Blad, nie udalo sie utworzyc nowego procesu.\n");
		close(client_socket);
		continue;
	} else if (pid == 0) {
		close(server_socket);
		handle_client_connection(client_socket);
		exit(0);
	} else {
		close(client_socket);
	}
    }
    close(server_socket);
    return 0;
}

