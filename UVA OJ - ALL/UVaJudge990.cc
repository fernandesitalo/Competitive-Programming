#include <bits/stdc++.h>
using namespace std;

int pd[31][1001];
int tempo[31];
int ouro[31];
int N;


int tesouro(int idx, int disp){
	if(idx == N || disp == 0) return 0;
	
	if(pd[idx][disp] != -1) return pd[idx][disp];
	
	if(disp >= tempo[idx])
		pd[idx][disp] = max(ouro[idx] + tesouro(idx+1,disp - tempo[idx]),
							tesouro(idx+1,disp));
	else pd[idx][disp] = tesouro(idx+1,disp);
	
	return pd[idx][disp];
}

vector<int> ans;

int rec(int idx,int disp){
	if(disp == 0 || idx == N) return 0;
	
	if(disp >= tempo[idx]){
		if(tesouro(idx+1,disp) == pd[idx][disp]) 
			rec(idx+1,disp);
		else {			
			rec(idx+1,disp-tempo[idx]);ans.push_back(idx);
		}
	}
	else rec(idx+1,disp);
}


int main(){   // freopen("in","r",stdin);
	
	int prof[31],t,w;
		
	bool line = false;	
	while(scanf(" %d %d",&t,&w)!= EOF){
		
		scanf(" %d",&N);
		for(int i = 0 ; i < N ; ++i){
			scanf("%d %d",&prof[i],&ouro[i]);
			tempo[i] = prof[i]*w + prof[i]*2*w;
		}
		
		if(line)puts(""); line = true;
		
		
		memset(pd,-1,sizeof pd);
		printf("%d\n",tesouro(0,t));
		rec(0,t);
		printf("%d\n",(int)ans.size());
		
		while((int)ans.size() > 0){
			int aux = ans.back(); ans.pop_back();
			printf("%d %d\n",prof[aux],ouro[aux]);			
		}
	}
		
	return 0;
}

