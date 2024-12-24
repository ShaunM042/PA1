all: seventh

seventh: seventh.c
	gcc -g -Wall -Werror -fsanitize=address -std=c11 -o seventh seventh.c

clean:
	rm -f seventh