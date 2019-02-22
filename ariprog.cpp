/*
  ID: nbjarvi1
  LANG: C++
  TASK: ariprog
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second)
	return true;
    else if (a.second == b.second)
	return (a.first < b.first);
    else
	return false;
}

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    int N, M;
    fin >> N >> M;

    int tmp;

    bool in_bisquares[1000000] = { false };
    set<int> bisquares;
    for (int p = 0; p <= M; ++p) {
	for (int q = 0; q <= p; ++q) {
	    tmp = pow(p, 2)+pow(q, 2);
	    bisquares.insert(tmp);
	    in_bisquares[tmp] = true;
	}
    }

    int upperlimit = (2*pow(M, 2)) / (N-1) + 2;

    vector<pair<int, int>> res;

    int total;
    bool allfound;

    for (int b = 1; b < upperlimit; ++b) {
	for (int a : bisquares) {
	    total = a+b;
	    allfound = true;
	    for (int n = 1; n < N; ++n) {
		if (!in_bisquares[total]) {
		    allfound = false;
		    break;
		}
		total += b;
	    }
	    if (allfound)
                res.push_back(make_pair(a, b));
	}
    }

    sort(res.begin(), res.end(), compare);

    if (!res.size())
	fout << "NONE\n";
    else
	for (int i = 0; i < ((int) res.size()); ++i)
	    fout << res.at(i).first << " " << res.at(i).second << "\n";

    fin.close();
    fout.close();
}
