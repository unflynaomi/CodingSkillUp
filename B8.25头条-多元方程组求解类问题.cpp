#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <typeinfo>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> lines;
    vector<string> search_lines;

    string line;
    lines.push_back("cannot_answer");
    search_lines.push_back("cannot_answer");

    for (int i=1; i<n+1; i++) {
        getline(cin, line, '\n');
        lines.push_back(line);
    }
    
    for (int i=1; i<m+1; i++) {
        getline(cin, line, '\n');
        search_lines.push_back(line);
    }
    
    
    
}

