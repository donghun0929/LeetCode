class Solution {
public:
    vector<string> letterCombinations(string digits) {
   
        vector<string> vs ;
        vector<string> childVec;
        
        if(digits.empty())
            return vs;
        
        int c = digits[0];
        string s = digits.substr(1);
        
        string numText = "";
        
        if(c==50)
            numText = "abc";
        else if(c==51)
            numText = "def";
        else if(c==52)
            numText = "ghi";
        else if(c==53)
            numText = "jkl";
        else if(c==54)
            numText = "mno";
        else if(c==55)
            numText = "pqrs";
        else if(c==56)
            numText = "tuv";
        else if(c==57)
            numText = "wxyz";
        
        for(char cc : numText)
        {
            childVec = letterCombinations(s);
            if(childVec.empty())
            {
                string ss ;
                ss+= cc;
                vs.push_back(ss);
            }
            else{
            for(string ss : childVec)
                vs.push_back(cc+ss);
            }
        }
        
        return vs;
    }
    
    
};