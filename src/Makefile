CC = gcc -std=c++17 -g
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I includes
GCOV_LIBS=--coverage
RM+=-r
PATH_GENERAL = ./model
PATH_TESTS = ./model/tests

TEST = $(PATH_TESTS)/test*
SRC = $(PATH_GENERAL)/calculate.cc $(PATH_GENERAL)/parser.cc $(PATH_GENERAL)/validation.cc
VIEWCONTROLLER = ./controller/*.cc ./controller/*.h ./view/*.cpp ./view/*.h

HEADERS = $(PATH_GENERAL)/*.h
OBJ = $(SRC:.cc=.o)
LIBA = smart_calc_v2.a
EXE = smart_calc_v2
ARCHIVE_DIR = smart_calc_v2


OS = $(shell uname)

ifeq ($(OS), Darwin)
	LIBFLAGS = -lgtest -lstdc++ -lgtest_main
else
	LIBFLAGS = -lstdc++ `pkg-config --cflags --libs gtest  --libs gtest_main`
endif

all: install

build: clean
	mkdir build
	cd ./build/ && qmake ../view && make

install: build
	cd ./build/ && make clean

uninstall:
	rm -rf build/

dist:
	rm -rf $(ARCHIVE_DIR)
	mkdir $(ARCHIVE_DIR)
	mkdir $(ARCHIVE_DIR)/src
	cp -r ./view ./controller ./model ./tests dvi.html Makefile $(ARCHIVE_DIR)/src/
	tar cvzf $(ARCHIVE_DIR).tgz $(ARCHIVE_DIR)
	rm -rf $(ARCHIVE_DIR)

dvi:
	open dvi.html

clean:
	@rm -rf *.gcda *.o *.a *.gcno *.tgz *.txt *.info *.dSYM report build smart_calc_v2 coverage $(ARCHIVE_DIR) $(OBJ)

%.o: %.cc
	$(CC) $(CFLAGS) $(LIBFLAGS) -c $^ -o $@

$(LIBA): $(OBJ)
	ar rcs $(LIBA) $^

tests: $(LIBA)
	$(CC) $(CFLAGS) $(TEST) -L. $(LIBFLAGS) $(LIBA) -o $(EXE) -lm
	./$(EXE)

gcov_report: $(LIBA)
	$(CC) $(GCOV_LIBS) $(CFLAGS) $(TEST) $(SRC) -L. $(LIBFLAGS) $(LIBA) -o coverage -lm
	./coverage
	lcov -t "coverage" -c -d  ./ --no-external --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./report/
	open ./report/index.html

check: tests
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(TEST) $(SRC) $(HEADERS)
	clang-format -n $(TEST) $(SRC) $(HEADERS) $(VIEWCONTROLLER)

leaks: tests
ifeq ($(OS), Darwin)
	leaks -atExit -- ./$(EXE)
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./$(EXE)
endif

rebuild: clean uninstall all

reinstall: clean uninstall install

.PHONY:		all install uninstall dist dvi clean check tests gcov_report