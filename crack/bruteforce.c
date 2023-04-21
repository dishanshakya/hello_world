#include <stdio.h>
#include <string.h>
#include <ctype.h>

int size;
char alpha[] = "0123456789@abcdefghijklmnopqrstuvwxyz";//ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *end;

int isvowel(char c)
{
	return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='I'||c=='O'||c=='E'||c=='U');
}

void print(char *s, int n)
{
	if (n < 1)
		return;
	char *index = alpha;
	while (s[size-n] != *index)
		++index;
	while (index < end)
	{
			s[size-n]= *index++;
			if (n ==1){
				for (int i=0; s[i] != '\0'; ++i)
				{
					if (isvowel(s[i]))
						continue;
					for (int j=i+1; s[j]!='\0'; ++j)
					{
						if (s[j] == s[i])
							goto scan;
					}
				}
				printf("%s\n", s);
			}
		scan: print(s, n-1);
	}
	if (index == end)
	{
		index = alpha;
		s[size-n] = *index++;
	}
}

int main(int argc, char** argv)
{
	end = alpha+strlen(alpha);
	if (argc < 2)
		return 0;
	char *s = *++argv;
	size = strlen(s);
	print(s, size);
	return 0;
}

