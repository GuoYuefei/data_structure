/*
 * Edge.h
 * ��Ϊ����ͼ�ıߵĽӿ�
 *
 *  Created on: 2018��1��8��
 *      Author: Administrator
 */

#ifndef EDGE_H_
#define EDGE_H_
//������Edge������Node�࣬��Ȼ�����ѭ������
//#include "Node.h"
#include "Cost.h"

class Edge {

private:
	int nextNode;					//��һ������id
	Cost cost;

public:
	Edge():nextNode(-1),cost(-1){};
	Edge(int nodeId,Cost cost):nextNode(nodeId),cost(cost){}
	Edge(int nodeId):nextNode(nodeId),cost(-1){};
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
	virtual Cost getCost(){
		return cost;
	}
	virtual void setCost(Cost cost){
		this->cost = cost;
	}
	virtual int getNextNode(){
		return nextNode;
	}
	virtual void setNextNode(int nextNode){
		this->nextNode = nextNode;
	}
//	virtual void setNextNode(int id){
////		this->nextNode = new Node(id);   ������д�����Դ���Ӧ��ͨ��idȥ��Node�ļ��ϱ߼�
//										//�ʱ�����Ӧ��д��Node�У����ҿ��Բ�д�������ұ߼�set�Ĺ������
//	}

};

#endif /* EDGE_H_ */
