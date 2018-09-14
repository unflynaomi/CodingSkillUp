#include<iostream>
#include<vector>
using namespace std;
/*
头条三面题目：有一个降序数组，假设score(i, j)=a[i]+a[j]且i不等于j，求score的前K的值。
思路：题意是需要从a[0]+a[1], a[0]+a[2],...,a[1]+a[2],...,a[1]+a[n-1],...,a[n-2]+a[n-1]中找出前K大的数。
     从上面的序列中可以得出一个对比序列：
     a[0]+a[1]  >=  a[0]+a[2]  >=  a[0]+a[3]  >=  ...  >=  a[0]+a[n-1]
                    a[1]+a[2]  >=  a[1]+a[3]  >=  ...  >=  a[1]+a[n-1]
                                   a[2]+a[3]  >=  ...  >=  a[2]+a[n-1]
                                   ...
                                                           a[n-2]+a[n-1]
     可以看出每次只需要比较每一行的第一个数，因为行内的数已经有大小关系了，然后取最大值，再将最大值所在的那一行替换为下一个数就可以了。
*/

vector<int> find_max_sum(vector<int>& nums, int k) {
    vector<int> result;
    if(nums.size() <= 1)
        return result;

    vector<int> queue;
    vector<int> pos;
    int current_pos = 0;

    queue.push_back(nums[0] + nums[1]);
    pos.push_back(1);

    while(k > 0) {
        int max_val = queue[0];
        int max_idx = 0;
        current_pos++;

        for(int i = 0; i < queue.size(); i++) {
            if(queue[i] != -10000 && max_val < queue[i]) {
                max_val = queue[i];
                max_idx = i;
            }
        }
        if(max_val == -10000)
            break;
        result.push_back(max_val);
        pos[max_idx]++;
        if(pos[max_idx] >= nums.size())
            queue[max_idx] = -10000;
        else
            queue[max_idx] = nums[max_idx] + nums[pos[max_idx]];
        if(current_pos < nums.size() - 1) {
            queue.push_back(nums[current_pos] + nums[current_pos + 1]);
            pos.push_back(current_pos + 1);
        }
        k--;
    }
    return result;
}

int main() {
    int a[] = {8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> nums;
    for(auto i : a) {
        nums.push_back(i);
    }
    vector<int> result = find_max_sum(nums, 5);
    for(auto i : result)
        cout << i << "  ";
    cout << endl;
    return 1;
}