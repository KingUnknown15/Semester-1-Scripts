#include <stdio.h>
void main()
{
	int i, j, n;
	printf("Masukan Baris : ");
	scanf("%d", &n);

	for(i=n-2; i>1; i--)
	{
		for(j=i; j<n; j++)
			{
    			printf("  ");
			}
		for(j=2; j<=(4*i-2); j=j+2)
			{
    			printf("%d ",j);
			}
		printf("\n");
	}


	for(i=1; i<=n-2; i++)
	{
		for(j=i; j<n; j++)
			{
    			printf("  ");
			}
		for(j=2; j<=(4*i-2); j=j+2)
			{
    			printf("%d ",j);
			}
		printf("\n");
	}
}

