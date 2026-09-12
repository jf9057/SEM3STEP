#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int> nums, int k) {
    unordered_map<int, int> mp;

    mp[0] = 1;

    int currentSum = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];

        int required = currentSum - k;

        if (mp.find(required) != mp.end()) {
            count += mp[required];
        }

        mp[currentSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, -1, 0};
    int k = 0;

    cout << subarraySum(nums, k) << endl;

    return 0;
}