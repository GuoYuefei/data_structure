/*
 * BinaryTree.cpp
 *
 *  Created on: 2017年5月14日
 *      Author: Administrator
 */

#include "BinaryTree.h"
#include <queue>				//引入队列，层次遍历时用
#include <iostream>

namespace std {


BinaryTree::~BinaryTree() {
	// TODO Auto-generated destructor stub
}

//接收数组指针按顺序插入二叉树 ds数组指针，length数组的长度
void BinaryTree::appendInts(const int* ds,const int length){
	for(int i = 0;i < length;i++){
		Node* node = new Node(*(ds+i));		//数组遍历成为node后调用appendNode存放
		appendNode(node);
	}

}

//用队列实现,针对完美二叉树构成
void BinaryTree::appendNode(Node* nd){
	queue<Node*> q;
	Node* temp = root;
	int flag=0;
//	Node next;
	q.push(temp);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp->left!=NULL){
			q.push(temp->left);
		}else{
			flag = -1;
			break;
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}else{
			flag = 1;
			break;
		}
	}
	switch (flag) {
		case -1:
			temp->left = nd;
			break;
		case 1:
			temp->right = nd;
			break;
		default:
			throw "程序错误";
			break;
	}
}

//层次遍历
void BinaryTree::level_traversal(){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		temp->printData();			//这个print还可以通过多态方式任意改变哦
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}
}


//前序递归
void BinaryTree::preorder_traversal(){
	preorder(root);
}
//中序
void BinaryTree::inorder_traversal(){
	inorder(root);
}
//后续
void BinaryTree::subsequent_traversal(){
	subsequent(root);
}











} /* namespace std */
