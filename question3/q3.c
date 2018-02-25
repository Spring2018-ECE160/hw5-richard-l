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
	char u[] = "no matches here";
	char v[] = "bla bla bla";
	char w[] = "white space matches     ";
	char x[] = "   ";
	int output1 = strend(s,t,strlen(s),strlen(t));
	printf("Output 1 (should be 1): %d\n", output1);

	int output2 = strend(u,v,strlen(u),strlen(v));
	printf("Output 2 (should be 0): %d\n", output2);

	int output3 = strend(w,x,strlen(w),strlen(x));
	printf("Output 3 (should be 1): %d\n", output3);
	return 0;
}
