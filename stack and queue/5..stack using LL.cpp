void MyStack ::push(int x) 
{
    // Your Code
    if(top==nullptr){
        StackNode* dummy= new StackNode(x);
        top=dummy;
    }
    else{
        StackNode* ele= new StackNode(x);
        ele->next=top;
        top=ele;
    }
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top==nullptr) return -1;
    int ans=top->data;
    top=top->next;
    return ans;
}
