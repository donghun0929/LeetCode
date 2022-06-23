class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nums = Sort(nums, 0, nums.size()-1);
        
        return nums[k-1];
    }
    
    vector<int> Sort(vector<int> nums, int left, int right)
    {
        vector<int> v;
        vector<int> lV;
        vector<int> rV;
        if(left==right)
        {
            v.push_back(nums[left]);
            return v;
        }
        lV = Sort(nums, left, (left+right)/2);
        rV = Sort(nums, (left+right)/2+1, right);
        return merge(lV, rV);
    }
    
    vector<int> merge(vector<int> lV, vector<int> rV)
    {
        vector<int> newVec;
        
        int i = 0;
        int j = 0;
        while(lV.size() != i && rV.size() != j)
        {
            if(lV[i] >= rV[j])
                newVec.push_back(lV[i++]);
            else
                newVec.push_back(rV[j++]);
        }
        if(i != lV.size())
        {
            for(;i< lV.size(); i++)
            {
                newVec.push_back(lV[i]);
            }
        }
        else
        {
            for(;j< rV.size(); j++)
            {
                newVec.push_back(rV[j]);
            }
        }
        return newVec;
    }
    
    
};