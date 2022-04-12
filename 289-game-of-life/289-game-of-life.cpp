class Solution {
public:
    
    int map[25][25] = {0,};
    //vector<vector<int>> map;
    int m=0;
    int n=0;
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        //int map[m][n] = {0,};
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                setNewBoard(i, j, board);   
            }
        }
        
         for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                board[i][j] = map[i][j];   
            }
        }
        
        
    }
    
    void setNewBoard(int i,int j, vector<vector<int>>& board)
    {
        int k =0;
        for(int y = i-1; y<= i+1; y++)
        {
            if(y<0 || y == m)
                continue;
            for(int x = j-1; x<= j+1; x++)
            {
                if(x < 0 || x == n || (i==y && j==x))
                    continue;
                if(board[y][x] == 1)
                    k++;
            }
        }
        if(k>3 && board[i][j]==1)
            map[i][j] = 0;
        else if(k==2)
        {
            if(board[i][j]==1)
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
            
        else if(k==1)
            map[i][j]=0;
        else if(k==3)
            map[i][j]=1;
    }
};