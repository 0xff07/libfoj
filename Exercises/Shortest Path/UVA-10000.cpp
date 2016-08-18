#include<cstdio>
#include<cstring>
using namespace std;

#define MAXNODE 110
#define _OO -1000000000
int dist[MAXNODE][MAXNODE];

int main()
{
	int CASE = 0;
	int n, s;
	while(scanf("%d", &n) != EOF && n){
		scanf("%d", &s);
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= n; j++){
				dist[i][j] = (i == j) ? 0 : _OO;
			}
		}
		
		int b, t;
		while(scanf("%d%d", &b, &t) != EOF && b)
			dist[b][t] = 1;

		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++){
					if(dist[i][k] == _OO || dist[k][j] == _OO)
						continue;
					int alt = dist[i][k] + dist[k][j];
					dist[i][j] = alt > dist[i][j] ? alt : dist[i][j];
				}

		int max = _OO;
		for(int i = 1; i <= n; i++){
			max = (dist[s][i] > max)? dist[s][i] : max;
		}
		for(int i = 1; i <= n; i++){
			if(dist[s][i] == max){
				printf("Case %d: The longest path from %d has length %d, ", ++CASE, s, dist[s][i]);
				printf("finishing at %d.\n\n", i);
				break;
			}
		}

	}
	return 0;
}
