#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Polaczono: %s <ip> <port> <data>\n", argv[0]);
        return 1;
    }
    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    char *data = argv[3];

    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        fprintf(stderr, "Blad nie utworzono socketa\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Blad, nie polaczono z serwerem.\n");
        return 1;
    }

    int num_bytes_sent = send(client_socket, data, strlen(data), 0);
    if (num_bytes_sent == -1) {
        fprintf(stderr, "Blad, nie udalo sie wyslac danych do serwera.\n");
        close(client_socket);
        return 1;
    }

 
    int num_bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if (num_bytes_received == -1) {
        fprintf(stderr, "Blad, nie uzyskano odpowiedzi od serwera.\n");
        close(client_socket);
        return 1;
    }

    buffer[num_bytes_received] = '\0';
    printf("Wynik: %s\n", buffer);


    close(client_socket);

    return 0;
}

