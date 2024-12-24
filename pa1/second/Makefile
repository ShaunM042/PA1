all: second

second: second.c
	gcc -g -Wall -Werror -fsanitize=address -std=c11 -o second second.c

clean:
	rm -f second