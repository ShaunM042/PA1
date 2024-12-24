all: fourth

fourth: fourth.c
	gcc -g -Wall -Werror -fsanitize=address -std=c11 -o fourth fourth.c

clean:
	rm -f fourth