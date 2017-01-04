// MyApplication.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int GetMaxSum(vector<int> ratings) {
	int max_sum = 0;
	bool isSkip = false;//skip���� ���� false:����, true:�Ұ���
	for (int _ratings_i = 0; _ratings_i < ratings.size(); _ratings_i++) {
		if (ratings[_ratings_i] >= 0) {//����� ������ ����
			max_sum += ratings[_ratings_i];
			isSkip = false;
		}
		else {//�����̸�
			if (!isSkip) {//skip�����ϸ�
				int succeesiveNegativeNum = 0;//���ӵ� ������ ����
				for (int i = _ratings_i; i<ratings.size() && ratings[i]<0; i++) succeesiveNegativeNum++;
				if (succeesiveNegativeNum == 1) {//���ӵ� ������ �� ��
					isSkip = true;//skip�Ұ��� ���� ����
				}
				else if (succeesiveNegativeNum%2 == 0) {//���ӵ� ������ ¦����
					if (ratings[_ratings_i] < ratings[_ratings_i + 1]) {//������ ���� ���
						max_sum += ratings[_ratings_i+1];//������ �� ����
						_ratings_i++;//skip
						isSkip = false;
					}
					else {//�������� ���� ���
						max_sum += ratings[_ratings_i];
						_ratings_i++;//skip
						isSkip = true;
					}
				}
				else if (succeesiveNegativeNum%2 != 0) {//���ӵ� ������ Ȧ����(3�� �̻�)
					if (ratings[_ratings_i+1] < ratings[_ratings_i] && ratings[_ratings_i] < ratings[_ratings_i+2]) {//����� ���� ���� ���
						max_sum += ratings[_ratings_i];
						max_sum += ratings[_ratings_i + 2];
						_ratings_i += 2;
						isSkip = false;
					}
					else {//���� �� skip
						max_sum += ratings[_ratings_i + 1];
						_ratings_i += 2;
						isSkip = true;
					}
				}
			}
			else {//skip�Ұ����ϸ�
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

