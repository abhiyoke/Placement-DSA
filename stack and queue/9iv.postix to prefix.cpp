/ Function to convert postfix expression to prefix
string postfixToPrefix(string postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (isOperator(c)) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = c + op2 + op1;
            s.push(temp);
        } else {
            s.push(string(1, c));
        }
    }

    return s.top();
}
