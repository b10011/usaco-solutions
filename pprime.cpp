/*
  ID: nbjarvi1
  LANG: C++
  TASK: pprime
*/

#include <bits/stdc++.h>

using namespace std;

bool isprime(int n) {
    if (n % 2 == 0)
	return false;
    
    for (int i = 3; i <= sqrt(n); i += 2)
	if (n % i == 0)
	    return false;
    
    return true;
}

int intlength(int n) {
    return (((int) log10(n))+1);
}

int main() {
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");

    int A, B;
    fin >> A >> B;
    
    int A_len = (intlength(A) + 1) / 2;
    int B_len = (intlength(B) + 1) / 2;
    
    for (int len = A_len; len <= B_len; ++len) {
	for (int i = pow(10, len-1); i < pow(10, len); ++i) {
	    int num_odd = i * pow(10, (len - 1));

	    for (int j = 0; j < (len - 1); ++j)
		num_odd += ((int) (i / pow(10, (j+1)))) % 10 * pow(10, len-j-2);

	    if (num_odd > B)
		break;

	    if (A <= num_odd && isprime(num_odd))
		fout << num_odd << "\n";
	}
	
	for (int i = pow(10, len-1); i < pow(10, len); ++i) {
	    int num_even = i * pow(10, len);
	    for (int j = 0; j < len; ++j)
		num_even += ((int) (i / pow(10, j))) % 10 * pow(10, len-j-1);

	    if (num_even > B)
		break;

	    if (A <= num_even && isprime(num_even))
		fout << num_even << "\n";
	}
    }

    fout.close();
    fin.close();
}
