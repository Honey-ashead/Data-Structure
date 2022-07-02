#include "Calculator.h"

// 根据操作符计算表达式的值
void Calculator::DoOperator(char op) {
	double left, right, value;
	bool result;
	result = Get2Operators(left, right);
	if (result) {
		switch (op) {
			case '+':
				value = left + right;
				s.push(value);
				break;
			case '-':
				value = left - right;
				s.push(value);
				break;
			case '*':
				value = left * right;
				s.push(value);
				break;
			case '/':
				if (right == 0) {
					cerr << "Division by zero!" << endl;
					Clear();
				} else {
					value = left / right;
					s.push(value);
					break;
				}
			default:
				cerr << "Unknown operator: " << op << "!" << endl;
				break;
		}
	} else {
		Clear();
	}
}

// 从栈顶取出两个操作数
bool Calculator::Get2Operators(double& left, double& right) {
	if (s.empty()) {
		cerr << "Lack of right operand!" << endl;
		return false;
	}
	right = s.top();
	s.pop();
	if (s.empty()) {
		cerr << "Lack of left operand!" << endl;
		return false;
	}
	left = s.top();
	s.pop();
	return true;
}

// 将操作数的值入栈
void Calculator::AddOperand(double value) {
	s.push(value);
}

// 读取字符串并求一个后缀表达式的值，以字符‘#’结束
double Calculator::Run(const char e[]) {
	char ch;
	double newOperand, result = 0;
	int i = 0;
	ch = e[i++];

	while (ch != '#') {
		switch (ch) {
			case '+':
			case '-':
			case '*':
			case '/':
                DoOperator(ch);
				break;
			default:
				newOperand = double(ch - '0');
				AddOperand(newOperand);
		}
		ch = e[i++];
	}
    result = s.top();
	return result;
}

void Calculator::Clear() {
	while (!s.empty()) {
		s.pop();
	}
}