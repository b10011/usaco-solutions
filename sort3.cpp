/*
  ID: nbjarvi1
  LANG: C++
  TASK: sort3
*/

#include <bits/stdc++.h>

using namespace std;

int N;
int l[1001];
int sl[1001];

int main() {
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");

    fin >> N;

    for (int i = 0; i < N; ++i) {
        fin >> l[i];
        sl[i] = l[i];
    }

    sort(sl, sl+N);

    int counter = 0;
    bool ready = false;

    while (!ready) {
	ready = true;
	for (int i = 0; i < N; ++i) {
	    if (l[i] != sl[i]) {
		int j;
		for (j = i+1; j < N; ++j)
		    if (sl[j] == l[i] && l[j] == sl[i])
			break;
		
		if (j == N)
		    for (j = i+1; j < N; ++j)
			if (sl[j] == l[i] && l[j] != sl[j])
			    break;
		
		swap(l[i], l[j]);
		++counter;
		ready = false;
		break;
	    }
	}
    }

    fout << counter << endl;
    
    fout.close();
    fin.close();
}
