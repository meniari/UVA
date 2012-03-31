#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX			3
#define PERMUT		6
#define BROWN		'B'
#define GREEN		'G'
#define CLEAR		'C'
#define BINS		9
#define MAX_LINE	80

char bin[MAX];
char bins[PERMUT][MAX];
int movements[PERMUT];
int positions[MAX], step;
int cant[BINS];

void print() {
	int i;
	for (i=1; i<=MAX; i++) {
		bins[step][i] = bin[positions[i]];
	}
	step++;
}

int valid(int p) {
	int i;
	for (i=1; i<p; i++)
		if (positions[i] == positions[p])
			return 0;
	return 1;
}

void permute(int p) {
	int found;
	int i, j;

	for (i=1; i<=MAX; i++) {
		positions[p] = i;
		if (valid(p))
			if (p == MAX)
				print();
			else 
				permute(p+1);
	}
}

int main(int argc, char **argv) { 
	int i, j;
	int min;
	int posit;
	int step = 1;
	char bin1, bin2, bin3;
	
	while(scanf("%d %d %d %d %d %d %d %d %d", &cant[0], &cant[1], &cant[2], &cant[3], &cant[4], &cant[5], &cant[6], &cant[7], &cant[8]) != EOF) {
		
		min = cant[3]+cant[6]+cant[2]+cant[8]+cant[1]+cant[4];
		bin1 = 'B';	bin2 = 'C';	bin3 = 'G';

		movements[2] = cant[3]+cant[6]+cant[2]+cant[5]+cant[1]+cant[7];
		if (min>movements[2]) {
			bin1 = 'B';	bin2 = 'G';	bin3 = 'C';
			min = movements[2];
		}

		movements[3] = cant[0]+cant[6]+cant[5]+cant[8]+cant[1]+cant[4];
		if (min>movements[3]) {
			bin1 = 'C';	bin2 = 'B';	bin3 = 'G';
			min = movements[3];
		}
	
		movements[4] = cant[0]+cant[3]+cant[5]+cant[8]+cant[1]+cant[7];
		if (min>movements[4]) {
			bin1 = 'C';	bin2 = 'G';	bin3 = 'B';
			min = movements[4];
		}

		movements[5] = cant[0]+cant[6]+cant[2]+cant[5]+cant[4]+cant[7];
		if (min>movements[5]) {
			bin1 = 'G';	bin2 = 'B';	bin3 = 'C';
			min = movements[5];
		}

		movements[6] = cant[0]+cant[3]+cant[2]+cant[8]+cant[4]+cant[7];
		if (min>movements[6]) {
			bin1 = 'G';	bin2 = 'C';	bin3 = 'B';
			min = movements[6];
		}

		printf("%c%c%c %d\n", bin1, bin2, bin3, min);
	}
	return 0;
}
