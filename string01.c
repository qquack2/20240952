#include <stdio.h>
#include <string.h>

int main()
{
	char src[100];
	char dest[100];
	//int length;
	int result;

	gets(src);
	/*length = strlen(src);
	printf("length of src = %d\n", length);
	strcpy(dest, src);
	puts("src = %s, dest = %s\n",src, dest);
	strcpy(dest, src);
	puts("src = %s, dest = %s\n", src, dest);*/
	gets(dest);
	
	result = strcmp(src, dest);
	printf("result = %d\n", result);


	return 0;
}