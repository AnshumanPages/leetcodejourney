class Solution {
public:
    string largestOddNumber(string num) {
        int  newodd=-1;
        for(int i=0;i<num.size(); i++){
            if((num[i] -'0')%2!=0){
               newodd=i;
            }
       
        }
         if(newodd==-1){
                return "";
            }
         return num.substr(0,newodd+1);
        
    }
};