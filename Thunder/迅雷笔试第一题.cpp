#include<iostream>
#include<vector>
using namespace std;
/*
迅雷笔试编程题第一题：有两个无序数组，假设score(i, j)=a[i]+b[j]，求score的前K的值。
思路：题意是需要从a[0]+b[0], a[0]+b[0],...,a[1]+b[0],...,a[1]+b[n-1],...,a[m-1]+b[n-1]中找出前K大的数。
     这个题目跟头条的那个有点类似，不过变成两个数组，思路是一样，首先将数组降序排列。从上面的序列中可以得出一个对比序列：
     a[0]+b[0]   >=  a[0]+b[1]    >=  a[0]+a[2]    >=  ...  >=  a[0]+b[n-1]
     a[1]+b[0]   >=  a[1]+b[1]    >=  a[1]+b[2]    >=  ...  >=  a[1]+b[n-1]
     a[2]+b[0]   >=  a[2]+b[1]    >=  a[2]+b[2]    >=  ...  >=  a[2]+a[n-1]
                                   ...
     a[m-1]+b[0] >=  a[m-1]+b[1]  >=  a[m-1]+b[2]  >=  ...  >=  a[m-1]+a[n-1]
     可以看出每次只需要比较每一行的第一个数，因为行内的数已经有大小关系了，然后取最大值，再将最大值所在的那一行替换为下一个数就可以了。
*/

vector<int> find_max_sum(vector<int>& a, vector<int>& b, int k) {
    vector<int> queue;
    vector<int> pos;
    vector<int> result;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int current_pos = 0;
    if(a.size() == 0 || b.size() == 0)
        return result;
    queue.push_back(a[0] + b[0]);
    pos.push_back(0);
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
        pos[max_idx] += 1;
        if(pos[max_idx] >= b.size())
            queue[max_idx] = -10000;
        else
            queue[max_idx] = a[max_idx] + b[pos[max_idx]];
        if(current_pos < a.size()) {
            queue.push_back(a[current_pos] + b[0]);
            pos.push_back(0);
        }
        k--;
    }
    return result;
}

int main() {
    int a[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int b[] = {9, 9, 7, 6, 4};
    vector<int> nums_a;
    vector<int> nums_b;
    for(auto i : a)
        nums_a.push_back(i);
    for(auto i : b)
        nums_b.push_back(i);
    vector<int> result = find_max_sum(nums_a, nums_b, 5);
    for(auto i : result)
        cout << i << "  ";
    cout << endl;
    return 1;
}
