#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back
#define PI 2*acos(0)


// 1 -  x > y
// 0 - x == y
// -1  x < y
inline int cmp(long double x,long  double y = 0, long double tol = EPS){
  return (x <= y + tol) ? (x+tol < y) ? -1 : 0 : 1;
}


// template<class type>
struct ponto{
  double x,y;

  ponto(): x(0),y(0){}
  ponto(double x, double y):x(x),y(y){}
  bool operator < (ponto outro){
    if(fabs( x- outro.x ) > EPS) return x < outro.x; // x != x.outro
    return y < outro.y;     // x == x.outro
  }
  bool operator == (ponto outro){
    return (fabs(x-outro.x) < EPS && (fabs(y-outro.y)) < EPS);
  }
};

// rotacionar o ponto p theta graus no sentido horario
// theta deve estar em graus!
ponto rotate(ponto p, double theta){
  double rad = DEG_to_RAD(theta);
  return ponto(p.x*cos(rad) - p.y*sin(rad),p.x*sin(rad) + p.y*cos(rad)); // matriz de rotação CP3
}


double dist(ponto p1,ponto p2){ // distancia euclidiana
  return hypot(p1.x - p2.x,p1.y-p2.y);
}

struct linha{
  double a,b,c;
};

void FazLinha(ponto p1,ponto p2, linha &l){ // dado 2 pontos controi uma linha
  if(fabs(p1.x - p2.x) < EPS){
    l.a = 1.0; l.b = 0.0;  l.c = -p1.x;
  }else {
    l.a = -(double) (p1.y-p2.y)/(p1.x-p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a*p1.x) - p1.y;
  }
}

bool Paralelas(linha l1,linha l2){  //  l1//l2 ?
  return (fabs(l1.a-l2.a) < EPS) && fabs(l1.b-l2.b) < EPS;
}

bool Iguais(linha l1, linha l2){ //      l1 == l2 ?
  return Paralelas(l1,l2) && (fabs(l1.c-l2.c) < EPS);
}

bool Intersecao(linha l1,linha l2,ponto &p){ //   l1 intercepta l2 ?
  if(Paralelas(l1,l2)) return false;
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if(fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
  else                 p.y = -(l2.a * p.x + l2.c);
  return true;
}


//#######################################################################
struct vetor{ // vetor matematico
  double x,y;
  vetor(double x,double y) : x(x), y(y) {}
};

vetor FazVetor(ponto a, ponto b){ // AB = B - A  ---> controi um vetor dado dois pontos
  return vetor(b.x - a.x,b.y - a.y);
}
vetor scale(vetor v, double s){ // multiplicar um scalar s pelo vetor v
  return vetor(v.x*s,v.y*s);
}
ponto translate(ponto p, vetor v){ // p passa a ser origem do vetor v
  return ponto(p.x+v.x,p.y+v.y);
}

double dot(vetor a,vetor b){    // produto escalar, vetor A * vetor B
 return (a.x*b.x + a.y*b.y);
}

double ModuloVetor_semRaiz(vetor v){    // ????????????????????????????????????????????????????
  return v.x*v.x+v.y*v.y;
}
//###################################################

double distToline(ponto p, ponto a, ponto b,ponto &c){ // distancia minima de um ponto a uma linha
  vetor ap = FazVetor(a,p);
  vetor ab = FazVetor(a,b);
  double u = dot(ap,ab) / ModuloVetor_semRaiz(ab);
  c = translate(a,scale(ab,u));
  return dist(p,c);
}

double distTolineSegment(ponto p, ponto a, ponto b, ponto &c){ // distancia do ponto p ao segmento ab
  vetor ap = FazVetor(a,p);
  vetor ab = FazVetor(a,b);
  double u = dot(ap,ab)/ModuloVetor_semRaiz(ab);
  if(u < 0.0){
    c = ponto(a.x,a.y);
    return dist(p,a);
  }
  if(u > 1.0){
    c = ponto(b.x,b.y);
    return dist(p,b);
  }
  return distToline(p,a,b,c);
}


double angle(ponto a, ponto o, ponto b){ // angulo AOB
  vetor oa = FazVetor(o,a);
  vetor ob = FazVetor(o,b);
  return acos(dot(oa,ob)/sqrt(ModuloVetor_semRaiz(oa)*ModuloVetor_semRaiz(ob)));
}

double cross(vetor a, vetor b){ // determinate de 2 vetores...
  return a.x*b.y-a.y*b.x;
}


bool ccw(ponto p, ponto q, ponto r){   /// diz somente esquerda ou direira
  return cross(FazVetor(p,q),FazVetor(p,r)) > 0;
}
bool collinear(ponto p, ponto q, ponto r){ /// diz somente se é da mesma linha
  return fabs(cross(FazVetor(p,q),FazVetor(p,r))) < EPS;
}


/// ORIENTACAO
// 0 e pq os pontos sao colineares
// 1 e pq o ponto p esta a direita da reta ab
// -1 e p1 o ponto p esta a esquerda da reta ab
// importante!!! ponto P primeiro, depois a linha
int det3pontos_ori(ponto p, ponto a, ponto b){
  double det = ((-(p.x*b.y) - (b.x*a.y) -(a.x*p.y)) + (p.y*b.x) + (a.y*p.x) + (b.y*a.x));
  return fabs(det) < EPS ? 0 : det > 0 ? 1 : -1 ;
}

// return (((y[b]-y[a]) * (x[c]-x[b])) == ((x[b]-x[a]) * (y[c]-y[b])));
bool collinear_det(ponto a, ponto b, ponto c){
  return ((b.y - a.y)*(c.x - b.x) == (b.x-a.x) * (c.y-b.y));
}


inline bool le(ponto &p){ if(cin>>p.x>>p.y) return true; return false;}
inline void imprime(ponto p){ cout << p.x<<" " << p.y; }


// produto vetorial, area do paralelogramo formado pelos vetores OA e OB
double cross(ponto origem, ponto a, ponto b) {
    return (a.x-origem.x)*(b.y-origem.y)-(a.y-origem.y)*(b.x-origem.x);   // O -> origem
}


// dado as 3 medianas do triangulo, dá pra calcular sua area
double Area(double mediana1, double mediana2,double mediana3){
    double sm = (mediana1+mediana2+mediana3)/2.0;
    double temp = sm * (sm-mediana1)*(sm-mediana2)*(sm-mediana3);
    if(0 >= temp) return -1; // nao da pra calcular a area com as medianas fornecidas
    else          return 4.0*sqrt(temp)/3.0;
}

// l1 - lado1, l2 - lado2, l3 - lado3
bool ValidaTriangulo(double l1,double l2,double l3){ // condicao de existencia do triangulo
  return cmp(l1 , abs(l3-l2) > 0 && cmp((l3+l2) , l1) > 0 &&
    cmp(l2 , abs(l1-l3)) > 0 && cmp((l1+l3) , l2) > 0 &&
    cmp(l3 , abs(l2-l1)) > 0 && cmp((l2+l1) , l3)) > 0;
}


// contando somente com entradas validas
// maior circulo dentro do triangulo
double RaioDoCirculoDentroDoTriangulo(double ab, double bc, double ca){ // lados do triangulo
  double sp = (ab+bc+ca)/2.0; // semi perimetro
  double area = sqrt(sp*(sp-ab)*(sp-bc)*(sp-ca));
  return area/(0.5*sp*2.0);
}

// menor circulo que contem o triangulo fornecido
double RaioCirculoForaDoTriangulo(double ab, double bc, double ca){
  double sp = (ab+bc+ca)/2.0; // semi perimetro
  double area = sqrt(sp*(sp-ab)*(sp-bc)*(sp-ca));
  return ab*bc*ca/(4.0*area);
}


// linha perpendicular a l, que passa pelo ponto p
void linhaperpendicular(linha l, ponto p, linha &l1){
  // l => ax+by+c = 0

  if(fabs(l.a) < EPS){ // l é horizontal
    l1.a = 1.0;
    l1.b = 0.0;
    l1.c = -p.x;
    return;
  }
  l1.a = -l.b/l.a;
  l1.b = 1.0;
  l1.c = (double) - p.y + (l.b*p.x)/l.a;
}

ponto pontomedio(ponto a, ponto b){
  return ponto((a.x+b.x)/2.0,(a.y+b.y)/2.0);
}



double det2pontos(vetor a, vetor b){
  return ((a.x*b.y) - (b.x*a.y));
}





// dado 2 pontos do circulo e seu raio,achamos seu centro
bool cicle2PtsRad(ponto p1,ponto p2,double r, ponto &c){

  double d2 = (p1.x - p2.x)*(p1.x-p2.x) + (p1.y - p2.y)*(p1.y-p2.y);
  double det = r*r / d2 - 0.25;

  if(det < 0.0) return false;

  double h = sqrt(det);
  c.x = (p1.x+p2.x)*0.5 + (p1.y - p2.y)*h;
  c.y = (p1.y+p2.y)*0.5 + (p1.x - p2.x)*h;
  return true;
}



// dado 3 pontos(A,B,C) da circunferencia e facil achar o centro
// reta ortogonal a reta AB que passa pelo ponto medio entre A e B
// itercecção com
// reta ortogonal a reta BC que passa pelo ponto medio entre B e C
void AchaCentroCircunferencia3Pontos(ponto a, ponto b, ponto c, ponto &CENTRO){

  linha l1,l2,l3,l4;

  FazLinha(a,b,l1);
  FazLinha(c,a,l2);

  linhaperpendicular(l1,pontomedio(a,b),l3);
  linhaperpendicular(l2,pontomedio(c,a),l4);

  ponto p;
  Intersecao(l3,l4,CENTRO);
}


// retorna 0 para dentro do circulo, 1 para borda, 2 para fora do circulo
int dentroCirculo(ponto p, ponto c, double R){
  double dx = p.x - c.x , dy = p.y - c.y;
  double Euc = dx*dx + dy*dy, rSq = R*R;
  return (cmp(Euc,rSq) < 0 ? 0 : fabs(Euc-rSq) < EPS ? 1 : 2);
}


struct retangulo{
  ponto cd,be;//cima direita, baixo esquerda

  retangulo(ponto a, ponto b){
    cd = ponto(max(a.x,b.x),max(a.y,b.y));
    be = ponto(min(a.x,b.x),min(a.y,b.y));
  }

  bool pontoEstaDentro(ponto p){
    return (cd.x > p.x && cd.y > p.y && p.x > be.x && p.y > be.y);
  }
};


struct circulo{
  ponto c;
  double r;
  circulo(ponto c, double r) : c(c) , r(r) {}
  circulo(){}
};




// ########################################################################
              /*FUNCAO DE VERIFICAR SE DOIS SEGMENTOS SE CRUZAM*/

              /*FUNCAO DE OBTER A DISTANCIA MINIMA DE UM SEGMENTO A UM PONTO */

//  1: CW
// -1: CCW
//  0: colinear
inline int orientacao(vetor a, vetor b){ // orientacao do vetor a e b
  ll c = cross(a,b);
  if(c == 0) return 0;
  return c < 0 ? 1 : -1;
}

// Retorna se o ponto p esta entre b e c
bool Entre1(ponto p, ponto b,ponto c){
  return (dist(p,b)+dist(p,c) == dist(b,c));
}

// retona se o ponto p esta no segmento qr
bool Entre2(ponto p,ponto q, ponto r)
{// faz o retangulo e verifica se o ponto esta no retangulo
    return (orientacao(FazVetor(p, q),FazVetor(p, r)) == 0 && // pontos colineares
            p.x <= max(q.x, r.x) && p.x >= min(q.x, r.x) && // entre max(X) e min(X)
            p.y <= max(q.y, r.y) && p.y >= min(q.y, r.y));   // entre max(Y) e min(Y)
}


bool IntersecaoDeSegmentos(ponto p1,ponto q1,ponto p2, ponto q2){

    int o1 = orientacao(FazVetor(p1,q1),FazVetor(p1,p2));
    int o2 = orientacao(FazVetor(p1,q1),FazVetor(p1,q2));
    int o3 = orientacao(FazVetor(p2,q2),FazVetor(p2,p1));
    int o4 = orientacao(FazVetor(p2,q2),FazVetor(p2,q1));

    // caso geral
    if (o1 != o2 && o3 != o4)
        return true;

    // CasosEspeciais

    // p1, q1 e p2 sao colinear e p2 não esta no segmento p1q1
    if (o1 == 0 && Entre1(p2, p1, q1)) return true;

    // p1, q1 e p2 sao colinear e q2 não esta no segmento p1q1
    if (o2 == 0 && Entre1(q2,p1, q1)) return true;

    // p2, q2 e p1 sao colinear e p1 não esta no segmento p2q2
    if (o3 == 0 && Entre1( p1,p2, q2)) return true;

    // p2, q2 e q1 sao colinear e q1 não esta no segmento p2q2
    if (o4 == 0 && Entre1(q1, p2, q2)) return true;

    return false;
}
// r é ponto
// p e q é um segmento

double DistanciaPontoSegmento(ponto r, ponto p, ponto q){

  vetor A = FazVetor(p,r);
  vetor B = FazVetor(q,r);
  vetor C = FazVetor(q,p);

  double a = ModuloVetor_semRaiz(A);
  double b = ModuloVetor_semRaiz(B);
  double c = ModuloVetor_semRaiz(C);

  // não forma triangulo .: a é mais perto de C
  if (cmp(b, a+c) >= 0) return sqrt(a);

  // não forma triangulo .: b é mais perto de C
  if (cmp(a, b+c) >= 0) return sqrt(b);

  return fabs(det2pontos(A,B))/sqrt(c); // altura do triangulo formado....
  // relacoes no triangulo retangulo
}

// ####################################################################



/*



sen (theta) = catetoOposto/Hipotenusa
cos (theta) = catetoAdjacente/Hipotenusa
tan (theta) = catetoOposto/catetoAdjacente


>>>> funcoes trigonometricas que envolvem angulos só funcionam em radianos <<<<

            ^
           /|\
          / |Ĉ\
    (b)  /  |  \    (a)
        /   |h  \
       /    |    \
      /Â____|____B\

          (c)

Area = base*altura* 0.5

area triangulo = (c*altura)/2

      * altura = sen(Â)*b, hipot = b
      * AreaTriangulo = (c*b*sin(A))/2
      * Dá pra isolar sin(A) = 2*Area/(c*b)



*** RELACOES METRICAS NO TRIANGULO RETANGULO ***
.... baseadas em pitagoras e semelhança de triangulos

                      A
                      *
                     *|  *
               (c)  * |     *    (b)
                   *  |(h)     *
                  *   |           *
                 *    |              *
              B * * * H * * * * * * *  *   C
                '-(n)-''------(m)------'
                '-------(a)------------'

>> os triangulos  ABC~ABH~AHC são SEMELHANTES .:
    c/h = b/m = a/b

concluimos que:

*** como c/h = cn    entao:   >>  b^2 = a*n
*** como h/n = m/n   entao:   >>  h^2 = m*n
*** pitagoras   a^2 = b^2 + c^2

>>> 5 RELACOES METRICAS NO TRIANGULO RETANGULO <<<<

  1. b^2 = a*m

  2. a*h = b*c

  3. c^2 = a*n

  4. h^2 = m*n

  5. a^2 = b^2 + c^2

>>>> LEI DOS SENOS <<<<
DIZ QUE:

  a/sen(Â) = b/sen(B) = c/sen(Ĉ)

>>> LEI DOS COSSENOS <<<<

  a^2 = b^2 + c^2 - 2*b*c*cos(Â)

  b^2 = a^2 + c^2 - 2*a*c*cos(B)

  c^2 = b^2 + a^2 - 2*b*a*cos(Ĉ)
*/




/*
  checar se um ponto P esta dentro do triangulo ABC

  area(A,B,C) == area(A,C,P) + area(A,B,P) + area(C,B,P);

  ou

  fazer um poligono convexo de 3 lados...
  usar a funcao....

  ou

  usar produto vetorial .. escolher 2 lados e verificar se o ponto esta entre eles
  escolher outros 2 lados e verificar se o ponto esta entre eles...
*/


// verifica se o ponto P esta dentro triangulo ABC
bool dentroTriangulo(ponto P,ponto A,ponto B,ponto C){

  int a = det3pontos_ori(P,A,B);
  int b = det3pontos_ori(P,A,C);
  int c = det3pontos_ori(P,B,C);

  // verifica se está entre 2 lados
  // verifica se esta entre outros 2 lados...
  // dessa garantimos que esta dentro do triangulo;;
  /// if((a!= b) && (b!= c)) -> considerando borda fora

  if((a!= b || !(a||b)) && (b!= c || !(b||c))){ // considerando borda dentro
    return true;
  }
  return false;
}
// verifica se o ponto P esta dentro triangulo ABC
bool dentroTriangulo2(ponto P,ponto A,ponto B,ponto C){
  double area = fabs(cross(A,B,C))/2.0;

  double area1 = fabs(cross(P,A,B))/2.0;
  double area2 = fabs(cross(P,A,C))/2.0;
  double area3 = fabs(cross(P,C,B))/2.0;

  return fabs(area - (area1+area2+area3)) < EPS;
}


/*
  >> PRODUTO VETORIAL <<   (ou cross)

  DEF.: EH O DETERMINANTE DOS PONTOS FORNECIDOS

  O QUE SIGNIFICA ? REPRESENTA A AREA DO PARALELOGRAMO FORMADO PELO DOS PONTOS/VETORES

  SE É 0 ? OS PONTOS SAO COLINEARES!!!!
  SE É <0 ? ENTAO eh CW (sentido horario - lado direito)
  se É >0 ? ENTAO eh CCW  (sentido anti horario - lado esquerdo)

*/



//###############################################


struct quadrilatero{
  ponto lowerLeft,upperRight;
};

// interseccao entre dois quadrilateros
bool SobrePosicao(quadrilatero a, quadrilatero b, quadrilatero &ans){

    double maxX = max(a.lowerLeft.x, b.lowerLeft.x);
    double minX = min(a.upperRight.x, b.upperRight.x);
    double maxY = max(a.lowerLeft.y, b.lowerLeft.y);
    double minY = min(a.upperRight.y, b.upperRight.y);

    if (maxX >= minX || minY <= maxY)
        return false;

    ans = quadrilatero{ ponto(maxX, maxY) , ponto(minX, minY) };
    return true;
}



//######################################################
/// POLIGONOS

// VERIFICA SE O PONTO ESTA NO POLIGONO CONVEXO (triangulo e o caralho a4 que seja convexo)
bool InConvexPolygon(ponto P, const vector<ponto> &poly){
    for(int i=1;i<3;i++){
        if(!ccw(poly[i-1],poly[i],P)){
            return false;
        }
    }
    if(!ccw(poly[2],poly[0],P)) return false;
    return true;
}


/// DICAS GEOMETRIA
// ordenar pelo coef angular .: linhas iguais juntas
// abrir formulas!!
// escrever todas informações que a questao lhe dá, as implicitas principalmente
// USAR SEMPRE O PRODUTO VETORIAL (DETERMINANTE) QNDO POSSIVEL




int main(){
  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(3) << fixed;

  int t;
  cin>>t;

  ponto A,B,O(0,0);
  double R;

  while(t--){
    le(A),le(B);
    cin>>R;


    double AB = dist(A,B);


    double d = DistanciaPontoSegmento(O,A,B);

    if(d >= R){
      cout << AB << '\n';
    }else{
      double OA = dist(A,O);
      double OB = dist(B,O);


      double tangentes  = sqrt(OA*OA - R*R) + sqrt(OB*OB - R*R);

      double COS_THETA = acos((OA*OA + OB*OB - AB*AB)/(2*OA*OB)) - acos(R/OA) - acos(R/OB);

      double circunferencia = COS_THETA*R;

      cout << tangentes + circunferencia << '\n';
    }
  }

  return 0;
}
