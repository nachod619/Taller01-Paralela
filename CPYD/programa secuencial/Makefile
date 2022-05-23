#variables
CC=g++
obj= secuencial.cpp
LIB=
CPPFLAGS=-Wall -g3
MKDIR=mkdir -p

#folders: 
#	@$(MKDIR) build dist

all: ejecutar

ejecutar: $(obj)
	@$(CC) $(obj) -o ejecutar $(LIB)

%.o: %.c
	@$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	@rm ejecutar 