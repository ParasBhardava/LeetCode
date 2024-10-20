class Solution {
    
private:
    bool parseOr(vector<int> &arr)
    {
        int n = arr.size(), res = arr[0];
        for(int i = 1; i < n; i++)
            res |= arr[i];
        
        return res;
    }
    
    bool parseAnd (vector<int> &arr)
    {
        int n = arr.size(), res = arr[0];
        for(int i = 1; i < n; i++)
            res &= arr[i];
        
        return res;
    }
    
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            if(expression[i] == ',' || expression[i] == '(') 
                continue;
            
            if(expression[i] == ')')
            {
                vector<int> arr;
                while(st.top() != '&' && st.top() != '|' && st.top() != '!')
                {
                    char ch = st.top();
                    st.pop();
                    if(ch == 't') 
                        arr.push_back(1);
                    if(ch == 'f')
                        arr.push_back(0);
                }
                
                char ch = st.top();
                st.pop();
                
                if(ch == '&')
                {
                    if(parseAnd(arr)) 
                        st.push('t');
                    else
                        st.push('f');
                }
                else if(ch == '|') 
                {
                    if(parseOr(arr))
                        st.push('t');
                    else 
                        st.push('f');
                }
                else if(ch == '!')
                {
                    if(arr[0] == 0) 
                        st.push('t'); 
                    else
                        st.push('f');
                }
            }
            
            else
                st.push(expression[i]);
        }
        return (st.top() == 't');
    }
};