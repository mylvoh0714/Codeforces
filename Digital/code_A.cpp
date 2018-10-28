#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
using namespace std;
vector<pair<int, string>> vec;

int extract(string& s)
{
	int yy, mm, dd;
	const char *c = s.c_str();
	if ( sscanf(c, "%d-%d-%d", &yy, &mm, &dd) ) {}
	return yy;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string str;
	
	while ( 1 )
	{
		getline(cin, str);
		if ( str == "END" ) break;
		cout << extract(str);
		//vec.push_back({ extract(str), str });
	}
}