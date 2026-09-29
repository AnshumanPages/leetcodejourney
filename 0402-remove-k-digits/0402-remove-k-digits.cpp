class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && 
            ((st.top()-'0') > (num[i]-'0'))){
                st.pop();
                k--;
            }
            st.push(num[i]);

        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty())return "0";

        string resultant = "";

        while(!st.empty()) {
            resultant += st.top();
            st.pop();
        }

       
        reverse(resultant.begin(), resultant.end());

        
        int i = 0;

        while(i < resultant.size() && resultant[i] == '0') {
            i++;
        }

        resultant = resultant.substr(i);

        if(resultant.empty())
            return "0";

        return resultant;
    }
};