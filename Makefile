CC=g++
CFLAGS=-std=c++11 -Wall -Iinclude

all:: main

obj/Produto.o: src/Produto.cpp include/Produto.hpp
	${CC} ${CFLAGS} -c src/Produto.cpp -o obj/Produto.o

obj/Estoque.o: src/Estoque.cpp include/Estoque.hpp
	${CC} ${CFLAGS} -c src/Estoque.cpp -o obj/Estoque.o

obj/Caixa.o: src/Caixa.cpp include/Caixa.hpp
	${CC} ${CFLAGS} -c src/Caixa.cpp -o obj/Caixa.o

obj/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o obj/main.o

main: obj/Produto.o obj/Estoque.o obj/Caixa.o obj/main.o
	$(CC) $(CFLAGS) -o main obj/Produto.o obj/Estoque.o obj/Caixa.o obj/main.o

//incluir Funcionario, Cliente, Sistema
              
clean:
	rm -f obj/*.o main
