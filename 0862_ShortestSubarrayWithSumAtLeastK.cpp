// Optimal: Prefix sums with increasing deque. O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> candidates;
        int answer = n + 1;

        for (int i = 0; i <= n; i++) {
            while (!candidates.empty() && prefix[i] - prefix[candidates.front()] >= k) {
                answer = min(answer, i - candidates.front());
                candidates.pop_front();
            }

            while (!candidates.empty() && prefix[candidates.back()] >= prefix[i]) {
                candidates.pop_back();
            }

            candidates.push_back(i);
        }

        return answer == n + 1 ? -1 : answer;
    }
};