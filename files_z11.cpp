#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void make_file(){           //Генерируем и заносим в файл "f.txt" n случайных целых чисел
	srand(time(NULL));
	ofstream file;
	file.open("f.txt");
	int n, a;
	cin >>n;
	for (int i=0; i<n; i++){
		a=50-rand()%101;
		cout <<a<<" ";
		file <<" "<<a;
	}
	file.close();
}

string reed_file(){          //Построчное чтение данных из файла "f.txt", возврат строки
	int a, n=0;
	string s;
	fstream f;
	f.open("f.txt");
	if (f){
		while(!f.eof()){
			getline(f, s);
		}
		f.close();
	}
	else cout <<"MISSING FILE!";
	return s;
}

int main(){
	string s;
	ofstream file;
	file.open("rez.txt");
	int n=0, max=-51, min=51, min_chet=50, abs_max=-51;
	make_file();
	s=reed_file();
	for (int i=0; i<s.size(); i++){
		if (s[i]==' ') n++;
	}
	cout <<endl;
	int M[n];
	istringstream ss(s);
	for (int i=0; i<n; i++){
		ss >> M[i];
   	    cout <<M[i]<<" ";
   	    if (M[i]>max) max=M[i];
   	    if (M[i]<min) min=M[i];
   	    if (i%2!=0 && M[i]<min_chet) min_chet=M[i];
   	    if (i%2==0 && abs(M[i])>abs_max) abs_max=abs(M[i]);
    }
    cout <<endl<<max<<endl;
    cout <<min_chet<<endl;
    cout <<abs_max<<endl;
    cout <<max+min<<endl;
    cout <<M[0]-M[n-1];
    
    file <<"Max_el = "<<max <<" \n";
    file <<"Min_chet = "<<min_chet <<" \n";
    file <<"Abs_max_nechet = "<<abs_max <<" \n";
    file <<"Sum_max+min = "<<max+min<<" \n";
    file <<"Raznost 1 - n = "<<M[0]-M[n-1] <<" \n";
		    
    file.close();
    return 0;
}
