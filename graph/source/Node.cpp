/*
 * Node.cpp
 *
 *  Created on: 2018年1月8日
 *      Author: Administrator
 */
#include "Node.h"


Node::~Node(){
	delete &adjEdges;
}

//在graph中调用时还应检查e是否合法，e中出现的结点图中是否已经存在
bool Node::addEdge(Edge e){
	for(unsigned int i=0;i<adjEdges.size();i++){		//先要判定有无此邻边，有则不添加，返回false
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
	for(unsigned int i=0;i<adjEdges.size();i++){		//先要判定有无此邻边，有则删除，返回true
		if(adjEdges[i]==e){
			adjEdges.erase(adjEdges.begin()+i);
			return true;
		}
	}
	return false;						//未发现此边，返回false
}

bool Node::removeEdge(unsigned int id){
	Edge e = Edge(id);				//此时cost虽然会初始化默认，但是接下来的==运算符并不会比较cost
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










