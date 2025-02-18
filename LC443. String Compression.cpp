class Solution {
    public:
        int compress(vector<char>& chars) {
            int j=0,n=chars.size();
            for(int i=0;i<n;){
                int cnt=0;
                char curr=chars[i];
                while(i<n && chars[i]==curr){
                    i++;
                    cnt++;
                }
                chars[j++]=curr;
                if(cnt>1){
                    string str=to_string(cnt);
                    for(char ch:str){
                        chars[j++]=ch;
                    }
                }
            }
            return j;
        }
    };