#include <bits/stdc++.h>

using namespace std;

class RpnEval
{

public:
	static int evaluate(const string& input)
	{
		stack<int> eval;

		for(auto i: input)
		{	
			const char* ptr = &i;
			if(i == '+' or i == '-' or	i == '*' or i == '/')
			{
				int a = eval.top(); eval.pop();
				int b = eval.top(); eval.pop();

				switch(i)
				{
					case '+':
						eval.emplace(a+b);break;

					case '-':
						eval.emplace(a-b);break;

					case '/':
						eval.emplace(a/b);break;

					case '*':
						eval.emplace(a*b);break;
				}
			}
			else if(i == ',')
				continue;
			else {
				eval.emplace(stoi(ptr));

			}
		}

		return eval.top();
	}
};


int main(int argc, char* argv[])
{
	string in = "3,4,+,2,*,1,+";
	cout<< RpnEval::evaluate(in) << endl;
	return 0;
}