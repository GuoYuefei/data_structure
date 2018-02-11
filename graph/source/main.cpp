/*
 * main.cpp
 *
 *  Created on: 2018年1月20日
 *      Author: Administrator
 */

#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include "./Graph.h"

using namespace std;
uint temp = 0;
Graph g;
uint id;
set<uint,less<uint> > s;
void getin();
void getFromFile();
void f(Node& n);

int main(){
//	getin();
	getFromFile();
	queue<Node> q;
/*	s.insert(0);
	Node n = g.getNode(0);
	q.push(n);
	cout<<"广度优先搜索如下："<<endl;
	while(!q.empty()){
		n = q.front();
		q.pop();
		cout << n.getId() << " ";
		vector<Edge> es = n.getadjEdges();
		for(uint i=0;i<es.size();i++){
			temp = es[i].getNextNode();
			if(s.insert(temp).second){	//在set中插入是否成功，若成功则说明此node未遍历，否则就说明已遍历
				q.push(g.getNode(temp));
			}
		}
	}
*/

	cout <<endl<< "这是直接调用成员函数,从id=0结点广度优先遍历一个子图：";
	g.breadthOne(0,f);
	cout << endl << "直接调用成员函数,从id=0结点广度优先遍历一个全图：";
	g.BFS(0,f);
	cout << endl << "直接调用成员函数，从id=0结点深度优先遍历一个子图：";
	g.depthOne(0,f);
	cout << endl << "直接调用成员函数，从id=0结点深度优先遍历一个全图：";
	g.rsEdgeIter();				//在改变过iter后深度遍历时要每次重置一边
	g.DFS(0,f);

}


void outAllEdge(Node n){
	for(uint i=n.firstNeighbor();;i=n.nextNeighbor()){

	}
}

void f(Node& n){

	cout << n.getId()<<" ";
}

void getFromFile(){
	ifstream infile;
	infile.open("c://Users/Administrator/Desktop/cin2.txt",ios::in);
	cout << "输入定点id并加入g(空格隔开，回车停止)：" << endl;
	do{
		infile >> id ;
		g.insertVertex(id);
		cout << "已添加"<< id <<" " <<endl;
	}while(infile.get()!='\n');
	uint id1,id2,cost;
	cout << "请输入边，前面两个是连接顶点的两个id，id1和id2，最后为cost："<<endl;
	do{
		infile >> id1 >> id2 >> cost;
		g.addEdge(id1,id2,cost);
		cout << "已添加"<<id1<<"和"<<id2<<"的边，花费是"<<cost<<endl;
	}while(infile.get()!=';');

}

void getin(){
	cout << "输入定点id并加入g(空格隔开，回车停止)：" << endl;
	do{
		cin >> id ;
		g.insertVertex(id);
		cout << "已添加"<< id <<" " <<endl;
	}while(cin.get()!='\n');
	uint id1,id2,cost;
	cout << "请输入边，前面两个是连接顶点的两个id，id1和id2，最后为cost："<<endl;
	do{
		cin >> id1 >> id2 >> cost;
		g.addEdge(id1,id2,cost);
		cout << "已添加"<<id1<<"和"<<id2<<"的边，花费是"<<cost<<endl;
	}while(cin.get()!=';');

}

