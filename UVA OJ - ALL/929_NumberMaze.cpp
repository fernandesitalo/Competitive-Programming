#include <bits/stdc++.h>
using namespace std;

#define rep(i__,TAM) for(int i__ = 0 ; i__ < TAM ; ++i__)
#define INF 9999

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int dist[1000][1000];
int aux[1000][1000];

int linha,coluna;
	

inline bool valida(int l, int c){ return (l > -1 && c > -1 && l < linha && c < coluna);}

int L[] = {1,-1, 0, 0};
int C[] = {0, 0, 1,-1};

int f(){		
	memset(dist,INF,sizeof dist);
	dist[0][0] = aux[0][0];	
	priority_queue<iii,vector<iii>,greater<iii> >pq;

	pq.push(iii(aux[0][0],ii(0,0)));
	
	while(!pq.empty()){
		int d = pq.top().first;
		ii pos = pq.top().second;
		pq.pop();
		
		if(d > dist[pos.first][pos.second]) continue;
		
		rep(i,4){
			
			if( valida(pos.first+L[i] , pos.second+C[i]) ){
				
				if(dist[ pos.first ][ pos.second ] + aux[ pos.first+L[i] ][ pos.second+C[i]] < dist[ pos.first+L[i] ][ pos.second+C[i] ] ){
					dist[ pos.first + L[i] ][ pos.second + C[i]] = dist[ pos.first ][ pos.second ] + aux[ pos.first+L[i] ][ pos.second+C[i]];
					pq.push(iii(dist[ pos.first+L[i] ][ pos.second+C[i]],ii( pos.first+L[i] , pos.second+C[i])));
				}
			}			
		}
	}	
	
	return dist[linha-1][coluna-1];
}


int main(){	
	//freopen("e","r",stdin);
	
	int q;
	scanf(" %d",&q);
	
	while(q--){
	
		scanf("%d %d",&linha,&coluna);
	
		rep(i,linha){
			rep(j,coluna){
				scanf(" %d",&aux[i][j]);
			}
		}
		printf("%d\n",f());
	}
	
	return 0;
}
