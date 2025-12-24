#include "../include/Stack.hpp"

int	isOperand(char c)
{
	std::string symbols = "+-*/()^";
	size_t s = symbols.find(c);
	if (s != std::string::npos)
		return 0;
	//if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^')
	//	return (0);
	return (1);
}

int	prec(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else if (c == '*' || c == '/')
		return (2);
	return (0);
}
char	*convert(const char *infix)
{
	Stack<char> st;

	int i=0, j = 0;
	//char *postfix = new char[strlen(infix) + 1];
	char *postfix = new char[strlen(infix) + 1];
	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (st.isEmpty() || prec(infix[i]) > prec(st.stackTop()))
			{
				st.push(infix[i]);
				i++;
			}
			else
			{
				//while (!st.isEmpty() && prec(infix[i]) <= prec(st.stackTop()))
				//{
				//	try
				//	{
						postfix[j++] = st.pop() ;
				//	}
				//	catch(const std::exception& e)
				//	{
				//		std::cerr << e.what() << '\n';
				//	}
					
				//}
				//st.push(infix[i]);
				//i++;
			}
		}
	}
	while (!st.isEmpty())
	{
		try
		{
			/* code */
			postfix[j++] = st.pop();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	postfix[j] = '\0';
	return (postfix);
}


struct symbols
{
	char symbole;
	int in_stack_pre;
	int	out_stack_pre;
};

int	prec_out_stack(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else if (c == '*' || c == '/')
		return (3);
	else if (c == '^')
		return (6);
	else if (c == '(')
		return (7);
	else if (c == ')')
		return (0);
	return 0;
}

int	prec_in_stack(char c)
{
	if (c == '+' || c == '-')
		return (2);
	else if (c == '*' || c == '/')
		return (4);
	else if (c == '^')
		return (5);
	else if (c == '(')
		return (0);
	return (-1);
}

char *InToPostfix_bracket(const char *infix)
{
	char *postfix = new char[strlen(infix) + 1];
	Stack<char> st;
	int i =0;
	int j = 0;
	while (infix[i]!= '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (st.isEmpty() || prec_out_stack(infix[i]) > prec_in_stack(st.stackTop()))
			{
				st.push(infix[i]);
				i++;
			}
			else if (!st.isEmpty() && prec_out_stack(infix[i]) == prec_in_stack(st.stackTop()))
			{
				char c = st.pop();
				(void)c;
				i++;
			}
			else{
				postfix[j++] = st.pop();
			}
		}
	}
	while (!st.isEmpty())
	{
		try
		{
			postfix[j++] = st.pop();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	postfix[j] = '\0';
	return (postfix);
}

int eval(const char *postfix)
{
	Stack<int> st;
	int x1;
	int x2;
	int i = 0;
	while (postfix[i] != '\0')
	{
		if (isOperand(postfix[i]))
		{
			std::cout << "pushed: " << postfix[i] - '0' << std::endl;
			st.push(postfix[i] - '0');
		}
		else
		{
			x2 = st.pop();
			x1 = st.pop();
			switch (postfix[i])
			{
			case '+':
			{
				std::cout << x1 << ", " << x2 << std::endl;
				st.push(x1 + x2);
				break;
			}
			case '-':
			{
				st.push(x1 - x2);
				break;
			}
			case '*':
			{
				std::cout << x1 << ", " << x2 << std::endl;
				st.push(x1 * x2);
				break;
			}
			case '/':
			{
				st.push(x1 / x2);
				break;
			}
			default:
				break;
			}
		}
		i++;
	}
	return st.pop();
}