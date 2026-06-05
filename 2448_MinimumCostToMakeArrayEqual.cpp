// Optimal: Weighted median minimizes total weighted absolute distance. O(n log n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> entries;
        long long totalWeight = 0;

        for (int i = 0; i < nums.size(); i++) {
            entries.push_back({nums[i], cost[i]});
            totalWeight += cost[i];
        }

        sort(entries.begin(), entries.end());

        long long prefixWeight = 0;
        long long target = entries[0].first;

        for (auto& entry : entries) {
            prefixWeight += entry.second;
            if (prefixWeight * 2 >= totalWeight) {
                target = entry.first;
                break;
            }
        }

        long long answer = 0;
        for (auto& entry : entries) {
            long long value = entry.first;
            long long weight = entry.second;
            long long diff = value > target ? value - target : target - value;
            answer += diff * weight;
        }

        return answer;
    }
};