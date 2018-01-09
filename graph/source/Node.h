/*
 * Node.h
 *
 *  Created on: 2018��1��8��
 *      Author: Administrator
 */

#ifndef NODE_H_
#define NODE_H_
#include "Edge.h"
#include <vector>

using namespace std;
/**
 * ������Ϊ����ʹ��
 * ��h��ֱ��д�Ķ���inline������С����������inline���������ٶ�
 */
class Node {
private:
	const int id;						//node��Ψһʶ����ţ�����ʹ��int��š�
	int iterEdge;
protected:
	vector<Edge> adjEdges;			//ÿ��node����һ���ٱ�����,������Է��ʸ�����
public:
	//û��Ĭ�Ϲ��졢���ƹ��죬����ʹ�øù���
	Node(int id):id(id),iterEdge(0){};
	virtual ~Node(){};

	int getId() const{
		return id;
	}

	/**
	 * get the private attribute
	 */
	vector<Edge> getadjEdges() const{
		return adjEdges;
	};

	/**
	 * there are three functions to deal the iterEdge,
	 * then user can control the iterator
	 */
	void setIterEdge(int iter){
		iterEdge = iter;
	}

	int getIterEdge() const{
		return iterEdge;
	}

	void resetIter(){
		iterEdge = 0;
	}





	/****************************not inline******************************************/

	/**
	 * add an edge to this node.adjEdge
	 * if the edge didn't add this node ,return false to let user know
	 */
	bool addEdge(Edge e);

	/**
	 * provide two parameters which are Int and those two parameters can define an Edge
	 * then this function calls the function which is declared 'bool addEdge(Edge e);'
	 */
	bool addEdge(int a,int b);

	/**
	 * remove an edge from this node.adjEdge
	 * if there is not have the edge,the function will return false
	 */
	bool removeEdge(Edge e);

	/**
	 * provide two parameters which are Int and those two parameters can define an Edge
	 * then this function calls the function which is declared 'bool addEdge(Edge e)'
	 */
	bool removeEdge(int a,int b);

	/**
	 * get Node what current iterEdge point to
	 */
	Node thisNeighbor(){
		return adjEdges[iterEdge].getNextNode();
	}

	/**
	 * get Node what next iterEdge point to and the iterEdge will plus 1
	 */
	Node nextNeighbor(){
		return adjEdges[++iterEdge].getNextNode();
	}


};

#endif /* NODE_H_ */
