/*
  ID: nbjarvi1
  LANG: C++
  TASK: castle
*/

#include <bits/stdc++.h>

using namespace std;

int W, H;
int edgecount = 0;
int edges[40000] = { -1 };
bool coord2visited[2500] = { false };
int coord2id[2500] = { -1 };
int id2size[2500] = { 0 };
int id2size_sorted[2500] = { 0 };
int idsortbysize[2500] = { -1 };

#define COORD(x, y) (y)*W+(x)

int calc_rooms_sizes(int xy, int room_id) {
    if (coord2visited[xy])
	return 0;
    coord2visited[xy] = true;
    coord2id[xy] = room_id;
    int n = 1;
    for (int i = 0; i < edgecount; i += 2)
	if (edges[i] == xy)
	    n += calc_rooms_sizes(edges[i+1], room_id);
    return n;
}

#define MAKEEDGE(a, b) { edges[edgecount++] = a; edges[edgecount++] = b; edges[edgecount++] = b; edges[edgecount++] = a; }

int main() {
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    
    fin >> W >> H;

    int block;
    for (int i = 0; i < W*H; ++i) {
	fin >> block;
	if (!(block & 1)) MAKEEDGE(i, i-1); // West
	if (!(block & 2)) MAKEEDGE(i, i-W); // North
	if (!(block & 4)) MAKEEDGE(i, i+1); // East
	if (!(block & 8)) MAKEEDGE(i, i+W); // South
    }
    ++edgecount;

    int room_id = 0;
    for (int i = 0; i < W*H; ++i) {
	int size = calc_rooms_sizes(i, room_id);
	id2size[room_id] = size;
	id2size_sorted[room_id] = size;
	room_id += !!size;
    }

    sort(id2size_sorted, id2size_sorted+room_id, greater<int>());

    for (int i = 0; i < room_id; ++i)
	for (int j = 0; j < room_id; ++j)
	    if (id2size[j] == id2size_sorted[i])
		idsortbysize[i] = j;

    int combine_size = -1;
    int combine_y = -1;
    int combine_x = -1;
    int combine_d = -1;
    for (int b = 0; b < room_id; ++b) {
	for (int x = 0; x < W; ++x) {
	    for (int y = H-1; y >= 0; --y) {
		int i = y*W+x;
		int neighbors[2] = { i-W, i+1 };

		for (int j = 0; j < 2; ++j) {
		    int neighbor = neighbors[j];
		    if (neighbor < 0 || neighbor > W*H-1 || (j == 1 && x == W-1))
			continue;
		    int neighborid = coord2id[neighbor];
		    if (neighborid == coord2id[i])
			continue;
		
		    int currentsize = id2size[coord2id[i]] + id2size[neighborid];
		    if (combine_size < currentsize) {
			combine_size = currentsize;
			combine_y = y;
			combine_x = x;
			combine_d = j;
		    }
		}
	    }
	}
    }
    
    fout << room_id << "\n";
    fout << id2size_sorted[0] << "\n";
    fout << combine_size << "\n";
    fout << combine_y + 1 << " " << combine_x + 1 << " " << "NE"[combine_d] << "\n";

    fout.close();
    fin.close();
}
