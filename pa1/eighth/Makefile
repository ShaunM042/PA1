all: eighth

eighth: eighth.c
	gcc -g -Wall -Werror -fsanitize=address -std=c11 -o eighth eighth.c

clean:
	rm -f eighth