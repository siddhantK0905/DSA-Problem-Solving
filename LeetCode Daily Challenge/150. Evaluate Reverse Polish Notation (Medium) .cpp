class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
         int ans = 0;
        for(auto ch: tokens){
            
            if(ch.size() > 1 || isdigit(ch[0])){
                
                st.push(stoi(ch));   //stoi convert string into digit
            }

            else{
                 int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if(ch[0] == '+'){
                   ans = num1 + num2; 
                }
                if(ch[0] == '-'){
                   ans = num1 - num2; 
                }
                if(ch[0] == '*'){
                   ans = num1 * num2; 
                }
                if(ch[0] == '/'){
                    if(num2 != 0)
                   ans = num1 / num2; 
                }

                st.push(ans);

                
            }
        }

        return st.top();
    }
};
