#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>

#define MAX 100
#define VAR_COUNT 26 // Supports variables 'a' to 'z'

using namespace std;

char stack[MAX];
int top = -1;
int values[VAR_COUNT]; // Array to store values for variables
bool valueAssigned[VAR_COUNT] = {false}; // Track if a value has been assigned
char postfix[MAX]; // Store the last computed postfix expression

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
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // Highest precedence for exponentiation
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
            pop();  // Remove the '(' from the stack
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
        } else if (islower(c)) {
            valueStack[++valueTop] = values[c - 'a']; 
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
    char infix[MAX];
    int choice;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Convert infix to postfix\n";
        cout << "2. Evaluate postfix expression\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter an infix expression: ";
                cin >> infix;

                // Get unique variable values
                for (int i = 0; infix[i]; i++) {
                    if (islower(infix[i]) && !valueAssigned[infix[i] - 'a']) {
                        int value;
                        cout << "Enter value for " << infix[i] << ": ";
                        cin >> value;
                        values[infix[i] - 'a'] = value;
                        valueAssigned[infix[i] - 'a'] = true; // Mark the variable as assigned
                    }
                }

                infixToPostfix(infix, postfix);
                cout << "Postfix expression: " << postfix << endl;
                break;
            }
            case 2: {
                int evalChoice;
                cout << "Choose postfix evaluation option:\n";
                cout << "1. Use previous postfix expression\n";
                cout << "2. Enter a new postfix expression\n";
                cin >> evalChoice;

                if (evalChoice == 1) {
                    cout << "Using previous postfix expression: " << postfix << endl;
                    int result = evaluatePostfix(postfix);
                    cout << "Result of the previous postfix expression: " << result << endl;
                } else if (evalChoice == 2) {
                    cout << "Enter a new postfix expression: ";
                    cin >> postfix; // Store the new postfix expression
                    int result = evaluatePostfix(postfix);
                    cout << "Result of the new postfix expression: " << result << endl;
                }
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}