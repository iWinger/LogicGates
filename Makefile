truthtable: truthtable.c
	gcc -g -lm -Wall -Werror -fsanitize=address -o truthtable truthtable.c

clean:
	rm -f truthtable
