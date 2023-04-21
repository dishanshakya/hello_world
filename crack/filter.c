#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int min = 4;
	if (argc == 2)
		min = atoi(*++argv);
	char word[100];
	
here:
	while (scanf("%s", word) > 0)
	{
		int c;
		for (int i=0; word[i] != '\0'; ++i)
		{
			int cnt = 0;
			c = word[i];
			for (int j = i; word[j] == c; ++j)
			{
				++cnt;
				if (cnt > min)
					goto here;
			}
		}
		printf("%s\n", word);
	}
	return 0;
}
