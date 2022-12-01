class Solution {
public:
    bool halvesAreAlike(string s) {
        char c[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int half =s.length()/2;
        
        int nLeft = 0;
        int nRight = 0;
        for(int i = 0 ; i < half; i++)
        {
            bool exists = std::count(std::begin(c), std::end(c), s[i]) > 0;
            if(exists)
                nLeft++;
            
        }
        for(int i = half ; i < s.length(); i++)
        {
            bool exists = std::count(std::begin(c), std::end(c), s[i]) > 0;
            if(exists)
                nRight++;
        }
        
        if(nRight == nLeft)
            return true;
        return false;
    }
};