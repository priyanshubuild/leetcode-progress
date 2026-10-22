
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int p = 0;

        // Find the position of 0
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                p = i;
                break;
            }
        }

        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            // Check circular increasing order
            if (nums[(p + i) % n] != i) {
                inc = false;
            }

            // Check circular decreasing order
            if (nums[(p - i + n) % n] != i) {
                dec = false;
            }
        }

        int ans = INT_MAX;

        if (inc) {
            ans = min(ans, min(p, n - p + 2));
        }

        if (dec) {
            ans = min(ans, 1 + min(p + 1, n - 1 - p));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
