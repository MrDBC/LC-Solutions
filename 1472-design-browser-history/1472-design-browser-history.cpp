class BrowserHistory {
    stack<string> main, temp;
public:
    BrowserHistory(string homepage) {
        main.push(homepage);
    }
    
    void visit(string url) {
        while( !temp.empty())
            temp.pop();
        
        main.push(url);
    }
    
    string back(int steps) {
        
        while( main.size() >1 and steps-->0){
            
            temp.push(main.top());
            main.pop();
        }
        return main.top();
    }
    
    string forward(int steps) {
        
        while( !temp.empty() and steps-->0){
            main.push(temp.top());
            temp.pop();
        }
        
        return main.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */