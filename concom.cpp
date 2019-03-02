/*
  ID: nbjarvi1
  LANG: C++
  TASK: concom
*/

#include <bits/stdc++.h>

using namespace std;

int relations[100][100];
bool visited[100][100];
int companies = 0;

int main() {
    ifstream fin("concom.in");
    ofstream fout("concom.out");

    int N;
    fin >> N;

    int a, b, p;
    for (int i = 0; i < N; ++i) {
	fin >> a >> b >> p;
	companies = max(companies, max(a, b));
	relations[a-1][b-1] = p;
    }

    int edited;
    for (int parent_i = 0; parent_i < companies; ++parent_i) {
	edited = false;
    	for (int child_i = 0; child_i < companies; ++child_i) {
	    if (relations[parent_i][child_i] <= 50) continue;
	    if (parent_i == child_i) continue;
	    if (visited[parent_i][child_i]) continue;
	    visited[parent_i][child_i] = true;
	    
	    for (int grandchild_i = 0; grandchild_i < companies; ++grandchild_i) {
		if (relations[parent_i][child_i] > 50) {
		    relations[parent_i][grandchild_i] += relations[child_i][grandchild_i];
		    edited = true;
		    if (visited[child_i][grandchild_i])
			visited[parent_i][grandchild_i] = true;
		}
	    }
	    
	    if (edited) {
		parent_i = -1;
		break;
	    }
    	}
    }

    for (int parent_i = 0; parent_i < companies; ++parent_i)
	for (int child_i = 0; child_i < companies; ++child_i)
	    if (parent_i != child_i)
		if (relations[parent_i][child_i] > 50)
		    fout << parent_i+1 << " " << child_i+1 << "\n";

    fout.close();
    fin.close();
}
