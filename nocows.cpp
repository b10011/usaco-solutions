/*
  ID: nbjarvi1
  LANG: C++
  TASK: nocows
*/

#include <bits/stdc++.h>

using namespace std;

int N, H;
int mem[100][100];

#define PRIME 9901

int main() {
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");

    fin >> N >> H;

    if (N % 2 == 0) {
	fout << "0\n";
	return 0;
    }
    
    N = ((N+1) >> 1);

    cout << N << " " << H << endl;

    for (int j = 0; j < H+1; ++j)
	mem[0][j] = 1;

    for (int i = 1; i < N; ++i)
	for (int j = 1; j < H; ++j)
	    for (int k1 = 0, k2 = i-1; k1 <= i, k2 >= 0; ++k1, --k2)
		mem[i][j] = (mem[i][j] + ((mem[k1][j-1] * mem[k2][j-1]) % PRIME)) % PRIME;

    int res = mem[N-1][H-1] - mem[N-1][H-2];
    res = (res + PRIME) % PRIME;
    fout << res << "\n";

    fout.close();
    fin.close();
}
