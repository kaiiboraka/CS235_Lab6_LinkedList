all:
	g++ -o linked_list main.cpp -g
test: all
	valgrind --leak-check=full -s ./linked_list