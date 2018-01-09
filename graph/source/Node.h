/*
 * Node.h
 *
 *  Created on: 2018年1月8日
 *      Author: Administrator
 */

#ifndef NODE_H_
#define NODE_H_
#include "Edge.h"
#include <vector>

using namespace std;
/**
 * 可以作为基类使用
 * 在h中直接写的都是inline函数，小函数可以用inline增加运行速度
 */
class Node {
private:
	const int id;						//node的唯一识别符号，我这使用int编号。
	int iterEdge;
protected:
	vector<Edge> adjEdges;			//每个node都有一个临边数组,子类可以访问该属性
public:
	//没有默认构造、复制构造，必须使用该构造
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
