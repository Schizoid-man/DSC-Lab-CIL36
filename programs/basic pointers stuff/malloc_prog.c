#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *ptr = (int*)malloc(sizeof(int));
	if (ptr == NULL){
		printf("Memory allocation failed \n");
		return 1;
	}
	*ptr = 42;
	printf("The value stored at at ptr: %d \n", *ptr);
	free(ptr);
	return 0;
}
