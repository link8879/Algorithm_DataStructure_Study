#pragma once

class Stack 
{
public:
	void Push(int data);	//スタックにデータを追加
	void Pop();	//スタックからデータを削除
	void Display();	//スタックの内容を表示
	void top();	//スタックのトップのデータを表示
	bool isEmpty();	//スタックが空かどうかを表示
	int size();	//スタックのサイズを表示
	void Clear();	//スタックを空にする
	void ~Stack();	//スタックのデストラクタ
	void Stack(int capacity);
private:
	int* stackArray;	//スタックの配列
	int topIndex = -1;	//スタックのトップのインデックス
};