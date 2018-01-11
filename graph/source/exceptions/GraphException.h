/*
 * GraphException.h
 *
 *  Created on: 2018Äê1ÔÂ10ÈÕ
 *      Author: Administrator
 */

#ifndef EXCEPTIONS_GRAPHEXCEPTION_H_
#define EXCEPTIONS_GRAPHEXCEPTION_H_

#include <iostream>


namespace std {
/**
 * interface for any GraphException
 */
class GraphException{
public:
	GraphException(){};
	virtual ~GraphException(){};
	virtual void printErr()=0;
};

} /* namespace std */

#endif /* EXCEPTIONS_GRAPHEXCEPTION_H_ */
