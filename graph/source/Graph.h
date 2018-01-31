/*
 * Graph.h
 *
 *  Created on: 2018年1月8日
 *      Author: Administrator
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include "Node.h"
#include "Edge.h"
#include "Cost.h"
#include <vector>
#include "./exceptions/NoMatchId.h"
#include <set>
#include <queue>
#include <stack>




class Graph {
private:
	uint iterNode;

protected:
	vector<Node> nodes;				// vertex collection

public:
	static int maxId;				//record the max of node's id in this graph

	Graph();
	Graph(const vector<Node>& nodes);
	Graph(const Graph& g);
	virtual ~Graph();


	/************************************Base Operate***************************************/

	/**
	 * there are three functions to deal the iterNode,
	 * then user can control the iterator
	 */
	uint getIterNode() const{
		return iterNode;
	}

	bool setIterNode(unsigned int iter){
		if(iter<nodes.size()&&iter>=0){
			this->iterNode = iter;
			return true;
		}
		return false;
	}

	void resetIter(){
		this->iterNode = 0;
	}



	/**
	 * judge the vertex node is in the graph or not
	 */
	bool existNode(const Node node) const;

	/**
	 * judge the vertex node is in the graph or not
	 * the node is defined by the id is a
	 */
	bool existNode(uint a) const;


	/**
	 * judge the Edge is in the graph or not
	 * the edge will connect two nodes those are defined by id is a and b
	 */
	bool existEdge(uint a,uint b) const;

	/**
	 * judge the Edge is in the graph or not
	 * the edge will connect two nodes which are a and b reference to
	 */
	bool existEdge(const Node a,const Node b) const;

	/**
	 * return the node's position,start at 0
	 * if don't have this id ,return -1
	 */
	unsigned int nodePos(uint id) const;

	/**
	 * get the Node reference which is matching the id
	 */
	Node getNode(unsigned int id) const;

	/**
	 * 得到的是引用，所以就是把图的一个私有变量直接暴露，特别危险，慎用，将来可能修改，暂时未用
	 */
	vector<Node>& getNodes(){
		return nodes;
	}

	/**
	 * list all Edges which is adjacent to the node whose id is id
	 */
	vector<Edge> neighbors(uint id) const ;


	/**
	 * list all Edges which is adjacent to the node
	 * return vector<Edge>
	 */
	vector<Edge> neighbors(Node node) const ;




	/**
	 * insert a node into the graph's vertex collection
	 */
	bool insertVertex(Node node);

	/**
	 * insert a node whose id is 'id' into this graph
	 */
	bool insertVertex(uint id);

	/**
	 * delete vertex from this graph
	 */
	bool deleteVertex(Node node);

	/**
	 * delete vertex whose id is 'id' from this graph
	 */
	bool deleteVertex(uint id);







	/**
	 * provide three parameters
	 * a and b is the node's id,cost is edge's cost
	 * put the edge which defined three parameters into this graph
	 */
	bool addEdge(uint id1,uint id2,Cost cost);


	/**
	 * provide three parameters can define an edge ,put that into this graph
	 */
	bool addEdge(Node a,Node b,Cost cost);

	/**
	 * add an edge which have a vertex id is i to the graph
	 */
	bool addEdge(uint i,Edge e);

	/**
	 * add an edge which have a vertex is node to graph
	 */
	bool addEdge(Node node,Edge e);


	/**
	 * provide two ids,and this two ids can define two nodes those can define an edge
	 * remove the edge from this graph
	 */
	bool removeEdge(uint a,uint b);

	/**
	 * remove an edge from the graph
	 */
	bool removeEdge(uint id1,Edge e);

	bool removeEdge(Node a,Edge e);

	/**
	 * remove the edge which is defined by this two nodes which user provide from this graph
	 */
	bool removeEdge(Node a,Node b);





	/**
	 * provide two parameters which is two ids that can define two nodes
	 * then the two nodes can define an edge what we should find
	 * search the edge and find the edge's cost
	 * success : return the edge's cost
	 * flase : return NULL
	 */
	Cost getEdgeCost(uint id1,uint id2);

	/**
	 * provide a parameter which is an edge
	 * search the edge and find the edge's cost in the node a
	 * success : return the edge's cost
	 * flase : return NULL
	 */
	Cost getEdgeCost(Node a,Edge e);

	/**
	 * provide two parameters which can define an edge
	 * search the edge is defined by the two nodes and find the edge's cost
	 * success : return the edge's cost
	 * flase : return NULL
	 */
	Cost getEdgeCost(Node node1,Node node2);

	/**
	 * can set edge's cost
	 */
	bool setEdgeCose(uint id1,Edge e);

	bool setEdgeCose(Node node1,Edge e);

	/**
	 * a and b can define an edge
	 * then set edge's cost
	 */
	bool setEdgeCost(Node node1,Node node2,Cost cost);

	/**
	 * a and b can define two nodes
	 * the two nodes can define an edge
	 * then set the edge's cost
	 */
	bool setEdgeCost(uint id1,uint id2,Cost cost);

/**************************************************************************************************/

	/**
	 * return the node which the node' iterEdge point to
	 */
	Node firstNeighbor(Node node);

	/**
	 * return the node'id which the node'iterEdge point to
	 */
	uint firstNeighborId(Node node);

	/**
	 * return the node which the iterEdge point to that in the node whose id is id
	 */
	Node firstNeighbor(uint id);

	/**
	 * return the node's id which the iterEdge point to that in the node whose id is id
	 */
	uint firstNeighborId(uint id);



	/**
	 * iterEdge ++
	 * then  return the node which the node' iterEdge point to
	 */
	Node nextNeighbor(Node node);

	/**
	 * iterEdge ++
	 * return the node'id which the node'iterEdge point to
	 */
	uint nextNeighborId(Node node);

	/**
	 * iterEdge ++
	 * return the node which the iterEdge point to that in the node whose id is id
	 */
	Node nextNeighbor(uint id);

	/**
	 * iterEdge ++
	 * return the node's id which the iterEdge point to that in the node whose id is id
	 */
	uint nextNeighborId(uint id);

	/*************************************Complex Operate***********************************/

	/**
	 * search one son of the graph for one node
	 * should provide the node's id
	 * if the graph is connected graph,then return true
	 * 个人认为提供的参数保住正确在这里应该是调用者的责任
	 */
	bool breadthOne(uint id);

	/**
	 * search one son of the graph for one node
	 * should provide the node
	 * if the graph is connected graph,then return true
	 */
	bool breadthOne(Node n);

	/**
	 * search the all graph,you can provide the node's id
	 * also if you don't provide any parameter,the id=0 will be search first
	 */
	void BFS(uint id=0);

	/**
	 * refer to the other one
	 */
	void BFS(Node n);



};

#endif /* GRAPH_H_ */
