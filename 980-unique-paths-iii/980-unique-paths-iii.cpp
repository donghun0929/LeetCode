class Solution {
public:
    int result = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int nRobotX=0;
        int nRobotY=0;
        int nEndX=0;
        int nEndY=0;
        
        vector<vector<int>> v(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int j = 0; j< grid.size(); j++)
        {
            for(int i = 0; i<grid[0].size(); i++)
            {
                if(grid[j][i] == 1)
                {
                    nRobotY = j;
                    nRobotX = i;
                }
                if(grid[j][i] == 2)
                {
                    nEndX=i;
                    nEndY=j;
                }
                if(grid[j][i] ==-1)
                    v[j][i] = -1;
            }
        }
        
        findRoot(nRobotX, nRobotY, nEndX, nEndY, v);
        
        return result;
    }
    
    void findRoot(int X, int Y, int endX, int endY, vector<vector<int>>& v){
        
        if(v[Y][X] == 1 || v[Y][X] == -1)
            return;
        v[Y][X]=1;
        
        if(X == endX&& Y ==endY)
        {
            bool bTrue = true;
            for(int i =0; i < v.size(); i++)
            {
                for(int j =0; j < v[0].size(); j++)
                {
                    if(v[i][j] == 0)
                    {
                        bTrue = false ;
                        break;
                    }
                }
                if(!bTrue)
                    break;
            }
            if(bTrue)
                result +=1;
        }
        if(X-1 >= 0)
            findRoot(X-1, Y, endX, endY, v); //9
        if(Y-1 >=0)
            findRoot(X, Y-1, endX, endY, v); //12
        if(Y+1 < v.size())
            findRoot(X, Y+1, endX, endY, v); //6
        if(X+1 < v[0].size())
            findRoot(X+1, Y, endX, endY, v); //3
        
        v[Y][X] =0;
        return;
    }
};