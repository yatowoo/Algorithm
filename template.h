/*
* 
*  Author: Yitao Wu / yato 	
*	
*  Description:
*	Sort Class for Algotithm Learning
*/

#ifndef YATO_ALGORITHM_SORT
#define YATO_ALGORITHM_SORT

class Sort {

public :
	// Contructor
	Sort();
	// Destructor
	~Sort();
	inline int InsertionSort(int* A, int n);
	inline int MergeSort(int* A, int p, int r);
	inline int PrintArray(int* A, int n);
private:
	inline int Merge(int* A,int p, int q, int r);
	bool isInstance;
};

Sort::Sort(){
	isInstance = true;
}

int MergeSort(int *A, int p, int r){
	if(p < r){
		int q = (p+r)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}

int Merge(int *A, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1];
	int R[n2+1];
	for(int i = p ; i <= q ; i ++)
		L[i] = A[i];
	for(int i = q+1 ; i <= r ; i++)
		R[i] = A[i];

}

#endif // YATO_TEMPLATE
