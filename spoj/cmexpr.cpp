#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

pair<string,int> GetCombinedOperand(pair<string,int>& left_operand, char oprtr, pair<string,int>& right_operand){
  string left_expression, right_expression;
  int left_expression_operators, right_expression_operators;

  tie(left_expression, left_expression_operators) = left_operand;
  tie(right_expression, right_expression_operators) = right_operand;

  if(oprtr == '+'){
    return {left_expression + "+" + right_expression, left_expression_operators | right_expression_operators | (1 << 0)};
  }

  if(oprtr == '-'){
    if((right_expression_operators & (1 << 0)) == 0 && (right_expression_operators & (1 << 1)) == 0){
      return {left_expression + "-" + right_expression, left_expression_operators | right_expression_operators | (1 << 1)};
    }
    return {left_expression + "-(" + right_expression + ")", left_expression_operators | (1 << 1)};
  }

  string expression = "";
  int expression_operators = 0;

  if((left_expression_operators & (1 << 0)) != 0 || (left_expression_operators & (1 << 1)) != 0){
    expression += "(" + left_expression + ")";
  }
  else{
    expression += left_expression, expression_operators |= left_expression_operators;
  }

  if(oprtr == '*'){
    expression += "*", expression_operators |= (1 << 2);

    if((right_expression_operators & (1 << 0)) != 0 || (right_expression_operators & (1 << 1)) != 0){
      expression += "(" + right_expression + ")";
    }
    else{
      expression += right_expression, expression_operators |= right_expression_operators;
    }
  }
  else{
    expression += "/", expression_operators |= (1 << 3);

    if(right_expression_operators != 0){
      expression += "(" + right_expression + ")";
    }
    else{
      expression += right_expression;
    }
  }

  return {expression, expression_operators};
}

void CombineExpressions(stack<pair<string,int>>& operands, stack<char>& operators){
  pair<string,int> right_operand = operands.top();
  operands.pop();

  pair<string,int> left_operand = operands.top();
  operands.pop();

  operands.push(GetCombinedOperand(left_operand, operators.top(), right_operand));
  // printf("CombineExpressions(%s,%c,%s) = %s\n", left_operand.first.c_str(), operators.top(), right_operand.first.c_str(), operands.top().first.c_str());
  operators.pop();

}

int GetPriority(char c){
  if(c == '('){
    return -1;
  }

  if(c == ')'){
    return 0;
  }

  if(c == '+' || c == '-'){
    return 1;
  }

  return 2;
}

string Solve(){
  string s;
  cin >> s;

  stack<pair<string,int>> operands;
  stack<char> operators;

  s = "(" + s + ")";
  for(char c: s){
    if(c == '('){
      operators.push('(');
      continue;
    }

    if(isalpha(c)){
      operands.push({string(1, c), 0});
      continue;
    }

    while(!operators.empty() && GetPriority(operators.top()) >= GetPriority(c)){
      CombineExpressions(operands, operators);
    }

    if(c != ')'){
      operators.push(c);
      continue;
    }

    operators.pop();
  }

  return operands.top().first;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}