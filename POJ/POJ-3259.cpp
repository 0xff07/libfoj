#include<cstdio>
using namespace std;
#define MAXNODE 5100
#define MAXEDGE 25100
#define OO 1000000000

int main()
{
	int b[MAXEDGE], t[MAXEDGE], w[MAXEDGE];
	int F, N, M, W;
	scanf("%d", &F);
	for(int index = 0; index < F; index++){
		scanf("%d%d%d", &N, &M, &W);
		int size = 0;
		int dist[MAXNODE];
		for(int i = 0; i < N; i++){
			dist[i] = OO;
		}
		dist[1] = 0;

		for(int i = 0; i < M; i++){
			scanf("%d%d%d", &b[size], &t[size], &w[size]);
			++size;
			b[size] = t[size-1];
			t[size] = b[size-1];
			w[size] = w[size-1];
			++size;
		}
		for(int i = 0; i < W; i++){
			scanf("%d%d%d", &b[size], &t[size], &w[size]);
			w[size] = -1 * w[size];
			++size;
		}

		int neg = 0;
		for(int i = 0; i < N - 1; i++){
			for(int j = 0; j < size; j++){
				int alt = dist[b[j]] + w[j];
				if(alt < dist[t[j]] ){
					dist[t[j]] = alt;
				}
			}
		}
		for(int i = 0; i < size; i++){
			int alt = dist[b[i]] + w[i];
			if(alt < dist[t[i]]){
				neg = 1;
				break;
			}
		}
		if(neg)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
