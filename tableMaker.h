#pragma once
#include <fstream>
#include "VecFunctions.h"
#include "loopLength.h"

class TableMaker
{
public:
    TableMaker(int dimensions, int m);

    void start();
private:
    void beginHtmlDoc();

    void makeCell(vector<int>& vec);

    void makeFirstRow(int dimension, vector<int>& vec);

    void makeRow(int dimension, vector<int>& vec);

    void makeColumn(int dimension, vector<int>& vec);

    void makeTable(int dimension, vector<int>& vec);

    ofstream stream;
    int dimensions;
    int m;
    int loopLength;
    vector<vector<int>> mainVec;
};