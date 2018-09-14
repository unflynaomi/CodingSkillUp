#include<iostream>
#include<vector>
using namespace std;
/*
迅雷笔试编程题第二题：有一个无序数组a，找到一个数，位置为i，使得a[0]+a[1]+...+a[i - 1]==a[i]==a[i+1]+a[i+2]+...+a[n-1]。
思路：先计算数的和，在扫描的时候减去前面a[0]+a[1]+...+a[i - 1]和a[i]，就得到后面数字的和，然后比较大小即可，比较简单。
*/

int find_fronr_end_equal(vector<int>& nums) {
    int sum = 0;
    for(auto i : nums)
        sum += i;
    int current_sum = 0;
    for(int i = 1; i < nums.size(); i++) {
        current_sum += nums[i - 1];
        if(current_sum == nums[i] && sum - current_sum - nums[i] == nums[i])
            return nums[i];
    }
    return -1;
}

int main() {
    int a[] = {1,3,4,4};
    vector<int> nums;
    for(auto i : a)
        nums.push_back(i);
    int result = find_fronr_end_equal(nums);
    cout << result <<  endl;
    return 1;
}