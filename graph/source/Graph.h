/*
 * Graph.h
 *
 *  Created on: 2018��1��8��
 *      Author: Administrator
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include "Node.h"
#include "Edge.h"
#include <vector>

/**
 * ����ͼ
 * ��ͼ���֮����ֻ��һ��˽�еĶ��㼯������Node�к������������ͷ������Է��ʸ��Եı߼�
 */
class Graph {
private:
	vector<Node> nodes;				//���㼯 vertex collection

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
