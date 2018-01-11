/*
 * NoMatchId.h
 *
 *  Created on: 2018Äê1ÔÂ10ÈÕ
 *      Author: Administrator
 */

#ifndef EXCEPTIONS_NOMATCHID_H_
#define EXCEPTIONS_NOMATCHID_H_

#include "GraphException.h"
#include <string>
namespace std{
	class NoMatchId: public GraphException {
	private:
		const string info;
		unsigned int errid;
	public:
		NoMatchId():info("id can not be fonud"),errid(-1){};
		NoMatchId(unsigned int id):info("id can not be fonud"),errid(id){};
		virtual ~NoMatchId(){};
		virtual void printErr(){
			cerr << info << "\tid is" << errid<<endl;
		}
	};

}

#endif /* EXCEPTIONS_NOMATCHID_H_ */
