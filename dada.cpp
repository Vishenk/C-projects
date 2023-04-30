#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool proverka(int el, vector <int> M){
	bool marker=false;
	for (int i=0; i<M.size(); i++){
		if (el==M[i]) marker=true;
	}
	return marker;
}

int main()
{
    ifstream fout("26.txt");
    int n, a, k=0, max=0;
    fout >> n;
    vector <int> M, nech;
    if (!fout.good()) cout << "NO FILE!" << endl;
    else
    {
        while (fout >> a) M.push_back(a);
    }
    fout.close();
    
  	for (int i=0; i<M.size(); i++){
   		if (M[i]%2!=0) nech.push_back(M[i]);
	}
	
	for (int i=0; i<nech.size()-1; i++){
		for (int j=i+1; j<nech.size(); j++){
			a=(nech[i]+nech[j])/2;
			if (proverka(a,M)==1){
				cout<<a<<endl;
				k++;
				if (a>max) max=a;
			}
		}
	}
	cout <<k<<" "<<max;
    return 0;
}
