class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        else
        {
            int now=-1;
            int last=2;
            int lastlast=1;
            for(int i=3;i<=n;i++)
            {
                now=last+lastlast;
                lastlast=last;
                last=now;
            }
            return now;
        }
        
    }
};

