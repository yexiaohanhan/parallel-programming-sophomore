#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;

	int addsum;
	int subsum;
	// int mulsum ;
	//
	__asm__ __volatile__(
	
	 //传参
	 			"mov r0 , x4   \n"    //mov 执行是将第二个操作数移到第一个操作数上    
	 			"mov r1 , x5   \n"
	//运算
				"mul r2 , r1 , r0   \n"   //将r1*r0的值赋值给寄存器r2
	 			"add r2 , r1 , r0   \n"   //将r1+r0的值赋值给寄存器r2
	             		"sub r3 , r1 , r0   \n"   //将r1-r0的值赋值给寄存器r2
	// 												   				//传参数
				"mov %0 , r2   \n"												   					      "mov %1 , r3   \n"
	//
	// 												   										//在汇编的代码中，没有除法，除法是一个协处理器的函数
	//
	// 												   												//参数是从上到下，从左到右以零开始自增   %0  %1  %2
				:"=r"(addsum), "=r"(subsum)
				: "r"(a), "r"(b)
				: "r0", "r1", "r2", "r3"
	);	                    	
	printf("a : %d  b :%d  addsum:%d  subsum:%d \n", a, b, addsum, subsum);											     return 0;
	}
