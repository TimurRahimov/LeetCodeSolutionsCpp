#include "Problem1593.h"

int Problem1593::maxUniqueSplit(const string& s) {
    list<string> strings{};
    return back(s, 0, 0, 0, strings);
}


int Problem1593::back(const string& s, size_t currentIndex, size_t branchStart, size_t branchEnd, const list<string>& strings) {
    if (currentIndex == s.length())
        return strings.size();

    list<string> stringsCopy(strings);

    bool breakBan = false;
    string branch = s.substr(branchStart, branchEnd - branchStart + 1);

    for (const string& str : strings) {
        if (str == branch) {
            breakBan = true;
            break;
        }
    }
    stringsCopy.push_back(branch);

    int joinBranch = back(s, currentIndex + 1, branchStart, branchEnd + 1, strings);
    int breakBranch = breakBan ? 0 : back(s, currentIndex + 1, branchEnd + 1, branchEnd + 1, stringsCopy);

    return joinBranch > breakBranch ? joinBranch : breakBranch;
}


void Problem1593::test()
{
    testStart(1593);

    list<tuple<string, int>> testcases = {
        {"ababccc", 5},
        {"aba", 2},
        {"aa", 1}
    };

    for (const auto& tc : testcases) {
        string str = get<0>(tc);
        int must = get<1>(tc);

        long long result = Problem1593().maxUniqueSplit(str);

        cout << "maxUniqueSplit(\"" + str + "\") = ";
        cout << result << " must " << must << endl;

        if (result != must)
            throw "[TestCase error]: " + to_string(result) + " != " + to_string(must);
    }

    testEnd();
}