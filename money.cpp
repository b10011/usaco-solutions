/*
  ID: nbjarvi1
  LANG: C++
  TASK: money
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("money.in");
    ofstream fout("money.out");

    int V, N;
    fin >> V >> N;

    int coins[26];

    int coin;
    for (int i = 0; i < V; ++i) {
	fin >> coin;
	coins[i+1] = coin;
    }

    sort(coins, coins+V);

    long long mem[26][10001];
    for (int i = 0; i <= V; ++i)
	mem[i][0] = 1;

    for (int i = 1; i <= V; ++i) {
	for (int j = 1; j <= N; ++j) {
	    mem[i][j] = mem[i-1][j];
	    int tmp = j-coins[i];
	    if (tmp >= 0)
		mem[i][j] += mem[i][tmp];
	}
    }

    fout << mem[V][N] << "\n";

    fout.close();
    fin.close();
}
