CC = g++
CC_FLAGS = -Wall


all: clean test_single_linked_list test

%: %.cpp
	$(CC) $(CC_FLAGS) $*.cpp -o $*

clean:
	rm -f test_single_linked_list

test:
	./test_single_linked_list
