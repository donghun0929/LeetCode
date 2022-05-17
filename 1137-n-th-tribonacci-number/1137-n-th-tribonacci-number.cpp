class Solution {
public:
    
    int map[39] = {0,};
    int tribonacci(int n) {
        if(map[n] != 0)
            return map[n];
        if(n==0 || n== 1)
        {
            map[n] = n;
            return map[n];
        }
        if(n==2)
        {
            map[n] = 1;
            return map[n];
        }
        map[n] += tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        return map[n];
    }
};