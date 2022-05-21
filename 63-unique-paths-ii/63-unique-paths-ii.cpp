class Solution {
public:
    int map[101][101] = {0,};
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        searchMap(0,0,obstacleGrid);
        return map[0][0];
    }
    
    int searchMap(int i, int j, vector<vector<int>>& obstacleGrid)
    {
        if(map[i][j] != 0)
            return map[i][j];
        if(i==obstacleGrid.size()-1 && j ==obstacleGrid[0].size()-1 && obstacleGrid[i][j] == 0)
        {
            map[i][j]=1;
            return map[i][j];
        }
        if(obstacleGrid[i][j] != 0)
            return 0;

        
        
        if(i < obstacleGrid.size()-1)
            map[i][j] += searchMap(i+1,j,obstacleGrid);
        if(j < obstacleGrid[0].size()-1)
            map[i][j] += searchMap(i,j+1,obstacleGrid);
        
        return map[i][j];
    }
};