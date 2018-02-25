#include <stdio.h>
#include <ctype.h>

//getfloat still returns an int, but it's written to *pn the actual float.

// K&R Pg. 97
int getch();
void ungetch(int);

#define BUFSIZE 100

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getch(void) // get a (possibly pushed back) charater
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
		//printf(c);
        buf[bufp++] = c;
}

int getfloat(double *pn)
{
    int c, sign, adSign; //adSign 
	double holder;
	int place = 1;
	double afterDec = 0;

    while (isspace(c = getch())) // skip white space
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') // && c != '.')
    {
        ungetch(c); // it's not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;  //check the sign
	adSign = sign;

    if (c == '+' || c == '-') //pass the sign
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
	
	if(c == '.') {
		c = getch();
	}
	//the following for loop gets the characters after the decimal
	for (holder = 0; isdigit(c); c = getch(),place*=10) {
        holder = 10 * holder + (c - '0');
	}
	//append the newfound digits by adding it to the previous determined answer
	//but make sure the sign is right
	afterDec = adSign*(holder/place);
	*pn+=afterDec;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main()
{
    int c;
	double pn;
	for(int i = 0; i < 3; i++) {
    	c = getfloat(&pn);
    	printf("c=%d pn=%f\n", c, pn);
		c = 0;
		pn = 0;
	}    
	return 0;
}
