/*
  ID: nbjarvi1
  LANG: C++
  TASK: hamming
*/

#include <bits/stdc++.h>

using namespace std;

int N, B, D;

int count_ones(int b) {
    int c = 0;
    for (int i = B-1; i >= 0; --i)
	if (b >> i & 1)
	    ++c;
    return c;
}

bool ok(vector<int> &prev, int i) {
    for (auto b : prev)
	if (count_ones(i ^ b) < D)
	    return false;
    return true;
}

int main() {
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");

    fin >> N >> B >> D;
    
    vector<int> prev;

    int max_i = pow(2, B);

    while (N > 0) {
	for (int i = 0; i < max_i; ++i) {
	    if (ok(prev, i)) {
		prev.push_back(i);
		--N;
		if (!N) i = max_i;
	    }
	}
    }

    for (int i = 0; i < prev.size(); ++i) {
	if (i % 10) fout << " ";
	else if (i) fout << "\n";
	fout << prev[i];
    }
    fout << "\n";

    fout.close();
    fin.close();
}
