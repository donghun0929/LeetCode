class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int, int> m;
        vector<int> v;
        int nSize = mat.size();
        int n = INT_MAX;
        
        for(int i = 0 ; i < mat[0].size(); i++)
        {
            m.insert({mat[0][i],1});
        }
        for(int i = 1 ;  i < mat.size(); i++)
        {
            for(int j = 0 ;  j < mat[i].size(); j++)
            {
                if(m.find(mat[i][j]) != m.end())
                    m[mat[i][j]]++;
            }
        }
    
    for (auto iter : m) 
    {
        if(nSize ==iter.second)
            v.push_back(iter.first);
    }
    if(v.size()!=0)
    {
        for(auto iter : v)
        {
            n = n <= iter ? n :iter;   
        }
            return n;
    }
    
    return -1;
    }
};