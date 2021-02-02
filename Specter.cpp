#include <iostream>
#include <fstream>
#include <vector>
#include <random>
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
            cout << tempVec[k] << ", ";
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
        int counter = count(mainVec.begin(), mainVec.end(), vec);
        stream << //"\n<table>\n"
            "<th>"
            << counter <<
            "</th>\n";
            //"<table>\n";
    }
    else if (dimension == 1)
    {
        //stream << "<table>";
        stream << "<tr>\n";
        for (int k = 0; k < m; k++)
            makeTable(stream, dimension - 1, m, loopLength, mainVec, vec);
        stream << "</tr>\n";
        //stream << "</table>";
    }
    else if (dimension == 2)
    {
        stream << 
            "<table>";
        for (int j = 0; j < m; j++)
        {
            stream << "<tr>";
            makeTable(stream, dimension - 1, m, loopLength, mainVec, vec);
            stream << "</tr>";
        }
        stream << "</table>\n"
            ;
    }
    else if (dimension % 2 == 1)
    {
        /*/stream << "\n<table>\n";
        for (int k = 0; k < m; k++)
        {
            stream << "<th>\n";
            makeTable(stream, dimension - 1, m, loopLength, mainVec, vec);
            stream << "</th>";
        }
        stream << "</table>\n";*/
        stream << "<table>";
        for (int j = 0; j < m; j++)
        {
            stream << "<th>";
            makeTable(stream, dimension - 1, m, loopLength, mainVec, vec);
            stream << "</th>";
        }
        stream << "</table>";
    }
    else if (dimension % 2 == 0)
    {

        /*stream << "<tr>\n";
        for (int i = 0; i < m; i++)
            makeTable(stream, dimension - 1, m, loopLength, mainVec, vec);
        stream << "</tr>\n";*/
        
        for (int j = 0; j < m; j++)
        {
            stream << "<tr>";
            makeTable(stream, dimension - 1, m, loopLength, mainVec, vec);
            stream << "</tr>";
        }
    }


}

int main()
{
    ofstream table("table.html");
    beginHtmlDoc(table);
    int dimensions = 1;
    int m = 5;
    int loopLength = looplength(0, 1, 5);
    cout << "Loop Length: " << loopLength << endl;
    vector<int> startingVec = createStartingVec(loopLength, m);
    if ((startingVec.size() % dimensions) != 0)
    {
        dublivateVecDataNtimes(dimensions, startingVec);
    }
    vector<vector<int>> mainVector = { {0,0},{0,0},{1,1} };
    vector<int> vec = { 0,0 };
    dublivateVecDataNtimes(1, vec);
    for (int i = 0; i < startingVec.size(); ++i)
    {
        cout << startingVec[i] << endl;
    }
    vector<vector<int>> result = divideVecByNElements(dimensions, startingVec);
    cout << result.size() << endl;
    vector<int> vecSearch;
    table << "<table>";
    makeTable(table, 4, m, loopLength, result, vecSearch);
    table << "</table>";
    
}

