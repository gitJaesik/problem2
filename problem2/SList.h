#pragma once
#include <iostream>
#include <string>
#include "SList.h"

using namespace std;

class SList
{
public:
	struct Node
	{
		string node_sWord;
		int node_iCounter;
		Node* node_pNext;
		Node(){ node_pNext = NULL; }
	};

	Node* m_pHead;

public:
	SList();
	~SList();

	// InsertByInsertionSort
	// SearchByBinarySearch

	// Insertion sort�� ����Ͽ� ����
	bool InsertionSort(string sWord);
};

