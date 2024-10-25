#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *ptr;
	int n = 5, new_n = 10;
	ptr = (int*)malloc(n*sizeof(int));
	if (ptr == NULL){
		printf("Memory allocation failed \n");
		return 1;
	}
	for (int i =0;i<n;i++)
	{
		ptr[i] = i+1;
	}
	printf("OG array: ");
	for(int i =0;i<n;i++){
		printf("%d",ptr[i]);
	}
	ptr = (int*)realloc(ptr,new_n*sizeof(int));
	if(ptr == NULL){
	printf("Memory reallocation failed \n");
	return 1;
	}printf("Resized array: ");
	for (int i = n;i<new_n;i++){
		printf("%d", ptr[i]);
	}
	free(ptr);
	return 0;
}

