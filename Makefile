BIN:=avl-tree

all: clean build_interactive
	g++ *.o -o $(BIN)
	rm -f *.o

build_node:
	g++ -c tree/avl-tree/avl_tree_node.cpp

build_tree: build_node
	g++ -c tree/avl-tree/avl_tree.cpp

build_interactive: build_tree
	g++ -c interactive/main.cpp

clean:
	rm -f $(BIN) *.o
