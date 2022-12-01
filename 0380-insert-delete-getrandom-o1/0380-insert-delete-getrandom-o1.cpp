class RandomizedSet {
public:
    vector<int> v;
    
    RandomizedSet() {
        v.clear();
    }
    
    bool insert(int val) {
        
    if(find(v.begin(), v.end(), val) == v.end()) { // vector내에 0이 존재하지 않음
        
        v.push_back(val);
        return true;
    }
        
        return false;
    }
    
    bool remove(int val) {
        if(find(v.begin(), v.end(), val) == v.end()) { // vector내에 0이 존재하지 않음
            return false;
        }v.erase(std::remove(v.begin(), v.end(), val), v.end());
        return true;
    }
    
    int getRandom() {
        int nSize = v.size();
        if(nSize == 0)
            return -1;
        int random = rand()%nSize;
        int k = v[random];
        
        return k;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */