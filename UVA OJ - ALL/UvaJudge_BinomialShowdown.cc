#include <bits/stdc++.h>
using namespace std;
#define M 99999
typedef unsigned long long ull;
typedef pair<ull,ull> ii;

map<ii,ull> pd;

ull C(ull n,ull k){
	if(n == k || k == 0)return 1;
	ii pos = ii(n,k);
	if(pd.find(pos) != pd.end()) return pd[pos];
	return pd[pos] = C(n-1,k-1) + C(n-1,k);
}


ull f(ull n, ull k){
	
#include <bits/stdc++.h>
using namespace std;
#define M 99999
typedef unsigned long long ull;
typedef pair<ull,ull> ii;

int main() {
	int n,k,i;
	ull ans;
	
	while (scanf("%d %d", &n, &k), n || k) {
		ans = 1;
		if (k > (n / 2)) k = n - k;
		for (i = 0; i < k; i++)
			ans *= (n - i),ans /= (1 + i);
		printf("%llu\n", ans);
	}
	return 0;
}


}





int main(){
	
	freopen("in","r",stdin);
	
	ull n,k;
	while(scanf(" %llu %llu",&n,&k),n||k) printf("%llu\n",C(n,k));
	return 0;
}
