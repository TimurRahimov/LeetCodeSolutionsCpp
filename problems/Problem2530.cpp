#include "Problem2530.h"
#include <queue>
#include <list>
#include <tuple>

using namespace std;

long long Problem2530::maxKelements(vector<int>& nums, int k)
{
	priority_queue<int> max_priority_queue = priority_queue<int>();

    for (int num : nums)
    {
        max_priority_queue.push(num);
    }

    long long score = 0;    

    for (int i = 0; i != k; ++i) {
        const int value = max_priority_queue.top();
        score += value;
        max_priority_queue.pop();
        max_priority_queue.push(ceil((double) value / 3));
    }

    return score;
}

void Problem2530::test()
{
	testStart(2530);

    list<tuple<vector<int>, int, long long>> testcases = {
        {{10, 10, 10, 10, 10}, 5, 50},
        {{1, 10, 3, 3, 3}, 3, 17}
    };

	for (const auto& tc : testcases) {
        vector<int> nums = get<0>(tc);
        int k = get<1>(tc);
        long long must = get<2>(tc);

        long long result = Problem2530().maxKelements(nums, k);

		cout << "maxKelements(" << "... ) = ";
		cout << result << " must " << must << endl;

		if (result != must)
			throw "[TestCase error]: " + to_string(result) + " != " + to_string(must);
	}

	testEnd();
}
