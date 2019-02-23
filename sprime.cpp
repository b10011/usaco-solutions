/*
  ID: nbjarvi1
  LANG: C++
  TASK: sprime
*/

#include <bits/stdc++.h>

using namespace std;

bool isprime(int n) {
    if (n == 1)
	return false;
    if (n == 2)
	return true;
    
    if (n % 2 == 0)
	return false;

    int sqrt_n = sqrt(n);
    
    for (int i = 3; i <= sqrt_n; i += 2)
	if (n % i == 0)
	    return false;
    
    return true;
}

int intlength(int n) {
    return (((int) log10(n))+1);
}

int N;
int head[] = { 2, 3, 5, 7 };
int rest[] = { 1, 3, 7, 9 };

void print_sprimes_starting_with(ofstream &f, int n) {
    if (isprime(n)) {
	int l = intlength(n);
	if (l == N)
	    f << n << endl;
	else if (l < N) {
	    n *= 10;
	    for (int i = 0; i < 4; ++i) {
		print_sprimes_starting_with(f, n + rest[i]);
	    }
	}
    }
}

int main() {
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");

    fin >> N;
    
    for (int i = 0; i < 4; ++i)
	print_sprimes_starting_with(fout, head[i]);

    fout.close();
    fin.close();
}
