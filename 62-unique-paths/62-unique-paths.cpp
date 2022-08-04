class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n, 0));
        v[m-1][n-1]= 1;
        moveRobot(0 , 0, m-1, n-1, v);
        return v[0][0];
    }
    
    int moveRobot(int x, int y, int m, int n, vector<vector<int>>& v)
    {
        if(x > m || y > n)
            return 0;
        if(v[x][y] != 0)
            return v[x][y];
        int k = moveRobot(x+1, y, m, n, v);
        int kk = moveRobot(x, y+1, m, n, v);
        v[x][y] =  k+kk;
        return v[x][y];
    }
};