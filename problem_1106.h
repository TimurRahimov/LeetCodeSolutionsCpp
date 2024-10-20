#pragma once
#include <string>
using namespace std;

class problem_1106
{
public:

	bool parseBoolExpr(string expression) {
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
	};

};
