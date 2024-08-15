# Настройки компилятора
CC = g++
CFLAGS = -std=c++17 -Wall

INC_DIR = ./include/
SRC_DIR = ./src/

NAME = Curves
NAME_DLL = $(NAME).dll
NAME_EXE = $(NAME).exe

FILES_DLL = $(SRC_DIR)Curve.cpp $(SRC_DIR)Circle.cpp $(SRC_DIR)Ellipse.cpp $(SRC_DIR)Helix.cpp
FILES_MAIN = $(SRC_DIR)main.cpp

all: build

# Запуск собранной программы
.SILENT: run
run:
	./$(NAME_EXE)

# Очистка выходной директории
.SILENT: clean
clean:
	erase *.exe \
	erase *.dll

# Сборка  dll
DLLFLAG = -shared -fPIC
.SILENT: dll
dll:
	$(CC) $(CFLAGS) $(DLLFLAG) $(FILES_DLL) -I $(INC_DIR) -o $(NAME_DLL)

#
.SILENT: build
build:
	$(CC) $(CFLAGS) $(NAME_DLL) $(FILES_MAIN) -I $(INC_DIR) -o $(NAME_EXE)