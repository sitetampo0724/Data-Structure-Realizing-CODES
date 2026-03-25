#pragma once
#include <string>
#include <stack>
#include <list>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class calc {
	char* expression;
	enum token {OPAREN,ADD,SUB,MULTI,DIV,EXP,CPAREN,VALUE,EOL};
	void BinaryOp(enum token type, stack<int, list<int>>& s);
	token GetOp(int &value);
public:
	calc(char* c)
	{
		expression = new char[strlen(c) + 1];
		strcpy_s(expression, strlen(c) + 1, c);
	}
	~calc() {
      delete expression;
	}
	int result();
};
int calc::result() {
	int value;
	stack<int, list<int>> num;
	stack<token, list<token>> op;
	token temp;
    char* cur = expression; 
	while ((temp = GetOp(value)) != EOL)
	{
		switch (temp) {
		case VALUE:num.push(value);break;
		case OPAREN:op.push(temp);break;
		case CPAREN: {
			while (op.top() != OPAREN) {
				BinaryOp(op.top(), num);
				op.pop();
			}
			if (op.top() != OPAREN)cerr << "lack a Open Parenthesis" << endl;
			op.pop();
			break;
		}
		case EXP:op.push(temp);break;
		case MULTI:case DIV: {
			while (!op.empty() && (op.top() == MULTI || op.top() == DIV || op.top() == EXP))
			{
				BinaryOp(op.top(), num);
				op.pop();
			}
			op.push(temp);
			break;
		}
		case ADD:case SUB: {
			while (!op.empty() && (op.top() == MULTI || op.top() == DIV || op.top() == EXP || op.top() == SUB
				|| op.top() == ADD ))
			{
				BinaryOp(op.top(), num);
				op.pop();
			}
			op.push(temp);
			break;
		}
		}
	}
	while (!op.empty())
	{
		BinaryOp(op.top(), num);
		op.pop();
	}
	if (num.empty())
	{
		cout << "No result!" <<endl;
		return 0;
	}
	int result_value = num.top();
	if (!num.top())
	{
		cout << "Lack operation!" << endl;
	}
	expression = cur;
	return result_value;
}
void calc::BinaryOp(enum token type, stack<int, list<int>>& s)
{
	int top, top2, result;
	if (s.empty())
	{
		cout << "lack right number!" << endl;
		exit(1);
	}
	top = s.top();
	s.pop();
	if (s.empty())
	{
		cout << "lack left number!" << endl;
		exit(1);
	}
	top2 = s.top();
	s.pop();
    switch (type) {
	case ADD: {
		result = top2 + top;
		s.push(result);
		break;
	}
	case SUB: {
		result = top2 - top;
		s.push(result);
		break;
	}
	case MULTI: {
		result = top2 * top;
		s.push(result);
		break;
	}
	case DIV: {
		if (top == 0) {
			cerr << "Division by zero!" << endl;
			exit(1);
		}
		result = top2 / top;
		s.push(result);
		break;
	}
	case EXP: {
		result = (int)pow(top2, top);
		s.push(result);
		break;
	}
	default: {
		cerr << "Unknown operator in BinaryOp" << endl;
		exit(1);
	}
	}
		
}
calc::token calc::GetOp(int& value)
{
	while (*expression && *expression == ' ')
	{
		expression++;
	}
	if (*expression == 0)
		return EOL;
	if (*expression >= '0' && *expression <= '9')
	{
		value = 0;
		while (*expression >= '0' && *expression <= '9')
		{
			value = value * 10 + *expression - '0';
			expression++;
		}
		return VALUE;
	}
    switch (*expression)
	{
	case '(': expression++; return OPAREN;
	case ')': expression++; return CPAREN;
	case '+': expression++; return ADD;
	case '-': expression++; return SUB;
	case '/': expression++; return DIV;
	case '*': expression++; return MULTI;
	case '^': expression++; return EXP;
	default:
		cerr << "Invalid character: " << *expression << endl;
		expression++;
		return EOL;
	}
}