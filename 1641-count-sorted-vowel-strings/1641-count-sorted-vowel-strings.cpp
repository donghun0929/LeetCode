class Solution {
public:
    int countVowelStrings(int n) {
       //Next = a->5, e->4, i->3, o->2, u->1;
        if(n==1)
            return 5;
        
        return req(n-1, 0, 0, 5);
    }
    
    int req(int n, int count, int mul, int text)
    {
        if(n == count)
            return text;
        for(int i = 1; i <= text; i++)
        {
            int k=0;
            mul += req(n, count+1, k, i);
        }
        return mul;
    }
};