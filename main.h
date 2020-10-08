#ifndef UNTITLED1_MAIN_H
#define UNTITLED1_MAIN_H
#include <vector>
class Grid {
public:

    Grid(int l, int w);

    int getLength() const;

    void setLength(int length);

    int getWidth() const;

    void setWidth(int width);

    const std::vector<std::vector<bool>> &getGrid() const;

    void setGrid(const std::vector<std::vector<bool>> &grid);

    void setValAt(int x, int y, bool val);

    void fill();

    void print();

    Grid compareTo(Grid & g2)const;
private:
    int length, width;
    std::vector<std::vector<bool>> grid;
};

#endif
