#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-4
#define MAXN 10090
using namespace std;


// link para formacao teorica sobre o assunto : https://en.wikipedia.org/wiki/Closest_pair_of_points_problem#Planar_case


typedef pair<double,double> Point;
#define x first 
#define y second
 
 
Point P[MAXN];

double dist(Point a,Point b)
{	return hypot(a.x - b.x,a.y - b.y); }

bool cmpX(Point a,Point b)
{	return a.x > b.x; }
bool cmpY(Point a, Point b)
{	return a.y > b.y; }

double VerificaFaixa(Point faixa[], int size, float d) // pega menor distancia entre pontos que estao na faixa selecionada
{
    double TamFaixa = d,temp; 		 // tamanho da faixa a ser varrida 
    sort(faixa,&faixa[size],cmpY);	 // ordernar pela coordenacao Y
    
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (faixa[j].y - faixa[i].y) < TamFaixa; ++j){		// O(n²) -> forca bruta mesmo com pequena poda
            temp = dist(faixa[i],faixa[j]);
            if (temp < TamFaixa)	TamFaixa = temp;
		}
    return TamFaixa;
}

double ClosestPairPoints(int l, int r){

    if ((r-l) <= 3){ // so 3 pontos , mete o loco e faz na força bruta 
	    double distmin = INF;
		for(int i = l; i < r; ++i)
			for(int j = i+1; j < r; ++j)
				if(dist(P[i], P[j]) < distmin)  distmin = dist(P[i], P[j]);
		return distmin;	
	}
	
    int mid = (l+r)/2	   ,	pos = 0;
    Point midPoint = P[mid],	faixa[r-l+2];// ponto que esta no centro da faixa de pontos que iremos verificar
    
    double dl = ClosestPairPoints(l,mid);			// menor distancia na faixa da esquerda 
    double dr = ClosestPairPoints(mid+1,r);			// menor distancia na faixa da direita
    double d = min(dl, dr);							// distancia minima(esquerda,direita) -- amplitude da faixa 	
    
    for (int i = l; i < r; i++){	// obtenção dos pontos que estão na faixa desejada, entao no intervalo da amplitude em relacao a x 						
        if ( abs(P[i].x - midPoint.x)  < d)
            faixa[pos++] = P[i];
	}
    return min(d, VerificaFaixa(faixa, pos, d) );
}
 
 
int main(){
		
	//~ freopen("in","r",stdin);	
	
	int n,i;
	double ans;
	
	while(scanf(" %d",&n),n){
		for(i = 0 ; i < n ; ++i) scanf(" %lf %lf",&P[i].x,&P[i].y);
		
		sort(P,&P[n],cmpX); // ordenar em relação a X, antes de chamar a funcao
		ans = ClosestPairPoints(0,n);
		
		if(ans > 10000.0) puts("INFINITY");
		else printf("%.4lf\n",ans);
	}
	return 0;
}
