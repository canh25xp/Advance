// In Practice, You should use the statndard input/output
// in order to receive a score properly.
// Do not use file input and output. Please be very careful. 

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int find_max(int arr[], int n, int limit);

int main(int argc, char** argv){
	int TEST_CASE;
	
	ios::sync_with_stdio(false);

	freopen("input.txt", "r", stdin);
	cin >> TEST_CASE;

	for(int test_case = 1; test_case <= TEST_CASE; ++test_case){
		int ans = 0;
		int max_weight, cows;
		cin >> max_weight >> cows;

		int data[100000]={0};
		int index=0;
		for(int i = 0 ; i < cows ; ++i){
			int cow;
			cin >> cow;
			data[index] = cow;
			index++;
			for(int j = (index-2); j>=0 ; j--){
				int temp = cow + data[j];
				data[index] = temp;
				index++;
			}
		}
		ans = find_max(data, index, max_weight);

		// Print the answer to standard output(screen).
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}

int find_max(int arr[], int n, int limit){
	int max=0;
	for(int i=0;i<n;i++){
		if(arr[i]>max && arr[i]<=limit){
			max=arr[i];
		}
	}
	return max;
}