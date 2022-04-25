class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> v;
        
        req(v, n, n, "");
        return v;
    }
    
    void req(vector<string>& v,int n, int m, string s)
    {
        if(m==0 && n==0)
        {
            v.push_back(s);
            return;
        }
        if(n>0)
            req(v, n-1, m,s+"(");
        if(m>0 && m>n)
            req(v, n, m-1,s+")");
    }
};