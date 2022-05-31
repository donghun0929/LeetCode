class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() <= k)
            return false;
        
        set<string> st;
        int cnt = pow(2, k);
        
        for(int i=0; i <= s.length() -k; i++)
        {
            //if(s[i] == '\"')
            //    continue;
            string ss ="";
            for(int j =0; j < k;j++)
            {
                ss+=s[j+i];
            }
            //cout << ss << endl;
            st.insert(ss);
        }
        //cout << cnt << endl;
        //cout << st.size() << endl;
        if(st.size() ==cnt)
            return true;
        
        return false;
    }
};