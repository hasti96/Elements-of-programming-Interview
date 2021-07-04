#include <bits/stdc++.h>

using namespace std;

class ReverseWord
{
public:
	static string& strReverse(string& s)
	{
		reverse(s.begin(), s.end());

		int start = 0;

		for(int i = 0; i < s.size(); i++)
		{
			if(s.at(i) == ' ')
			{
				reverse(s.begin() + start, s.begin() + i);
				start = i + 1;
			}

			if(i == s.size() - 1)
			{
				reverse(s.begin() + start, s.end());
			}
		}
		
		return s;
	}

};

int main(int argc, char* argv[])
{	
	string a = "Bob Likes Alice";

	cout<< ReverseWord::strReverse(a);

	return 0;
}