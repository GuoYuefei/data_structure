/*
 * Edge.h
 * 作为无向图的边的接口
 *
 *  Created on: 2018年1月8日
 *      Author: Administrator
 */

#ifndef EDGE_H_
#define EDGE_H_

#include "Node.h"
#include "Cost.h"

class Edge {

private:
	Cost cost;
	Node nextNode;					//下一个结点

public:
	Edge():cost(-1),nextNode(-1){};
	Edge(Cost cost,int nextNode):cost(cost),nextNode(nextNode){};
	virtual ~Edge(){};

	/**
	 * all get and set functions
	 */
	virtual Cost getCost(){
		return cost;
	}
	virtual void setCost(Cost cost){
		this->cost = cost;
	}
	virtual Node getNextNode(){
		return nextNode;
	}
	virtual void setNextNode(Node nextNode){
		this->nextNode = nextNode;
	}
	virtual void setNextNode(int id){

	}

};

#endif /* EDGE_H_ */
