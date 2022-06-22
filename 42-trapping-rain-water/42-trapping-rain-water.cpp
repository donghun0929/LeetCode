class Solution {
public:
    int trap(vector<int>& height) {
        stack <int> s;
        int retVal = 0;
        int high = 0;
        if(height.size()==1)
            return 0;
        
        for(int i = 0; i < height.size(); i++)
        {
            high = height[high] > height[i] ? high : i;
        }
        
        retVal += LeftStack(height,high);
        retVal += RightStack(height,high);
        
        return retVal;
    }
    
    int LeftStack(vector<int>& height, int Right)
    {
        stack <int> s;
        int retVal = 0;
        int maxNum = height[0];  
        int cnt = 1;
        s.push(maxNum);
        for(int i = 1; i <= Right; i++)
        {
            
            if(maxNum <= height[i] && cnt > 0)
            {
                s.pop();
                s.push(height[i]);
                maxNum =  height[i];
                cnt++;
            }
            else if(maxNum <= height[i] && cnt == 0)
            {
                while(!s.empty())
                {
                    int k = s.top();
                    s.pop();
                    retVal = retVal + (maxNum - k);
                }
                s.push(height[i]);
                maxNum = height[i];
                cnt++;
            }
            if(maxNum > height[i])
            {
                s.push(height[i]);
                cnt = 0;
            }
        }
        
        return retVal;
    }
    
    int RightStack(vector<int>& height, int Left)
    {
        stack <int> s;
        int retVal = 0;
        int maxNum = height[height.size()-1];  
        int cnt = 1;
        s.push(maxNum);
        for(int i = height.size()-1; i >= Left ; i--)
        {
            
            if(maxNum <= height[i] && cnt > 0)
            {
                s.pop();
                s.push(height[i]);
                maxNum =  height[i];
                cnt++;
            }
            else if(maxNum <= height[i] && cnt == 0)
            {
                while(!s.empty())
                {
                    int k = s.top();
                    s.pop();
                    retVal = retVal + (maxNum - k);
                }
                s.push(height[i]);
                maxNum = height[i];
                cnt++;
            }
            if(maxNum > height[i])
            {
                s.push(height[i]);
                cnt = 0;
            }
        }
        
        return retVal;
    }
};