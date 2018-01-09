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

bool Node::addEdge(Edge& e){
	for(unsigned int i=0;i<adjEdges.size();i++){		//先要判定有无此邻边，有则不添加，返回false
		if(adjEdges[i]==e){
			return false;
		}
	}
	adjEdges.push_back(e);
	return true;
}

bool Node::addEdge(int a,Cost& cost){
	Edge e = *new Edge(a,cost);
	return addEdge(e);
}

bool Node::removeEdge(Edge& e){
	for(unsigned int i=0;i<adjEdges.size();i++){		//先要判定有无此邻边，有则删除，返回true
		if(adjEdges[i]==e){
			adjEdges.erase(adjEdges.begin()+i);
			return true;
		}
	}
	return false;						//未发现此边，返回false
}

bool Node::removeEdge(int a){
	Edge e = *new Edge(a);				//此时cost虽然会初始化默认，但是接下来的==运算符并不会比较cost
	return removeEdge(e);
}










