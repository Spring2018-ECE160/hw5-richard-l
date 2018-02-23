#include <stdio.h>

void strcatMe(char *, char *);

void strcatMe(char *s, char *t) {
	int i = 0, j = 0;
	while(*(s+i) != '\0') {
		i++;
	}
	while((*(s+(i++)) = *(t+(j++))) != '\0');
}

int main()  {
	char s1[1000] = "Hi Professor Hong, ";
	char s2[] = "this is a strcat test!";
	strcatMe(s1,s2);
	printf("%s\n", s1);
	
	return 0;
}


