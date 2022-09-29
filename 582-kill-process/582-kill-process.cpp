class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        map<int, vector<int>> m;
        queue<int> q;
        vector < vector <int> > tempData(50001);
        vector <bool> vVisit(50001 , 0);
        vector<int> retVal;
        
        for(int i = 0 ; i < pid.size(); i++)
        {
            tempData[ppid[i]].push_back(pid[i]);
        }
        //tempData.clear();
        q.push(kill);
        retVal.push_back(kill);
        //vVisit[kill]  = 1;
        if(tempData[kill].size() == 0)
        {
            return retVal;
        }

        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            
            if(tempData[k].size() != 0 )
            {
                
                if(vVisit[k] != 1)
                {
                    retVal.insert(retVal.end(), tempData[k].begin(), tempData[k].end());
                    vVisit[k]  = 1;
                    for(int i =0 ;  i < tempData[k].size(); i++)
                    {
                        if(!vVisit[tempData[k][i]])
                            q.push(tempData[k][i]);
                    }
                }
            }   
        }
        
        return retVal;
    }
};