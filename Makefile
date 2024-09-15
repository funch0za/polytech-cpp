BIN:=avl-tree

CXX:=g++ 
CXXFLAGS:=-g -std=c++17
#CXXFLAGS:=-g -std=c++17

all: clean build_interactive
	$(CXX) *.o -o $(BIN) $(CXXFLAGS)
	rm -f *.o

build_node:
	$(CXX) -c tree/node.cpp $(CXXFLAGS)

build_tree: build_node
	$(CXX) -c tree/tree.cpp $(CXXFLAGS)

build_interactive: build_tree
	$(CXX) -c interactive/main.cpp $(CXXFLAGS)
 
clean:
	rm -f $(BIN) *.o
