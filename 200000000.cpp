#include<iostream>

using namespace std;
int main(){
	
for (int i=200000000; i<=400000000; i++){
    int k=i;
    if (k%4==0){
		while (k%4==0){
        	k/=4;}}
    else {
    	continue;}
	while (k%9==0){
        k/=9; }
    if (k==3){
            cout<<i<<endl; }
   }
}
