/*
  ID: nbjarvi1
  LANG: C++
  TASK: runround
*/

#include <bits/stdc++.h>

using namespace std;

bool isrunround(int n) {
    int len = ((int)log10(n))+1;
    bool visited[9] = { false };
    bool selected[10] = { false };
    selected[0] = true;
    int nums[9] = { 0 };
    int t = n;
    for (int i = len-1; i >= 0; --i) {
	nums[i] = t % 10;
	if (selected[nums[i]])
	    return false;
	selected[nums[i]] = true;
	t /= 10;
    }
    int p = 0;
    for (int i = 0; i < len; ++i) {
	if (visited[p])
	    return false;
	visited[p] = true;
	p = (p + nums[p]) % len;
    }
    return p == 0;
}

int main() {
    ifstream fin("runround.in");
    ofstream fout("runround.out");

    int N;
    fin >> N;

    while (true) {
	++N;
	if (isrunround(N))
	    break;
    }
    
    fout << N << "\n";
    
    fout.close();
    fin.close();
}
