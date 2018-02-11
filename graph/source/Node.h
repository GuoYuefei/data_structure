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
			this->adjEdges.push_back(ve[i]);
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
	 * �����e��nextNode���ԣ�cost����
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
	 * get the private copy attribute
	 */
	virtual vector<Edge> getadjEdges() const{
		return adjEdges;
	};


	/**
	 * 通过nextid来得到边，若不存在就返回Edge（-1）的边
	 */
	virtual Edge getByNextId(uint nextNodeId){
		for(uint i=0;i<adjEdges.size();i++){
			if(adjEdges[i].getNextNode()==nextNodeId){
				return adjEdges[i];
			}
		}
		return NONE;			//自动调用函数Edge(NONE)
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
	 * ���node��������ߣ����ǱߵĻ��Ѳ�ͬ����ô���滻�����ߣ����û�����������e��
	 * �����ββ������ã������Ϳ���������ĺ���ʵ��ʱֱ�ӵ���
	 */
	virtual void setEdgeCost(Edge e);

	/**
	 * a��nextNode��ֵ����costһ������һ���ߣ�
	 * ������������ھ͸���������������ھ������
	 */
	virtual void setEdgeCost(unsigned int a,Cost& cost);

	/**
	 * get Node'id what current iterEdge point to
	 * the Node should been found in the graph,its class Graph's responsibility
	 */
	virtual uint firstNeighbor(){
		if(iterEdge<adjEdges.size()){
			return adjEdges[iterEdge].getNextNode();
		}else{
			return (uint)NONE;			//已经到头了
		}
	}

	/**
	 * get Node's what next iterEdge point to and the iterEdge will plus 1
	 * 如果没到底就返回连接的节点的id，否则返回NONE
	 */
	virtual uint nextNeighbor(){
		if(iterEdge+1<adjEdges.size()){
			return adjEdges[++iterEdge].getNextNode();
		}else{
			return (uint)NONE;
		}
	}

};

#endif /* NODE_H_ */
