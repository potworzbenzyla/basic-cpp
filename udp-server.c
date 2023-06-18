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

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Użycie: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if (server_socket == -1) {
        fprintf(stderr, "Błąd: nie utworzono socketa.\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Błąd socketa\n");
        return 1;
    }

    printf("Serwer nasłuchuje na porcie: %d...\n", port);

    for (;;) {
        socklen_t client_addr_len = sizeof(client_addr);

        int num_bytes_received = recvfrom(server_socket, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &client_addr_len);

        if (num_bytes_received == -1) {
            fprintf(stderr, "Błąd w trakcie odbierania danych.\n");
            continue;
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

        int num_bytes_sent = sendto(server_socket, buffer, strlen(buffer), 0, (struct sockaddr*)&client_addr, client_addr_len);

        if (num_bytes_sent == -1) {
            fprintf(stderr, "Błąd, nie wysłano danych.\n");
        } else {
            printf("Wysłano odpowiedź do: %s\n", inet_ntoa(client_addr.sin_addr));
        }
    }

    close(server_socket);
    return 0;
}

