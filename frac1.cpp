/*
  ID: nbjarvi1
  LANG: C++
  TASK: frac1
*/

#include <bits/stdc++.h>

using namespace std;

typedef tuple<float, int, int> frac;
typedef vector<frac> fracs;

bool mycompare(const frac &a, const frac &b) {
    return get<0>(a) < get<0>(b);
}

int main() {
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");

    int N;
    fin >> N;
    
    vector<frac> list;
    set<double> used;

    list.push_back(make_tuple(0.0, 0, 1));

    for (int i = 1; i <= N; ++i)
	for (int j = 1; j < i; ++j) {
	    double f = (double)j/i;
	    if (used.find(f) == used.end()) {
		list.push_back(make_tuple(f, j, i));
		used.insert(f);
	    }
	}
    
    list.push_back(make_tuple(1.0, 1, 1));

    sort(list.begin(), list.end(), mycompare);

    for (fracs::iterator i = list.begin(); i != list.end(); i++)
	fout<< get<1>(*i) << "/" << get<2>(*i) << "\n";
    
    fout.close();
    fin.close();
}
