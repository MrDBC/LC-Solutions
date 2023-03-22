// class Solution {
//     vector<string> res;
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> us;
//         for(auto str:wordDict)
//             us.insert(str);
        
//         string word="", sentence="";
//         dfs( s, 0, word, sentence, us);
//         return res;
//     }
    
//     void dfs( string& s, int idx, string& word, string& sentence, unordered_set<string>& us ){
//         if( idx>s.size())
//             return ;
//         if( idx== s.size()){
//             res.push_back(sentence);
//             return;
//         }
        
//         // idx =3
//         // cat sanddog
//         // 012 3456789
//         if( us.find(word) != us.end()){ //cat
//             // sentence+= word+" ";
//             string tempword="";
//             string tempsentence= sentence+word+" ";
//             dfs(s, idx, tempword, tempsentence,us); // sentence ="cat and " rem="dog"
            
            
//             dfs(s,idx, word, sentence, us ); 
//         }
//         else{
//             word+= s[idx]; // and
//             dfs(s, idx+1, word, sentence, us);
//         }
//     }
// };

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //insert all the words in the set
        unordered_set<string> set;
        vector<string> res;
        for(auto word:wordDict)
            set.insert(word);
        //to store the current string 
        string curr="";
        findHelper(0,s,curr,set,res);
        return res;
    }
    
    void findHelper(int ind,string s,string curr,unordered_set<string> set,vector<string>& res)
    {
        if(ind==s.length())
        {
            //we have reached end
            curr.pop_back(); //remove the trailing space
            res.push_back(curr);
        }
        string str="";
        for(int i=ind;i<s.length();i++)
        {
            //get every substring and check if it exists in set
            str.push_back(s[i]);
            if(set.count(str))
            {
                //we have got a word in dict 
                //explore more and get other substrings
                findHelper(i+1,s,curr+str+" ",set,res);
            }
        }
    }
};