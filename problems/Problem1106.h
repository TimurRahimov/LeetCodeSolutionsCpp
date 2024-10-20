#pragma once
#include <iostream>
#include <map>
#include <string>

#include "abstracts\LeetCodeProblem.h"

using namespace std;

class Problem1106 : public LeetCodeProblem
{
public:

	bool parseBoolExpr(string expression)
	{
		char command = expression.at(0);
		if (command == 't')
			return true;
		else if (command == 'f')
			return false;
		else {
			size_t start = expression.find_first_of('(') + 1;
			size_t end = expression.find_last_of(')');
			string inner = expression.substr(start, end - start);

			if (command == '!') {
				return !parseBoolExpr(inner);
			}

			int bracketsLevel = 0;
			int lastComma = -1;

			for (size_t i = 0; i != inner.size(); ++i) {
				if (inner.at(i) == '(')
					bracketsLevel++;
				else if (inner.at(i) == ')')
					bracketsLevel--;
				else if (inner.at(i) == ',' && bracketsLevel == 0) {
					if (command == '&' && !parseBoolExpr(inner.substr(lastComma + 1, i - lastComma + 1)))
						return false;
					else if (command == '|' && parseBoolExpr(inner.substr(lastComma + 1, i - lastComma + 1)))
						return true;
					lastComma = i;
				}
			}
			return parseBoolExpr(inner.substr(lastComma + 1));
		}

		return false;
	}

	void test() override {
		map<string, bool> testcases = {
			{"!(&(f,t))", true},
			{"|(f,&(t,|(t,f)),f,t)", true},
			{"|(f,f,f,t)", true},
			{"&(|(f))", false}
		};

		for (const auto& tc : testcases) {
			bool result = Problem1106().parseBoolExpr(tc.first);
			cout << "parseBoolExpr(\"" + tc.first << "\") = ";
			cout << result << " must " << tc.second << endl;
			if (result != tc.second)
				throw "[TestCase error]: " + to_string(result) + " != " + to_string(tc.second);
		}
	};

};
