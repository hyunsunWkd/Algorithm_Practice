// MyLinkedList.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;

	ListNode(int i) {
		val = i;
		next = NULL;
	}
};

ListNode *insert(ListNode *head, int data) {
	ListNode *insertNode = new ListNode(data);

	ListNode *ptr = NULL;
	ptr = head;
	if (ptr == NULL) {
		head = insertNode;
	}
	else {
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = insertNode;
	}
	return head;
}

void displayNode(ListNode *head) {
	ListNode *list = head;
	while (list != NULL) {
		cout << list->val << endl;
		list = list->next;
	}
}

ListNode *deleteGreaterThanX(ListNode *list, int x) {

	return list;
}

int main()
{	
	int n, x;
	cin >> n;
	vector<int> numbers(n);
	ListNode *list = NULL;

	for (int _numbers_i = 0; _numbers_i < n; _numbers_i++) {
		cin >> numbers[_numbers_i];
		list = insert(list, numbers[_numbers_i]);
	}
	cin >> x;
	displayNode(list);

	system("pause");
    return 0;
}