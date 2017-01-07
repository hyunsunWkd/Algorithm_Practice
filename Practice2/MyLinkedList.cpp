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

ListNode *deleteGreaterThanX(ListNode *head, int x) {
	ListNode *ptr = NULL;
	ListNode *before, *deleteNode = NULL;
	ptr = head;
	if (ptr != NULL) {
		before = ptr;
		while (ptr->next != NULL) {
			if (ptr->val > x) {
				if (ptr == head) { //가장 첫번째 노드를 삭제할 경우
					deleteNode = ptr;
					head = ptr->next;
					delete deleteNode;
					ptr = head;
				}
				else {
					deleteNode = ptr;
					before->next = deleteNode->next;
					delete deleteNode;
					ptr = before;
				}
			}
			before = ptr;
			ptr = ptr->next;
		}
		if (ptr->next == NULL && ptr->val > x) {
			before->next = NULL;
			delete ptr;
		}
	}
	return head;
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
	list = deleteGreaterThanX(list, x);
	displayNode(list);

	system("pause");
    return 0;
}