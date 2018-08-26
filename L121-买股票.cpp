class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int j = 0;
        for (int i = 1; i < prices.size(); i ++){
          int compare = prices[i] - prices[j];
          if(compare > maxProf){
            maxProf = compare;
          }     
          if(prices[i] < prices[j])
              j = i;
        }
        return maxProf;
        
    }
};