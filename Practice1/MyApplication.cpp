// MyApplication.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int GetMaxSum(vector<int> ratings) {
	int max_sum = 0;
	bool isSkip = false;//skip가능 상태 false:가능, true:불가능
	for (int _ratings_i = 0; _ratings_i < ratings.size(); _ratings_i++) {
		if (ratings[_ratings_i] >= 0) {//양수면 무조건 더함
			max_sum += ratings[_ratings_i];
			isSkip = false;
		}
		else {//음수이면
			if (!isSkip) {//skip가능하면
				int succeesiveNegativeNum = 0;//연속된 음수의 갯수
				for (int i = _ratings_i; i<ratings.size() && ratings[i]<0; i++) succeesiveNegativeNum++;
				if (succeesiveNegativeNum == 1) {//연속된 음수가 한 개
					isSkip = true;//skip불가로 상태 변경
				}
				else if (succeesiveNegativeNum%2 == 0) {//연속된 음수가 짝수개
					if (ratings[_ratings_i] < ratings[_ratings_i + 1]) {//왼쪽이 작은 경우
						max_sum += ratings[_ratings_i+1];//오른쪽 것 더함
						_ratings_i++;//skip
						isSkip = false;
					}
					else {//오른쪽이 작은 경우
						max_sum += ratings[_ratings_i];
						_ratings_i++;//skip
						isSkip = true;
					}
				}
				else if (succeesiveNegativeNum%2 != 0) {//연속된 음수가 홀수개(3개 이상)
					if (ratings[_ratings_i+1] < ratings[_ratings_i] && ratings[_ratings_i] < ratings[_ratings_i+2]) {//가운데가 제일 작은 경우
						max_sum += ratings[_ratings_i];
						max_sum += ratings[_ratings_i + 2];
						_ratings_i += 2;
						isSkip = false;
					}
					else {//양쪽 다 skip
						max_sum += ratings[_ratings_i + 1];
						_ratings_i += 2;
						isSkip = true;
					}
				}
			}
			else {//skip불가능하면
				max_sum += ratings[_ratings_i];
				isSkip = false;
			}
		}
	}
	return max_sum;
}

int main()
{
	int n;
	cin >> n;
	vector<int> ratings(n);
	for (int _ratings_i = 0; _ratings_i < n; _ratings_i++) {
		cin >> ratings[_ratings_i];
	}
	cout << GetMaxSum(ratings) << endl;
	system("pause");
    return 0;
}

