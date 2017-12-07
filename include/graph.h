#include <iostream>

template <class T>
struct Node {
	T current;
	int id;
	struct Node<T> *adj;
};

template <class T>
struct AdjList {
	 struct Node<T> *head;
};

template <class T>
class Graph {
	public:
		Graph(int V);
		Graph(Graph<T>& copy);
		Node<T> *newListNode(T data, int id);
		void addEdge(T src, int srcid, T dest, int destid);
		Graph<T> resize();
		void printGraph();
	private:
		int V;
		int size = 0;
		struct AdjList<T> *array;
		Graph<T> operator=(Graph<T> *a) {
			this->size = a->size;
			copy(a->array[0], a->array[0] = a->size, this->array[0]);
		}
};


/*
 *
 *
 *
 * Implementation
 *
 *
 *
 */

template <class T>
Graph<T>::Graph(int V) {
	this->V = V;
	array = new AdjList<T>[V];
	for(int i=0; i<V; ++i) {
		array[i].head = NULL;
	}
}

template <class T>
Graph<T>::Graph(Graph<T>& copy) {
	this->size = copy.size;
	for(int i=0; i<V; ++i) {
		this->array[i] = copy.array[i];
	}
	delete this;
}

template <class T>
Node<T>* Graph<T>::newListNode(T data, int id) {
	Node<T> *newNode = new Node<T>;
	newNode->current = data;
	newNode->id = id;
	newNode->adj = NULL;
	++size;
	return newNode;
}

template <class T>
void Graph<T>::addEdge(T src, int srcid, T dest, int destid) {
		//Create dest node
		Node<T> *newNode= newListNode(dest, destid);

		newNode->adj = array[srcid].head;
		array[srcid].head = newNode;

		//Create src node
		newNode = newListNode(src, srcid);
		
		newNode->adj = array[destid].head;
		array[destid].head = newNode;
}

template <class T>
void Graph<T>::printGraph() {
	for(int i=0; i<V; ++i) {
		Node<T> *pCrawl = array[i].head;
		std::cout << pCrawl->current;
	}
	for(int v=0; v<V; ++v) {
		Node<T> *pCrawl = array[v].head;
		std::cout << "\n Adjacency List of vertex " << v << "\n head";
		while(pCrawl) {
			std::cout << "-> " << pCrawl->current;
			pCrawl = pCrawl->adj;
		}
		std::cout << std::endl;
	}
}

template <class T>
Graph<T> Graph<T>::resize() {
	Graph<T> newGraph(V+5);
	newGraph = *this;
	return newGraph;
}
