// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	
	
	int minDiffernce(int arr[], int n) 
	{ 
	    int sum=0;
	    
	    for(int i=0;i<n;i++){
	        sum=sum+arr[i];
	    }
	    
	    
	    int answer=subsetsum(arr,n,sum);
	    
	    // Your code goes here
	    return answer;
	}
	
	    
	int subsetsum(int arr[],int n, int sum){
	    
	    bool t[n+1][sum+1];
	     for(int i=0;i<n+1;i++){
	        for(int j=0;j<sum+1;j++){
	            
	            if(i==0){
	                t[i][j]=0;
	            }        
	            
	            if(j==0){
	                t[i][j]=1;
	            }        
	        }
	     }
	    
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<sum+1;j++){
	            
	            if(arr[i-1]<=j){
	                t[i][j]=t[i-1][j-arr[i-1]] or t[i-1][j];
	            }
	            
	            else{
	                t[i][j]=t[i-1][j];
	            }
	        }
	    }
	    
	   
	 int minans = INT_MAX;
	   for(int i = 0; i < sum+1; i++){
	    if(t[n][i] == 1)
        {
            minans = min(minans, abs(i - (sum-i)));
        }
        
	   }
	   return minans; 
	 
	
	}
	
	
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends