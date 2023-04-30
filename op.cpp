#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	ifstream fout;
	fout.open("26users.txt");
	vector <int> users;
	string str;
	int n;
	if (!fout.good()) cout << "no file";
	else {
		while (fout >> str) 
		{
			getline(fout, str);
			istringstream ss(str);
			for (int i=0; i<str.size(); i++) {
				ss>>n;
				cout <<n << " ";
				users.push_back(n);
			}
		}
		fout.close();
		for (int i=0; i<users.size(); i++) cout <<users[i] << " ";
	}
	return 0;
}
