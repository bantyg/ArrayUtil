#include "expr_assert.h"
#include "arrayUtil.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void test_to_compare_two_int_array(){
	int size = 4,length = 3;
	int *array1,*array2;
	struct ArrayUtil a1,a2;
	array1 = calloc(length,size);
	array2 = calloc(length, size);
	a1.basePtr = array1;
	a1.size = size;
	a1.length = length;
	a2.basePtr = array2;
	a2.size = size;
	a2.length = length;
	array1[0] = 1;
	array2[0] = 1;
	assertEqual(areEqual(a1,a2),1);
}

void test_to_compare_two_char_array(){
	int size = 4,length = 3;
	char *array1,*array2;
	struct ArrayUtil a1,a2;
	array1 = calloc(length,size);
	array2 = calloc(length, size);
	a1.basePtr = array1;
	a1.size = size;
	a1.length = length;
	a2.basePtr = array2;
	a2.size = size;
	a2.length = length;
	array1[0] = 'a';
	array2[0] = 'a';
	assertEqual(areEqual(a1,a2),1);
}

void test_to_compare_two_float_array(){
	int size = 4,length = 3;
	float *array1,*array2;
	struct ArrayUtil a1,a2;
	array1 = calloc(length,size);
	array2 = calloc(length, size);
	a1.basePtr = array1;
	a1.size = size;
	a1.length = length;
	a2.basePtr = array2;
	a2.size = size;
	a2.length = length;
	array1[0] = 1.0;
	array2[0] = 1.1;
	assertEqual(areEqual(a1,a2),0);

}


void test_to_create_int_array(){
	int size = 4;
	int length = 3;
	struct ArrayUtil array = create(size,length);
    int *result;
    result=(int*)array.basePtr;
	assertEqual(*result,0);
	assertEqual(*(result+1),0);
	assertEqual(*(result+2),0);
	assertEqual(sizeof(*(result+2)),4);

}


void test_to_create_char_array(){
	int size = 1;
	int length = 4;
	struct ArrayUtil array = create(size,length);
    char *result;
    result=(char*)array.basePtr;
	assertEqual(*result,0);
	assertEqual(*(result+1),0);
	assertEqual(*(result+2),0);
	assertEqual(sizeof(*(result+2)),1);
}


void test_to_create_int_with_array_diffferent_size(){
	int size = 3;
	int length = 4;
	struct ArrayUtil array = create(size,length);
    int *result;
    result=(int*)array.basePtr;
	assertEqual(*result,0);
	assertEqual(*(result+1),0);
	assertEqual(*(result+2),0);
	assertEqual(array.size,3);
	assertEqual(sizeof(*(result+2)),4);
}	