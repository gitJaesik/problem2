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
	cout << "�� �ܾ� ���� : " << m_iTotalWordsCounter << endl;
	cout << "---------------  �ܾ�� ---------------" << endl;

	if (m_pHead == NULL)
	{
		cout << "empty" << endl;
	}

	Node* pPos = m_pHead;

	while (pPos)
	{
		cout << "�ܾ� : " << pPos->node_sWord << endl;
		cout << "���� : " << pPos->node_iCounter << endl;
		cout << "--------------------------------" << endl;

		pPos = pPos->node_pNext;

	}
}


bool SList::InsertToFirst(string sWord)
{
	if (sWord == "")
		return true;

	// Total Count ����
	m_iTotalWordsCounter++;

	// ������ ��� ó��x
	// ������ alphabetical�� ó���Ǿ�����

	Node* pTemp = new Node;
	pTemp->node_sWord = sWord;

	// �ʱⰪ�� 1���̱� ������ 1�� ����
	pTemp->node_iCounter = 1;

	// element�� ����� ���� ��
	// m_pHead = NULL   =====>  m_pHead = data1 -> NULL
	if (m_pHead == NULL)
	{
		pTemp->node_pNext = NULL;
		m_pHead = pTemp;

		// InsertionSort�� �̿��Ͽ� ����
		InsertionSort();
		return true;
	}

	// element �� ������ ��
	// m_pHead = data -> data -> data  =====> m_pHead = data1 -> data -> data -> data
	pTemp->node_pNext = m_pHead;  // data1 -> (m_pHead)data -> data -> data
	m_pHead = pTemp;

	// InsertionSort�� �̿��Ͽ� ����
	InsertionSort();
	return true;
}


// binary search���� (a0 + n) / 2 �� �κ��Դϴ�.
void* SList::MiddleNode(Node* startNode, Node* endNode)
{
	if (startNode == NULL)
	{
		// the link is empty
		return NULL;
	}
	
	// ����ó��
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
			// ã�� �ܾ �����ϴ�.
			InsertToFirst(sWord);
			return NULL;
		}

		// ��� ã��
		if (middle->node_sWord == sWord)
		{
			// �Ȱ��� �ܾ ������ ī���� ����
			middle->node_iCounter++;
			return middle;
		}
		else if (middle->node_sWord < sWord)
		{
			// middle���� end���� �˻�
			startNode = middle->node_pNext;
		}
		else
		{
			// start���� middle���� �˻�
			endNode = middle;
		}
	} while (endNode == NULL || endNode->node_pNext != startNode);

	// ã�� �ܾ �����ϴ�.
	InsertToFirst(sWord);
	return NULL;
}


void SList::execute(string sWord)
{
	BinarySearch(sWord);
}
