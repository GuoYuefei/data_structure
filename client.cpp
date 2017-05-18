/*

 * client.cpp
 *
 *  Created on: 2017年3月10日
 *      Author: Administrator

#include<iostream>
#include"linear_list/SeqList.h"
//#include"linear_list/SeqList.cpp"

using namespace std;

template class SeqList<int>;//声明类
int main(){
	SeqList<int> seqlist(16);
	cout<<"maxSize:"<<seqlist.Size()<<endl;
	seqlist.input();
	seqlist.output();

	seqlist.sort();
	cout << "排序后：" << endl;
	seqlist.output();
	cout << "#3\t" << *seqlist.getData(3) << endl;
	cout << "Szie:" << seqlist.Size() << "\tlength:" <<seqlist.Length()<<endl;
	cout << "是空的吗？\t"<<seqlist.isEmpty()<<endl;
	cout << "last is " << seqlist.getLast()  <<endl;
	int num4 = 444444;
	seqlist.insert(4,num4);
	num4 = 0;
	seqlist.output();

	seqlist.remove(4,num4);
	cout << "num4:" << num4 <<endl;
	seqlist.output();

	int num1 = 1;
	cout << "1在顺序表的第"<<seqlist.search(num1)<<endl;


	seqlist.setData(3,num4);
	seqlist.output();
	seqlist.insert(16,num1);			//测试insert有木有自动扩容
	seqlist.insert(17,num1);
	seqlist.output();
	return 0;
}



*/
