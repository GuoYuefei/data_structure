/*
 * Node.h
 *
 *  Created on: 2018年1月8日
 *      Author: Administrator
 */

#ifndef NODE_H_
#define NODE_H_
#define NONE (-1)

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
	unsigned int id;				//node's unqiue id
	unsigned int iterEdge;
protected:
	vector<Edge> adjEdges;		//every node have an array that formed by all adjacent edges
public:
	/**
	 * no default constructor
	 * user must use this constructor
	 */
	Node(uint id):id(id),iterEdge(0){
		adjEdges.clear();
	};

	/**
	 * copy constructor
	 */
	Node(const Node& node):id(node.getId()),iterEdge(0){
		vector<Edge> ve= node.getadjEdges();
		for(uint i=0;i<ve.size();i++){
			this->adjEdges[i] = ve[i];
		}
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
	unsigned int getId() const{
		return id;
	}

	bool existEdge(uint nextNodeId){
		for(uint i=0;i<adjEdges.size();i++){
			if(adjEdges[i].getNextNode()==nextNodeId){
				return true;
			}
		}
		return false;
	}

	/**
	 * 仅检查e的nextNode属性，cost不管
	 */
	bool existEdge(Edge e){
		return existEdge(e.getNextNode());
	}

	uint edgePos(Edge e){
		for(uint i=0;i<adjEdges.size();i++){
			if(adjEdges[i]==e){
				return i;
			}
		}
		return NONE;
	}

	/**
	 * get the private attribute
	 * 给不给引用是个问题，给了引用user灵活，但是不安全，暂且不给引用
	 */
	virtual vector<Edge> getadjEdges() const{
		return adjEdges;
	};


	/**
	 * 根据nextNodeId的值找到这个顶点的邻接边，并返回该边的一个副本
	 * 在使用这个函数前可以先用existEdge函数检测是否存在该边
	 * 若不存在会返回一个Edge（NONE）的对象
	 */
	virtual Edge getByNextId(uint nextNodeId){
		for(uint i=0;i<adjEdges.size();i++){
			if(adjEdges[i].getNextNode()==nextNodeId){
				return adjEdges[i];
			}
		}
		return NONE;			//其实会返回Edge（NONE）这个对象
	}

	/**
	 * there are three functions to deal the iterEdge,
	 * then user can control the iterator
	 */
	bool setIterEdge(unsigned int iter){
		if(iter<adjEdges.size()&&iter>=0){
			iterEdge = iter;
			return true;
		}
		return false;
	}

	unsigned int getIterEdge() const{
		return iterEdge;
	}

	void resetIter(){
		iterEdge = 0;
	}



	/**
	 * add an edge to this node.adjEdge
	 * if the edge didn't add to this node ,return false to let user know
	 */
	virtual bool addEdge(Edge e);

	/**
	 * provide two parameters which are Int and those two parameters can define an Edge
	 * then this function calls the function which is declared 'bool addEdge(Edge e);'
	 */
	virtual bool addEdge(unsigned int id,Cost cost);

	/**
	 * remove an edge from this node.adjEdge
	 * if there is not have the edge,the function will return false
	 */
	virtual bool removeEdge(const Edge& e);

	/**
	 * provide one parameter which is Int and that parameter can define an Edge
	 * then this function calls the function which is declared 'bool removeEdge(Edge e)'
	 */
	virtual bool removeEdge(unsigned int id);

	/**
	 * 如果node中有这个边，但是边的花费不同，那么就替换这条边，如果没有则添加这条e边
	 * 这里形参不用引用，这样就可以让下面的函数实现时直接调用
	 */
	virtual void setEdgeCost(Edge e);

	/**
	 * a是nextNode的值，和cost一起定义了一条边，
	 * 这条边如果存在就覆盖它，如果不存在就添加它
	 */
	virtual void setEdgeCost(unsigned int a,Cost& cost);

	/**
	 * get Node'id what current iterEdge point to
	 * the Node should been found in the graph,its class Graph's responsibility
	 */
	virtual int firstNeighbor(){
		return adjEdges[iterEdge].getNextNode();
	}

	/**
	 * get Node's what next iterEdge point to and the iterEdge will plus 1
	 */
	virtual int nextNeighbor(){
		return adjEdges[++iterEdge].getNextNode();
	}

};

#endif /* NODE_H_ */
