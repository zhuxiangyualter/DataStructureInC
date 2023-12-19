/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-09.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
/**
 * 中值表达式转后缀表达式
 * @param infix_expression
 * @return
 */
string infixToPostfix(string infix_expression) {
    stack<char> stk;
    string postfix_expression = "";
    for (char c : infix_expression) {
        if (isdigit(c)) {
            postfix_expression += c;
        } else if (c == '(') {
            stk.push(c);
        } else if (c == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postfix_expression += stk.top();
                stk.pop();
            }
            stk.pop();
        } else {
            while (!stk.empty() && stk.top() != '(' && c <= stk.top()) {
                postfix_expression += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }
    while (!stk.empty()) {
        postfix_expression += stk.top();
        stk.pop();
    }
    return postfix_expression;
}
/**
 * 后缀表达式求值
 * @param postfix_expression
 * @return
 */
string evaluatePostfix(string postfix_expression) {
    stack<int> stk;
    for (char c : postfix_expression) {
        if (isdigit(c)) {
            stk.push(c - '0');
        } else {
            int num2 = stk.top(); stk.pop();
            int num1 = stk.top(); stk.pop();
            switch (c) {
                case '+': stk.push(num1 + num2); break;
                case '-': stk.push(num1 - num2); break;
                case '*': stk.push(num1 * num2); break;
                case '/': stk.push(num1 / num2); break;
            }
        }
    }
    return to_string(stk.top());
}
int main() {
    //中值表达式求值问题
    string postfix_expression;//后缀表达式
    cin >> postfix_expression;

    stack<int> stk;
    //遍历后缀表达式
    for (char c : postfix_expression) {
        if (isdigit(c)) {//如果是数字
            stk.push(c - '0');//将数字字符转换为数字
        } else {
            int num2 = stk.top(); stk.pop();
            int num1 = stk.top(); stk.pop();//注意顺序
            switch (c) {
                case '+': stk.push(num1 + num2); break;
                case '-': stk.push(num1 - num2); break;
                case '*': stk.push(num1 * num2); break;
                case '/': stk.push(num1 / num2); break;
            }
        }
    }

    cout << "输出结果为：" << stk.top() << endl;
    return 0;
}
