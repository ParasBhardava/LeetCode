class Solution {
public:
    string customSortString(string order, string str) {
        
        string ans = "";
        int arr[26];
        
        for(int i=0; i<26; i++)
            arr[i] = 25;
            
        int n = order.length();
        int m = str.length();
        
        for(int i=0; i<n; i++)
            arr[order[i] - 'a'] = i;
        
        for(int i=0; i<m-1; i++)
        {
            for(int j=i+1; j<m; j++)
            {
                if(arr[str[j]-'a'] < arr[str[i]-'a'])
                {
                    char temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;  
                }
            }
        }
        
        ans += str;
        return ans;
    }
};