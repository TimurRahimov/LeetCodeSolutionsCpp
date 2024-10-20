#pragma once
#include <iostream>
#include <map>
#include <string>

#include "abstracts\LeetCodeProblem.h"

using namespace std;

// 1106. Parsing A Boolean Expression

class Problem1106 : public LeetCodeProblem
{
public:

	bool parseBoolExpr(string expression);


	// Унаследовано через LeetCodeProblem
	void test() override;

};
