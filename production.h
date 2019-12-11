/*
 * production.h
 *
 *  Created on: Nov 23, 2019
 *      Author: Tyler Jones
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_


#include <iostream>
#include <algorithm>

using namespace std;

class Production {
public:
	Production();
	virtual ~Production();
	void production(int arr[8][8]);
	void printArray(int arr[8][8]);
};

#endif /* PRODUCTION_H_ */
