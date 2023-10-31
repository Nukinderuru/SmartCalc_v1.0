CC = gcc -g

FLAGS = -std=c11 -Wall -Werror -Wextra
TEST_FLAGS = -lcheck -lpthread -pthread -lm
TARGET = SmartCalc

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS += -lsubunit -lgcov -lrt
endif

all: test

install: install_calc move_calc open_calc

install_calc:
	mkdir build
	cd ./build/ && qmake ../SmartCalc/SmartCalc.pro && make && mv SmartCalc SmartCalc.app
	
move_calc:
	mkdir $(HOME)/SmartCalc
	cp -rf ./build $(HOME)/SmartCalc/
	@-rm -rf ./build/

open_calc:
	chmod 777 $(HOME)/SmartCalc/build/SmartCalc.app
	$(HOME)/SmartCalc/build/SmartCalc.app

uninstall:
	@-rm -rf $(HOME)/SmartCalc/

dvi: $(TARGET).pdf
	open $(TARGET).pdf

$(TARGET).pdf: info/$(TARGET).tex
	texi2pdf -q -c info/$(TARGET).tex -o $(TARGET).pdf

dist:
	mkdir build
	cd ./build/ && qmake ../SmartCalc/SmartCalc.pro && make && mv SmartCalc SmartCalc.app
	tar cvzf dist_smartcalc_qt.tgz ./build/
	@-rm -rf ./build/

test: ./SmartCalc/*.c ./SmartCalc/smart_calc.h ./tests/*.c ./tests/tests.h
	$(CC) $(FLAGS) ./SmartCalc/*.c ./tests/*.c -o ./tests/test.out $(TEST_FLAGS)
	./tests/test.out

gcov_report: clean
	$(CC) $(FLAGS) ./SmartCalc/*.c ./SmartCalc/smart_calc.h ./tests/*.c ./tests/tests.h --coverage -o ./tests/test.out $(TEST_FLAGS)
	./tests/test.out
	gcovr -r . -s --html --html-details -o ./coverage_report.html
	open ./coverage_report.html

style_fix:
	clang-format -style=Google -i ./SmartCalc/*.c ./SmartCalc/*.h ./SmartCalc/*.cpp
	clang-format -style=Google -i ./tests/*.c ./tests/*.h

style_check:
	clang-format -style=Google -n ./SmartCalc/*.c ./SmartCalc/*.h ./SmartCalc/*.cpp
	clang-format -style=Google -n ./tests/*.c ./tests/*.h

leaks:
ifeq ($(shell uname -s), Linux)
	valgrind --leak-check=yes  ./tests/test.out
else
	leaks --atExit -- ./tests/test.out
endif

clean:
	rm -f *.gcda *.gcov *.o *.a *.gcno coverage_report*
	rm ./tests/test.out