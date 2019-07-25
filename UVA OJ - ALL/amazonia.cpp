// UVa 10687 - Monitoring the Amazon

#include <iostream>
#include <limits.h> // only to use INT_MAX as infinity
#include <string.h> // only to use memset
using namespace std;

struct point {
	int x, y;
};

int dist(point p1, point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int lnk[1000][2];
bool visited[1000];

int count(int i) {
	if (visited[i])
		return 0;
	visited[i] = true;
	return count(lnk[i][0]) + count(lnk[i][1]) + 1;
}

int main() {
	int n;
	while (cin >> n && n) {
		point p[1000];
		// read input
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		// see who is connected to who
		for (int i = 0; i < n; i++) {
			int mina = INT_MAX, minb = INT_MAX;
			int ca = -1, cb = -1;
			for (int j = 0; j < n; j++)
				if (i != j) {
					int d = dist(p[i], p[j]);
					if (d <= mina) {
						minb = mina;
						mina = d;
						cb = ca;
						ca = j;
					} else if (d < minb) {
						minb = d;
						cb = j;
					}
				}
			lnk[i][0] = ca;
			lnk[i][1] = cb;
		}
		// see if the graph is connected
		memset(visited, false, sizeof(visited));
		if (count(0) == n)
			cout << "All stations are reachable.\n";
		else
			cout << "There are stations that are unreachable.\n";
	}
	return 0;
}
