all:
	gcc main.c stack.c -Wall -Werror -Wextra
	./a.out
check:
	cppcheck --enable=all --force --suppress=missingIncludeSystem *.h *.c

leaks:
	CK_FORK=no leaks --atExit -- ./a.out

lint:
	cp ./linters/CPPLINT.cfg CPPLINT.cfg
	python3 ./linters/cpplint.py --extension=c *.c *.h
	rm CPPLINT.cfg

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./a.out

clean:
	rm -f a.out
