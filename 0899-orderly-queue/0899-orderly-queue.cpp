class Solution {
public:
    string orderlyQueue(string s, int k) {
        vector<int> v;
        vector<int> minV;
        vector<int> tempVec;
        int nLen = s.length();
        if(k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        else
        {
            for(int i = 0; i <nLen; i++)
            {
                int k = (int)s[i];
                v.push_back(k);
                minV.push_back(k);
            }
            
            for(int i = 1; i < nLen; i++)
            {
                tempVec.clear();
                int nStart = (i)%nLen;
                int j = 0;
                bool bParentPass = false;
                while(j < nLen){
                    nStart = (i + j)% nLen;
                    if(minV[j] > v[nStart]){
                        bParentPass = true;
                        tempVec.push_back(v[nStart]);
                    }
                    else if(minV[j] >= v[nStart]){
                        
                        tempVec.push_back(v[nStart]);
                    }
                    else{
                        if(bParentPass){
                            tempVec.push_back(v[nStart]);
                        }
                        else
                        {break;}
                    }
                    j++;
                }
                if(tempVec.size() == nLen)
                    minV = tempVec;
            }
        }
        
        s = "";
        for(int i = 0 ; i < nLen ; i++)
        {
            s +=minV[i];
        }
        return s;
    }
};