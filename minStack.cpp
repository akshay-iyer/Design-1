// Time Complexity : O(1) for all
// Space Complexity : O(n)  
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// 1. Maintain 2 vectors one for regular elements and 1 to store min el so far
// 2. While pushing ensure to keep min element at the end of min_st

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> st;
    vector<int> min_st;
    MinStack() {
        
    }
    
    void push(int x) {
        st.emplace_back(x);
        if(min_st.size() == 0 || x<min_st.back())
            min_st.emplace_back(x);
        else
            min_st.emplace_back(min_st.back());
    }
    
    void pop() {
        st.pop_back();
        min_st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return min_st.back();
    }
};

// Alternative solutions: keep a min_el as well to avoid repeats in min_st 
// Either this or in min_st use a pair showing min and number of times it has occured 
// Or just use one stack with pair of that element and the min of stack so farl
class MinStack {
public:
    vector<int> st; 
    vector<int> min_st;
    int min_el=INT_MAX;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.emplace_back(x);
        if(x<=min_el){
            min_st.emplace_back(x);
            min_el = x;
        }
        cout<<"added "<<x<<endl;
    }
    
    void pop() {
        int num = st.back();
        st.pop_back();
        if(num == min_el){
            min_st.pop_back();
        }
        if(min_st.size()==0)
            min_el = INT_MAX;
        else
            min_el = min_st.back();
        cout<<"popped out "<<num<<endl;
    }
    
    int top() {
        cout<<"top el is: "<<st.back()<<endl;
        return st.back();
    }
    
    int getMin() {
        cout<<"min is "<<min_el<<endl;
        return min_el;
    }
};
