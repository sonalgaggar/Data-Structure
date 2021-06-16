##Next greater element in a circular array

#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n;
  //cout<<"enter size of array: ";
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  


int res[n];

 for (int i = 0; i < n; i++) {
		
		res[i]=-1; 
		for (int j = i + 1; j < n + i; j++) {
			if (arr[i]< arr[j % n]) {
				
				res[i]=arr[j%n];
				break;
			}
		}
		
	}
	cout<<"the next greater elements of all array elements: "<<endl;
 
  for (int i = 0; i < n; i++) {
    cout <<arr[i]<<"---->  " <<res[i] <<endl;
  }
 
  return 0;
}
