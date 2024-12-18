#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    // Создание сокета
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Ошибка при создании сокета: " << strerror(errno) << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Преобразование IPv4 адреса из текстового формата в бинарный
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Неверный адрес/неподдерживаемый адрес: " << strerror(errno) << std::endl;
        return -1;
    }

    // Подключение к серверу
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Ошибка подключения: " << strerror(errno) << std::endl;
        return -1;
    }

    // Здесь можно добавить логику для отправки и получения данных
    // Например, отправка сообщения
    const char *message = "Hello from client";
    if (send(sock, message, strlen(message), 0) < 0) {
        std::cerr << "Ошибка отправки сообщения: " << strerror(errno) << std::endl;
        close(sock);
        return -1;
    }

    // Закрытие сокета
    close(sock);
    return 0;
}