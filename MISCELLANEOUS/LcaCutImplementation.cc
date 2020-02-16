#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define maxn 10000
typedef long long ll;
 
vector<int> g[maxn];
int n;
 
int pai[maxn][20];
// pai[x][i] = pai a uma distancia 2^i do vertice x
 
int h[maxn];
 
void dfs(int x, int p) {
    pai[x][0] = p;
    for(int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if(y == p) continue;
        h[y] = h[x] + 1;
        dfs(y, x);
    }
}
 
void calc() {
    for(int i = 1; i < 20; ++i) {
        for(int x = 0; x < n; ++x) {
            // pai[x][i] = pai[ pai[x][i-1] ][i-1];
            int p1 = pai[x][i-1];
            int p2 = pai[p1][i-1];
            pai[x][i] = p2;
        }
    }
}
 
int lca(int x, int y) {
    if(h[y] > h[x]) swap(x, y);
    int dist = h[x] - h[y];
   
    for(int i = 0; i < 20; ++i) {
        if(dist & (1<<i)) {
            x = pai[x][i];
        }
    }
    if(x == y) return x;
     
    for(int i = 19; i >= 0; --i) {
        if(pai[x][i] != pai[y][i]) {
            x = pai[x][i];
            y = pai[y][i];
        }
    }
    return pai[x][0];
}
 
int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, 0);
    calc();
    
    
    while(1){
		int a,b;
		cin>>a>>b;
		cout << lca(a,b);
		
	}
    
 
    return 0;
}
