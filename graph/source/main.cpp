/*
 * main.cpp
 *
 *  Created on: 2018年1月20日
 *      Author: Administrator
 */
#include <iostream>
#include <queue>
#include <set>
#include "./Graph.h"

using namespace std;
uint temp = 0;
int main(){
	Graph g;
	uint id;
	set<uint,less<uint> > s;
	//添加节点 回车结束
	do{
		cin >> id ;
		g.insertVertex(id);
	}while(cin.get()!='\n');
	uint id1,id2,cost;
	do{
		cin >> id1 >> id2 >> cost;
		g.addEdge(id1,id2,cost);
	}while(cin.get()!=';');			//分号结束

	queue<Node> q;
	s.insert(0);
	Node n = g.getNode(0);
	q.push(n);
	while(!q.empty()){
		n = q.front();
		q.pop();
		cout << n.getId() << " ";
		vector<Edge> es = n.getadjEdges();			//只取到了其边的复制
		for(uint i=0;i<es.size();i++){
			temp = es[i].getNextNode();
			if(s.insert(temp).second){
				q.push(g.getNode(temp));
			}
		}
	}


}


