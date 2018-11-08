#if 0
// my dijikstra..... 
#include <stdio.h>

#define MAX_N 100
#define V 9
#define INFINIT 99

#define IS_SPG 0
#define MIN_D 1

#define debug 1
//unsigned int h[MAX_N];
//int T;

int spg[V][2];   // 0: is in group, 1 : distance;

void init() {
	int i, j;

	for (i = 0; i < V; i++) {
		spg[i][IS_SPG] = 0;
		spg[i][MIN_D] = INFINIT;
	}
}

// ckkang V0.1 version. !!!! 
void dijkstra1(int g[V][V], int idx) {
	int i;

	spg[idx][IS_SPG] = 1;

	// breadth first search
	for (i = 0; i < V; i++) {
		int nxt_dist = g[idx][i];
		if (nxt_dist == 0) continue;

		if (idx == 3) {
			printf("%d", spg[i][MIN_D]);
		}

		if (spg[i][MIN_D] > spg[idx][MIN_D] + nxt_dist) {  // if spg destination is larger than this + distance
			spg[i][MIN_D] = spg[idx][MIN_D] + nxt_dist;
			// if change inside spg -> call one more
			if (spg[i][IS_SPG] == 1) {
				dijkstra1(g, i);
			}

		}
		if (spg[i][IS_SPG] == 0) {
			dijkstra1(g, i);
		}
	}
}

int main(void)
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = {
		{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
		{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	init();
	spg[0][MIN_D] = 0;
	dijkstra1(graph, 0);

	if (debug) {
		int i;
		for (i = 0; i < V; i++) {
			printf("node %d : is_spg = %d, shortest_length = %d\n", i, spg[i][IS_SPG], spg[i][MIN_D]);
		}

	}

	getchar();
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}

#endif