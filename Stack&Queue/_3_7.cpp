/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-12-09.
*/
#include <iostream>
#include <stack>

using namespace std;
/**
 * 判断括号是否匹配
 * @param left
 * @param right
 * @return
 * 这段代码首先定义了一个辅助函数isMatch来检查两个括号是否匹配，
 * 然后在checkBrackets函数中使用一个栈来存储遇到的左括号，当遇到右括号时，检查栈顶的左括号是否与之匹配，如果匹配则弹出栈顶元素，
 * 如果不匹配或者栈为空则返回不匹配。
 * 最后，如果栈为空则说明所有的括号都匹配，否则说明有未匹配的括号
 */
bool isMatch(char left, char right) {
    if (left == '(' && right == ')') return true;
    if (left == '[' && right == ']') return true;
    if (left == '{' && right == '}') return true;
    return false;
}

bool checkBrackets(string expression) {
    stack<char> stk;
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty() || !isMatch(stk.top(), c)) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();

}

int main() {
    string expression;
    cout << "请输入一个中缀表达式：" << endl;
    cin >> expression;
    if (checkBrackets(expression)) {
        cout << "括号匹配成功！" << endl;
    } else {
        cout << "括号匹配失败！" << endl;
    }
    return 0;{}
}
