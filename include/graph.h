#pragma once

#include <iostream>
#include <sstream>

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
		int size(){return V;}
		void printGraph();
	private:
		int V;
		struct AdjList<T> *array;
		Graph<T> operator=(Graph<T> *a) {
			copy(a->array[0], a->array[0] = a->V, this->array[0]);
		}
		std::ostringstream output;
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
Graph<T>::Graph(int V) : V(V){
	array = new AdjList<T>[V];
	for(int i=0; i<V; ++i) {
		array[i].head = NULL;
	}
}

template <class T>
Graph<T>::Graph(Graph<T>& copy) {
	this->V = copy.V;
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
	for(int v=0; v<this->size(); ++v) {
		Node<T> *pCrawl = array[v].head;
		std::cout << "\n Adjacency List of vertex " << v << "\n head";
		while(pCrawl) {
			output << pCrawl->current;
			pCrawl = pCrawl->adj;
		}
	}
}
/*
template <class T>
Graph<T> Graph<T>::resize() {
	Graph<T> newGraph(V+5);
	newGraph = *this;
	return newGraph;
}
*/
