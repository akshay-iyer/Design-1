// Time Complexity : O(1) for all 
// Space Complexity : O(n)  
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// Double hashing
// 1. See range and take sqrt as the first hash code and sqrt+1 as the second hashcode
// 2. For values betn 0-1000000, there'll be 1000 buckets and each bucket will have 1001 items. 1001 since consider 0-25 at bucket 0, there'll be 6 elements 
// 3. First only create a vector of size 1000, populate individual buckets only when necessary to save space

class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> arr;
    int code1 = 1000;
    int code2 = 1001;
    MyHashMap() {
        arr.resize(1000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash1 = key%code1;
        if(arr[hash1].size() == 0){
            arr[hash1].resize(1001);
            for(int j=0;j<arr[hash1].size();j++)
                arr[hash1][j] = -1;
        }
        int hash2 = key/code2;
        arr[hash1][hash2] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash1 = key%code1;
        if(arr[hash1].size() == 0)
            return -1;
        int hash2 = key/code2;
        return arr[hash1][hash2];        
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key*/
    void remove(int key) {
        int hash1 = key%code1;
        if(arr[hash1].size() == 0)
            return;
        int hash2 = key/code2;
        arr[hash1][hash2] = -1;        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */