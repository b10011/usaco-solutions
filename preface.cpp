/*
  ID: nbjarvi1
  LANG: C++
  TASK: preface
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("preface.in");
    ofstream fout("preface.out");

    int N;
    fin >> N;

    int c[7][13] =
        {
         {  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1 },
         {  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
         {  0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0 },
         {  0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
         {  0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
         {  0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
         {  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
        };

    int m[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    int r[13] = { 0 };
    int n;
    for (int t = 1; t <= N; ++t) {
        n = t;
        for (int i = 0; i < 13; ++i) {
            int x = n/m[i];
            if (x) {
                for (int j = 0; j < x; ++j)
                    for (int k = 0; k < 7; ++k)
                        r[k] += c[k][i];
                n -= x*m[i];
            }
        }
    }
    
    int p = 0;
    for (p = 0; p < 7; ++p)
        if (!r[p])
            break;
    for (int i = 0; i < p; ++i)
        fout << "IVXLCDM"[i] << " " << r[i] << "\n";

    fout.close();
    fin.close();
}
