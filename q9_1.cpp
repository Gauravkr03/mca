#include<bits/stdc++.h>


#define MAX 100
#define VAR_COUNT 26 

using namespace std;

char stac[MAX];
int top = -1;
int values[VAR_COUNT]; 
bool valueAssigned[VAR_COUNT] = {false}; 

void push(char item) {
    if (top < MAX - 1) {
        stac[++top] = item;
    }
}

char pop() {
    if (top != -1) {
        return stac[top--];
    }
    return '\0';
}

char peek() {
    if (top != -1) {
        return stac[top];
    }
    return '\0';
}

bool isEmpty() {
    return top == -1;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; 
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
        if (isdigit(c)) {
            valueStack[++valueTop] = c - '0'; 
        }
         else if (isupper(c)) {
            valueStack[++valueTop] = values[c - 'A'];
         }
         else if (isOperator(c)) {
            int b = valueStack[valueTop--];
            int a = valueStack[valueTop--];
            int result;
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = (int)pow(a, b); break; 
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

    
    for (int i = 0; infix[i]; i++) {
        if (islower(infix[i]) && !valueAssigned[infix[i] - 'A']) {
            int value;
            cout << "Enter value for " << infix[i] << ": ";
            cin >> value;
            values[infix[i] - 'A'] = value;
            valueAssigned[infix[i] - 'A'] = true; 
        } else if (isupper(infix[i]) && !valueAssigned[infix[i] - 'A']) {
            int value;
            cout << "Enter value for " << infix[i] << ": ";
            cin >> value;
            values[infix[i] - 'A'] = value;
            valueAssigned[infix[i] - 'A'] = true; 
        }
    }

    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result of the expression: " << result << endl;

    return 0;
}

