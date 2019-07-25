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

void bfs(Graph &graph, int s) {
    vector<int> d = vector<int>(graph.n, -1);
    d[s] = 0;
    graph.visited = vector<bool>(graph.n, false);
    graph.visited[s] = true;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < int(graph.adjList[u].size()); ++j) {
            ii v = graph.adjList[u][j];
            if (!graph.visited[v.first]) {
                d[v.first] = d[u] + 1;
                graph.visited[v.first] = true;
                q.push(v.first);
            }
        }
    }

    map<int, int> m;
    for (int i = 0; i < int(graph.n); ++i) {
        if (d[i] > 0) {
            if (m.find(d[i]) == m.end()) m[d[i]] = 0;
            m[d[i]]++;
        }
    }

    int countEmp = 0;
    for (int i = 0; i < int(graph.n); ++i)
        if (graph.visited[i]) countEmp++;

    if (countEmp == 1) printf("0\n");
    else {
        int countMax = 0, i;
        for (auto item : m) {
            if (item.second > countMax)
                i = item.first, countMax = item.second;
        }
        printf("%d %d\n", countMax, i);
    }
}

stack<int> bfs2(Graph &graph, int s, int d) {

    graph.visited = vector<bool>(graph.n, false);
    vector<int> pai(graph.n, -1);
    queue<int> q;
    bool find = false;

    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < int(graph.adjList[u].size()); ++j) {
            ii v = graph.adjList[u][j];

            if (!graph.visited[v.first]) {
                graph.visited[v.first] = true;
                q.push(v.first);
                pai[v.first] = u;
                if (v.first == d) {
                    find = true;
                    break;
                }
            }

        }
        if (find) break;
    }

    stack<int> st;
    if (!find) return st;

    int i = d;
    while (true) {
        st.push(i);
        if (i == s) break;
        i = pai[i];
    }

    return st;
}

string getKeyMap(map<string, int> m, int v) {
    for (auto i : m)
        if (i.second == v) return i.first;
    return "";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r", stdin);
    freopen("../out.txt","w", stdout);
#endif

    int e, n, v;
    cin >> e;
    Graph graph(e + 1, true);
    for (int i = 0; i < e; ++i) {
        cin >> n;
        while (n--) {
            cin >> v;
            graph.setEdge(i, v, 1);
        }
    }

    int c, s;
    cin >> c;
    while (c--) {
        cin >> s;
        bfs(graph, s);
    }

    return 0;
}









