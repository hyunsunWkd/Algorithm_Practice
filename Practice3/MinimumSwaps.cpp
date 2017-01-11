// MinimumSwaps.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		for (int i = j+1; i < numbers.size(); i++) {//�ִ� Ž��
			if (max < numbers[i]) {
				max = numbers[i];
				maxIndex = i;
			}
		}
		if (max != numbers[j]) {//�ִ��� �ٸ� ��ġ�� ���� ������ swap
			swap(numbers[j], numbers[maxIndex]);
			minSwap++;
		}
	}
	cout << "�ּ� �̵� Ƚ�� : " << minSwap << endl;
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

