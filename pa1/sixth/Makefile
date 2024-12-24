all: sixth

sixth: sixth.c
	gcc -g -Wall -Werror -fsanitize=address -std=c11 -o sixth sixth.c

clean:
	rm -f sixth