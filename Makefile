# Makefile

FILE = main.c
FILE2 = 2021.c

.PHONY: clean

all: longest year ever

longest: 
	@clang++ loading.cpp -o forever
	@./forever
year:
	@gcc $(FILE) 
	@./a.out
ever:
	@clear

2021: clean
	@gcc $(FILE2) 
	@./a.out

work:
	@echo ""
	@echo ""
	@echo "			WE WISH YOU ALL A BETTER NEW YEAR "
	@echo ""
	@echo ""

clean:
	@rm -rf a.out 2021 forever
