/*
  ID: nbjarvi1
  LANG: C++
  TASK: agrinet
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");

    int N;
    int E[101][101];

    fin >> N;
    for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
	    fin >> E[i][j];

    int distance[101];
    bool intree[101];
    int source[101];
    
    for (int i = 0; i < N; ++i) {
	distance[i] = numeric_limits<int>::max();
	intree[i] = false;
	source[i] = -1;
    }

    int treesize = 1;
    int treecost = 0;
    intree[0] = true;

    for (int i = 0; i < N; ++i)
	if (E[0][i] != 0)
	    { distance[i] = E[0][i]; source[i] = 0; }

    while (treesize < N) {
	int minnode = numeric_limits<int>::max();
	int minnode_i = -1;
	for (int i = 0; i < N; ++i)
	    for (int j = 0; j < N; ++j)
		if (E[i][j] != 0 && intree[i] && !intree[j])
		    if (E[i][j] < minnode)
			{ minnode = E[i][j]; minnode_i = j; }

	++treesize;
	treecost += distance[minnode_i];
	intree[minnode_i] = true;

	for (int i = 0; i < N; ++i)
	    if (E[minnode_i][i] != 0 && E[minnode_i][i] < distance[i])
		{ distance[i] = E[minnode_i][i]; source[i] = minnode_i; }
    }

    fout << treecost << "\n";

    fout.close();
    fin.close();
}
