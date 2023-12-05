CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -O3 -std=c++11 -I include/

all: main

#vaga:

Usuario:
	@mkdir -p build
	$(CC) $(CFLAGS) -c src/Usuario.cpp -o build/Usuario.o
SistemaBancario:
	$(CC) $(CFLAGS) -c src/SistemaBancario.cpp  -o build/SistemaBancario.o
Extrato:
	$(CC) $(CFLAGS) -c src/Extrato.cpp  -o build/Extrato.o
Saldo:
	$(CC) $(CFLAGS) -c src/Saldo.cpp -o build/Saldo.otr
Transferencia:
	$(CC) $(CFLAGS) -c src/Transferencia.cpp -o build/Transferencia.o
Emprestimo:
	$(CC) $(CFLAGS) -c src/Emprestimo.cpp -o build/Emprestimo.o
Desenvolvedor:
	$(CC) $(CFLAGS) -c src/Desenvolvedor.cpp -o build/Desenvolvedor.o
# Modifique a funcao main


main:Extrato Saldo Usuario Transferencia Emprestimo Desenvolvedor SistemaBancario
	$(CC) $(CFLAGS) build/Extrato.o build/Saldo.o build/Usuario.o build/Emprestimo.o build/Transferencia.o build/Desenvolvedor.o build/SistemaBancario.o src/main.cpp -o $(TARGET)
	
#	@clear
clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
