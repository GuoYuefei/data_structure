/*
 * Cost.h
 *
 *  Created on: 2018��1��8��
 *      Author: Administrator
 */

#ifndef COST_H_
#define COST_H_

class Cost {
private:
	int cost;
public:
	virtual Cost():cost(-1){};
	virtual ~Cost(){};
	virtual int getCost(){
		return cost;
	}
	virtual void setCost(int cost){
		this->cost = cost;
	}
};

#endif /* COST_H_ */
