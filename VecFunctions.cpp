#include "VecFunctions.h"

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

vector<vector<int>>  divideVecByNElements(int N, vector<int>& vec)
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