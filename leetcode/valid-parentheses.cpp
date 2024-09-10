class Solution {
public:
    bool isValid(string s) {

        stack<char> stack;
        for (char c : s) {
            switch (c) {
                case '{': stack.push('}'); break;
                case '[': stack.push(']'); break;
                case '(': stack.push(')'); break;
                default:
                    if (stack.empty() || c != stack.top()) return false;
                    stack.pop();
            }
        }

        return stack.empty();
    }
};