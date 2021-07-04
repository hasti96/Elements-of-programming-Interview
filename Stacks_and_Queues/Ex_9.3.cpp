#include <bits/stdc++.h>

using namespace std;

class wellFormedness
{
public:
	static bool check(string& input)
	{
		bool retVal = true;

		stack<char> leftChar;

		for(int i= 0; i < input.size(); i++)
		{
			switch(input.at(i))
			{
				case '{':
				case '(':
				case '[':
					leftChar.emplace(input.at(i));					
				break;

				case '}':
					if(leftChar.top() == '{')
						leftChar.pop();
					else
						retVal = false;
					break;
				
				case ')':
					if(leftChar.top() == '(')
						leftChar.pop();
					else
						retVal = false;

					break;
				
				case ']':
					if(leftChar.top() == '[')
						leftChar.pop();
					else
						retVal = false;

					break;

				default:
					printf("Incorrect symbol in input\n");
					break;
			}

			if(!retVal)
			{
				printf("bracket error at position : [%d]\n", i);
				break;
			}
		}

		if(!leftChar.empty())
		{
			retVal = false;
			printf("bracket are not balanced\n");
		}

		return retVal;
	}
};

int main(int argc, char const *argv[])
{
	string inp1 = "{[()]}";
	string inp2 = "[[[[";

	cout<< wellFormedness::check(inp1) << endl;
	cout<< wellFormedness::check(inp2) << endl;
	return 0;
}