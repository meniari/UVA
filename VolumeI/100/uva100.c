#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE   80
#define MAX_NUMBER 1000000

int n1problem(int n, int cnt) {
	cnt++;
	if(n == 1)
		return cnt;
	if(n%2 == 0)
		return n1problem(n/2, cnt);
	else
		return n1problem(3*n+1, cnt);
}

int getMaximumLengthCycle(int i, int j) { 
	int k, result, max;
	max = 0;
	for(k=i; k<=j; k++) { 
		result = n1problem(k, 0);
		if(result > max)
			max = result;
	}
	return max;
}

int main(int argc, char **argv) {
	FILE *f, *g;
	int max, aux = -1;
	int cnt, i, j, nb;
	char line[MAX_LINE];

	f = fopen("in.txt", "r");
	if(f == NULL) {
		printf("Error: cannot open the output file.");
		exit(0);
	}

	g = fopen("out.txt", "w");
	if(g == NULL) { 
		printf("Error: cannot open the output file.");
		exit(0);
	}

	while(fgets(line, sizeof(line), f) != NULL) {
		sscanf(line, "%d %d", &i, &j);
		if(((i>0) && (i<MAX_NUMBER)) && ((j>0) && (i<MAX_NUMBER))) {
			max = getMaximumLengthCycle(i, j);
			fprintf(g, "%d %d %d\n", i, j, max);
		}
	}
	fclose(f);
	fclose(g);
	return 0;
}
