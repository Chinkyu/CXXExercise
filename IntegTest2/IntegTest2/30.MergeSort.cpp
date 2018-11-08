#if 0
#include <stdio.h>

#define debug 1
#define MAX_N 100000

int N, K;

int n[MAX_N];

void init() {
	int i;

	for (i = 1; i < N; i++) {
		n[i] = 0;
	}
}

void dump() {
	for (int i = 0; i < N; i++) {
		printf("%d ", n[i]);
	}
	printf("\n");
}


// merge sort -- my draft version 
int t[MAX_N];

void mergesort1(int *a, int low, int high) {
	long long i, j, k;

	if (high - low == 1) {
		if (a[high] < a[low]) {
			// switch
			int t = a[low];
			a[low] = a[high];
			a[high] = t;
		}
		return;
	}
	else if (high - low < 2) {
		return;
	}

	int mid = (low + high) / 2;
	mergesort1(a, low, mid);
	mergesort1(a, mid + 1, high);

	// merging two number
	i = low;
	j = mid + 1;
	k = 0;
	do {
		t[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

		if (i > mid) { // used up all low -> add high
			while (j <= high) {
				t[k++] = a[j++];
			};
		}
		if (j > high) {
			while (i <= mid) {
				t[k++] = a[i++];
			};
		}
	} while (i <= mid || j <= high);

	for (i = 0; i < k; i++) {
		a[low + i] = t[i];
	}

}

void mergesort2(int *a, int l, int r) {
	int i, j, k, m;

	if (l >= r) return;

	m = (l + r) / 2;
	mergesort2(a, l, m);
	mergesort2(a, m + 1, r);
	for (i = l; i <= m; i++) t[i] = a[i];
	for (j = m + 1; j <= r; j++) t[r - (j - (m + 1))] = a[j];
	i = l; j = r;
	for (k = l; k <= r; k++) {
		a[k] = (t[i] > t[j]) ? t[i++] : t[j--];
	}
}

int main(void)
{
	int i, j;
	int test_case;
	int T;

	freopen("30.MergeSort_input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

//	T = 1;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &K);

		for (i = 0; i < N; i++) {
			scanf("%d", &n[i]);
		}

//		init();
//		if (debug) dump();
		mergesort2(n, 0, N-1);
//		if (debug) dump();

		printf("%d sorting done\n", test_case);

//		printf("#%d %lld\n", test_case, search_sequence());
	}

	getchar();
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}

#endif