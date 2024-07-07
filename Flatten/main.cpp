#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define TEST_CASE 10
#define WIDTH 100
#define MAX_HEIGHT 100

int height_difference(int arr[], int n);
int find_max(int arr[], int n);
int find_min(int arr[], int n);

int main(){
	ios::sync_with_stdio(false);
	freopen("flatten_test_input.txt", "r", stdin);
	for(int index = 0 ; index <TEST_CASE ; index++){
		int dump_count=0, ans=0;
		cin >> dump_count;
		int boxes[WIDTH];
		for(int i=0 ; i<WIDTH ; i++){
			cin >> boxes[i];
		}

		for(int i=0; i<dump_count ; i++){
			boxes[find_max(boxes,WIDTH)]--;
			boxes[find_min(boxes,WIDTH)]++;
		}

		ans = boxes[find_max(boxes,WIDTH)] - boxes[find_min(boxes,WIDTH)];

		cout << "#" << index+1 << " " << ans << endl;
	}
	return 0;
}

int find_max(int arr[], int n){
	int max=0, max_index=0;
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
			max_index=i;
		}
	}
	return max_index;
}

int find_min(int arr[], int n){
	int min=MAX_HEIGHT, min_index=0;
	for(int i=0; i<n ;i++){
		if(arr[i]<min){
			min = arr[i];
			min_index=i;
		}
	}
	return min_index;
}

int height_difference(int arr[], int n){
	return arr[n-1]-arr[0];
}