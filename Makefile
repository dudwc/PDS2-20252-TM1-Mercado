CC=g++
CFLAGS=-std=c++11 -Wall -Iinclude
BIN_DIR=bin
OBJ_DIR=obj

all:: $(BIN_DIR)/main

$(OBJ_DIR)/Produto.o: src/Produto.cpp include/Produto.hpp | $(OBJ_DIR)
	${CC} ${CFLAGS} -c src/Produto.cpp -o $(OBJ_DIR)/Produto.o

$(OBJ_DIR)/Estoque.o: src/Estoque.cpp include/Estoque.hpp | $(OBJ_DIR)
	${CC} ${CFLAGS} -c src/Estoque.cpp -o $(OBJ_DIR)/Estoque.o

$(OBJ_DIR)/Caixa.o: src/Caixa.cpp include/Caixa.hpp | $(OBJ_DIR)
	${CC} ${CFLAGS} -c src/Caixa.cpp -o $(OBJ_DIR)/Caixa.o

$(OBJ_DIR)/Sistema.o: src/Sistema.cpp include/Sistema.hpp | $(OBJ_DIR)
	${CC} ${CFLAGS} -c src/Sistema.cpp -o $(OBJ_DIR)/Sistema.o

$(OBJ_DIR)/Funcionario.o: src/Funcionario.cpp include/Funcionario.hpp | $(OBJ_DIR)
	${CC} ${CFLAGS} -c src/Funcionario.cpp -o $(OBJ_DIR)/Funcionario.o

$(OBJ_DIR)/Cliente.o: src/Cliente.cpp include/Cliente.hpp | $(OBJ_DIR)
	${CC} ${CFLAGS} -c src/Cliente.cpp -o $(OBJ_DIR)/Cliente.o

$(OBJ_DIR)/main.o: src/main.cpp include/Produto.hpp include/Estoque.hpp include/Caixa.hpp include/Sistema.hpp include/Cliente.hpp include/Funcionario.hpp | $(OBJ_DIR)
	${CC} ${CFLAGS} -c src/main.cpp -o $(OBJ_DIR)/main.o

$(BIN_DIR)/main: $(OBJ_DIR)/Produto.o $(OBJ_DIR)/Estoque.o $(OBJ_DIR)/Caixa.o $(OBJ_DIR)/Sistema.o $(OBJ_DIR)/Funcionario.o $(OBJ_DIR)/Cliente.o $(OBJ_DIR)/main.o | $(BIN_DIR)
	${CC} ${CFLAGS} -o $(BIN_DIR)/main $(OBJ_DIR)/Produto.o $(OBJ_DIR)/Estoque.o $(OBJ_DIR)/Caixa.o $(OBJ_DIR)/Sistema.o $(OBJ_DIR)/Funcionario.o $(OBJ_DIR)/Cliente.o $(OBJ_DIR)/main.o

# Comando para executar o programa
run: $(BIN_DIR)/main
	./$(BIN_DIR)/main

# Criar diretórios se não existirem
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR)/*.o 2> /dev/null || true
	rm -f $(BIN_DIR)/main 2> /dev/null || true

.PHONY: all clean run