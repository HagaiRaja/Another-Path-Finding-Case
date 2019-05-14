#ifndef __PAPANCATUR_H__
#define __PAPANCATUR_H__

struct PapanCatur {
	int size;	// = |rows| = |columns|
	int** data;	// = |movements allowed| from (i, j)
	
	PapanCatur(int _size){
		size = _size;
		data = new int*[size];
		for (int i = 0; i < size; i++)
			data[i] = new int[size];
	}
	
	~PapanCatur(){
		for (int i = 0; i < size; i++)
			delete data[i];
		delete data;
	}
};

#endif