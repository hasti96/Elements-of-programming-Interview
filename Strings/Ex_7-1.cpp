#include <bits/stdc++.h>

using namespace std;

class StringConversion
{
public:
	static int strToInt(string input)
	{
		int retVal = 0;
		for(auto i: input)
		{
			if(i == '-')
				continue;
			retVal = (retVal * 10) + (i - '0');
		}
		
		return input[0] == '-' ? -retVal : retVal;
	}

	static string intToString(int input)
	{
		bool isNegative = input < 0 ? true : false;

		string retVal;

		while(input)
		{
			retVal += '0' + abs(input % 10);
			input = input / 10;
			
		}

		if(isNegative)
			retVal = retVal + '-';


		reverse(retVal.begin(), retVal.end());

		return retVal;
	}
};

int main(int argc, char* argv[])
{

	cout<< StringConversion::strToInt("123") << endl;
	cout<< StringConversion::intToString(-1234) << endl;

	return 0;
}