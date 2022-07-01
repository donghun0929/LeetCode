class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int dp[101][3] = {0,};   
        int nMin = INT_MAX;   
        int maxSize =  costs.size()-1;
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for(int i = 1 ; i < costs.size(); i++)
        {
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + costs[i][2];
        }
        
        nMin = min(dp[maxSize][0],dp[maxSize][1]);
        nMin = min(nMin,dp[maxSize][2]);
        
        return nMin;
    }
};