/*
 * Cost.h
 *
 *  Created on: 2018年1月8日
 *      Author: Administrator
 */

#ifndef COST_H_
#define COST_H_

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

	Cost& operator=(const Cost& c){
		if(this!=&c){
			unsigned int temp = c.getCost();
			this->cost = temp;
		}
		return *this;
	}
};

#endif /* COST_H_ */
