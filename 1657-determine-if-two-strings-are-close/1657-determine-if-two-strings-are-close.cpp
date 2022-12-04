class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<int, int> m1;
        map<int, int> m2;
        
        vector<int> v1(27);
        vector<int> v2(27);
        
        if(word1.length() != word2.length())
            return false;
        
        for(int i = 0; i < word1.length(); i++)
        {
            int c1 = word1[i] -97;
            int c2 = word2[i] -97;
            v1[c1]++;
            v2[c2]++;
        }
        
        
        for(int i = 0 ; i < v1.size(); i++)
        {
            
            if(v1[i] == 0 && v2[i]!= 0)
                return false;
            
            if(v1[i] != 0 && v2[i]== 0)
                return false;
            
            if(m1.find(v1[i]) != m1.end())
            {
                m1[v1[i]]++;
            }
            else
            {
                m1.insert({v1[i], 1});
            }  
        }
        
        for(int i = 0 ; i < v1.size(); i++)
        {   
            if(m1.find(v2[i]) != m1.end())
            {
                m1[v2[i]]--;
            }
            else
            {
                return false;
            }  
        }
        
        map<int, int> :: iterator iter;
        
        for(iter = m1.begin(); iter != m1.end(); ++iter)
        {
            if(iter->second != 0)
                return false;
        }
        
        
        return true;
    }
};