#include "SList.h"

#include <iostream>
#include <string>

using namespace std;


SList::SList()
{
	m_pHead = NULL;
	m_iTotalWordsCounter = 0;
}


SList::~SList()
{
}


//  
void SList::InsertionSort()
{
	Node* node = m_pHead;

	if (node == NULL)
		return;

	// Make the first node the start of the sorted list.
	Node* sortedList = node;
	node = node->node_pNext;
	sortedList->node_pNext = NULL;

	/*
	32451
	3                  2 4 5 1
	(sortedList) 3        (current) 2          (node) 4 5 1
	(current) 2 3     (node) 4 5 1
	(sortedList) 2 3   (current) 4       (node)  5 1
	(search) 2 4 ............
	*/
	while (node != NULL) {
		// Advance the nodes.
		Node* current = node;
		node = node->node_pNext;

		// Find where current belongs.
		if (current->node_sWord < sortedList->node_sWord) {
			// Current is new sorted head.
			current->node_pNext = sortedList;
			sortedList = current;
		}
		else {
			// Search list for correct position of current.
			Node* search = sortedList;
			while (search->node_pNext != NULL && current->node_sWord > search->node_pNext->node_sWord)
				search = search->node_pNext;

			// current goes after search.
			current->node_pNext = search->node_pNext;
			search->node_pNext = current;
		}
	}
	m_pHead = sortedList;
}

//// Insertion sort를 사용하여 삽입
//bool SList::InsertionSort(string sWord)
//{
//	// Total Count 증가
//	m_iTotalWordsCounter++;
//
//	// 숫자인 경우 처리x
//	// 문제에 alphabetical만 처리되어있음
//
//	Node* pTemp = new Node;
//	pTemp->node_sWord = sWord;
//
//	// 초기값은 1개이기 때문에 1로 정함
//	pTemp->node_iCounter = 1;
//
//	if (m_pHead == NULL)
//	{
//		pTemp->node_pNext = NULL;
//		m_pHead = pTemp;
//
//		return true;
//	}
//	
//	Node* pPos = m_pHead;
//	Node* pPreNode = NULL;
//
///*
//	// 기본 Insertion sort 개념
//	for (i = 1; i < n; i++)
//	{
//		t = a[i];
//		j = i;
//		while (a[j - 1] > t && j > 0)
//		{
//			a[j] = a[j - 1];
//			j--;
//		}
//		a[j] = t;
//	}*/
//
//	// while문안에서는 중간에 넣을 수 있는 경우
//	while (pPos)
//	{
//		// 중간부분에 위치를 넣는 경우
//		if (pPos->node_sWord > pTemp->node_sWord)
//		{
//			if (pPreNode == NULL)
//			{   // if (b > a ) --->  m_pHead -> a -> b 순서로 정렬 
//				pTemp->node_pNext = pPos;
//				m_pHead = pTemp;
//			}
//			else
//			{	// insert c in m_pHead -> b -> d -> e
//				// m_pHead -> b -> c- > d -> e;
//				pTemp->node_pNext = pPos;
//				pPreNode->node_pNext = pTemp;
//			}
//			return true;
//		}
//		// error 처리
//		//else if(pPos->node_sWord == pTemp->node_sWord)
//		//{
//		//	//counter + 1을 해야하지만 이미 잘못됨
//		// }
//
//		pPreNode = pPos;
//		pPos = pPos->node_pNext;
//	}
//
//	// while문을 나왔을 경우는 마지막에 들어가는 경우
//	pTemp->node_pNext = NULL;
//	pPreNode->node_pNext = pTemp;
//
//	return true;
//}


void SList::DisPlayWords()
{
	cout << "=======================================" << endl;
	cout << "총 단어 갯수 : " << m_iTotalWordsCounter << endl;
	cout << "---------------  단어들 ---------------" << endl;

	if (m_pHead == NULL)
	{
		cout << "empty" << endl;
	}

	Node* pPos = m_pHead;

	while (pPos)
	{
		cout << "단어 : " << pPos->node_sWord << endl;
		cout << "갯수 : " << pPos->node_iCounter << endl;
		cout << "--------------------------------" << endl;

		pPos = pPos->node_pNext;

	}
}


bool SList::InsertToFirst(string sWord)
{
	// Total Count 증가
	m_iTotalWordsCounter++;

	// 숫자인 경우 처리x
	// 문제에 alphabetical만 처리되어있음

	Node* pTemp = new Node;
	pTemp->node_sWord = sWord;

	// 초기값은 1개이기 때문에 1로 정함
	pTemp->node_iCounter = 1;

	// element가 비워져 있을 시
	// m_pHead = NULL   =====>  m_pHead = data1 -> NULL
	if (m_pHead == NULL)
	{
		pTemp->node_pNext = NULL;
		m_pHead = pTemp;

		// InsertionSort를 이용하여 정렬
		InsertionSort();
		return true;
	}

	// element 가 존재할 때
	// m_pHead = data -> data -> data  =====> m_pHead = data1 -> data -> data -> data
	pTemp->node_pNext = m_pHead;  // data1 -> (m_pHead)data -> data -> data
	m_pHead = pTemp;

	// InsertionSort를 이용하여 정렬
	InsertionSort();
	return true;
}
