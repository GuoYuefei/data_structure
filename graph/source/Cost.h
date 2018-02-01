/*
 * Cost.h
 *
 *  Created on: 2018��1��8��
 *      Author: Administrator
 */

#ifndef COST_H_
#define COST_H_


/**
 * ·�����Ѷ�����
 */
class Cost {
private:
	unsigned int cost;
public:
	Cost():cost(-1){};
	Cost(unsigned int cost):cost(cost){};
	/**
	 * copy constructor
	 */
	Cost(const Cost& cost):cost(cost.getCost()){};
	virtual ~Cost(){};
	virtual unsigned int getCost() const{
		return cost;
	}
	virtual void setCost(int cost){
		this->cost = cost;
	}
};

#endif /* COST_H_ */
