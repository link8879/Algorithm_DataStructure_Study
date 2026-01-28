#pragma once

class Node {
public:
	int data;	//データ
	Node* next;	//次のノードへのポインタ
};

class LinkedList {
public:
	Node* head = nullptr; //リストの先頭ノードへのポインタ
	void Display();	//リストの表示
	void Search(int data);	//ノードの検索
	void Insert(int data);	//ノードの挿入
	void Delete(int data);	//ノードの削除
};