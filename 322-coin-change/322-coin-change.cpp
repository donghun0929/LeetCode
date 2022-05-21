class Solution {
public:
    int val[10001] ={0,};
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0 )
            return 0;
        vector<int> coins2 ; 
        for(int c : coins)
        {
            if(c > amount)
                continue;
            coins2.push_back(c);
            val[c] = 1;
        }
        
        if(coins2.size()==0)
            return -1;
        sort(coins2.begin(), coins2.end());
        
        for(int i= coins2[0]; i <= amount; i++)
        {
            int minVal = INT_MAX;
            if(val[i]!=0)
                continue;
            else{
                for(int c: coins2)
                {
                    if(i-c > 0 && val[i-c]!=0 && minVal > val[i-c])
                        minVal = val[i-c];
                }
                if(minVal != INT_MAX)
                    val[i] = minVal+1;
            }
        }
        
        int ret = (val[amount] == 0 )? -1: val[amount];
        return ret;
    }
};