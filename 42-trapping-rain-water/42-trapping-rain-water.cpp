class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> leftVal(20001);
        vector<int> rightVal(20001);
        
        int leftMax = 0;
        int rightMax = 0;
        int val=0;
        
        for(int L = 0; L < height.size(); L++)
        {
            int H = height[L];
            leftMax = leftMax > H ? leftMax : H;
            if(L == 0)
                continue;
            leftVal[L] = leftMax - H;            
        }
        
        for(int R= height.size()-1; R >=0; R--)
        {
            int H = height[R];
            rightMax = rightMax > H ? rightMax : H;
            if(R == height.size()-1)
                continue;
            rightVal[R] = rightMax - H;            
        }
        
        for(int i = 0; i < height.size(); i++)
        {
            int waterDeep = min(rightVal[i],leftVal[i]);
            val += waterDeep;
        }
        return val;
    }
};