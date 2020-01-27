/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 *  1- Open brackets must be closed by the same type of brackets.
 *  2- Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> p;

        for(char& c : s) {
            switch(c) {
                case '(':
                case '{':
                case '[': p.push(c); break;
                case ')': if(p.empty() || p.top() != '(') return false; else p.pop(); break; 
                case '}': if(p.empty() || p.top() != '{') return false; else p.pop(); break;
                case ']': if(p.empty() || p.top() != '[') return false; else p.pop(); break; 
                default: ;    
            }
        }

        return p.empty();
    }
};