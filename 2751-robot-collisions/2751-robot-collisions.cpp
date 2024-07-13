struct robot{
    int pos;
    int health;
    char dir;
    int idx;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        vector<robot> arr;
        for(int i = 0; i < n; i++)
        {
            robot r;
            r.pos = positions[i];
            r.health = healths[i];
            r.dir = directions[i];
            r.idx = i;
            arr.push_back(r);
        }
        
        sort(arr.begin(), arr.end(), [&](robot &a, robot &b){
            return a.pos < b.pos;
        });
        
        stack<int>st;
        vector<int>temp(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(arr[i].dir == 'R')
                st.push(i);
            
            else
            {
                while(!st.empty() && arr[i].health > 0 && arr[st.top()].dir == 'R' && arr[st.top()].health < arr[i].health)
                {
                    st.pop();
                    arr[i].health--;
                }
                
                if(st.empty() || arr[st.top()].dir  == 'L')
                    st.push(i);
                
                else if(!st.empty() && arr[st.top()].health == arr[i].health)
                    st.pop();
                
                else if(!st.empty() && arr[st.top()].health > arr[i].health)
                    arr[st.top()].health--;
            }
        }
        
        while(!st.empty())
        {
            int idx = arr[st.top()].idx;
            temp[idx] = arr[st.top()].health;
            st.pop();
        }
        
        vector<int>res;
        for(auto it : temp)
        {
            if(it != 0)
                res.push_back(it);
        }
        
        return res;
    }
};