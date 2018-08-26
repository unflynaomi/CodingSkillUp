#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <typeinfo>
#include <math.h>
#define ll long long

using namespace std;

const int mod=1000000007;
int dp[1010],f[1010],dp2[1010];
int main()
{
    int n;
    cin>>n;
    f[0]=1;
//    cout<<"shsg"<<10LL<<endl;
    for(int i=1;i<=1000;i++) f[i]=10LL*f[i-1]%mod;//f[1]=10,..f[9]=10^9,f[11]=999999937,  这里为什么小于1000次，没想明白。
    dp2[0]=dp[0]=0;dp2[1]=dp[1]=10;//dp2[0]合法表达式，dp[0]合法字符串,dp2[1]=dp[1]=10是指0-9有10种情况吗？
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-2];
        dp[i]=(dp[i]+f[i])%mod;
        dp2[i]=dp[i];
        for(int j=1;j<i;j++)
            dp[i]=(dp[i]+2LL*dp[j]*dp2[i-1-j])%mod;//维护dp[i]的时候，考虑最后一个加号或者减号出现的位置j，
    }
    cout<<dp[n]<<endl;
    return 0;
}

