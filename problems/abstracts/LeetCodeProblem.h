#pragma once
#include <iostream>
#include <map>
#include <string>

using namespace std;

class LeetCodeProblem
{
private:

	int number = -1;
	string title = "";

public:

	virtual void test() = 0;

	void testStart(int number) {
		this->number = number;
		this->title = "============= Problem" + to_string(number) + " =============";
		cout << title << endl;
	}

	void testEnd() {
		for (size_t i = 0; i < title.length(); i++)
		{
			cout << "=";
		}
		cout << endl << endl;
	}

};

