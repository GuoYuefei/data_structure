/*
 * Graph.cpp
 *
 *  Created on: 2018��1��8��
 *      Author: Administrator
 */

#include "Graph.h"

int Graph::maxId = 0;


Graph::Graph(){
}

Graph::Graph(const vector<Node>& nodes){
	this->nodes = nodes;					//��������һ����node���ϸ�ֵ����
}

Graph::Graph(const Graph& g){
	this->nodes = g.nodes;
}

Graph::~Graph(){

}

bool Graph::existNode(Node node){
	for(unsigned int i=0;i<nodes.size();i++){
		if(nodes[i]==node){
			return true;
		}
	}
	return false;
}

bool Graph::existNode(int a){
	Node node = *new Node(a);
	return existNode(node);
}

bool Graph::existEdge(Node a,Node b){

}








