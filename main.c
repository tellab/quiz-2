#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool sumsTo(uint x[], uint n, uint k, uint v) {
	if(v==0 && k==0) {
		return true;
	}
	if(v!=0 && k==0) {
		return false;
	}
	if(n==0) {
		return false;
	}
	int res1 = 0;
	if(v >= x[0]) {
		res1 = sumsTo(x+1, n-1, k-1, v-x[0]);
	}
	int res2 = sumsTo(x+1, n-1, k, v);
	if ((res1 + res2) > 0) {
	    return true;
	} else {
	    return false;
	}
}

void main(void) {
    int array1[5] = {1,2,3,4,5};
    printf("result1: %d (should be true)\n", sumsTo(array1, 5, 2, 3));

    int array2[10] = {1,3,5,7,9,10,20,30,40,50};
    printf("result2: %d (should be true)\n", sumsTo(array2, 10, 3, 16));

    int array3[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}; //total = 20
    printf("result3: %d (should be false)\n", sumsTo(array3, 20, 20, 20));
}