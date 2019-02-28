/*
  ID: nbjarvi1
  LANG: C++
  TASK: prefix
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    vector<string> prefixes;
    string seq;

    string s;
    string dot(".");
    while (fin >> s)
	if (s == dot) break;
	else prefixes.push_back(s);
    while (fin >> s)
	seq += s;

    int P = prefixes.size();
    int S = seq.size();

    int mem[200001];

    for (int i = 0; i < S; ++i)
	for (int j = 0; j < P; ++j)
	    if (seq.substr(i, prefixes[j].size()) == prefixes[j])
		for (int k = 0; k < prefixes[j].size(); ++k)
		    mem[i+k] += 1;

    int biggest;
    for (biggest = 0; biggest < S; ++biggest)
	if (!mem[biggest])
	    break;
    
    fout << biggest << "\n";
    
    fout.close();
    fin.close();
}
