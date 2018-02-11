/*
 * Graph.cpp
 *
 *  Created on: 2018年1月8日
 *      Author: Administrator
 */

#include "Graph.h"

//int Graph::maxId = 0;


Graph::Graph():iterNode(0){
}

Graph::Graph(const vector<Node>& nodes):iterNode(0){
	this->nodes = nodes;
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
		if(nodes[i]==a||nodes[i]==b){
			vector<Edge> temp = nodes[i].getadjEdges();
			if(nodes[i]==a){
				for(unsigned int j=0;j<temp.size();j++){
					if(temp[j].getNextNode()==b.getId()) return true;
				}
				return false;
			}else{
				for(unsigned int j=0;j<temp.size();j++){
					if(temp[j].getNextNode()==a.getId()) return true;
				}
				return false;
			}
		}
	}
	return false;
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
	return (uint)NONE;
}


Node Graph::getNode(unsigned int id) const{
	unsigned int i = nodePos(id);
	if(i==(uint)NONE){
		NoMatchId err = NoMatchId(id);
		err.printErr();
		throw err;
	}
	return nodes[i];
}

//ֻ
vector<Edge> Graph::neighbors(uint id) const {
	try{
		return getNode(id).getadjEdges();
	}catch(NoMatchId& e){
		throw;
	}
}

vector<Edge> Graph::neighbors(Node node) const{
	if(existNode(node)){
		return getNode(node.getId()).getadjEdges();
	}else{
		throw NoMatchId(node.getId());
	}
}


bool Graph::insertVertex(Node node){
	if(!existNode(node)){
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
		Edge e1 = Edge(id2,cost);		//������ӵ�id1����node���ڽӱ�
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
	if(e==NONE) return NONE;				//��ʵ����e==Edge(NONE)�ıȽ�
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

//�ǵ�Ҫ�ı����������е�����
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
	return getNode(id).nextNeighbor();				//++iter���õ���һ��firstNeighbor
}

uint Graph::nextNeighborId(Node node){
	return node.nextNeighbor();						//在
}

Node Graph::nextNeighbor(uint id){
	return getNode(nextNeighborId(id));
}

Node Graph::nextNeighbor(Node node){
	return getNode(nextNeighborId(node));
}

/******************************广度优先开始*********************************************/
bool Graph::breadthOne(uint id,fun f,set_ui& s){
	queue<Node*> q;					//放入的是指针，这样权限大些
//	set<uint> s;			//用于判别是否遍历过该node
	uint temp = id;
	if(!s.insert(temp).second){
		return false;				//要遍历的顶点在set中了
	}
//	try{
	Node* n = &nodes[nodePos(temp)];
	q.push(n);
	while(!q.empty()){
		n = q.front();
		q.pop();
		(*f)(*n);				//将当前遍历的node交给f函数
		vector<Edge> es = n->getadjEdges();			//也可以使用封装好的iter遍历
		for(uint i=0;i<es.size();i++){
			temp = es[i].getNextNode();
			if(s.insert(temp).second){				//如果插入set成功了，说明没有遍历过，那就遍历
				q.push(&nodes[nodePos(temp)]);
			}
		}
	}
//	}catch (NoMatchId& e) {			//如果有错就打印错误
//		e.printErr();
//		return false;
//	}
	return true;
}

bool Graph::breadthOne(Node n,fun f,set_ui& s){
	return breadthOne(n.getId(),f,s);
}

void Graph::BFS(uint id,fun f,set_ui& s){
	uint temp = id;
//	bool result =
	breadthOne(temp,f,s);
	for(uint i = 0;i<nodes.size();i++){
//		if(!result){
//			break;			//发生错误，跳出循环
//		}
		if(s.insert(nodes[i].getId()).second){
			temp = nodes[i].getId();
			s.erase(temp);
			breadthOne(temp,f,s);
		}
	}
//	return result;
}

void Graph::BFS(Node n,fun f,set_ui& s){
	BFS(n.getId(),f,s);
}
/************************************广度优先部分结束********************************************/

/**
 * 深度遍历之前要重置Node中Edge集合的迭代器
 */
void Graph::rsEdgeIter(){
	for(uint i=0;i<nodes.size();i++){
		nodes[i].resetIter();
	}
}

/************************************深度优先开始***********************************************/

/*
 * 本来这应该是一个递归算法的，但是考虑到效率可以用栈实现，但是较复杂
 * 在使用以下4个任意一个函数时需要提前将图中各点的迭代器清0
 */
bool Graph::depthOne(uint id,fun f,set_ui& s){
	uint temp = id;
	stack<Node*> stk;
	if(!s.insert(temp).second){			//插入没成功证明s中已经有了，也就是已经遍历过或者不要求遍历的
		return false;
	}
	Node* n = &nodes[nodePos(temp)];
	(*f)(*n);
	stk.push(n);
	while(!stk.empty()){
		n = stk.top();
		for(temp=n->firstNeighbor();temp!=(uint)NONE;temp=n->nextNeighbor()){	//若没到底了就退出循环
			if(!s.insert(temp).second){
				continue;					//此时temp代表的node已经遍历或无需遍历了
			}else{
				n = &nodes[nodePos(temp)];
				(*f)(*n);					//执行相应函数
				stk.push(n);
				temp=n->nextNeighbor();		//得手动下啦
				break;
			}
		}//只有当以上for循环真的因为for中条件退出时，执行以下代码
		if(temp==(uint)NONE){
			stk.pop();
		}
	}
	return true;
}

bool Graph::depthOne(Node n,fun f,set_ui& s){
	return depthOne(n.getId(),f,s);
}

void Graph::DFS(uint id,fun f,set_ui& s){
	uint temp = id;
	depthOne(temp,f,s);
	for(uint i = 0;i<nodes.size();i++){
		if(s.insert(nodes[i].getId()).second){
			temp = nodes[i].getId();
			s.erase(temp);
			depthOne(temp,f,s);
		}
	}
}

void Graph::DFS(Node n,fun f,set_ui& s){
	DFS(n.getId(),f,s);
}





