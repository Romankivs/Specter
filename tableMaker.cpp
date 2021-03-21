#include "tableMaker.h"

TableMaker::TableMaker(int dimensions, int m) :
    dimensions(dimensions), m(m), loopLength(looplength(0, 1, m))
{
    stream.open("table.html");
    vector<int> startingVec = createStartingVec(loopLength, m);
    if ((startingVec.size() % dimensions) != 0)
    {
        dublivateVecDataNtimes(dimensions, startingVec);
    }
    mainVec = divideVecByNElements(dimensions, startingVec);
}

void TableMaker::start()
{
    beginHtmlDoc();
    vector<int> vecSearch;
    if (dimensions % 2 == 1)
        stream << "\n<table>\n";
    makeTable(dimensions, vecSearch);
    if (dimensions % 2 == 1)
        stream << "\n</table>\n";
}

void  TableMaker::beginHtmlDoc()
{
    stream << "<!DOCTYPE html>\n"
        "<html>\n"
        "<head>\n"
        "<style>\n"
        "table, th, td{\n"
        "    border: 4px solid black;\n"
        "    border - collapse: collapse;\n"
        "}\n"
        "</style>\n"
        "</head>\n"
        "<body>";
}

void  TableMaker::makeCell(vector<int>& vec)
{
    stream << "<th bgcolor = ";
    int counter = count(mainVec.begin(), mainVec.end(), vec);
    int colorChange = counter * 50;
    if (colorChange > 255)
        colorChange = 255;
    stream << "#ff" << hex << (255 - colorChange) << hex << (255 - colorChange) << ">";
    stream << dec << counter;
    stream << "</th>";
}

void  TableMaker::makeFirstRow(int dimension, vector<int>& vec)
{
    for (int j = 0; j < m; j++)
    {
        vector<int> tempPush = vec;
        tempPush.push_back(j);
        makeTable(dimension - 1, tempPush);
    }
}

void  TableMaker::makeRow(int dimension, vector<int>& vec)
{
    for (int j = 0; j < m; j++)
    {
        stream << "<th>";
        vector<int> tempPush = vec;
        tempPush.push_back(j);
        makeTable(dimension - 1,tempPush);
        stream << "</th>\n";
    }
}

void  TableMaker::makeColumn(int dimension, vector<int>& vec)
{
    stream << "<table>";
    for (int j = 0; j < m; j++)
    {
        stream << "<tr>\n";
        vector<int> tempPush = vec;
        tempPush.push_back(j);
        makeTable(dimension - 1,tempPush);
        stream << "</tr>\n";
    }
    stream << "</table>";
}

void  TableMaker::makeTable(int dimension, vector<int>& vec)
{
    if (dimension == 0)
    {
        makeCell(vec);
    }
    else if (dimension == 1)
    {
        makeFirstRow(dimension, vec);
    }
    else if (dimension % 2 == 1)
    {
        makeRow(dimension, vec);
    }
    else if (dimension % 2 == 0)
    {
        makeColumn(dimension, vec);
    }
}