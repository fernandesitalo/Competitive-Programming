#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct ponto {
    long long x, y;
};
#define eps 1e-8


/// determinante bruto mesmo
long long cross(ponto o, ponto a, ponto b) {
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}



bool cmp(ponto a, ponto b) {
  if(a.x != b.x)
      return a.x < b.x; /// menor x
  return a.y < b.y; /// menor y
}


int monotone(ponto p[], int n, ponto ch[]) {
    sort(p, p+n, cmp);
    int i, top = 0, t;

    // top é o topo da "pilha"

    // CASCO DE BAIXO
    for(i = 0; i < n; i++) {
      /// PELO MENOS 2 PONTOS....
      /// tira todos os pontos que estao a direita da linha (ch[top-2],ch[top-1]);
      while(top >= 2 && cross(ch[top-2], ch[top-1], p[i]) <= 0) top--;

      ch[top++] = p[i]; // coloca
    }

    // CASCO DE CIMA
    for(i = n-2, t = top+1; i >= 0; i--) {
      // conserva o casco de cima já formado
      // tira todos pontos que estao a 'direita' da linha (ch[top-1],ch[top-2])
      while(top >= t && cross(ch[top-2], ch[top-1], p[i]) <= 0) top--;

      ch[top++] = p[i]; // coloca
    }

    return top-1;
}

ponto p[100005], ch[200005];
int main() {

    freopen("in","r",stdin);

    int t, n, m, i, j;
    char cc;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(i = 0, j = 0; i < n; i++) {
            scanf("%lld %lld %c", &p[j].x, &p[j].y, &cc);
            if(cc == 'Y')   j++;
        }
        m = monotone(p, j, ch);
        printf("%d\n", m);
        for(i = 0; i < m; i++)
            printf("%lld %lld\n", ch[i].x, ch[i].y);
    }
    return 0;
}
