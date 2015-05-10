#include "SList.h"


SList::SList()
{
	m_pHead = NULL;
}


SList::~SList()
{
}


// Insertion sort�� ����Ͽ� ����
bool SList::InsertionSort(string sWord)
{

	// ������ ��� ó��x
	// ������ alphabetical�� ó���Ǿ�����

	Node* pTemp = new Node;
	pTemp->node_sWord = sWord;

	// �ʱⰪ�� 1���̱� ������ 1�� ����
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
	// �⺻ Insertion sort ����
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

	// while���ȿ����� �߰��� ���� �� �ִ� ���
	while (pPos)
	{
		// �߰��κп� ��ġ�� �ִ� ���
		if (pPos->node_sWord > pTemp->node_sWord)
		{
			if (pPreNode == NULL)
			{   // if (b > a ) --->  m_pHead -> a -> b ������ ���� 
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
		// error ó��
		//else if(pPos->node_sWord == pTemp->node_sWord)
		//{
		//	//counter + 1�� �ؾ������� �̹� �߸���
		// }

		pPreNode = pPos;
		pPos = pPos->node_pNext;
	}

	// while���� ������ ���� �������� ���� ���


	return false;
}
