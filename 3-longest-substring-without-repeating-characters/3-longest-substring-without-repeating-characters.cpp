class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> mc;
        int val = 0;
        int left = 0;
        for(int right =0; right < s.length() ; right++)
        {
            if(mc.find(s[right]) != mc.end())
            {
                int TempLeft = mc[s[right]];
                if(left <= TempLeft)
                    left = TempLeft+1;
            }
            mc[s[right]] = right;
            val = val > (right- left+1) ? val : (right- left+1);
        }
        return val;
    }
};