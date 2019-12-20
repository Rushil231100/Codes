#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	long long int a,b,x,y,z;
	while(t--){
	    cin>>a>>b;
	    x=abs(a-b);
	    y=1+8*x;
	    for(long long int i=0;i<1000000000;i++){
	        if(isPerfectSquare(y+16*i)){
	            z=(floor(sqrt(y+16*i))-1)/2;
	            cout<<z<<endl;
	            break;
	        }
	    }
	}
	return 0;
}
