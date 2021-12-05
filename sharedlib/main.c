#include<stdio.h>
#include "libarith.so"

int main(int argc, char const *argv[])
{

	int x=13,y=45;

	printf("\nSum: %d + %d = %d\n",x,y,add(x,y));
	printf("\nDif: %d - %d = %d\n",x,y,sub(x,y));
	return 0;

}
