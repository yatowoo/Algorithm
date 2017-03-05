/*
 * Heap.h
 *
 *  Created on: 26 Mar 2015
 *      Author: torrence
 */

#ifndef HEAP_H_
#define HEAP_H_

class Heap {
public:
	Heap();
	virtual ~Heap();
	int length(){
		return len;
	}
	int operator [](int i){
			if(i < len)
				return a[i-1];
			return 0;
	}
private:
	int* a;
	int len;
};

#endif /* HEAP_H_ */
