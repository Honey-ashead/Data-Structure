#pragma once
#include <iostream>
#include <stack>
using namespace std;

class Calculator {
public:
	Calculator() = default;
	double Run(const char e[]);
	void Clear();

private:
	stack<double> s;
	void AddOperand(double value);
	bool Get2Operators(double& left, double& right);
	void DoOperator(char op);
};