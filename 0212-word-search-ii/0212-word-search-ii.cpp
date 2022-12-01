class Solution {
    struct Trie
    {
        bool last = false;
        Trie *T[26];// = NULL;
        
        Trie(){
            for (int i = 0; i < 26; i++) {
                T[i] = NULL;
            }
        }
    };
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string> ret ;
        vector<vector<int>> step(board.size(), vector<int>(board[0].size()));
        
        Trie *t = new Trie();
        Trie *map = t;
        for(int i = 0 ; i < words.size(); i ++)
        {
            t = map;
            for(int j = 0 ; j < words[i].length(); j++)
            {
                int c = words[i][j] - 'a';
                if(t->T[c] == NULL)
                {
                    t->T[c] = new Trie();
                    t =t->T[c];
                }
                else
                {
                    t =t->T[c];
                }
            }
            t->last= true;
        }
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size();j++)
            {
                int c = board[i][j] - 'a';
                
                if(map->T[c] != NULL)
                {
                    insertWord(board, words, map, i, j, "", ret,step);
               }
            }
        }
        
        return ret;
    }
    
    void insertWord(vector<vector<char>>& board, vector<string>& words, Trie* map, int x, int y, string member, vector<string>& ret, vector<vector<int>>& step)
    {
                
        if(x < 0 || x >= board.size())
        {
            return;
        }
        if( y < 0 || y >= board[0].size())
        {
            return;
        }
        if(step[x][y]==1)
            return;
        
        int c = board[x][y] - 'a';
        
        if(map->T[c] == nullptr)
            return;
        
        step[x][y] = 1;
        
        member = member+board[x][y];
        
        map = map -> T[c];
        if(map->last == true)
        {
            map->last = false;
            ret.push_back(member);
        }
        
        insertWord(board, words, map, x+1, y, member, ret, step);
        //map->T[c] = t; 
        
        //t = map;
        //m = map -> T[c];
        insertWord(board, words, map, x-1, y, member, ret, step);
        //map->T[c] = t;
        
        //m = map -> T[c];
        insertWord(board, words, map, x, y-1, member, ret, step);
        //map->T[c] = t;
        
        //m = map -> T[c];
        insertWord(board, words,map, x, y+1, member, ret, step);
        //map->T[c] = t;
        
        step[x][y] = 0;
        return;
    }
};