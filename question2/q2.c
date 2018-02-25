#include <stdio.h>

void strcatMe(char *, char *);

void strcatMe(char *s, char *t) {
	int i = 0, j = 0;
	while(*(s+i) != '\0') {
		i++;
	}
	while( (*(s+i) = *(t+j) ) != '\0') {
		i++;
		j++;
	}
}

int main()  {
	printf("'/' indicates the end of the first string\n");
	char s1[1000] = "Hi Professor Hong,/";
	char s2[] = " this is a strcat test!";
	strcatMe(s1,s2);

	char s3[1000] = "I named it strcatMe because/";
	char s4[] = " strcat is already defined and it gave me a warning.";
	strcatMe(s3,s4);

	char s5[1000] = "This is String 5; now we append string 6:/";
	char s6[] = " This is String 6! Ta-da!";
	strcatMe(s5,s6);

	printf("Strings 1 and 2: %s\n", s1);
	printf("Strings 3 and 4: %s\n", s3);
	printf("Strings 5 and 6: %s\n", s5);
	
	return 0;
}


