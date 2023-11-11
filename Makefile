CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -pedantic -std=c99

EXE = bin
OBJS = bin/obj
# VPATH = bin/obj # Opción que se puede usar para distintos archivos ubicados en el 
# mismo directorio, como las interfaces. Esto tiene sentido únicamente para los requisitos.

./bin/matrices: main.c $(OBJS)/cuerpo.o $(OBJS)/matriz.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS)/cuerpo.o: cuerpos/reales.c interfaces/cuerpo.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS)/matriz.o: espacios-vectoriales/matriz.c interfaces/matriz.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r $(OBJS)/*
	rm bin/matrices
