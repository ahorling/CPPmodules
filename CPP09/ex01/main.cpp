#include <stack>
#include <iostream>

enum Scuffed{error = -1, divide = 10, multiply = 11, subtract = 12, add = 13, space = 14};

int	determine_action(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c == '/')
		return (divide);
	else if (c == '*')
		return (multiply);
	else if (c == '-')
		return (subtract);
	else if (c == '+')
		return (add);
	else if (c == ' ')
		return (space);
	return (error);
}

void	multiply_stack(std::stack<int>* myStack)
{
	int valueRight = myStack->top();
	myStack->pop();
	int valueLeft = myStack->top();
	myStack->pop();
	int valueRet = valueLeft * valueRight;
	myStack->push(valueRet);
}

void	divide_stack(std::stack<int>* myStack)
{
	int valueRight = myStack->top();
	myStack->pop();
	int valueLeft = myStack->top();
	myStack->pop();
	int valueRet = valueLeft / valueRight;
	myStack->push(valueRet);
}
void	subtract_stack(std::stack<int>* myStack)
{
	int valueRight = myStack->top();
	myStack->pop();
	int valueLeft = myStack->top();
	myStack->pop();
	int valueRet = valueLeft - valueRight;
	myStack->push(valueRet);
}
void	add_stack(std::stack<int>* myStack)
{
	int valueRight = myStack->top();
	myStack->pop();
	int valueLeft = myStack->top();
	myStack->pop();
	int valueRet = valueLeft + valueRight;
	myStack->push(valueRet);
}

void	action_jump(std::stack<int>* myStack, int scuffed_action)
{
	if (scuffed_action == multiply)
		multiply_stack(myStack);
	else if (scuffed_action == divide)
		divide_stack(myStack);
	else if (scuffed_action == subtract)
		subtract_stack(myStack);
	else if (scuffed_action == add)
		add_stack(myStack);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Incorrect amount of arguements" << std::endl;
		return (1);
	}
	std::stack<int> myStack;
	int scuffed_action = 0;
	for (int i = 0; argv[1][i]; i++)
	{
		scuffed_action = determine_action(argv[1][i]);
		if (scuffed_action == space)
			continue;
		else if (scuffed_action == error)
		{
			std::cout << "Error in Parsing the string at char[" << i << "] it was [" << argv[1][i] << "]" << std::endl;
			return (1);
		}
		if (scuffed_action >= 0 && scuffed_action <= 9)
			myStack.push(scuffed_action);
		else
		{
			if (myStack.size() < 2)
			{
				std::cout << "Not enough arguements in the stack in order to perform action " << argv[1][i] << std::endl;
				return (1);
			}
			action_jump(&myStack, scuffed_action);
		}
	}
	std::cout << myStack.top() << std::endl;
}