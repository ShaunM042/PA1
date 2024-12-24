all: third

third: third.c
	gcc -g -Wall -Werror -fsanitize=address -std=c11 -o third third.c

clean:
	rm -f third