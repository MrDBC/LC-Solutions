class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        string ans;
        int n= s.size();
        for( int i=0; i<n; i++){
            
            string temp;
            if( s[i]=='/')
                continue;
            while(i<n && s[i]!='/'){
                temp+= s[i];
                i++;
            }
            if( temp==".")
                continue;
            else if( temp==".."){
                if( !st.empty())
                    st.pop();
            }
            else{
                st.push(temp);
            }
        }
        
        if( st.empty())
            ans = '/';
        while( !st.empty()){
            ans = '/'+ st.top() + ans;
            st.pop();
        }
        
        
        return ans;
    }
};

// home
// foo

// /../a//b

// a b