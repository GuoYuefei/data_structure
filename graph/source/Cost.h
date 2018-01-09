/*
 * Cost.h
 *
 *  Created on: 2018年1月8日
 *      Author: Administrator
 */

#ifndef COST_H_
#define COST_H_


/**
 * 路径花费顶层类
 */
class Cost {
private:
	int cost;
public:
	Cost():cost(-1){};
	Cost(int cost):cost(cost){};
	virtual ~Cost(){};
	virtual int getCost(){
		return cost;
	}
	virtual void setCost(int cost){
		this->cost = cost;
	}
};

#endif /* COST_H_ */
