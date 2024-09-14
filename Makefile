all:
	g++ inter/main.cpp tree/*.cpp tree/avl-tree/*.cpp -I tree/avl-tree/*.hpp tree/*.hpp -o avl-tree
