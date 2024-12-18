# Определяем компилятор и флаги компиляции
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Имя выходного файла
TARGET = client

# Исходные файлы
SRCS = client.cpp

# Правила сборки
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Правило для очистки скомпилированных файлов
clean:
	rm -f $(TARGET)
