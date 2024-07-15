#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return -1;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    for (char& c : infix) {
        // If the character is an operand, add it to the postfix string
        if (isalpha(c) || isdigit(c)) {
            postfix += c;
        }
        // If the character is an open parenthesis, push it to the stack
        else if (c == '(') {
            s.push(c);
        }
        // If the character is a close parenthesis, pop and add to postfix until an open parenthesis is found
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        // If the character is an operator
        else {
            while (!s.empty() && getPrecedence(c) <= getPrecedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all the remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix = "A+B*(C-D)";
    cout << "Infix: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
