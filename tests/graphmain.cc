#include "graph.h"

int main() {
	Graph<int> g(6);

	g.addEdge(0, 0, 1, 1);
	g.addEdge(0, 0, 2, 2);
	g.addEdge(1, 1, 2, 2);
	g.addEdge(2, 2, 4, 4);
	g.addEdge(3, 3, 4, 4);
	g.addEdge(4, 4, 5, 5);
	g.addEdge(0, 0, 5, 5);
	g.addEdge(5, 5, 6, 6);

	g.printGraph();
}
