/*
* 
*  Author: Yitao Wu / yato 	
*	
*  Description:
*	Sort Class for Algotithm Learning
*/

#ifndef YATO_ALGORITHM_SORT
#define YATO_ALGORITHM_SORT

#include<iostream>
#include<climits>
#include<float.h>

class Sort {

public :
	// Contructor
	Sort();
	// Destructor
	~Sort(){isInstance=false;}
	inline int InsertionSort(int* A, int n);
	inline int MergeSort(int* A, int p, int r);
	inline void PrintArray(int* A, int n);
private:
	inline int Merge(int* A,int p, int q, int r);
	bool isInstance;
};

Sort::Sort(){
	isInstance = true;
}
// Divide array for merge
inline int Sort::MergeSort(int *A, int p, int r){
	if(p < r){
		int q = (p+r)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
	return 0;
}
// Merge 2 sorted array
inline int Sort::Merge(int *A, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1];
	int R[n2+1];
	for(int i = 0 ; i < n1 ; i ++)
		L[i] = A[i+p];
	L[n1] = INT_MAX;
	for(int i = 0 ; i < n2 ; i++)
		R[i] = A[i+q+1];
	R[n2] = INT_MAX;
	
	int i=0,j=0;
	for(int k = p ; k <= r ; k ++){
		if(L[i] < R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}
	return 0;
}

inline void Sort::PrintArray(int *A, int n){
	for(int i = 0 ; i < n ; i++)
		std::cout << "\t" << A[i];
	std::cout << std::endl;
}
#endif /* YATO_SORT */
