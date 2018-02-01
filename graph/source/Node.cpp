/*
 * Node.cpp
 *
 *  Created on: 2018��1��8��
 *      Author: Administrator
 */
#include "Node.h"


Node::~Node(){
	delete &adjEdges;
}

bool Node::addEdge(Edge e){
	for(unsigned int i=0;i<adjEdges.size();i++){
		if(adjEdges[i]==e){
			return false;
		}
	}
	adjEdges.push_back(e);
	return true;
}

bool Node::addEdge(unsigned int a,Cost cost){
	Edge e = *new Edge(a,cost);
	return addEdge(e);
}

bool Node::removeEdge(const Edge& e){
	for(unsigned int i=0;i<adjEdges.size();i++){
		if(adjEdges[i]==e){
			adjEdges.erase(adjEdges.begin()+i);
			return true;
		}
	}
	return false;
}

bool Node::removeEdge(unsigned int id){
	Edge e = Edge(id);
	return removeEdge(e);
}

void Node::setEdgeCost(Edge e){
	for(unsigned int i=0;i<adjEdges.size();i++){
		if(adjEdges[i]==e){
			Edge* temp = &adjEdges[i];
			delete temp;
			adjEdges[i] = e;
			return;
		}
	}
	adjEdges.push_back(e);
}

void Node::setEdgeCost(unsigned int a,Cost& cost){
	Edge e = *new Edge(a,cost);
	setEdgeCost(e);
}










