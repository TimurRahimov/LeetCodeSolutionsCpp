#pragma once
#include <iostream>
#include <vector>

#include "abstracts/LeetCodeProblem.h"

using namespace std;

// 2530. Maximal Score After Applying K Operations

class Problem2530 : public LeetCodeProblem 
{
public:

    long long maxKelements(vector<int>& nums, int k);

    // Унаследовано через LeetCodeProblem
    void test() override;

};