#include "SList.h"


SList::SList()
{
	m_pHead = NULL;
}


SList::~SList()
{
}


// Insertion sort를 사용하여 삽입
bool SList::InsertionSort(string sWord)
{

	// 숫자인 경우 처리x
	// 문제에 alphabetical만 처리되어있음

	Node* pTemp = new Node;
	pTemp->node_sWord = sWord;

	// 초기값은 1개이기 때문에 1로 정함
	pTemp->node_iCounter = 1;

	if (m_pHead == NULL)
	{
		pTemp->node_pNext = NULL;
		m_pHead = pTemp;

		return true;
	}
	
	Node* pPos = m_pHead;
	Node* pPreNode = NULL;

/*
	// 기본 Insertion sort 개념
	for (i = 1; i < n; i++)
	{
		t = a[i];
		j = i;
		while (a[j - 1] > t && j > 0)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;
	}*/

	// while문안에서는 중간에 넣을 수 있는 경우
	while (pPos)
	{
		// 중간부분에 위치를 넣는 경우
		if (pPos->node_sWord > pTemp->node_sWord)
		{
			if (pPreNode == NULL)
			{   // if (b > a ) --->  m_pHead -> a -> b 순서로 정렬 
				pTemp->node_pNext = pPos;
				m_pHead = pTemp;
			}
			else
			{	// insert c in m_pHead -> b -> d -> e
				// m_pHead -> b -> c- > d -> e;
				pTemp->node_pNext = pPos;
				pPreNode->node_pNext = pTemp;
			}
			return true;
		}
		// error 처리
		//else if(pPos->node_sWord == pTemp->node_sWord)
		//{
		//	//counter + 1을 해야하지만 이미 잘못됨
		// }

		pPreNode = pPos;
		pPos = pPos->node_pNext;
	}

	// while문을 나왔을 경우는 마지막에 들어가는 경우


	return false;
}
