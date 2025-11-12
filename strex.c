#include<stdio.h>
#include<stdlib.h>

#define MIN_LEN 4

int main()
{
	int c;
	int count = 0;		// incremented whenever we find ASCII characters
	char *mem = (char *) calloc(100, sizeof(char));
	while((c = getchar()) != EOF)
	{
		if (c <= 0x7E && c >= 0x20)
		{
			mem[count] = (char) c;
			count++;
			// printf("%c", c);
		}
		else 
		{
			if (count >= MIN_LEN)
			{
				// printf("count: %d\n", count);
				mem[count] = 0x00;
				printf("%s\n", mem);
			}
			count = 0;
		}
	}
	free(mem);
	// printf("\n");
	return 0;
}
