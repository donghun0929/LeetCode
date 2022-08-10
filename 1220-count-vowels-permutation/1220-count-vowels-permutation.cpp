class Solution {
public:
    int countVowelPermutation(int n) {
        long long dp[2][5] = {1,1,1,1,1,};
        int modulo = 1000000007; 
        if(n ==0)
            return 0;
        if(n == 1)
            return 5;
        
        bool bSecond = false;
        while(n > 0)
        {
            if(bSecond){
                dp[0][0] = (dp[1][1] + dp[1][2]+dp[1][4])%modulo;
                dp[0][1] = (dp[1][0] + dp[1][2])%modulo;
                dp[0][2] = (dp[1][1] + dp[1][3])%modulo;
                dp[0][3] = (dp[1][2])%modulo;
                dp[0][4] = (dp[1][2]+dp[1][3])%modulo;
                bSecond= false;
            }   
            else{
                dp[1][0] = (dp[0][1] + dp[0][2]+dp[0][4])%modulo;
                dp[1][1] = (dp[0][0] + dp[0][2])%modulo;
                dp[1][2] = (dp[0][1] + dp[0][3])%modulo;
                dp[1][3] = (dp[0][2])%modulo;
                dp[1][4] = (dp[0][2]+dp[0][3])%modulo;
                bSecond = true;
            }
            n--;
        }
        if(bSecond)
        {
            return (dp[0][4] +dp[0][3]+dp[0][2]+dp[0][1]+dp[0][0])%modulo;
        }
        return (dp[1][4] +dp[1][3]+dp[1][2]+dp[1][1]+dp[1][0])%modulo;
    }
};