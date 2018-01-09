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

/**
 * 无向图
 * 该图设计之处，只有一个私有的顶点集，但是Node中含有其他变量和方法可以访问各自的边集
 */
class Graph {
private:
	vector<Node> nodes;				// vertex collection

public:
	static int maxId;				//record the max of node's id in this graph

	Graph();
	Graph(const vector<Node>& nodes);
	Graph(const Graph& g);
	virtual ~Graph();


	/************************************Base Operate***************************************/

	/**
	 * judge the vertex node is in the graph or not
	 */
	bool existNode(Node node);

	/**
	 * judge the vertex node is in the graph or not
	 * the node is defined by the id is a
	 */
	bool existNode(int a);


	/**
	 * judge the Edge is in the graph or not
	 * the edge will connect two nodes those are defined by id is a and b
	 */
	bool existEdge(int a,int b);

	/**
	 * judge the Edge is in the graph or not
	 * the edge will connect two nodes which are a and b reference to
	 */
	bool existEdge(Node a,Node b);

	/**
	 * list all Edges which is adjacent to the node
	 * return vector<Edge>
	 */
	vector<Edge> neighbors(Node node);




	/**
	 * insert a node into the graph's vertex collection
	 */
	bool insertVertex(Node node);

	/**
	 * insert a node whose id is 'id' into this graph
	 */
	bool insertVertex(int id);

	/**
	 * delete vertex from this graph
	 */
	bool deleteVertex(Node node);

	/**
	 * delete vertex whose id is 'id' from this graph
	 */
	bool deleteVertex(int id);





	/**
	 * add an edge to the graph
	 */
	bool addEdge(Edge e);

	/**
	 * provide three parameters can define an edge ,put that into this graph
	 */
	bool addEdge(Node a,Node b,Cost cost);

	/**
	 * provide three parameters
	 * a and b is the node's id,cost is edge's cost
	 * put the edge which defined three parameters into this graph
	 */
	bool addEdge(int a,int b,Cost cost);

	/**
	 * remove an edge from the graph
	 */
	bool removeEdge(Edge e);

	/**
	 * remove the edge which is defined by this two nodes which user provide from this graph
	 */
	bool removeEdge(Node a,Node b);

	/**
	 * provide two ids,and this two ids can define two nodes those can define an edge
	 * remove the edge from this graph
	 */
	bool removeEdge(int a,int b);




	/**
	 * provide a parameter which is an edge
	 * search the edge and find the edge's cost
	 * success : return the edge's cost
	 * flase : return NULL
	 */
	Cost getEdgeCost(Edge e);

	/**
	 * provide two parameters which can define an edge
	 * search the edge is defined by the two nodes and find the edge's cost
	 * success : return the edge's cost
	 * flase : return NULL
	 */
	Cost getEdgeCost(Node a,Node b);

	/**
	 * provide two parameters which is two ids that can define two nodes
	 * then the two nodes can define an edge what we should find
	 * search the edge and find the edge's cost
	 * success : return the edge's cost
	 * flase : return NULL
	 */
	Cost getEdgeCost(int a,int b);

	/**
	 * can set edge's cost
	 */
	bool setEdgeCose(Edge e,Cost cost);

	/**
	 * a and b can define an edge
	 * then set edge's cost
	 */
	bool setEdgeCost(Node a,Node b,Cost cost);

	/**
	 * a and b can define two nodes
	 * the two nodes can define an edge
	 * then set the edge's cost
	 */
	bool setEdgeCost(int a,int b,Cost cost);





	/**
	 * return the node which the node' iterEdge point to
	 */
	Node firstNeighbor(Node node);

	/**
	 * return the node'id which the node'iterEdge point to
	 */
	int firstNeighborId(Node node);

	/**
	 * return the node which the iterEdge point to that in the node whose id is id
	 */
	Node firstNeighbor(int id);

	/**
	 * return the node's id which the iterEdge point to that in the node whose id is id
	 */
	int firstNeighborId(int id);



	/**
	 * iterEdge ++
	 * then  return the node which the node' iterEdge point to
	 */
	Node nextNeighbor(Node node);

	/**
	 * iterEdge ++
	 * return the node'id which the node'iterEdge point to
	 */
	int nextNeighborId(Node node);

	/**
	 * iterEdge ++
	 * return the node which the iterEdge point to that in the node whose id is id
	 */
	Node nextNeighbor(int id);

	/**
	 * iterEdge ++
	 * return the node's id which the iterEdge point to that in the node whose id is id
	 */
	int nextNeighborId(int id);




	/*************************************Complex Operate***********************************/




};

#endif /* GRAPH_H_ */
