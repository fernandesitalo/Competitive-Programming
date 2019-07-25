#include <bits/stdc++.h>
using namespace std;

#define rep(i__,TAM) for(int i__ = 0 ; i__ < TAM ; ++i__)
#define INF 99999

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dist[101][101];
int aux[101][101];

void floyd(int V){
	
	memcpy ( aux, dist, sizeof aux );
	
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int aj = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }


}


int main(){
	freopen("e","r",stdin);
	
	int q,n,e,t;
	scanf(" %d",&q);
	
	while(q--){
		scanf(" %d %d %d",&n,&e,&t);
		
		
		adj.assign(n+4,vii());
		int u,v,c,tam;
		scanf(" %d",&tam);
		
		memset(dist,INF,sizeof dist);
		
		rep(i,tam){
			scanf("%d %d %d",&u,&v,&c);
			aux[u][v] = c;		
		}
		
		
		u = 1;
		for(int i = 1 ; i <= n ; ++i){
			if(i != e){
				floyd(i);			
				if(t >= dist[e]) u++;
			}
		}
		printf("%d\n",u);
		if(q)puts("");
	}	
	return 0;
}
