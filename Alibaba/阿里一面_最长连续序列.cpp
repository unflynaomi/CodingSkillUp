#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
阿里巴巴一面编程题：有一个无序数组a，最长的连续序列。（LeetCode 128）
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
思路：将数组放在哈希表中，然后去查数的加一在不在表中。注意如果该数减一的值在表中，不需要操作，因为遍历i-1时必定会遍历到i。
*/

int longest_consecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int result = 0;
    for(auto i : nums) {
        int temp = 1;
        if(!s.count(i - 1)) {
            while(s.count(++i))
                temp += 1;
        }
        result = result > temp ? result : temp;
    }
    return result;
}

int main() {
    int a[] = {100, 4, 200, 1, 3, 2};
    vector<int> nums;
    for(auto i : a)
        nums.push_back(i);
    int result = longest_consecutive(nums);
    cout << result <<  endl;
    return 1;
}
