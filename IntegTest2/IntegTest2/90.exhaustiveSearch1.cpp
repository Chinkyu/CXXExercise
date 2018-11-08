#if 0
#include <stdio.h>

#define N 6

#define ONE -8
#define INF -9

void exhaustiveSearch1() {
	int i, j, k, l, m, n, o;
	int zero_tab[N] = { ONE, 0, ONE, 7, ONE, 1 };
	int idx_tab[N];


	for (i = 0; i < N; i++) {
		if (zero_tab[0] != ONE) { idx_tab[0] = zero_tab[0]; }
		else idx_tab[0] = i;
		for (j = 0; j < N; j++) {
			if (zero_tab[1] != ONE) { idx_tab[1] = zero_tab[1]; }
			else idx_tab[i] = j;
			for (k = 0; k < N; k++) {
				if (zero_tab[2] != ONE) { idx_tab[2] = zero_tab[2]; }
				else idx_tab[2] = k;
				for (l = 0; l < N; l++) {
					if (zero_tab[3] != ONE) { idx_tab[3] = zero_tab[3]; }
					else idx_tab[3] = l;
					for (m = 0; m < N; m++) {
						if (zero_tab[4] != ONE) { idx_tab[4] = zero_tab[4]; }
						else idx_tab[4] = m;
						for (n = 0; n < N; n++) {
							if (zero_tab[5] != ONE) { idx_tab[5] = zero_tab[5]; }
							else idx_tab[5] = n;

							//printf("%d %d %d %d %d %d\n", i, j, k, l, m, n);
							for (o = 0; o < N; o++) {
								printf("%d ", idx_tab[o]);
							}
							printf("\n");


							if (zero_tab[5] != ONE) break;
						}
						if (zero_tab[4] != ONE) break;
					}
					if (zero_tab[3] != ONE) break;
				}
				if (zero_tab[2] != ONE) break;
			}
			if (zero_tab[1] != ONE) break;
		}
		if (zero_tab[0] != ONE) break;
	}


}


int zero_tab[N] = { ONE, 0, ONE, 7, ONE, 1 };
int idx_tab[N];
void exhaustiveSearch2(int idx) {
	if (idx >= N) {
		for (int j = 0; j < N; j++) {
			printf("%d ", idx_tab[j]);
		}
		printf("\n");
		return;
	}

	if (zero_tab[idx] != ONE) {
		idx_tab[idx] = zero_tab[idx];
		exhaustiveSearch2(idx + 1);
		return;
	}

	for (int i = 0; i < N; i++) {
//		printf("%d ", i);
		idx_tab[idx] = i;
		exhaustiveSearch2(idx + 1);
	}

}


int ex3_tbl[N];
void ex3_init() {
	for (int i = 0; i < N; i++) ex3_tbl[i] = 0;
}
void ex3(int idx) {

	if (idx >= N) {
		// print result.. or do testing. 
		for (int j = 0; j < N; j++) {
			printf("%ld", ex3_tbl[j]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		ex3_tbl[idx] = i;
		ex3(idx + 1);
	}
}

void main() {

	// using for loop
//	exhaustiveSearch1();

	// using recursion
	//exhaustiveSearch2(0);

	ex3(0);

	getchar();
}
#endif