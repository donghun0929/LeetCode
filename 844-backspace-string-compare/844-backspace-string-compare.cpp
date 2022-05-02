class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sS;
        stack<char> sT;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '"')
                continue;
            if(s[i] == '#' && sS.size()!=0)
            {
                sS.pop();
                continue;
            }
            if(s[i] == '#' && sS.size()==0)
            {
                continue;
            }
            
                sS.push(s[i]);
        }
        
        for(int i = 0; i < t.length(); i++)
        {
            if(t[i] == '"')
                continue;
            if(t[i] == '#' && sT.size()!=0)
            {
                sT.pop();
                continue;
            }
            if(t[i] == '#' && sT.size()==0)
            {
                continue;
            }
            sT.push(t[i]);
        }
        if(sS.size() != sT.size())
            return false;
        
        int size =  sS.size();
        
        for(int i = 0; i < size; i++)
        {
            if(sT.size()!=sS.size())
                return false;
            if(sT.top() == sS.top())
            {
                sT.pop();sS.pop();
                continue;
            }
            return false;
        }
        return true;
        
    }
};