#include <bits/stdc++.h>
#define M 1009
using namespace std;

string s1,s2; // size n, size m

int pd[M][M],pos;

// ed ->EditDist
int ed(int n, int m){ // S1 -> S2
	
  if(n == 0) return m;
  if(m == 0) return n;
	
	int &ref = pd[n][m];
	
	if(ref != -1) return ref;
	
	if(s1[n-1] == s2[m-1]) return ref = ed(n-1,m-1);
	
	return ref = 1 + min(ed(n-1,m),min(ed(n,m-1),ed(n-1,m-1)));
}


int main(){
  
  //~ freopen("in","r",stdin);
  
  int n,m,i,j;
  
  while(scanf(" %d",&n) == 1){
      cin>>s1;
      scanf(" %d",&m);
      cin>>s2;
      
      for(i = 0 ; i  <= n ; ++i)
        for(j =0 ; j <= m ; ++j)
          pd[i][j] = -1;
      
      printf("%d\n",ed(n,m));
  }
  
  return 0;
}
