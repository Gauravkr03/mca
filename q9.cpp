#include <iostream>
#include <cctype>
#include <cstring>

#define MAX 100

using namespace std;

char stack[MAX];
int top = -1;

void push(char item) {
    if (top < MAX - 1) {
        stack[++top] = item;
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top != -1) {
        return stack[top];
    }
    return '\0';
}

bool isEmpty() {
    return top == -1;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}

void infixToPostfix(const char *infix, char *postfix) {
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
        } else if (isOperator(c)) {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int evaluatePostfix(const char *postfix) {
    int valueStack[MAX];
    int valueTop = -1;

    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            int value;
            cout << "Enter value for " << c << ": ";
            cin >> value;
            valueStack[++valueTop] = value;
        } else if (isOperator(c)) {
            int b = valueStack[valueTop--];
            int a = valueStack[valueTop--];
            int result;
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            valueStack[++valueTop] = result;
        }
    }
    return valueStack[valueTop];
}

int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter an infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result of the expression: " << result << endl;

    return 0;
}
