class Solution {
public:
    int minSwaps(vector<int>& data) {
        int sum = accumulate(data.begin(), data.end(), 0);
        
        int maxCnt = 0;
        int addNum = 0;
        for(int j =0; j< sum; j++)
        {
            addNum+=data[j];
        }
        
        int left = 0;
        maxCnt = addNum;
        for(int i =0; i < data.size()-sum; i++)
        {
            addNum -= data[left++];
            addNum += data[sum+i];
            
            maxCnt = maxCnt > addNum ? maxCnt : addNum;

        }
        return sum - maxCnt;
    }
};