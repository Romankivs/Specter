#pragma once
#include <vector>
#include "fModM.h"

using namespace std;

vector<int> createStartingVec(int len, int Key);

void dublivateVecDataNtimes(int N, vector<int>& vec);

vector<vector<int>> divideVecByNElements(int N, vector<int>& vec);