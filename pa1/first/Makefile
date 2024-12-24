all: first

first: first.c
	#gcc line should be indented with a tab
	gcc -g -Wall -Werror -fsanitize=address -std=c11 -o first first.c

clean:
	#rm line should also be indented with a tab
	rm -f first