/*
 * main.cpp
 *
 *  Created on: 2018��1��20��
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
	//��ӽڵ� �س�����
	do{
		cin >> id ;
		g.insertVertex(id);
	}while(cin.get()!='\n');
	uint id1,id2,cost;
	do{
		cin >> id1 >> id2 >> cost;
		g.addEdge(id1,id2,cost);
	}while(cin.get()!=';');			//�ֺŽ���

	queue<Node> q;
	s.insert(0);
	Node n = g.getNode(0);
	q.push(n);
	while(!q.empty()){
		n = q.front();
		q.pop();
		cout << n.getId() << " ";
		vector<Edge> es = n.getadjEdges();			//ֻȡ������ߵĸ���
		for(uint i=0;i<es.size();i++){
			temp = es[i].getNextNode();
			if(s.insert(temp).second){
				q.push(g.getNode(temp));
			}
		}
	}


}


