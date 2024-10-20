#include <iostream>
#include "problem_1106.h"
#include <map>

#define P1106

using namespace std;

int main()
{   

#ifdef P1106
	cout << "=== problem_1106 ===\n";
	map<string, bool> testcases = {
		{"!(&(f,t))", true},
		{"|(f,&(t,|(t,f)),f,t)", true},
		{"|(f,f,f,t)", true},
		{"&(|(f))", false}
	};

	for (const auto& tc : testcases) {
		bool result = problem_1106().parseBoolExpr(tc.first);
		cout << "TC: " + tc.first << " = ";
		cout << result << " must " << tc.second << endl;
		if (result != tc.second)
			throw "[TestCase error]: " + to_string(result) + " != " + to_string(tc.second);
	}
	cout << "=== end ===\n";
#endif // P1106

}
