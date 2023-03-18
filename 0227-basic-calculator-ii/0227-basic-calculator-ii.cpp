class Solution {
public:
     int calculate(string s) {
        stack<int> stk;
        int a;
        istringstream iss(s);
        char op = '+';
         
         // read numbers here( becoz a is int(number type) , so stream only reads no.)
        while (iss >> a){
            if (op == '+' || op == '-'){
                stk.push(op == '+' ? a : -a);
            } 
            else{
                int last = stk.top();
                stk.pop();
                if (op == '*') 
                    last *= a;
                else if(op == '/')
                    last /= a;
                stk.push(last);
            }
            
            // read only the operators(string type)
            iss >> op;
        }
        int sum = 0;
        while(!stk.empty()){
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};