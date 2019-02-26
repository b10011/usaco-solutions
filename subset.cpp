/*
  ID: nbjarvi1
  LANG: C++
  TASK: subset
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("subset.in");
    ofstream fout("subset.out");

    int N;
    fin >> N;

    int total = N*N+N;

    long long mem[40][780];
    for (int i = 0; i <= N; ++i)
	mem[i][0] = 1;

    for (int i = 1; i < (total>>1); ++i)
	for (int j = 0; j <= N; ++j)
	    mem[j][i] = mem[j-1][i-j] + mem[j-1][i];

    if (total>>1&1)
	fout << "0\n";
    else
	fout << (mem[N][total>>2]>>1) << "\n";

    fout.close();
    fin.close();
}
