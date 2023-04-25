// You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

// Implement the SmallestInfiniteSet class:

// SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
// int popSmallest() Removes and returns the smallest integer contained in the infinite set.
// void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.





class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        for(int i =1;i<=1000;i++) st.insert(i);
    }
    
    int popSmallest() {
        int a = *st.begin();
        st.erase(a);
        return a;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};