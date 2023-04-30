#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
    ifstream fout("27-A.txt");
    int n, a, k=0, max=0;
    fout >> n;
    vector <int> ost0, ost1, ost2;
    if (!fout.good()) cout << "NO FILE!" << endl;
    else
    {
        while (fout >> a)
		{
			if (a%3==0) ost0.push_back(a);
			if (a%3==1) ost1.push_back(a);
			if (a%3==2) ost2.push_back(a);
		 }
    }
    fout.close();
    
  	for (int i=0; i<ost0.size(); i++) 
  	{
  		for (int j=i+1; j<ost0.size(); j++) 
  		{
  			for (int k=j+1; k<ost0.size(); k++) 
  			{
  				if (ost0[i]+ost0[j]+ost0[k] > max) max=ost0[i]+ost0[j]+ost0[k];
			}
		}
		for (int j=0; j<ost1.size(); j++) 
  		{
  			for (int k=0; k<ost2.size(); k++) 
  			{
  				if (ost0[i]+ost1[j]+ost2[k] > max) max=ost0[i]+ost1[j]+ost2[k];
			}
		}
	}
	
	for (int i=0; i<ost1.size(); i++) 
  	{
  		for (int j=i+1; j<ost1.size(); j++) 
  		{
  			for (int k=j+1; k<ost1.size(); k++) 
  			{
  				if (ost1[i]+ost1[j]+ost1[k] > max) max=ost1[i]+ost1[j]+ost1[k];
			}
		}
	}
	cout << max;
    return 0;
}
