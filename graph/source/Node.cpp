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

bool Node::addEdge(Edge& e){
	for(unsigned int i=0;i<adjEdges.size();i++){		//��Ҫ�ж����޴��ڱߣ�������ӣ�����false
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
	for(unsigned int i=0;i<adjEdges.size();i++){		//��Ҫ�ж����޴��ڱߣ�����ɾ��������true
		if(adjEdges[i]==e){
			adjEdges.erase(adjEdges.begin()+i);
			return true;
		}
	}
	return false;						//δ���ִ˱ߣ�����false
}

bool Node::removeEdge(int a){
	Edge e = *new Edge(a);				//��ʱcost��Ȼ���ʼ��Ĭ�ϣ����ǽ�������==�����������Ƚ�cost
	return removeEdge(e);
}










