all: fifth

fifth: fifth.c
	gcc -g -Wall -Werror -fsanitize=address -std=c11 -o fifth fifth.c

clean:
	rm -f fifth
