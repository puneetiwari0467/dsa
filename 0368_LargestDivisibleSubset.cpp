// Optimal: Sort + DP parent reconstruction. O(n^2)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n);

        int bestLength = 1;
        int bestIndex = 0;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if (dp[i] > bestLength) {
                bestLength = dp[i];
                bestIndex = i;
            }
        }

        vector<int> answer;
        while (parent[bestIndex] != bestIndex) {
            answer.push_back(nums[bestIndex]);
            bestIndex = parent[bestIndex];
        }
        answer.push_back(nums[bestIndex]);

        reverse(answer.begin(), answer.end());
        return answer;
    }
};