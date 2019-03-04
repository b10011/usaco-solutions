/*
  ID: nbjarvi1
  LANG: C++
  TASK: maze1
*/

#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>

using namespace std;

int maze[100][100];
int e = 0;
int exits[2][2];
int runs[3][100][100];
char chars[301][301];
bool visited[2][100][100];
int W, H;

#define WEST(i,j) ((maze[(i)][(j)]>>0)&1)
#define NORTH(i,j) ((maze[(i)][(j)]>>1)&1)
#define EAST(i,j) ((maze[(i)][(j)]>>2)&1)
#define SOUTH(i,j) ((maze[(i)][(j)]>>3)&1)

queue< tuple<int, int, int> > stepqueue;

void search(int run, int i, int j) {
    stepqueue.push(make_tuple(i, j, 1));

    while (!stepqueue.empty()) {
	tuple<int, int, int> current = stepqueue.front();
	stepqueue.pop();
	int y = get<0>(current);
	int x = get<1>(current);
	int val = get<2>(current);

	if (visited[run][y][x] && runs[run][y][x] <= val)
	    continue;
	
	runs[run][y][x] = min(val, runs[run][y][x]);
	visited[run][y][x] = true;
	
	if (WEST(y, x)) stepqueue.push(make_tuple(y, x-1, val+1));
	if (NORTH(y, x)) stepqueue.push(make_tuple(y-1, x, val+1));
	if (EAST(y, x)) stepqueue.push(make_tuple(y, x+1, val+1));
	if (SOUTH(y, x)) stepqueue.push(make_tuple(y+1, x, val+1));
    }
}

int main() {
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");
    
    fin >> W >> H;

    char c;
    fin.getline(&c, 1, '\n');

    for (int i = 0; i < 2*H+1; ++i) {
	fin.getline(chars[i], 300, '\n');
    }

    int cH = (H-1)*2, cW = (W-1)*2;
    for (int i = 0; i <= cH; i += 2) {
	for (int j = 0; j <= cW; j += 2) {
	    maze[i>>1][j>>1] |= (chars[i+1][j] == ' ') << 0;
	    maze[i>>1][j>>1] |= (chars[i][j+1] == ' ') << 1;
	    maze[i>>1][j>>1] |= (chars[i+1][j+2] == ' ') << 2;
	    maze[i>>1][j>>1] |= (chars[i+2][j+1] == ' ') << 3;

	    if (j == 0 && WEST(i>>1,j>>1)) { exits[e][0] = i>>1; exits[e++][1] = j>>1; };
	    if (i == 0 && NORTH(i>>1,j>>1)) { exits[e][0] = i>>1; exits[e++][1] = j>>1; };
	    if (j == cW && EAST(i>>1,j>>1)) { exits[e][0] = i>>1; exits[e++][1] = j>>1; };
	    if (i == cH && SOUTH(i>>1,j>>1)) { exits[e][0] = i>>1; exits[e++][1] = j>>1; };
	}
    }

    for (int i = 0; i < H; ++i)
	for (int j = 0; j < W; ++j)
	    for (int k = 0; k < 2; ++k)
		runs[k][i][j] = numeric_limits<int>::max();

    search(0, exits[1][0], exits[1][1]);
    search(1, exits[0][0], exits[0][1]);

    int maxlen = 0;
    for (int i = 0; i < H; ++i)
    	for (int j = 0; j < W; ++j)
	    maxlen = max(maxlen, min(runs[0][i][j], runs[1][i][j]));

    fout << maxlen << "\n";

    fout.close();
    fin.close();
}
