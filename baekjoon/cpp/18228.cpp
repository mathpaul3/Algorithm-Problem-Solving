#include <iostream>
using namespace std;
int main(){
	int arr[200000], N, min1 = 1000000000, min2 = 1000000000;
	bool penguin = false;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i] == -1 ? penguin = true : penguin ? arr[i] < min2 ? min2 = arr[i] : min2 = min2 : arr[i] < min1 ? min1 = arr[i] : min1 = min1;
//		if (arr[i] == -1) penguin = true;
//		else {
//			if (penguin) {
//				if (arr[i] < min2) min2 = arr[i];
//			} else {
//				if (arr[i] < min1) min1 = arr[i];
//			}
//		}
	}	
	cout << min1 + min2;
}
