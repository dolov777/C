CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
ifeq ($(MAKECMDGOALS), gcov_report)
 CFLAGS += --coverage
endif
TEST_DIR = tests

CSRC = $(wildcard s21*.c)
TEST_CSRC = $(wildcard $(TEST_DIR)/*.c)
OFILES=$(patsubst %.c, %.o, $(CFILES))

COBJ = $(CSRC:.c=.o)
LIBNAME = s21_string.a

.PHONY: all clean test gcov_report

all: $(LIBNAME) s21_string.a

s21_string.a: $(CSRC)
	$(CC) -c $(CFLAGS) $(CSRC)
	ar rcs $@ $(OFILES)
	ranlib $@

test: $(LIBNAME) 
	$(CC) $(CFLAGS) $(TEST_CSRC) -L . $(LIBNAME) -o ./$(TEST_DIR)/run_tests -lcheck -lsubunit -lm
	./$(TEST_DIR)/run_tests 
	
check:
	clang-format -style='{BasedOnStyle: Google}' -n *.c */*.c
	clang-format -style='{BasedOnStyle: Google}' -n *.h */*.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h	

clang:
	clang-format -style='{BasedOnStyle: Google}' -i *.c */*.c
	clang-format -style='{BasedOnStyle: Google}' -i *.h */*.h

$(LIBNAME): $(COBJ)
	ar rcs $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

gcov_report: $(LIBNAME)
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage $(TEST_CSRC) -L . $(LIBNAME) -o $(TEST_DIR)/run_tests -lgcov -lcheck -lsubunit -lm
	./$(TEST_DIR)/run_tests
	lcov -t "s21_test" -o $(TEST_DIR)/s21_test.info -c -d .
	genhtml -o report $(TEST_DIR)/s21_test.info

clean:
	rm -rf $(COBJ) $(LIBNAME) /$(TEST_DIR)/run_tests $(TEST_DIR)/s21_test.info ./report/ 
	rm -rf $(TEST_DIR)/run_tests $(TEST_DIR)/*gcda $(TEST_DIR)/*gcno *gcda *gcno