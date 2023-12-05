CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -O3 -std=c++11 -I include/

all: build

#vaga:

Usuario:
	@mkdir -p build
	$(CC) $(CFLAGS) -c src/Usuario.cpp -o build/Usuario.o
SistemaBancario:
	$(CC) $(CFLAGS) -c src/SistemaBancario.cpp  -o build/SistemaBancario.o
Extrato:
	$(CC) $(CFLAGS) -c src/Extrato.cpp  -o build/Extrato.o
Saldo:
	$(CC) $(CFLAGS) -c src/Saldo.cpp -o build/Saldo.o
Desenvolvedor:
	$(CC) $(CFLAGS) -c src/Desenvolvedor.cpp -o build/Desenvolvedor.o
# Modifique a funcao main
build: test run
test: testeFuncionario testeFilme testeSala testeCliente testeSessao testeCompra testeServico

run:Extrato Saldo Usuario  Desenvolvedor SistemaBancario
	$(CC) $(CFLAGS) build/Extrato.o build/Saldo.o build/Usuario.o build/Desenvolvedor.o build/SistemaBancario.o src/main.cpp -o $(TARGET)
	
#	@clear
clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
