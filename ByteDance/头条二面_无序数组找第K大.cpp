#include<iostream>
#include<vector>
using namespace std;
/*
头条二面题目：从无需数组中找到第K大的数字
思路：利用快排的思想，每次让哨兵归位，再判断第K大的数在左边还是右边，减少比较次数
*/

int find_kth(vector<int>& nums, int k) {
    if(k > nums.size())
        return -1;
    int start = 0, end = nums.size() - 1;
    int p = nums[start];
    while(start < end) {
        int left = start, right = end;
        while(left < right && nums[right] > p)
            right--;
        while(left < right && nums[left] < p)
            left++;
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        if(left == right) {
            if(left == k - 1)
                return p;
            else if(left > k - 1)
                end = left - 1;
            else
                start = left + 1;
            p = nums[start];
        }
    }
    return -1;
}

int main() {
    int a[] = {7, 8, 1, 2, 10, 5};
    vector<int> nums;
    for(auto i : a)
        nums.push_back(i);
    cout << find_kth(nums, 3);
    return 1;
}