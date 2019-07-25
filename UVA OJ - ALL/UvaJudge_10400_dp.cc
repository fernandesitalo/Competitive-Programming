#include <bits/stdc++.h>
#define Y 32000
using namespace std;

typedef long long ll;

int TAM;
ll N;

ll num[200];
char str[200];
bool dp[102][Y*2+5];

bool F(ll n,int idx){	
	
	if(fabs(n) > Y) return false;
	if(TAM == idx && N == n)return true;
	if(idx >= TAM) return false;
	
	if(dp[idx][Y+n] == false) return false;
	
	str[idx-1] = '*';
	if(F(n*num[idx],idx+1)) return dp[idx][Y+n] = true;
	
	str[idx-1] = '+';
	if(F(n+num[idx],idx+1)) return dp[idx][Y+n] = true;
	
	str[idx-1] = '-';
	if(F(n-num[idx],idx+1)) return dp[idx][Y+n] = true;
	
	if(n%num[idx] == 0){
		str[idx-1] = '/';
		if(F(n/num[idx],idx+1)) return dp[idx][Y+n] = true;
	}
	return dp[idx][Y+n] = false;
}	


int main(){
	
	
	int t;
	for(cin>>t;t--;){
		scanf("%d",&TAM);
		for(int i = 0 ; i < TAM ; ++i) scanf(" %lld",num+i);
		scanf(" %lld",&N);
		
		memset(dp,true,sizeof dp);
		
		if(F(num[0],1)){
			int idx = 0;
			printf("%lld",num[0]);
			for(int i = 1 ; i < TAM ; ++i){
				printf("%c%lld",str[idx++],num[i]);
			}
			printf("=%lld\n",N);
		}else{
			puts("NO EXPRESSION");
		}
	}

	
	return  0;
}
