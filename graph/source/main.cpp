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
	cout << "输入定点id并加入g(空格隔开，回车停止)：" << endl;
	do{
		cin >> id ;
		g.insertVertex(id);
	}while(cin.get()!='\n');
	uint id1,id2,cost;
	cout << "请输入边，前面两个是连接顶点的两个id，id1和id2，最后为cost："<<endl;
	do{
		cin >> id1 >> id2 >> cost;
		g.addEdge(id1,id2,cost);
	}while(cin.get()!=';');

	queue<Node> q;
	s.insert(0);
	Node n = g.getNode(0);
	q.push(n);
	while(!q.empty()){
		n = q.front();
		q.pop();
		cout << n.getId() << " ";
		vector<Edge> es = n.getadjEdges();
		for(uint i=0;i<es.size();i++){
			temp = es[i].getNextNode();
			if(s.insert(temp).second){
				q.push(g.getNode(temp));
			}
		}
	}


}


