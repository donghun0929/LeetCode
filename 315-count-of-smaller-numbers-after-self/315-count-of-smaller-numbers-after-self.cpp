class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> temp = {nums.begin(), nums.end()};
        
        vector<pair<int, int>> p(nums.size());
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            p[i].first = i;
            p[i].second = i;
         }
        reverse(p.begin(), p.end());
        
        mergeSort(nums, temp, p);
        for(int k = 0; k < p.size(); k++ )
        {
            int idx = p[k].first;
            int val = p[k].second;
            
            temp[idx] = val;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    
    void mergeSort(vector<int>& nums, vector<int>& temp, vector<pair<int, int>> &p)
    {
        if(nums.size() == 1)
            return;
        int mid =  nums.size()/2;
        int right = nums.size();
        
        divide(0, mid-1, temp, p);
        divide(mid, right-1, temp, p);
        merge(0, mid, right-1, temp, p);
    
    }
    
    void divide(int left, int right, vector<int> &temp, vector<pair<int, int>> &p)
    {
        int mid = left + (right- left)/2;
        if(left == mid) //swap
        {
            if(temp[left] <= temp[right])
            {
                int vTemp;
                pair<int, int> vPair;
                    
                vTemp = temp[left];
                temp[left] = temp[right];
                temp[right] = vTemp;
                
                
                p[left].second -= right - left;
                vPair = p[left];
                p[left] = p[right];
                p[right] = vPair;
            }
            return;   
        }
        divide(left, mid-1, temp, p);
        divide(mid, right,temp, p);
        merge(left, mid, right, temp, p);
    }
    
    void merge(int left, int mid ,int right, vector<int> &temp, vector<pair<int, int>> &p)
    {   
        int i = left;
        int j = mid;
        int k = 0;
        vector<int> regTemp(right-left+1);
        vector<pair<int, int>> regPair(right-left+1);
        while(i < mid && j <= right)
        {
            if(temp[i] <= temp[j])
            {
                regTemp[k] = temp[j];
                regPair[k] = p[j];
                
                j++;
            }
            else
            {
                regTemp[k] = temp[i];
                p[i].second += mid - j;
                regPair[k] = p[i];
                
                i++;
            }
            k++;
        }
        while(i < mid)
        {
            regTemp[k] = temp[i];
            p[i].second += mid -j;
            regPair[k] = p[i];
                
            i++;
            k++;
        }
        
        while(j <= right)
        {
            regTemp[k] = temp[j];
            regPair[k] = p[j];
                
            j++;
            k++;
        }
        
        copy(regTemp.begin(), regTemp.end(), temp.begin()+left);
        copy(regPair.begin(), regPair.end(), p.begin()+left);
    }
};