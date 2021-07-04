#include <bits/stdc++.h>

using namespace std;

class ShortestPath
{
public:
	static string find(string& path)
	{
		if(path.empty())
			throw invalid_argument("Empty string is not a valid path.");

		vector<string> path_name;
		if(path.front() == '/')
			path_name.emplace_back("/");

		stringstream ss(path);
		string token;

		while(getline(ss, token, '/'))
		{
			if(token == "..")
			{
				if(path_name.empty() or path_name.back() == "..")
				{
					path_name.emplace_back(token);
				}
				else
				{
					if(path_name.back() == "/")
					{
						throw invalid_argument("path error");
					}
					path_name.pop_back();
				}
			}
			else if(token != "." and token != "")
			{
				path_name.emplace_back(token);
			}
		}

		string result;
		if(!path_name.empty())
		{
			result = path_name.front();

			for(int i = 1 ; i < path_name.size(); i++)
			{
				if(i == 1 and result == "/")
				{
					result += path_name.at(i);
				}
				else
					result += "/" + path_name.at(i);
			}
		}

		return result;
	}
};

int main(int argc, char* argv[])
{
	string a = "/usr/lib/../bin/gcc";
	
	cout<< ShortestPath::find(a) << endl;

	return 0;
}