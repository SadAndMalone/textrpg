#pragma once

#include <vector>
#include <list>
#include <iterator>
#include "room.h"

template <class T>
struct Node{
	int id;
	T data;
};

template <class T> 
class Graph {
	public:
		Graph(int V=0);
		Node<T> addVertex(T newData);
		int addEdge(T source, T dest);
		void printAdjacent(Node<T> current);
		std::vector< Node<T> > vertices;
	private:
		int V;
		std::vector< std::list< Node<T> > > adjList;
};

template <class T>
Graph<T>::Graph(int V) {
	adjList = std::vector< std::list< Node<T> > >(V);
}

template <class T>
Node<T> Graph<T>::addVertex(T newData) {
	typename std::vector< Node<T> >::iterator it;
	for(it = vertices.begin(); it != vertices.end(); it++) {
		if(it->data == newData)
			return *it;
	}

	Node<T> newVertex;
	newVertex.data = newData;
	newVertex.id = V;
	++V;

	vertices.push_back(newVertex);

	return newVertex;
}

template <class T>
int Graph<T>::addEdge(T source, T dest) {
	//Get source and dest nodes, creating them if they don't exist
	Node<T> sourceNode = addVertex(source);
	Node<T> destNode = addVertex(dest);

	adjList[sourceNode.id].push_back(destNode);
	adjList[destNode.id].push_back(sourceNode);

	return sourceNode.id;
}

template <class T>
void Graph<T>::printAdjacent(Node<T> current) {
	typename std::list< Node<T> >::iterator listIt;

	for (listIt = adjList[current.id].begin(); listIt != adjList[current.id].end(); listIt++) {
		listIt->data->displayRoom();
	}
}
