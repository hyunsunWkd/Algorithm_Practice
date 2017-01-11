// MinimumSwaps.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void minSwap(vector<int> numbers) {
	int minSwap = 0;
	int max, maxIndex;
	for (int j = 0; j < numbers.size() - 1; j++) {
		max = numbers[j];
		for (int i = j+1; i < numbers.size(); i++) {//최댓값 탐색
			if (max < numbers[i]) {
				max = numbers[i];
				maxIndex = i;
			}
		}
		if (max != numbers[j]) {//최댓값이 바른 위치에 있지 않으면 swap
			swap(numbers[j], numbers[maxIndex]);
			minSwap++;
		}
	}
	cout << "최소 이동 횟수 : " << minSwap << endl;
}

int main()
{
	int n; 
	cin >> n;
	vector<int> numbers(n);
	for (int _numbers_i = 0; _numbers_i < n; _numbers_i++) 
		cin >> numbers[_numbers_i];
	minSwap(numbers);
	system("pause");
    return 0;
}

