/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
More formally,
    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.
*/
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int>gte(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty()  && st.top()>=A[i]){
            st.pop();
        }
        if(!st.empty()) gte[i]=st.top();
        st.push(A[i]);
    }
    return gte;
}
