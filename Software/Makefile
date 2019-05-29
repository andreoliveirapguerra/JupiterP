################# MakeFile ####################
## main = cadastro
## teste = estrutura
CC=gcc
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
EXEC=cadastro
all:$(EXEC)
	@echo"Compiling Cadastro"
cadastro: $(OBJ)
	$(CC) -o $@ $^
$.o: $.c
	$(CC) -o $@ -c $<
main.o: main.c estrutura.h
	$(CC) -o $@ -c $<
.PHONY: clean mrproper
clean:
	rm -rf *.o
	@echo "done Compiling code"
mrproper: clean
	rm -rf $(EXEC)
# estrutura.o: estrutura.c
# 	gcc -o estrutura.o -c estrutura.c
# cadastro.o: cadastro.c estrutura.h
# 	gcc -o cadastro.o -c cadastro.c 
# clean:
# 	rm -rf *.o
# mrproper: clean
# 	rm -rf cadastro
