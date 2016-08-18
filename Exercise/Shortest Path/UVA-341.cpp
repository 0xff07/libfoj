#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN 1000
#define MAXEDGE 50000
#define OO 2000000000

int b[MAXEDGE];
int w[MAXEDGE];
int t[MAXEDGE];
int p[MAXEDGE];
int dist[MAXN];

int main()
{
	int N;
	int CASE = 0;
	while(scanf("%d", &N) != EOF && N){
		memset(b, 0, sizeof(int)*(N + 1));
		memset(w, 0, sizeof(int)*(N + 1));
		memset(t, 0, sizeof(int)*(N + 1));
		for(int i = 1; i <= N; i++){
			p[i] = i;
			dist[i] = OO;
		}
		int size = 0;
		for(int i = 1; i <= N; i++){
			int M;
			scanf("%d", &M);
			while(M--){
				b[size] = i;
				scanf("%d%d", &t[size], &w[size]);
				size++;
			}
		}
		int from, to;
		scanf("%d%d", &from, &to);
		dist[from] = 0;
		for(int i = 1; i <= N; i++){
			for(int j = 0; j < size; j++){
				int alt = dist[b[j]] + w[j];
				if(alt < dist[t[j]]){
					dist[t[j]] = alt;
					p[t[j]] = b[j];
				}
			}
		}
		int path[MAXN];
		int len = 0;
		memset(path, 0, sizeof(int)*(N + 1));
		for(int i = to; i != p[i]; i = p[i])
			path[len++] = i;
		printf("Case %d: ", ++CASE);
		printf("Path = ");
		printf("%d ", from);
		for(int i = 0; i < len; i++){
			printf("%d", path[len - i - 1]);
			if(i != len-1)
				printf(" ");
		}
		printf("; ");
		printf("%d second delay\n", dist[to]);
		
	}
	return 0;
}
