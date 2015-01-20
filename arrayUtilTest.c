#include "expr_assert.h"
#include "arrayUtil.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void test_to_compare_two_int_array(){
	int typeSize = 4,length = 3,*array1,*array2;
	struct ArrayUtil a1,a2;
	array1 = calloc(length,typeSize);
	array2 = calloc(length, typeSize);
	a1.basePtr = array1;
	a1.typeSize = typeSize;
	a1.length = length;
	a2.basePtr = array2;
	a2.typeSize = typeSize;
	a2.length = length;
	array1[0] = 1;
	array2[0] = 1;
	assertEqual(areEqual(a1,a2),1);
}

void test_to_compare_two_char_array(){
	int typeSize = 4,length = 3;
	char *array1,*array2;
	struct ArrayUtil a1,a2;
	array1 = calloc(length,typeSize);
	array2 = calloc(length, typeSize);
	a1.basePtr = array1;
	a1.typeSize = typeSize;
	a1.length = length;
	a2.basePtr = array2;
	a2.typeSize = typeSize;
	a2.length = length;
	array1[0] = 'a';
	array2[0] = 'a';
	assertEqual(areEqual(a1,a2),1);
}

void test_to_compare_two_float_array(){
	int typeSize = 4,length = 3;
	float *array1,*array2;
	struct ArrayUtil a1,a2;
	array1 = calloc(length,typeSize);
	array2 = calloc(length, typeSize);
	a1.basePtr = array1;
	a1.typeSize = typeSize;
	a1.length = length;
	a2.basePtr = array2;
	a2.typeSize = typeSize;
	a2.length = length;
	array1[0] = 1.0;
	array2[0] = 1.1;
	assertEqual(areEqual(a1,a2),0);

}


void test_to_create_int_array_initializes_with_0(){
	int typeSize = 4,length = 3;
	int arrOf0[3] = {0,0,0};
	struct ArrayUtil array = create(typeSize,length);
	struct ArrayUtil array1;
    array1.basePtr = arrOf0;
    array1.typeSize = 4;
    array1.length = 3;
	assertEqual(areEqual(array, array1),1);
}


void test_to_create_char_array_initializes_with_0(){
	int typeSize = 1,length = 4;
	char arrOf0[4] = {0,0,0,0};
	struct ArrayUtil array = create(typeSize,length);
	struct ArrayUtil array1;
	array1.basePtr = arrOf0;
	array1.typeSize = 1;
	array1.length = 4;
	assertEqual(areEqual(array, array1),1);
}


void test_to_create_int_with_array_diffferent_typeSize_initializes_with_0(){
	int typeSize = 3,length = 4,*result;
	struct ArrayUtil array = create(typeSize,length);
    result=(int*)array.basePtr;
	assertEqual(*result,0);
	assertEqual(*(result+1),0);
	assertEqual(*(result+2),0);
	assertEqual(array.typeSize,3);
}	

void test_to_change_the_typeSize_of_int_array(){
	int typeSize = 4,length = 3,newLength = 5,*array1;
	struct ArrayUtil a1,a2;
	array1 = calloc(length,typeSize);
	array1[0] = 1;
	array1[1] = 2;
	array1[2] = 3;

	a1.basePtr = array1;
	a1.typeSize = typeSize;
	a1.length = length;
	a2 = resize(a1,newLength);
	a2.basePtr = array1;
	assertEqual(((int *)(a2.basePtr))[0],1);
	assertEqual(((int *)(a2.basePtr))[1],2);
	assertEqual(((int *)(a2.basePtr))[2],3);
	assertEqual(((int *)(a2.basePtr))[3],0);
	assertEqual(((int *)(a2.basePtr))[4],0);

}

void test_to_change_the_typeSize_of_array_to_small_array(){
	int typeSize = 4,length = 5,newLength = 3, *array1;
	struct ArrayUtil a1,a2;
	array1 = calloc(length,typeSize);
	array1[0] = 1;
	array1[1] = 2;
	array1[2] = 3;

	a1.basePtr = array1;
	a1.typeSize = typeSize;
	a1.length = length;

	a2 = resize(a1,newLength);
	a2.basePtr = array1;
	assertEqual(((int *)(a2.basePtr))[0],1);
	assertEqual(((int *)(a2.basePtr))[1],2);
	assertEqual(((int *)(a2.basePtr))[2],3);
}


void test_to_change_the_typeSize_of_float_array(){
	int typeSize = 4,length = 3,newLength = 5;
	float *array1;
	struct ArrayUtil a1,a2;
	array1 = calloc(length,typeSize);
	array1[0] = 1.1;
	array1[1] = 2.1;
	array1[2] = 3.1;

	a1.basePtr = array1;
	a1.typeSize = typeSize;
	a1.length = length;
	a2 = resize(a1,newLength);
	a2.basePtr = array1;
	assertEqual(((float *)(a2.basePtr))[0],(float)1.1);
	assertEqual(((float *)(a2.basePtr))[1],(float)2.1);
	assertEqual(((float *)(a2.basePtr))[2],(float)3.1);
	assertEqual(((float *)(a2.basePtr))[3],0);
	assertEqual(((float *)(a2.basePtr))[4],0);
}

