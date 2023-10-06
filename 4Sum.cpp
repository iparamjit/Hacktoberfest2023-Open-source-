#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int indx = 0; indx < n; indx++) {
        if (indx != 0 and nums[indx] == nums[indx - 1]) {
            continue;
        }
        int x = target - nums[indx];
        for (int i = indx + 1; i < n; i++) {
            if (i != indx + 1 and nums[i] == nums[i - 1]) {
                continue;
            }
            long y = x - (long)nums[i];
            int s = i + 1, e = n - 1;
            while (s < e) {
                long value = nums[s] + nums[e];
                if (value == y) {
                    result.push_back({nums[indx], nums[i], nums[s], nums[e]});
                    while (s < e and nums[s] == nums[s + 1]) {
                        s = s + 1;
                    }
                    while (s < e and nums[e] == nums[e - 1]) {
                        e = e - 1;
                    }
                    s = s + 1;
                    e = e - 1;
                } else if (value > y) {
                    while (s < e and nums[e] == nums[e - 1]) {
                        e = e - 1;
                    }
                    e = e - 1;
                } else {
                    while (s < e and nums[s] == nums[s + 1]) {
                        s = s + 1;
                    }
                    s = s + 1;
                }
            }
        }
    }
    return result;
}
