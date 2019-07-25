#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int coins[26];
int N;

int minCoins( int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V+1];
 
    // Base case (If given value V is 0)
    table[0] = 0;
 
    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
 
    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[V];
}



int main(){
	
//freopen("it","r",stdin);
	
	int t,m;
	for(scanf(" %d",&t);t--;){
		scanf(" %d %d",&N,&m);
		for(int i = 0 ; i < N ; ++i) scanf(" %d",coins+i);

		printf("%d\n",minCoins(N,m));
	}
	return 0;
}
