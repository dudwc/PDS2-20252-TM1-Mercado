CC=g++
CFLAGS=-std=c++11 -Wall -Iinclude

all:: main

obj/Produto.o: src/Produto.cpp include/Produto.hpp
	${CC} ${CFLAGS} -c src/Produto.cpp -o obj/Produto.o

obj/Estoque.o: src/Estoque.cpp include/Estoque.hpp
	${CC} ${CFLAGS} -c src/Estoque.cpp -o obj/Estoque.o

obj/Caixa.o: src/Caixa.cpp include/Caixa.hpp
	${CC} ${CFLAGS} -c src/Caixa.cpp -o obj/Caixa.o

obj/Sistema.o: src/Sistema.cpp include/Sistema.hpp
	${CC} ${CFLAGS} -c src/Sistema.cpp -o obj/Sistema.o

obj/Funcionario.o: src/Funcionario.cpp include/Funcionario.hpp
	${CC} ${CFLAGS} -c src/Funcionario.cpp -o obj/Funcionario.o

obj/Cliente.o: src/Cliente.cpp include/Cliente.hpp
	${CC} ${CFLAGS} -c src/Cliente.cpp -o obj/Cliente.o

obj/main.o: src/main.cpp include/Produto.hpp include/Estoque.hpp include/Caixa.hpp include/Sistema.hpp include/Cliente.hpp include/Funcionario.hpp
	${CC} ${CFLAGS} -c src/main.cpp -o obj/main.o

main: obj/Produto.o obj/Estoque.o obj/Caixa.o obj/Sistema.o obj/Funcionario.o obj/Cliente.o obj/main.o
	${CC} ${CFLAGS} -o bin/main obj/Produto.o obj/Estoque.o obj/Caixa.o obj/Sistema.o obj/Funcionario.o obj/Cliente.o obj/main.o
              
clean:
	del  obj\*.o 2> NUL
	del  bin\main.exe 2> NUL
	del  bin\main 2> NUL
