// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert prefix expression to postfix
string prefixToPostfix(string prefix) {
    stack<string> s;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix) {
        if (isOperator(c)) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = op1 + op2 + c;
            s.push(temp);
        } else {
            s.push(string(1, c));
        }
    }

    return s.top();
}
