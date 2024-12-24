all: ninth

ninth: ninth.c
	gcc -g -Wall -Werror -fsanitize=address -std=c11 -o ninth ninth.c

clean:
	rm -f ninth