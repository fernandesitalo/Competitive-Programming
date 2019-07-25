//Geometria computacional

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <functional>
#include <string.h>
#include <bitset>

#include <queue>
#include <limits.h>
#include <map>
#include <stack>

const double EPS = 1e-10;
const double PI = acos(-1.0);

using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but they are useful in competitive programming

#define UNVISITED -1
#define VISITED 1
#define INF INT_MAX

struct Graph {
    vector< vii > adjList;
    vector<int> dfs_visit;
    vector<int> indegree;
    vector<bool> visited;

    bool isDirected;

    unsigned int n;

    Graph(bool isDirected = true) : isDirected(isDirected) { n = 0; }
    Graph(unsigned int n, bool isDirected) :
        isDirected(isDirected) { this->n = n; reset(); }

    void setEdge(int u, int v, int peso) {
        if (u == v) return;
        adjList[u].push_back(make_pair(v, peso));
        if (!isDirected) adjList[v].push_back(make_pair(u, peso));
        //printf("u = %d, v = %d\n", u, v);
    }

    int getEdge(int u, int v) {
        for (auto i : adjList[u]) {
            if (i.first == v) return i.second;
        }
        return INF;
    }

    void reset() {
        adjList = vector< vii > (n, vii());
        dfs_visit = vector<int> (n, UNVISITED);
        indegree = vector<int> (n, 0);
        visited = vector<bool> (n, false);
    }

    void reset(int n) {
        this->n = n;
        reset();
    }
};

int bfs(Graph &graph, int s, int a) {
    if (s == a) return 0;
    //printf("s = %d a = %d\n", s, a);
    vector<int> d = vector<int>(graph.n, -1);
    d[s] = 0;
    graph.visited = vector<bool>(graph.n, false);
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < int(graph.adjList[u].size()); ++j) {
            ii v = graph.adjList[u][j];
            if (!graph.visited[v.first]) {
                if (v.first == a) return (d[u] + 1);
                d[v.first] = d[u] + 1;
                graph.visited[v.first] = true;
                q.push(v.first);
            }
        }
    }

    return -1;
}

int dr[] = {1, 0, -1,  0};
int dc[] = {0, 1,  0, -1};


int r, c;
int getNode(int k, int i, int j) {
    //printf("k = %d, i = %d, j = %d\n", k, i, j);
    return (k * (r * c) + i * c + j);
}

string grids[31][31];
bool isPosValid(int k, int rr, int cc) {
    return (!(rr < 0 || rr >= r ||
              cc < 0 || cc >= c ||
              grids[k][rr][cc] == '#'));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r", stdin);
    freopen("../out.txt","w", stdout);
#endif

    int l, i, j, k;
    string s;

    while (cin >> l >> r >> c && l && r && c) {
        Graph graph(l * r * c + 3, false);
        for (k = 0; k < l; ++k) {
            scanf(" ");
            for (i = 0; i < r; ++i) {
                getline(cin, s);
                grids[k][i] = s;
            }
        }

        int s, e;
        for (k = 0; k < l; ++k) {
            for (i = 0; i < r; ++i) {
                for (j = 0; j < c; ++j) {
                    if (grids[k][i][j] != '#') {
                        if (grids[k][i][j] == 'S') s = getNode(k, i, j);
                        else if (grids[k][i][j] == 'E') e = getNode(k, i, j);

                        int rr, cc;
                        //4 vizinhos
                        for (int d = 0; d < 4; ++d) {
                            rr = i + dr[d];
                            cc = j + dc[d];
                            if (isPosValid(k, rr, cc))
                                graph.setEdge(getNode(k, i, j), getNode(k, rr, cc), 1);
                        }
                        //Em baixo
                        if (k > 0 && isPosValid(k - 1, i, j))
                            graph.setEdge(getNode(k, i, j), getNode(k - 1, i, j), 1);

                    }
                }
            }
        }

        int r = bfs(graph, s, e);
        if (r == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", r);
    }

    return 0;
}









