CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -lm -lcheck -lsubunit

HEADERS = s21_decimal.h $(wildcard ./HEADERS/*.c) 
SOURCES_ALL = $(wildcard ./helpers/*.c) 	\
	$(wildcard ./arithmetics/*.c)			\
	$(wildcard ./comparision/*.c)			\
	$(wildcard ./convertors/*.c)			\
	$(wildcard ./comparison/*.c)			\
	$(wildcard ./other/*.c)

OBJ_LIBRARY := $(patsubst %.c, %.o, $(SOURCES_ALL))

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@

all: s21_decimal.a

s21_decimal.a: $(OBJ_LIBRARY) $(HEADERS)
	ar rcs s21_decimal.a $(OBJ_LIBRARY)
	ranlib s21_decimal.a
	rm -rf ./*/*.o

test: s21_decimal.a TESTS/SUITE_main.c
	gcc $(CFLAGS) TESTS/SUITE_main.c s21_decimal.a -o test.out $(LDFLAGS)
	./test.out

gcov_report: CFLAGS += $(GCOVFLAGS)
gcov_report: s21_decimal_gcov.a TESTS/SUITE_main.c
	gcc $(CFLAGS) TESTS/SUITE_main.c $(OBJ_LIBRARY) -o report.out $(LDFLAGS)
	./report.out
	gcov -f $(SOURCES_ALL)
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	open ./report/index-sort-f.html

s21_decimal_gcov.a: $(OBJ_LIBRARY)
	gcc $(CFLAGS) -c $(SOURCES_ALL)
	ar rcs s21_decimal_gcov.a $(OBJ_LIBRARY)
	ranlib s21_decimal_gcov.a

personal: s21_decimal.a TESTS/personal.c
	gcc $(CFLAGS) TESTS/personal.c s21_decimal.a -o test.out $(LDFLAGS)
	./test.out

check:
	clang-format -style=Google -n ./*/*.c

rebuild: clean all

clean:
	find . -name '*.o' -delete
	find . -name '*.a' -delete
	find . -name '*.gcno' -delete
	find . -name '*.gcda' -delete
	find . -name '*.info' -delete
	find . -name '*.out' -delete
	find . -name '*.gcov' -delete
	rm -rf ./report