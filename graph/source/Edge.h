/*
 * Edge.h
 * ��Ϊ����ͼ�ıߵĽӿ�
 *
 *  Created on: 2018年1月8日
 *      Author: Administrator
 */

#ifndef EDGE_H_
#define EDGE_H_
#define uint unsigned int
//不能让Edge类依赖Node类，不然会出现循环依赖
//#include "Node.h"
#include "Cost.h"
#define NONE (-1)

class Edge {

private:
	uint nextNode;					//��һ������id
	Cost cost;

public:
	Edge():nextNode(NONE),cost(NONE){};
	Edge(uint nodeId,Cost cost):nextNode(nodeId),cost(cost){}
	Edge(uint nodeId):nextNode(nodeId),cost(NONE){};
	Edge(const Edge& e):nextNode(e.getNextNode()),cost(e.getCost()){

	}
	virtual ~Edge(){};

	/**
	 * 只要认为nextNode是相等，那就认为边相等
	 */
	bool operator==(const Edge& that) const{
		return this->nextNode == that.nextNode;
	}


	/**
	 * all get and set functions
	 */
	virtual Cost getCost() const{
		return cost;
	}
	virtual void setCost(Cost cost){
		this->cost = cost;
	}
	virtual uint getNextNode() const{
		return nextNode;
	}
	virtual void setNextNode(uint nextNode){
		this->nextNode = nextNode;
	}


};

#endif /* EDGE_H_ */
