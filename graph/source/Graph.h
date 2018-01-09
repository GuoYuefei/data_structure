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
#include <vector>

/**
 * 无向图
 * 该图设计之处，只有一个私有的顶点集，但是Node中含有其他变量和方法可以访问各自的边集
 */
class Graph {
private:
	vector<Node> nodes;				//顶点集 vertex collection

public:
	Graph();
	virtual ~Graph();

	/**
	 * judge the Edge e is in the graph or not
	 */
	bool adjacent(Edge e);

	/**
	 * list all Edges which is adjacent to the node
	 * return vector<Edge>
	 */
	vector<Edge> neighbors(Node node);

	/**
	 * insert a node to the vertex collection
	 */
	bool insertVertex(Node node);

	/**
	 * delete vertex to
	 */
	bool deleteVertex(Node node);




};

#endif /* GRAPH_H_ */
