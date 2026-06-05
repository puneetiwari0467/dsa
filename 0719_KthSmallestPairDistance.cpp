// Optimal: Binary search the distance, count pairs with sliding window. O(n log n + n log W)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long pairs = 0;
            int left = 0;

            for (int right = 0; right < nums.size(); right++) {
                while (nums[right] - nums[left] > mid) {
                    left++;
                }
                pairs += right - left;
            }

            if (pairs >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};