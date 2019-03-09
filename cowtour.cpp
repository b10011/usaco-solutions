/*
  ID: nbjarvi1
  LANG: C++
  TASK: cowtour
*/

#include <bits/stdc++.h>

using namespace std;

struct vertex_t {
    int x;
    int y;
};

double distance(int ax, int ay, int bx, int by) {
    double x = abs(ax - bx);
    double y = abs(ay - by);
    if (x == 0.0) return y;
    if (y == 0.0) return x;
    double res = sqrt(x*x+y*y);
    return res;
}

double distance(vertex_t &a, vertex_t &b) {
    return distance(a.x, a.y, b.x, b.y);
}

int N;
vertex_t V[151];
bool E[151][151];
int F[151];
double D[151][151];
int FN;

double diameterfrom(int v) {
    double maxdist = 0;
    for (int i = 0; i < N; ++i)
	if (F[v] == F[i])
	    maxdist = max(maxdist, D[v][i]);
    return maxdist;
}

void assignfarmids() {
    int visited_n = 0;
    bool visited[151];
    fill(&visited[0], &visited[151], false);
    int FN = 0;

    while (visited_n < N) {
	queue<int> q;
	int unvisited = -1;
	for (int i = 0; i < N; ++i)
	    if (!visited[++unvisited])
		break;
	q.push(unvisited);
	F[unvisited] = FN;

	while (!q.empty()) {
	    int item = q.front();
	    q.pop();
	    F[item] = FN;
	    if (!visited[item]) ++visited_n;
	    visited[item] = true;
	    for (int i = 0; i < N; ++i)
		if (!visited[i] && E[item][i])
		    q.push(i);
	}

	++FN;
    }
}

void floydwarshall() {
    for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
	    D[i][j] = numeric_limits<double>::max();
    for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
	    if (E[i][j])
		D[i][j] = distance(V[i], V[j]);
    for (int i = 0; i < N; ++i)
	D[i][i] = 0;
    for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
	    for (int k = 0; k < N; ++k)
		if (D[j][k] > D[j][i] + D[i][k])
		    D[j][k] = D[j][i] + D[i][k];
}

int main() {
    ifstream fin("cowtour.in");
    ofstream fout("cowtour.out");

    char a;
    fin >> N;
    for (int i = 0; i < N; ++i)
	fin >> V[i].x >> V[i].y;

    fill(&E[0][0], &E[150][151], false);
    for (int i = 0; i < N; ++i) {
	for (int j = 0; j < N; ++j) {
	    fin >> a;
	    E[i][j] = (a == '1') ? true : false;
	}
    }

    assignfarmids();
    floydwarshall();
    
    double mindist = numeric_limits<double>::max();
    for (int i = 0; i < N; ++i) {
	for (int j = 0; j < N; ++j) {
	    if (F[i] != F[j]) {
		double dist = distance(V[i], V[j]);
		double newdist = dist + diameterfrom(i) + diameterfrom(j);
		mindist = min(mindist, newdist);
	    }
	}
    }

    // You can't be fucking serious. Rewrote the code 3 times
    // and debugged for hours just because the task wasn't
    // clear regarding this part and the first test case (7)
    // had way too much data for fast manual check.
    for (int i = 0; i < N; ++i)
	mindist = max(mindist, diameterfrom(i));
    // End of rant
    
    fout << fixed << setprecision(6) << mindist << "\n";

    fout.close();
    fin.close();
}
