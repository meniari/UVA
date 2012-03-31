#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long ackerman(long n, long cnt) { 
	cnt++;
	if(n == 1)
		return cnt;
	if(n%2 == 0)
		return ackerman(n/2, cnt);
	else
		return ackerman(3*n+1, cnt);
}

int main(int argc, char **argv) { 
	long i, j, max, k, result, nb, aux, n;

	while(scanf("%ld %ld", &i, &j)) {
		if((i == 0) && (j == 0))
			break;

		if(i > j) {
			aux = i;
			i = j;
			j = aux;
		}
		max = 0;
		 for(k=i; k<=j; k++) {

			 n = k;
			 result = 0;
			 do {
				 if(n%2 == 0)	n = n/2;
				 else n = n*3 + 1;
				 result++;
			 } while(n != 1);

			 if(max < result) {
				 max = result;
				 nb = k;
			 }
		 }
		 printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n", i, j, nb, max);
	}

	return 0;
}
