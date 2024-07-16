// Function to convert postfix expression to infix
string postfixToInfix(string postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (isOperator(c)) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = "(" + op2 + c + op1 + ")";
            s.push(temp);
        } else {
            s.push(string(1, c));
        }
    }

    return s.top();
}
