#include <stdio.h>
#include <string.h>

int strend(char *s, char *t, int sLen, int tLen) {
	int tCount;	
	if(sLen < tLen) {
		return 0;
	}
	int diff = sLen - tLen;
	for(int i = diff; i < sLen; i++) {
 		if (*(s+i) != *(t+tCount)) {
			return 0;
		}
	tCount++;
	}
	return 1;
}

int main()  {
	char s[] = "atest";
	char t[] = "test";
	output = strend(s,t,strlen(s),strlen(t));
	printf("Output: %d\n", output);
	return 0;
}
