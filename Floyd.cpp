#include<cstdio>
using namespace std;
#define MAX 110
#define OO 1000000000
//#define DEBUG ON

int G[MAX][MAX];
int main()
{
	int N;
	while(scanf("%d", &N) != EOF && N){

		/* initialize for Floyd */
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(i != j)
					G[i][j] = OO;
				else
					G[i][j] = 0;
			}
		}
	
		/* enter edges */
		for(int i = 1; i <= N; i++){
			int n, v;
			scanf("%d", &n);
			while(n--){
				scanf("%d", &v);
				scanf("%d", &G[i][v]);
			}
		}


		#ifdef DEBUG
		#define DEBUG_SECTION
		printf("original graph.\n");
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++)
				if(G[i][j] != OO)
					printf("%3d", G[i][j]);
				else
					printf("%3d", -1);
			printf("\n");
		}
		#endif

		/* Floyd-Warshal actually starts here */
		for(int k = 1; k <= N; k++)
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= N; j++)
					if(G[i][k] + G[k][j] < G[i][j])
						G[i][j] = G[i][k] + G[k][j];

		#ifdef DEBUG
		#define DEBUG_SECTION
		printf("Floyed graph.\n");
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++)
				if(G[i][j] != OO)
					printf("%3d", G[i][j]);
				else
					printf("%3d", -1);
			printf("\n");
		}
		#endif

		int curi = OO, curj, who, dis = 1;
		for(int i = 1; i <= N; i++){
			curj = 0;
			int flag = 0;
			for(int j = 1; j <= N; j++){
				if(G[i][j] == OO){
					flag = 1;
					break;
				}else if(i != j && G[i][j] > curj){
					curj = G[i][j];
					dis = 0;
				}
			}
			if(!flag && curj < curi){
				curi = curj;
				who = i;
			}
		}
		if(dis)
			printf("disjoint\n");
		else 
			printf("%d %d\n", who, curi);
	}
	return 0;
}
