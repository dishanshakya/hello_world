#include <stdio.h>
#include <string.h>

int main()
{
	char pass[10];
	char buffer[10];
	FILE *fptr;
	fptr = fopen("history", "w");
	while (scanf("%s", pass)>0)
	{
		printf("%s\n", pass);
		strcpy(buffer, pass);
		fseek(fptr, 0, SEEK_SET);
		fprintf(fptr, "%s\n", buffer);
	}
	return 0;
}


