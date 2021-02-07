#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "loopLength.h"

using namespace std;

vector<int> createStartingVec(int len, int Key)
{
    vector<int> tempVec;
    InitFmodM(0, 1, Key);
    for (int i = 0; i < len; i++)
    {
        tempVec.push_back(r());
    }
    return tempVec;
}

void dublivateVecDataNtimes(int N, vector<int>& vec)
{
    size_t size = vec.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < size; j++)
            vec.push_back(vec[j]);
    }
}

vector<vector<int>> divideVecByNElements(int N, vector<int> & vec)
{
    vector<vector<int>> resultVec;
    for (int i = 0; i <= vec.size() - N; i += N)
    {   
        vector<int> tempVec;
        for (int j = i; j < i + N; j++)
        {
            tempVec.push_back(vec[j]);
        }
        for (int k = 0; k < tempVec.size(); k++)
        resultVec.push_back(tempVec);
    }
    return resultVec;
}

void beginHtmlDoc(ofstream& stream)
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

void makeTable(ofstream& stream, int dimension, int m, int loopLength, vector<vector<int>> mainVec, vector<int> &vec)
{
    if (dimension == 0)
    {
        stream << "<th bgcolor = ";
        int counter = count(mainVec.begin(), mainVec.end(), vec);
        int colorChange = counter * 50;
        if (colorChange > 255)
            colorChange = 255;
        stream << "#ff" << hex << (255 - colorChange) << hex << (255 - colorChange) << ">";
        stream << dec <<  counter;
        stream << "</th>";
    }
    else if (dimension == 1)
    {
        for (int j = 0; j < m; j++)
        {
            vector<int> tempPush = vec;
            tempPush.push_back(j);
            makeTable(stream, dimension - 1, m, loopLength, mainVec, tempPush);
        }
    }
    else if (dimension % 2 == 1)
    {

        for (int j = 0; j < m; j++)
        {
            stream << "<th>";
            vector<int> tempPush = vec;
            tempPush.push_back(j);
            makeTable(stream, dimension - 1, m, loopLength, mainVec, tempPush);
            stream << "</th>\n";
        }

    }
    else if (dimension % 2 == 0)
    {
        stream << "<table>";
        for (int j = 0; j < m; j++)
        {
            stream << "<tr>\n";
            vector<int> tempPush = vec;
            tempPush.push_back(j);
            makeTable(stream, dimension - 1, m, loopLength, mainVec, tempPush);
            stream << "</tr>\n";
        }
        stream << "</table>";
    }
}

int main()
{
    ofstream table("table.html");
    beginHtmlDoc(table);
    int dimensions = 5;
    int m = 3;
    int loopLength = looplength(0, 1, m);
    vector<int> startingVec = createStartingVec(loopLength, m);
    if ((startingVec.size() % dimensions) != 0)
    {
        dublivateVecDataNtimes(dimensions, startingVec);
    }
    vector<vector<int>> result = divideVecByNElements(dimensions, startingVec);
    vector<int> vecSearch;
    if (dimensions % 2 == 1)
        table << "\n<table>\n";
    makeTable(table, dimensions, m, loopLength, result, vecSearch);
    if (dimensions % 2 == 1)
        table << "\n</table>\n";
    
}

