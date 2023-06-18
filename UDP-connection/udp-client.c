#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Użycie: %s <adres_IP_serwera> <port> <dane>\n", argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    char *data = argv[3];

    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if (client_socket == -1) {
        fprintf(stderr, "Błąd: nie utworzono socketa.\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    int num_bytes_sent = sendto(client_socket, data, strlen(data), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

    if (num_bytes_sent == -1) {
        fprintf(stderr, "Błąd, nie wysłano danych.\n");
        close(client_socket);
        return 1;
    }

    struct sockaddr_in response_addr;
    socklen_t response_addr_len = sizeof(response_addr);
    int num_bytes_received = recvfrom(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0, (struct sockaddr*)&response_addr, &response_addr_len);

    if (num_bytes_received == -1) {
        fprintf(stderr, "Błąd w trakcie odbierania danych.\n");
        close(client_socket);
        return 1;
    }

    buffer[num_bytes_received] = '\0';
    printf("Odpowiedź od serwera (%s:%d): %s\n", inet_ntoa(response_addr.sin_addr), ntohs(response_addr.sin_port), buffer);

    close(client_socket);
    return 0;
}

