CC = gcc -Wall -Werror -Wextra
GCOV = -fprofile-arcs -ftest-coverage

C_TESTS = testcases.c main.c
C_FILES = common.c stack.c

all: clean test

test:
	gcc -c testcases.c main.c
	gcc -fprofile-arcs -ftest-coverage -o result testcases.c main.c common.c stack.c -lcheck
	./result

clean:
	rm -f *.css *.info *.out *.html *.gcno *.gcda *.o *.a *.tar CPPLINT.cfg
# rm -rf project/*.o project/*.out project/smart_calc.pro.user tests_calc/tests.out
# rm -rf obj_dir docs


# tests:
# 	$(CC) -c $(C_TESTS)
# 	# @mv suite_*.o obj_dir
# 	$(CC) $(GCOV) -o tests/tests.out $(C_TESTS) $(C_FILES) -lcheck
# 	tests/./tests.out
# 	# @mv *.gcno *.gcda main.o obj_dir
