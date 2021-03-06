#include <queue>

vector <int> k_Largest(int *arr,int n, int k){


	priority_queue<int,vector<int>,greater<int>> pq;
	
	// Pushing the first k elements into a priority queue
	for(int i=0;i<k;i++){
		pq.push(arr[i]);
	}

	// If any of the next n-k elements are larger than elements in queue, pop the minimum
	// element and add the larger element
	for(int i=k;i<n;i++){
		if(pq.top()<arr[i]){
			pq.pop();
			pq.push(arr[i]);	
		}
		
	}
	
	int ab[k];
	
	// Pushing the elements of priority queue in an array in reverse order 
	for(int i=0;i<k;i++){
		
		ab[k-i-1]=pq.top();
		pq.pop();
	}
	
	return ab;
}
