class Solution {
public:
    set<string> sMap;
    int map[51][51]={0,};
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j<grid[0].size(); j++)
            {
                string s;
                if(map[i][j]== 0 &&grid[i][j]!=0)
                    sMap.insert(unionFind(j, i , j, i, grid[0].size(), grid.size(), grid));            
            }
        }
        
        return sMap.size();
    }
    
    string unionFind(int x, int y, int realX, int realY, int maxX, int maxY, vector<vector<int>>& grid)
    {
        if(x < 0 || x >= maxX || y < 0 || y >= maxY|| grid[y][x] ==0)
            return "";
        if(map[y][x] != 0)
            return "";
        map[y][x] = 1;
        int xx = realX - x;
        int yy = realY - y;
        string retVal = to_string(xx)+to_string(yy);
        retVal += unionFind( x+1, y, realX, realY, maxX, maxY,grid); //e
        retVal += unionFind( x-1, y, realX, realY, maxX, maxY,grid); //w
        retVal += unionFind( x, y+1, realX, realY, maxX, maxY,grid); //s
        retVal += unionFind( x, y-1, realX, realY, maxX, maxY,grid); //s
        
        return retVal;
    }
    
};