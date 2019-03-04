/*
  ID: nbjarvi1
  LANG: C++
  TASK: fracdec
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");

    int num, denom;
    fin >> num >> denom;

    vector<int> numbers;
    vector<int> numerators;

    vector<int>::iterator prev;
    int repeat_i = -1;
    
    numbers.push_back(((int)(num/denom)));
    num %= denom;
    numerators.push_back(num);

    while (true) {
	if (num == 0) break;
	
	while (num < denom) {
	    num *= 10;
	    numerators.push_back(num);
	    numbers.push_back(0);
	}
	
	prev = find(numerators.begin(), numerators.end(), num);
	if (prev != numerators.end()-1) {
	    numbers.pop_back();
	    repeat_i = distance(numerators.begin(), prev);
	    break;
	}
	
	numbers[numbers.size()-1] = num / denom;
	num %= denom;
    }
    
    if (numbers.size() == 1) {
	numbers.push_back(0);
    } else {
	int i = 0;
	while (numbers[repeat_i-i-1] == numbers[numbers.size()-1]) {
	    ++i;
	    numbers.pop_back();
	}
	repeat_i -= i;
    }
    
    fout << numbers[0] << ".";
    int counter;
    if (numbers[0] != 0)
	counter = ((int)log10(numbers[0])) + 2;
    else
	counter = 2;

    for (int i = 1; i < numbers.size(); ++i) {
	if (i == repeat_i) {
	    fout << "(";
	    ++counter;
	}
	if (counter % 76 == 0)
	    fout << "\n";
	fout << numbers[i];
	++counter;
    }

    if (1 <= repeat_i && repeat_i < numbers.size())
	fout << ")";
    fout << "\n";

    fout.close();
    fin.close();
}
