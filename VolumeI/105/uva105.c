#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int main(int argc, char **argv) { 
	int left, right, height;
	int *buildings;
	int i, j;
	int start;
	int startBuilding, stopBuilding;
	int lastH;

	startBuilding = MAX;
	stopBuilding = 1;
	buildings = (int *) calloc(MAX, sizeof(int));

	while (scanf("%d %d %d", &left, &height, &right)!= EOF) {		
		if (startBuilding > left)
			startBuilding = left;
		
		if (stopBuilding < right)
			stopBuilding = right;

		for (i=left; i<right; ++i)
			if (buildings[i] < height)
				buildings[i] = height;
	}
	
	lastH = buildings[startBuilding];
	printf("%d %d ", startBuilding, lastH);
	for (i=startBuilding+1; i<=stopBuilding; ++i) {
		if (buildings[i] != lastH){
			lastH = buildings[i];
			printf("%d %d", i, lastH);
		}
	}
	printf("\n");

	free(buildings);
	return 0;
}
