#variables
CC=mpig++
obj= mpi.cpp
LIB=-lm -lmpi
MKDIR=mkdir -p
CPPFLAGS=-Wall -g3

#folders:
#	@$(MKDIR) build dist

all: ejecutar

ejecutar: $(obj)
	@$(CC) $(obj) -o ejecutar

%.o: %.c
	@$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	@rm ejecutar 
