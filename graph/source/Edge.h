/*
 * Edge.h
 * ��Ϊ����ͼ�ıߵĽӿ�
 *
 *  Created on: 2018��1��8��
 *      Author: Administrator
 */

#ifndef EDGE_H_
#define EDGE_H_
#define uint unsigned int
//������Edge������Node�࣬��Ȼ�����ѭ������
//#include "Node.h"
#include "Cost.h"

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
	 * ��nextNode��Ⱦ���Ϊ����ˣ���ʵ����һ����������Ҫ��ͬһ��node�бȽ�
	 * edge����һ�����صĽ������Ǹ�node
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
////		this->nextNode = new Node(id);   ������д�����Դ���Ӧ��ͨ��idȥ��Node�ļ��ϱ߼�
//										//�ʱ�����Ӧ��д��Node�У����ҿ��Բ�д�������ұ߼�set�Ĺ������
//	}

};

#endif /* EDGE_H_ */
