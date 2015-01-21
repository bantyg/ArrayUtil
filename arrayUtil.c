#include <stdio.h>
#include "arrayUtil.h"
#include <stdlib.h>
#include <string.h>


ArrayUtil create(int size,int length){
	ArrayUtil newArray;
	newArray.typeSize = size;
	newArray.length = length;
    newArray.base =calloc(length, size);
	return newArray;
}

int areEqual(ArrayUtil a1,ArrayUtil a2){
	int i,flag = 0;
	char *a1Base = (char *)a1.base;
	char *a2Base = (char *)a2.base;
	if(a1.typeSize != a2.typeSize || a1.length != a2.length){
		return 0;
	}
	else{
		for(i=0;i<(a1.typeSize * a1.length);i++){
			if(a1Base[i] != a2Base[i])
				return 0;
		}
	}
	return 1;
}


ArrayUtil resize(ArrayUtil a1,int newlength){
	void *arr1;
	int i;
	int newSize = a1.typeSize * newlength;
	a1.base = realloc(a1.base,newSize);
	arr1 = a1.base;
	if(newlength > a1.length){
		for (i = a1.length; i < newlength; i++){
			((int *)(arr1))[i] = 0;
		}
		a1.length = newlength;
	}
	a1.length = newlength;
	return a1;
}
