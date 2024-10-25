#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *ptr;
	int n = 5;
	ptr = (int*)malloc(n*sizeof(int));
	if (ptr ==NULL)
	{
		printf("Memory not allocated \n");
		return 1;
	}
	printf("Memory successfully allocated using malloc \n");
	for (int i = 0; i<n;i++)
	{
		ptr[i] = i+1;
		printf("%d" , ptr[i]);
	}
	free(ptr);
	return 0;
}
