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

	int m_iTotalWordsCounter;

public:
	SList();
	~SList();

	// InsertByInsertionSort
	// SearchByBinarySearch

	// Insertion sort를 사용하여 삽입
	void InsertionSort();
	void DisPlayWords();
	bool InsertToFirst(string sWord);

	//Node* MiddleNode(Node* startNode, Node* endNode);
	void* MiddleNode(Node* startNode, Node* endNode);
	void* BinarySearch(string sWord);

	//void test(){
	//	Node* pTempTest = (Node*)BinarySearch("aa");
	//	if (pTempTest == NULL)
	//		cout << "there are no data" << endl;
	//	else
	//		cout << "tested by debug" << endl;
	//}

	void execute(string sWord);
};

