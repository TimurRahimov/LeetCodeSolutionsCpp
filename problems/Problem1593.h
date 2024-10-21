#pragma once
#include "abstracts/LeetCodeProblem.h"
#include <list>

class Problem1593 : public LeetCodeProblem
{
public:

    int maxUniqueSplit(const string& s);

	// Унаследовано через LeetCodeProblem
	void test() override;

private:

	int back(const string& s, size_t currentIndex, size_t branchStart, size_t branchEnd, const list<string>& strings);

};

