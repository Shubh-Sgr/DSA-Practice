class Solution {
public:
    bool isOperator(char c){
        if (c=='+' || c=='-' || c=='*' || c=='/'){
            return true;
        }
        return false;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int len = expression.size();
        if (len == 0){
            return ans;
        }
        if (len == 1){
            ans.push_back((expression[0] - '0'));
            return ans;
        }
        if (len == 2){
            ans.push_back(stoi(expression.substr(0,2)));
            return ans;
        }
        for (int i=0; i<len; i++){
            if (isOperator(expression[i])){
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                 vector<int> right = diffWaysToCompute(expression.substr(i+1));
                 for (int j=0; j<left.size(); j++){
                    for (int k=0; k<right.size(); k++){
                        if (expression[i] == '+'){
                            ans.push_back((left[j])+(right[k]));
                        }
                        else if (expression[i] == '-'){
                           ans.push_back((left[j])-(right[k]));
                        }
                        else if (expression[i] == '*'){
                            ans.push_back((left[j])*(right[k]));
                        }
                        else if (expression[i] == '/'){
                            ans.push_back((left[j])/(right[k]));
                        }
                    }
                 }
            }
        }
        return ans;
    }
};
