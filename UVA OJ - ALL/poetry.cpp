#include <bits/stdc++.h>
using namespace std;

int main(){
	register int q;
	
	
	scanf("%d",&q);
	while(q--){
		char s1[100],s2[100],s3[100],s4[100],s5[100],s6[100];
		s1[0] = s2[0] = s3[0] = s4[0] = s5[0] = '\0';
		
		scanf(" %[^<] %[^>] %[^<] %[^>] %[^\n] " ,s1,s2,s3,s4,s5);
		scanf(" <><>%[^...]",s6);
		
		printf("%s%s%s%s%s\n",s1,s2,s3,s4,s5);
		printf("%s%s%s%s%s\n",s6,s4,s3,s2,s5);
	}


	return 0;
}
