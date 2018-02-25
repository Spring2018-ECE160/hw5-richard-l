## Question 2

(K&R Exercise 5-3) Write a pointer version of the function <code>strcat</code> that we showed in Chapter 2: <code>strcat(s,t)</code> copies the string to to the end of s. Verify that your function works with at least 3 examples.

Compile Steps:

	gcc q2.c -o out2

Output:

	'/' indicates the end of the first string
	Strings 1 and 2: Hi Professor Hong,/ this is a strcat test!
	Strings 3 and 4: I named it strcatMe because/ strcat is already defined and it gave me a warning.
	Strings 5 and 6: This is String 5; now we append string 6:/ This is String 6! Ta-da!
