/*
  ID: nbjarvi1
  LANG: C++
  TASK: ttwo
*/

#include <bits/stdc++.h>

using namespace std;

struct coord_t {
    int x;
    int y;
    int dx;
    int dy;
} farmer, cow;

bool operator==(const coord_t &a, const coord_t &b) {
    return a.x == b.x && a.y == b.y && a.dx == b.dx && a.dy == b.dy;
}

char world[10][11];
typedef pair<coord_t, coord_t> coordpair;
vector<coordpair> steps;

void step(coord_t *obj) {
    int ny = obj->y+obj->dy, nx = obj->x+obj->dx;
    if ((ny >= 0 && ny < 10) && (nx >= 0 && nx < 10) && (world[ny][nx] != '*')) {
	obj->y = ny;
	obj->x = nx;
    } else {
	if (obj->dy == -1 && obj->dx == 0) { obj->dy = 0; obj->dx = 1; }
	else if (obj->dy == 0 && obj->dx == 1) { obj->dy = 1; obj->dx = 0; }
	else if (obj->dy == 1 && obj->dx == 0) { obj->dy = 0; obj->dx = -1; }
	else if (obj->dy == 0 && obj->dx == -1) { obj->dy = -1; obj->dx = 0; }
    }
}

int isfinished() {
    if ((farmer.y == cow.y) && (farmer.x == cow.x))
	return 1;
    else
	for (int i = 0; i < steps.size(); ++i)
	    if (steps[i].first == farmer && steps[i].second == cow)
		return -1;
    return 0;
}

int main() {
    ifstream fin("ttwo.in");
    ofstream fout("ttwo.out");

    for (int i = 0; i < 10; ++i) {
	fin.getline(world[i], 11, '\n');
	for (int j = 0; j < 10; ++j)
	    if (world[i][j] == 'C') { cow.y = i; cow.x = j; world[i][j] = '.'; }
	    else if (world[i][j] == 'F') { farmer.y = i; farmer.x = j; world[i][j] = '.'; }
    }

    farmer.dx = 0;
    farmer.dy = -1;
    cow.dx = 0;
    cow.dy = -1;

    int i = 1;
    int finishstate = 0;
    while (true) {
	step(&farmer);
	step(&cow);

	if ((finishstate = isfinished())) break;
	
	steps.emplace_back(farmer, cow);
	++i;
    }

    if (finishstate == -1)
	fout << "0\n";
    else
	fout << i << "\n";

    fout.close();
    fin.close();
}
