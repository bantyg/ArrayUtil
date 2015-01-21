typedef struct ArrayUtil{
	void *base;
	int typeSize;
	int length;
}ArrayUtil;

ArrayUtil create(int,int);
int areEqual(ArrayUtil a1,ArrayUtil a2);
ArrayUtil resize(ArrayUtil a1,int);
