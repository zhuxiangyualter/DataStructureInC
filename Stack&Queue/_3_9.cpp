#include <stack>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
int calculate(std::string s) {
    std::stack<int> stk;
    int num = 0;
    char sign = '+';
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        if (!isdigit(s[i]) && !iswspace(s[i]) || i == s.size() - 1) {
            if (sign == '-') {
                stk.push(-num);
            } else if (sign == '+') {
                stk.push(num);
            } else if (sign == '*') {
                stk.top() *= num;
            } else if (sign == '/') {
                stk.top() /= num;
            }
            sign = s[i];
            num = 0;
        }
    }
    int res = 0;
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    return res;
}
int main() {
    string s;
    cin>>s;
    cout<<calculate(s);
    return 0;
}
