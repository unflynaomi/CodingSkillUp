#include <iostream>

#include <iterator>

#include <string>

#include <sstream>

#include <vector>

#include <algorithm>


using namespace std;

vector<string> &split(const string &str, char delim, vector<string> &elems, bool skip_empty = true) {
    istringstream iss(str);
    for (string item; getline(iss, item, delim); )
        if (skip_empty && item.empty()) continue;
        else elems.push_back(item);
    return elems;
}

typedef vector<pair<int, int> > RangeList;

RangeList cover(const RangeList& intervals) {
    int left = intervals[0].first, right = intervals[0].second;
    RangeList result;

    for (int i = 1; i < intervals.size(); ++i) {
        // 前面自成一个区间，那么就此分开
        if (intervals[i].first > right) {
            result.push_back(make_pair(left, right));
            left = intervals[i].first;
            right = intervals[i].second;
        } else if (intervals[i].second > right) {
            right = intervals[i].second;
        }
    }
    result.push_back(make_pair(left, right));

    return result;
}

void display(const RangeList& intervals) {
    for (int i = 0; i < intervals.size(); ++i)
    {
    	if (i<intervals.size()-1)
    	cout << intervals[i].first << ',' << intervals[i].second<<";";
    	else
    	cout << intervals[i].first << ',' << intervals[i].second;
	}
        
    cout << endl;
}

int main() {
	 
   
    RangeList intervals;
    int n, start, end;
    cin >> n;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
         vector<string> result1;
         split(str, ';', result1);
	     for(int i=0;i<result1.size();i++)
	     {
	     	//cout<<result1[i]<<endl;
	     	vector<string> result2;
            split(result1[i], ',', result2);
            intervals.push_back(make_pair(atoi(result2[0].c_str()), atoi(result2[1].c_str())));
		 }
	        
    }
    sort(intervals.begin(), intervals.end());

    //display(intervals);
    RangeList result = cover(intervals);
    display(result);

    return 0;
}
