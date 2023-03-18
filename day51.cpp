// You have a browser of one tab where you start on the homepage and you can visit another url, 
// get back in the history number of steps or move forward in the history number of steps.

// Implement the BrowserHistory class:

// BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
// void visit(string url) Visits url from the current page. It clears up all the forward history.
// string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. 
// Return the current url after moving back in history at most steps.
// string forward(int steps) Move steps forward in history. 
// If you can only forward x steps in the history and steps > x, you will forward only x steps. 
// Return the current url after forwarding in history at most steps.


class BrowserHistory {
public:
    stack<string> upcoming; // store the forward urls
    stack<string> prev; // store the history
    string curr; // the current url 
    BrowserHistory(string homepage) {
        curr=homepage;
    }
    
    void visit(string url) {
        prev.push(curr);
        curr=url;  // current url is updated to the newly visited url
        upcoming=stack<string>();  // delete the forward history
    }
    
    string back(int steps) {
        while(steps-- and !prev.empty()){
            upcoming.push(curr);
            curr=prev.top();
            prev.pop();
        }
        return curr;
    }
    
    string forward(int steps) {
    while(steps-- and !upcoming.empty()){
            prev.push(curr);
            curr=upcoming.top();
            upcoming.pop();
        }
        return curr;
    }
};


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */