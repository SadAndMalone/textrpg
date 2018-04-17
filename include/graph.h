#pragma once

#include <iostream>
#include "room.h"

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
		int size(){return V;}
		void printGraph();
	private:
		int V;
		struct AdjList<T> *array;
		Graph<T> operator=(Graph<T> *a) {
			copy(a->array[0], a->array[0] = a->V, this->array[0]);
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
Graph<T>::Graph(int V) : V(V){
	array = new AdjList<T>[V];
	for(int i=0; i<V; ++i) {
		array[i].head = NULL;
	}
}

template <class T>
Graph<T>::Graph(Graph<T>& copy) {
	copy.V = this->V; 
	for(int i=0; i<V; ++i) {
		copy.array[i] = this->array[i];
	}
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
		Node<T> *newNode = newListNode(src, srcid);
		Node<T> *newNode2= newListNode(dest, destid);
		
		array[destid].head = newNode2;
		array[srcid].head = newNode;
		newNode->adj = array[destid].head;
		newNode2->adj = array[srcid].head;
}

template <class T>
void Graph<T>::printGraph() {
	Node<T> *pCrawl = array[0].head;
	while(pCrawl) {
		pCrawl->current->displayRoom();
		pCrawl = pCrawl->adj;
	}
}
