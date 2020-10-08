#include <iostream>
#include <random>
#include "main.h"
#include <time.h>

using namespace std;


int main() {
    int l;
    int w;
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter width: ";
    cin >> w;

    cout << "Grid 1" << endl;
    Grid grid1 = Grid(l,w);
    grid1.fill();
    grid1.print();

    cout << "\nGrid 2" << endl;
    Grid grid2 = Grid(l, w);
    grid2.fill();
    grid2.print();

    cout << "\nGrid 3" << endl;
    Grid grid3 = grid1.compareTo(grid2);
    grid3.print();

    return 0;
}

int Grid::getLength() const {
    return length;
}

void Grid::setLength(int length) {
    Grid::length = length;
}

int Grid::getWidth() const {
    return width;
}

void Grid::setWidth(int width) {
    Grid::width = width;
}

const vector<std::vector<bool>> &Grid::getGrid() const {
    return grid;
}

void Grid::setGrid(const vector<std::vector<bool>> &grid) {
    Grid::grid = grid;
}

Grid::Grid(int l, int w) : length(l), width(w), grid(vector<vector<bool>>(l, vector<bool>(w, false))) {
}

int generateNum(int n) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, n); // distribution in range [1, 6]
    return dist6(rng);
}

void Grid::fill() {
    int area = getLength() * getWidth();
    int fraction = area / 3;
    int i = 0;
    while (i < fraction) {
        int x = generateNum(getLength() - 1);
        int y = generateNum(getWidth() - 1);
        if (!getGrid().at(x).at(y)) {
            grid[x][y] = true;
            i++;
        }
    }

}

void Grid::print() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.at(i).size(); j++) {
            cout << grid.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

void Grid::setValAt(int x, int y, bool val){
    grid[x][y] = val;
}

Grid Grid::compareTo(Grid & g2)const{
    Grid c = Grid(g2.getLength(), g2.getWidth());
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.at(i).size(); j++) {
            if (grid.at(i).at(j) && g2.getGrid().at(i).at(j))
                c.setValAt(i,j,true);
        }
    }
    return c;
}
