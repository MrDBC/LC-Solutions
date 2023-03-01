class Solution {
public:
    string sortSentence(string s) {
        istringstream in(s);
        
        string str,res="";
        int total =0;
        vector<string> ans(10);
        while( in>>str){
            cout<<str<<endl;
            int n= str.size();
            ans[str[n-1]-'0'] = str.substr(0, n-1);
            cout<<ans[str[n-1]-'0']<<endl;
            ++total;
        }
        
        for(int i=1; i<=total; i++)  
            res+=ans[i]+" ";
        
        
        res.pop_back();
        return res;
    }
};