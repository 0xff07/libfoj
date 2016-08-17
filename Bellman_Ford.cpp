#include<cstdio>
using namespace std;
#define MAXNODE 200000
#define MAXEDGE 200000
#define OO 2000000000


int main()
{
	long b[MAXEDGE], t[MAXEDGE], w[MAXEDGE];
	int N, T;
	while(scanf("%d%d", &T, &N) != EOF){

		/* initialize */
		int dist[MAXNODE];
		for(int i = 1; i <= N; i++){
			dist[i] = OO;
		}
		dist[N] = 0;
		
		/* add edge in one direction */
		for(int i = 0; i < T; i++)
			scanf("%ld%ld%ld", &b[i], &t[i], &w[i]);

		/* add edge in reverse direction */
		for(int i = 0; i < T; i++){
			b[T + i] = t[i];
			t[T + i] = b[i];
			w[T + i] = w[i];
		}

		/* do relaxation */
		for(int i = 0; i <= N; i++){
			for(int j = 0; j < T + T; j++){
				int alt = dist[b[j]] + w[j];
				if(alt < dist[t[j]]){
					dist[t[j]] = alt;
				}
			}
		}

		printf("%d\n", dist[1]);
	}
	return 0;
}
