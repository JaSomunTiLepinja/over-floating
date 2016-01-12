#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

int main(void)
{
	int size = 16;
	int sizeBytes = size * sizeof(int32_t);
	int32_t *x = malloc(sizeBytes);
	int32_t *y = malloc(sizeBytes);
	int32_t *s = malloc(sizeBytes);

	clock_t tic,toc;

	int ish;
	unsigned long ans,idiv;

	// TODO Generate input data
	for(int i = 0; i < size; ++i) {
		x[i] = random() % 10;
		y[i] = x[i]^( x[i]/2 );
	}


	printf("Running on DFE.\n");
	tic = clock();
		CpuStream(size, y, s);
	toc = clock();
	printf("Elapsed: %f seconds\n",(double)(toc-tic) / CLOCKS_PER_SEC);


	printf("Running on C.\n");
	tic = clock();
		for(int i = 0; i < size; ++i) {
			ish=1;
			ans=y[i];
			for (;;) {
				ans ^= (idiv=ans >> ish);
				if (ish == 16) break;
				ish <<= 1;
			}
			y[i] = ans;
		}
	toc = clock();
	printf("Elapsed: %f seconds\n",(double)(toc-tic) / CLOCKS_PER_SEC);


	// TODO Use result data
	for(int i = 0; i < size; ++i)
		if ( s[i] != y[i] )
			{printf("Difference on [%d] element: \n%d, %d\n", i, s[i], y[i]); }

	printf("Done.\n");
	return 0;
}


