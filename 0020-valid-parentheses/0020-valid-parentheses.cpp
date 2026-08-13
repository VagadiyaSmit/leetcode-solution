class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

      for(char ch : s)
      {
        if(!stack.empty())
        {
            char last = stack.top();
            if(isPair (last,ch))
            {
                stack.pop();
                continue;
            }
        }
        stack.push(ch);
      }  
      return stack.empty();
    }

private:
    bool isPair(char last,char ch){
        return (last == '(' && ch ==')') || (last == '{' && ch == '}') || (last == '[' && ch == ']');
    }
};