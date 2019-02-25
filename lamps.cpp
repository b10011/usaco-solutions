/*
  ID: nbjarvi1
  LANG: C++
  TASK: lamps
*/

#include <bits/stdc++.h>

using namespace std;

int N, C;
bitset<100> lamps(string("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"));
bitset<100>  btn1(string("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"));
bitset<100>  btn2(string("0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"));
bitset<100>  btn3(string("1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010"));
bitset<100>  btn4(string("1001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001"));

int main() {
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");

    fin >> N >> C;

    vector< pair<int, int> > fstate;
    
    int n;
    fin >> n;
    while (n != -1) {
	fstate.emplace_back(n-1, 1);
	fin >> n;
    }

    fin >> n;
    while (n != -1) {
	fstate.emplace_back(n-1, 0);
	fin >> n;
    }
    
    vector< string > printed;
    bitset<100> tmp;
    bool ok;
    for (int i = 0; i < (1<<4); ++i) {
	tmp = lamps;
	int switched = 0;
	if (i >> 0 & 1) { tmp = tmp ^ btn1; ++switched; }
        if (i >> 1 & 1) { tmp = tmp ^ btn2; ++switched; }
	if (i >> 2 & 1) { tmp = tmp ^ btn3; ++switched; }
	if (i >> 3 & 1) { tmp = tmp ^ btn4; ++switched; }

	if (C < switched)
	    continue;
	ok = true;
	for (int j = 0; j < fstate.size(); ++j)
	    if (tmp[fstate[j].first] != fstate[j].second)
		ok = false;
	if (ok && switched%2 == C%2) {
	    string s = tmp.to_string();
	    reverse(s.begin(), s.end());
	    printed.push_back(s);
	}
    }

    if (printed.size() == 0) {
	fout << "IMPOSSIBLE\n";
    } else {
	sort(printed.begin(), printed.end());
	for (int i = 0; i < printed.size(); ++i) {
	    for (int j = 0; j < N; ++j)
		fout << printed[i][j];
	    fout << "\n";
	}
    }

    fout.close();
    fin.close();
}
