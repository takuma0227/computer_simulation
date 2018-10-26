#include <stdio.h>
#include <float.h>

int main(void){

	printf("float: MIN=%e MAX=%e\n", FLT_MIN, FLT_MAX);
	printf("double: MIN=%e MAX=%e\n", DBL_MIN, DBL_MAX);
	printf("long double: MIN=%e MAX=%e\n", LDBL_MIN, LDBL_MAX);

}