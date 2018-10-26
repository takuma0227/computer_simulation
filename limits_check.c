#include <stdio.h>
#include <limits.h>

int main(void){
	printf("int: MIN=%d MAX=%d\n",INT_MIN,INT_MAX);
	printf("unsigned int: MAX=%u\n", UINT_MAX);
	printf("long int: MIN=%ld MAX=%ld\n", LONG_MIN,LONG_MAX);
	printf("unsigned long int: MAX=%lu\n", ULONG_MAX);
	printf("long long int: MIN=%lld MAX=%lld\n", LLONG_MIN,LLONG_MAX);
	printf("unsigned long int: MAX=%llu\n", ULLONG_MAX);

}