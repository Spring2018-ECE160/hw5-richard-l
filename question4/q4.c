#include <stdio.h>
#include <string.h>

int strncpyMe(char *s, char *t, int numChar) {
	for(int i = 0; i < numChar; i++) {
		*(s+i) = *(t+i);
	}
	return 0;
}

int main()  {
	//I know single letter variable names are not too good, but in the
	//spirit of K&R, and how the problem was presented, I followed the trend.
	char empty[100] = "";
	char s[100] = "";
	char t[] = "yada yada tada";
	char u[] = "second string";
	char v[] = "copy this finally";

	int len1 = 12;
	int len2 = 10;
	int len3 = 6;

	int sSize = sizeof(s)/sizeof(s[0]);

	int tSize = strlen(t);
	int uSize = strlen(u);
	int vSize = strlen(v);

	if(tSize <= sSize) {
		strncpyMe(s,t,len1);
		printf("%s\n", s);
	}
	else {
		printf("Error, not enough space to copy t into s");
	}
	
	strncpy(s, empty, 100); //empty out the string so that it's clear for the next one

	if(uSize <= sSize) {
		strncpyMe(s,u,len2);
		printf("%s\n", s);
	}
	else {
		printf("Error, not enough space to copy u into s");
	}
	
	//we don't do it here, so now there will be some garbage from last one left

	if(vSize <= sSize) {
		strncpyMe(s,v,len3);
		printf("%s\n", s);
	}
	else {
		printf("Error, not enough space to copy v into s");
	}
	return 0;
}
