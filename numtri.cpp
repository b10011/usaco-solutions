/*
  ID: nbjarvi1
  LANG: C++
  TASK: numtri
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    int N;
    fin >> N;

    // When you miss Python
    int triangle[N][N];
    for (int r = 0; r < N; ++r)
	for (int c = 0; c <= r; ++c)
	    fin >> triangle[r][c];
    
    for (int r = 1; r < N; ++r)
    	for (int c = 0; c <= r; ++c)
    	    if (c == 0)
    		triangle[r][c] += triangle[r-1][c];
    	    else if (c == r)
    		triangle[r][c] += triangle[r-1][c-1];
    	    else
    		triangle[r][c] += max(triangle[r-1][c], triangle[r-1][c-1]);

    int maxsum = 0;
    for (int i = 0; i < N; ++i)
	maxsum = max(maxsum, triangle[N-1][i]);
    
    fout << maxsum << "\n";

    fin.close();
    fout.close();
}
