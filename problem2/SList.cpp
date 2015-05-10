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


void SList::DisPlayWords()
{
	cout << "=======================================" << endl;
	cout << "총 단어 종류 : " << m_iTotalWordsCounter << endl;
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
	if (sWord == "")
		return true;

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


// binary search에서 (a0 + n) / 2 인 부분입니다.
void* SList::MiddleNode(Node* startNode, Node* endNode)
{
	if (startNode == NULL)
	{
		// the link is empty
		return NULL;
	}
	
	// 예외처리
	if (startNode == endNode)
		return NULL;

	Node* pSlowPos = startNode;
	Node* pFastPos = startNode->node_pNext;

	while (pFastPos != endNode)
	{
		pFastPos = pFastPos->node_pNext;

		if (pFastPos != endNode)
		{
			pSlowPos = pSlowPos->node_pNext;
			pFastPos = pFastPos->node_pNext;
		}
	}

	return pSlowPos;
}


void* SList::BinarySearch(string sWord)
{
	Node* startNode = m_pHead;
	Node* endNode = NULL;

	do
	{
		Node* middle = (Node*)MiddleNode(startNode, endNode);

		if (middle == NULL)
		{
			// 찾는 단어가 없습니다.
			InsertToFirst(sWord);
			return NULL;
		}

		// 결과 찾음
		if (middle->node_sWord == sWord)
		{
			// 똑같은 단어가 나오면 카운터 증가
			middle->node_iCounter++;
			return middle;
		}
		else if (middle->node_sWord < sWord)
		{
			// middle부터 end까지 검색
			startNode = middle->node_pNext;
		}
		else
		{
			// start부터 middle까지 검색
			endNode = middle;
		}
	} while (endNode == NULL || endNode->node_pNext != startNode);

	// 찾는 단어가 없습니다.
	InsertToFirst(sWord);
	return NULL;
}


void SList::execute(string sWord)
{
	BinarySearch(sWord);
}
