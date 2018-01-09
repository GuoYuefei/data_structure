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
//#include "Graph.h"

using namespace std;
/**
 * 可以作为基类使用
 * 在h中直接写的都是inline函数，小函数可以用inline增加运行速度
 */
class Node {
private:
	int id;				//node's unqiue id
	int iterEdge;
protected:
	vector<Edge> adjEdges;		//every node have an array that formed by all adjacent edges
public:
	/**
	 * no default constructor
	 * user must use this constructor
	 */
	Node(int id):id(id),iterEdge(0){
		adjEdges.clear();
	};

	/**
	 * copy constructor
	 */
	Node(const Node& node):id(node.getId()),iterEdge(0){
		this->adjEdges = node.getadjEdges();
	}

//	Node():id(++(Graph::maxId)),iterEdge(0){};

	/**
	 * destructor
	 */
	virtual ~Node();

	/**
	 * we think if two nodes have same id,they is equal
	 */
	bool operator==(const Node& that) const{
		return this->id == that.id;
	}



	/*******************************Base Operate***************************************/

	/**
	 * get the node's unique id
	 */
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



	/**
	 * add an edge to this node.adjEdge
	 * if the edge didn't add this node ,return false to let user know
	 */
	bool addEdge(Edge& e);

	/**
	 * provide two parameters which are Int and those two parameters can define an Edge
	 * then this function calls the function which is declared 'bool addEdge(Edge e);'
	 */
	bool addEdge(int a,Cost& cost);

	/**
	 * remove an edge from this node.adjEdge
	 * if there is not have the edge,the function will return false
	 */
	bool removeEdge(Edge& e);

	/**
	 * provide one parameter which is Int and that parameter can define an Edge
	 * then this function calls the function which is declared 'bool removeEdge(Edge e)'
	 */
	bool removeEdge(int a);

	/**
	 * get Node'id what current iterEdge point to
	 * the Node should been found in the graph,its class Graph's responsibility
	 */
	int firstNeighbor(){
		return adjEdges[iterEdge].getNextNode();
	}

	/**
	 * get Node's what next iterEdge point to and the iterEdge will plus 1
	 */
	int nextNeighbor(){
		return adjEdges[++iterEdge].getNextNode();
	}

};

#endif /* NODE_H_ */
