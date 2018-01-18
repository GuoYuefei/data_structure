/*
 * Graph.cpp
 *
 *  Created on: 2018年1月8日
 *      Author: Administrator
 */

#include "Graph.h"

int Graph::maxId = 0;


Graph::Graph():iterNode(0){
}

Graph::Graph(const vector<Node>& nodes):iterNode(0){
	this->nodes = nodes;					//发生的是一个个node不断赋值过程
}

Graph::Graph(const Graph& g):iterNode(0){
	this->nodes = g.nodes;
}

Graph::~Graph(){

}

bool Graph::existNode(const Node node) const{
	for(unsigned int i=0;i<nodes.size();i++){
		if(nodes[i]==node){
			return true;
		}
	}
	return false;
}

bool Graph::existNode(uint id) const{
	Node node = *new Node(id);
	return existNode(node);
}

bool Graph::existEdge(const Node a,const Node b) const{
	for(unsigned int i=0;i<nodes.size();i++){
		if(nodes[i]==a||nodes[i]==b){				//根据==的重载，只要id相同的Node类型就认为是相等的
			vector<Edge> temp = nodes[i].getadjEdges();
			if(nodes[i]==a){
				for(unsigned int j=0;j<temp.size();j++){	//确定一节点后遍历该节点
					if(temp[j].getNextNode()==b.getId()) return true;
				}
				return false;				//a中没有连向b的边
			}else{
				for(unsigned int j=0;j<temp.size();j++){
					if(temp[j].getNextNode()==a.getId()) return true;
				}
				return false;					//b中没有连向a的边
			}
		}
	}
	return false;					//没找到两个节点
}

bool Graph::existEdge(uint a,uint b) const{
	Node aa = Node(a);
	Node bb = Node(b);
	return existEdge(aa,bb);
}

unsigned int Graph::nodePos(uint id) const{
	for(unsigned int i=0;i<nodes.size();i++){
		if(nodes[i].getId()==id){
			return i;
		}
	}
	//不存在就返回这个所以在existNode(...)测试返回是true时不会返回以下类型
	return (uint)NONE;		//NONE=-1虽然不是是无符号数，但是根据编码不变转化，他是unsigned里最大的
}

//只能得到容器里的一个副本，并不能对真实的node做写操作
Node Graph::getNode(unsigned int id) const{
	unsigned int i = nodePos(id);
	if(i==(uint)NONE){							//若没有一个id就抛出异常并终止此函数
		throw NoMatchId(id);
	}
	return nodes[i];
}

//只能得到容器的副本
vector<Edge> Graph::neighbors(uint id) const {
	try{
		return getNode(id).getadjEdges();
	}catch(NoMatchId& e){
		throw;						//捕捉到的异常再次向上抛出
	}
}

vector<Edge> Graph::neighbors(Node node) const{
	if(existNode(node)){							//只要存在与提供的node的id相同结点就输出所有邻接边
		return getNode(node.getId()).getadjEdges();
	}else{
		throw NoMatchId(node.getId());
	}
}


bool Graph::insertVertex(Node node){
	if(!existNode(node)){					//图中不存在node顶点时添加
		this->nodes.push_back(node);
		return true;
	}else{
		return false;
	}
}

bool Graph::insertVertex(uint id){
	if(!existNode(id)){
		Node node = Node(id);				//just use stack space
		this->nodes.push_back(node);
		return true;
	}else{
		return false;
	}
}

bool Graph::deleteVertex(uint id){
	if(existNode(id)){
		int i = nodePos(id);				//search the position
		nodes.erase(nodes.begin()+i);
		return true;
	}
	return false;
}

bool Graph::deleteVertex(Node node){
	return deleteVertex(node.getId());
}


bool Graph::addEdge(uint id1,uint id2,Cost cost){
	if(existEdge(id1,id2)){
		return false;
	}else{
		uint id1pos = nodePos(id1);
		uint id2pos = nodePos(id2);
		Edge e1 = Edge(id2,cost);		//这是添加到id1所在node的邻接边
		Edge e2 = Edge(id1,cost);
		nodes[id1pos].addEdge(e1);
		nodes[id2pos].addEdge(e2);
		return true;
	}
}

bool Graph::addEdge(Node node1,Node node2,Cost cost){
	uint id1 = node1.getId();
	uint id2 = node2.getId();
	return addEdge(id1,id2,cost);
}



bool Graph::addEdge(uint id1,Edge e){
	uint id2 = e.getNextNode();
	return addEdge(id1,id2,e.getCost());
}

bool Graph::addEdge(Node node,Edge e){
	return addEdge(node.getId(),e);
}

bool Graph::removeEdge(uint id1,uint id2){
	uint id1pos = nodePos(id1);
	uint id2pos = nodePos(id2);
	bool flag = false;
	flag = nodes[id1pos].removeEdge(id2);
	if(flag==false){
		return flag;
	}else{
		flag = nodes[id2pos].removeEdge(id1);
	}
	return flag;
}

bool Graph::removeEdge(Node node1,Node node2){
	uint id1 = node1.getId();
	uint id2 = node2.getId();
	return removeEdge(id1,id2);
}

bool Graph::removeEdge(uint id1,Edge e){
	uint id2 = e.getNextNode();
	return removeEdge(id1,id2);
}

bool Graph::removeEdge(Node node1,Edge e1){
	uint id1 = node1.getId();
	uint id2 = e1.getNextNode();
	return removeEdge(id1,id2);
}

Cost Graph::getEdgeCost(uint id1,uint id2){
	uint id1pos = nodePos(id1);
	Edge e =nodes[id1pos].getByNextId(id2);
	if(e==NONE) return NONE;				//其实做了e==Edge(NONE)的比较
	return e.getCost();
}

Cost Graph::getEdgeCost(Node node1,Node node2){
	return getEdgeCost(node1.getId(),node2.getId());
}

Cost Graph::getEdgeCost(Node node1,Edge e){
	uint id1 = node1.getId();
	uint id2 = e.getNextNode();
	return getEdgeCost(id1,id2);
}

//记得要改变两个顶点中的内容
bool Graph::setEdgeCost(uint id1,uint id2,Cost cost){
	if(existEdge(id1,id2)){
		uint id1pos = nodePos(id1);
		uint id2pos = nodePos(id2);
		nodes[id1pos].setEdgeCost(id2,cost);
		nodes[id2pos].setEdgeCost(id1,cost);
		return true;
	}else{
		return false;
	}
}

uint Graph::firstNeighborId(uint id){
	return getNode(id).firstNeighbor();
}

/**
 * that is not sure ,may be change
 */
uint Graph::firstNeighborId(Node node){
	return node.firstNeighbor();
}

Node Graph::firstNeighbor(uint id){
	return getNode(firstNeighborId(id));
}

Node Graph::firstNeighbor(Node node){
	return getNode(firstNeighborId(node));
}

uint Graph::nextNeighborId(uint id){
	return getNode(id).nextNeighbor();				//++iter，得到下一个firstNeighbor
}

uint Graph::nextNeighborId(Node node){
	return node.nextNeighbor();						//与前面的first函数一样直接用了提供的node
													//之前写得大多数函数多是只要取node中的id信息
}

Node Graph::nextNeighbor(uint id){
	return getNode(nextNeighborId(id));
}

Node Graph::nextNeighbor(Node node){
	return getNode(nextNeighborId(node));
}















