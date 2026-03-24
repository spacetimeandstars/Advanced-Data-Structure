#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

// Factorial (Recursion)
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Postfix Evaluation
int evaluatePostfix(string exp) {
    stack<int> s;
    for (char ch : exp) {
        if (isdigit(ch))
            s.push(ch - '0');
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.top();
}

int main() {
    int choice, val, n;
    string exp;

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n2. Pop\n3. Display\n";
        cout << "4. Show Recursion (Factorial)\n";
        cout << "5. Polish Notation\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                st.push(val);
                break;

            case 2:
                if (st.empty())
                    cout << "Stack Underflow\n";
                else {
                    cout << "Popped: " << st.top() << endl;
                    st.pop();
                }
                break;

            case 3:
                if (st.empty()) {
                    cout << "Stack is empty\n";
                } else {
                    stack<int> temp = st;
                    cout << "Stack: ";
                    while (!temp.empty()) {
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;

            case 4:
                cout << "Enter number: ";
                cin >> n;
                cout << "Factorial = " << factorial(n) << endl;
                break;

            case 5:
                cout << "Enter postfix expression: ";
                cin >> exp;
                cout << "Result = " << evaluatePostfix(exp) << endl;
                break;
        }

    } while (choice != 6);

    return 0;
}
