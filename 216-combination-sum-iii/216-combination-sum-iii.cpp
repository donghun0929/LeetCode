class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> vv;
        vector<int> v;
        combination(k, n, v, vv);
        return vv;
    }
    
    void combination(int k, int n, vector<int> &val, vector<vector<int>> &result)
    {
        if(k ==0 && n == 0)
        {
            result.push_back(val);
            return;
        }
        
        for(int i = val.empty() ? 1 :val.back()+1; i< 10;i++)
        {
            val.push_back(i);
            combination(k-1, n-i, val, result);
            val.pop_back();
        }
    }
};

