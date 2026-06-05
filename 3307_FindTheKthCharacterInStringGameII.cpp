// Optimal: Walk backward through operations and count alphabet shifts. O(m)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> length(operations.size() + 1, 1);

        for (int i = 0; i < operations.size(); i++) {
            if (length[i] >= k - length[i]) {
                length[i + 1] = k;
            } else {
                length[i + 1] = length[i] * 2;
            }
        }

        int shifts = 0;
        for (int i = operations.size() - 1; i >= 0; i--) {
            long long half = length[i];
            if (k > half) {
                k -= half;
                shifts += operations[i];
            }
        }

        return char('a' + shifts % 26);
    }
};