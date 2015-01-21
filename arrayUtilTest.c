#include "expr_assert.h"
#include "arrayUtil.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ArrayUtil util;
void test_areEqual_returns_1_if_two_int_array_are_equal(){
	int array1[] = {1,2,3};
	int array2[] = {1,2,3};
	ArrayUtil a1 = create(4,3);
	ArrayUtil a2 = create(4,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_if_two_int_array_are_not_equal(){
	int array1[] = {1,2,4};
	int array2[] = {1,2,3};
	ArrayUtil a1 = create(4,3);
	ArrayUtil a2 = create(4,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),0);
}

void test_areEqual_returns_1_if_two_char_array_are_equal(){
	char array1[] = {'a','b','c'};
	char array2[] = {'a','b','c'};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_if_two_char_array_are_not_equal(){
	char array1[] = {'a','a','c'};
	char array2[] = {'a','b','c'};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),0);
}

void test_areEqual_returns_1_if_two_float_array_are_equal(){
	float array1[] = {1.0,0.2,3.4};
	float array2[] = {1.0,0.2,3.4};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_if_two_float_array_are_not_equal(){
	float array1[] = {1.0,1.2,3.4};
	float array2[] = {1.0,0.2,3.4};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_create_creates_an_int_array_initializes_with_0(){
	int typeSize = 4,length = 3;
	int arrOf0[3] = {0,0,0};
	ArrayUtil array = create(typeSize,length);
	ArrayUtil array1;
    array1.base = arrOf0;
    array1.typeSize = 4;
    array1.length = 3;
	assertEqual(areEqual(array, array1),1);
}

void test_create_creates_char_array_initializes_with_0(){
	int typeSize = 1,length = 4;
	char arrOf0[4] = {0,0,0,0};
	ArrayUtil array = create(typeSize,length);
	ArrayUtil array1;
	array1.base = arrOf0;
	array1.typeSize = 1;
	array1.length = 4;
	assertEqual(areEqual(array, array1),1);
}

void test_to_create_int_with_array_diffferent_typeSize_initializes_with_0(){
	int typeSize = 3,length = 4,*result;
	ArrayUtil array = create(typeSize,length);
    result=(int*)array.base;
	assertEqual(*result,0);
	assertEqual(*(result+1),0);
	assertEqual(*(result+2),0);
	assertEqual(array.typeSize,3);
}	

void test_to_change_the_length_of_int_array_to_greater_length(){
	int newLength = 5;
	int number[] = {0,0,0,0,0};
	ArrayUtil a1 = create(4,3);
	ArrayUtil expected = {number,sizeof(int), 5};
	ArrayUtil a3 = resize(a1, newLength);
	assert(areEqual(expected,a3));
}

void test_to_change_the_length_of_array_to_small_array_length(){
	int newLength = 3;
	int number[] = {0,0,0};
	ArrayUtil a1 = create(4,5);
	ArrayUtil expected = {number,sizeof(int),3};
	ArrayUtil a3 = resize(a1, newLength);
	assertEqual(areEqual(expected,a3),1);
	
}

void test_to_change_the_length_of_char_array_to_grater_length(){
	int newLength = 5;
	int number[] = {0,0,0,0,0};
	ArrayUtil a1 = create(4,3);
	ArrayUtil expected = {number,sizeof(int),5};
	ArrayUtil a3 = resize(a1, newLength);
	assertEqual(areEqual(expected,a3),1);
	
}

void test_to_change_the_length_of_float_array_to_greater_length(){
	int newLength = 5;
	int number[] = {0,0,0,0,0};
	ArrayUtil a1 = create(4,3);
	ArrayUtil expected = {number,sizeof(float), 5};
	ArrayUtil a3 = resize(a1, newLength);
	assert(areEqual(expected,a3));
}



