target = BST_O

complie: main.cpp
	g++ main.cpp -o $(target)
run: 
	./$(target) 5 2 1 3 8 7 9
