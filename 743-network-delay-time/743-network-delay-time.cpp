class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> v(n+1);
        //int map[101] = {0,}; 
        vector<int> map(n+1, INT_MAX);
        bool bChk[101] = {false};
        
        map[k] = 0;
        for(vector<int> vv : times)
        {
            v[vv[0]].push_back(make_pair(vv[1],vv[2]));
        }
        
        queue<int> q;
        q.push(k);
        
        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            for(pair<int, int> p: v[k])
            {
                if(map[p.first] > map[k] + p.second)
                {
                    map[p.first] =  map[k] + p.second;
                    q.push(p.first);
                }
            }
        }
        int retVal = -1;
        for(int i=1; i <=n ; i++)
        {
            if(map[i] == INT_MAX)
                return -1;
            retVal = retVal< map[i] ? map[i]: retVal;
        }

        return retVal;
    }
};