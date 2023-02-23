parametrosCompilacao= -lm -g
nomePrograma=trab2

all: $(nomePrograma)

$(nomePrograma): main.o
	gcc -o $(nomePrograma) main.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)