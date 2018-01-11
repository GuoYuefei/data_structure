/*
 * Edge.h
 * 作为无向图的边的接口
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

class Edge {

private:
	uint nextNode;					//下一个结点的id
	Cost cost;

public:
	Edge():nextNode(NONE),cost(NONE){};
	Edge(uint nodeId,Cost cost):nextNode(nodeId),cost(cost){}
	Edge(uint nodeId):nextNode(nodeId),cost(NONE){};
	Edge(const Edge& e):nextNode(e.getNextNode()),cost(e.getCost()){

	}
	virtual ~Edge(){};

	/**
	 * 当nextNode相等就认为相等了，其实还有一个条件，需要在同一个node中比较
	 * edge还有一个隐藏的结点就是那个node
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
//	virtual void setNextNode(int id){
////		this->nextNode = new Node(id);   这样的写法明显错误，应该通过id去找Node的集合边集
//										//故本函数应该写在Node中，而且可以不写，就是找边加set的过程组成
//	}

};

#endif /* EDGE_H_ */
