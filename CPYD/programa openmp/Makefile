#variables
CC=g++
obj= secuencial.cpp
LIB=-fopenmp
CPPFLAGS=-Wall -g3
MKDIR=mkdir -p

#folders:
#	@$(MKDIR) build dist

all: ejecutar

ejecutar: $(obj)
	@$(CC) $(obj) -o ejecutar

%.o: %.c
	@$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	@rm ejecutar