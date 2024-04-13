class Solution {
private:
    vector<int> NSL(vector<int>&v)
    {
        vector<int>left;
        stack<pair<int, int>>st;
        int pseudoIndex = -1;

        for(int i=0; i<v.size(); i++)
        {
            if(st.size() == 0)
                left.push_back(pseudoIndex);

            else if(st.size()>0 && st.top().first<v[i])
                left.push_back(st.top().second);

            else if(st.size() > 0 && st.top().first >= v[i])
            {
                while(st.size() > 0 && st.top().first >= v[i])
                {
                    st.pop();
                }

                if(st.size() == 0)
                    left.push_back(pseudoIndex);

                else
                    left.push_back(st.top().second);
            }

            st.push({v[i], i});
        }
        return left;
    }

    vector<int> NSR(vector<int>&v)
    {
        vector<int>right;
        stack<pair<int, int>>st;
        int pseudoIndex = v.size();

        for(int i=v.size()-1; i>=0; i--)
        {
            if(st.size() == 0)
                right.push_back(pseudoIndex);

            else if(st.size() >0 && st.top().first<v[i])
                right.push_back(st.top().second);

            else if(st.size() > 0 && st.top().first >= v[i])
            {
                while(st.size() > 0 && st.top().first >= v[i])
                {
                    st.pop();
                }

                if(st.size() == 0)
                    right.push_back(pseudoIndex);

                else
                    right.push_back(st.top().second);
            }

            st.push({v[i], i});

        }

        reverse(right.begin(), right.end());
        return right;
    }

    
    int MAH(vector<int>&v)
    {
        vector<int> right = NSR(v);
        vector<int> left = NSL(v);

        
        int mx = INT_MIN;

        for(int i = 0; i<v.size(); i++)
            mx = max(mx, (right[i]-left[i]-1)*v[i]);

        return mx;
    }

    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        
        if(n == 0)
            return 0;
        
        int m = matrix[0].size();
        vector<int>v;
        
        for(int j = 0; j < m; j++)
            v.push_back(matrix[0][j] - '0');
        
        int mx = MAH(v);
    
         for(int i = 1; i < n; i++)
         {
             for(int j = 0; j < m; j++)
             {
                 if(matrix[i][j] == '0')
                    v[j] = 0;

                else
                    v[j] += 1;
             }
             
             mx = max(mx, MAH(v));
         }
        
        return mx;
    }
};