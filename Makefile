################# MakeFile ####################
## main = cadastro
CC=gcc
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
EXEC=cadastro
all:$(EXEC)
	@echo "Compiling Cadastro"
cadastro: $(OBJ)
	@$(CC) -g -o $@ $^
	@echo "enter make clean to remove the temp files"
$.o: $.c
	@$(CC) -g -o $@ -c $<
main.o: main.c estrutura.h
	$(CC) -g -o $@ -c $<
	@echo "Done Compiling"
.PHONY: clean mrproper
clean:
	rm -rf *.o
	@echo "Done cleaning obj"
	@clear
mrproper: clean
	rm -rf $(EXEC)
