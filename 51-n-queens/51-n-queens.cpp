class Solution {
public:
     
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> vv(n, vector<int>(n, 0) );
        vector<vector<string>> vs;
        vector<pair<int, int>> vp;
        
        for(int i=0; i< n ; i++)
        {
            vv[0][i] = 1;
            vp.push_back({i, 0});
            if(findOverlap(vv, n, vp,vs))
                solveQueen(n, 1, vv, vs, vp);   
            vp.pop_back();
            vv[0][i] = 0;
        }
        
        return vs;
    }
    
    void solveQueen(int n, int x, vector<vector<int>> vv, vector<vector<string>>& vs, vector<pair<int, int>> vp)
    {
        if(n <= x)
            return;
        for(int i=0; i< n ; i++)
        {
            vv[x][i]= 1;
            vp.push_back({i, x});
            if(findOverlap(vv, n, vp,vs))
                solveQueen(n, x+1 , vv, vs, vp);    
            vp.pop_back();
            vv[x][i]= 0;
        }
    }
    
    bool findOverlap(vector<vector<int>> vv, int n , vector<pair<int, int>> vp, vector<vector<string>>& vs)
    {
        
        for(int k = vp.size() - 1 ; k >=0; k--)
        {
            int x = vp[k].first;
            int y = vp[k].second;
            for(int i = 0; i< n;i++)
            {
                if(vv[i][x] == 1  && i != y)
                {
                    return false;
                }
            }
            for(int i = x -1, j =  y - 1; i >= 0 && j >= 0; i--,j--)
            {
                if(vv[j][i] == 1)
                    return false;
            }
            for(int i = x-1, j = y+1; i >=0 && j < n; i--, j++)
            {
                if(vv[j][i] == 1)
                    return false;
            }
        }
        
        if(vp.size() == n){
            vector<string> v;
            for(int i=0; i < n ; i++)
            {
                string s = "";
                for(int j = 0 ; j < n ; j++)
                {
                    if(vv[i][j] == 0)
                        s += ".";
                    else
                        s += "Q";
                }
                v.push_back(s);
            }
            vs.push_back(v);
        }
        return true;
    }
    
};