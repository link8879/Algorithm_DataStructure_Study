#include<iostream>
#include "Stack.h"

void Stack::Push(int data) {
	// スタックにデータを追加する処理
	if (Stack::size() == capacity) {
		std::cout << "No Capacity" << std::endl;
		return;
	}
	else {
		stackArray[topIndex++] = data;	// スタックの配列にデータを追加
		std::cout << "Push: " << data << std::endl;
	}
}

void Stack::Pop() {
	// スタックからデータを削除する処理
	if (!isEmpty()) {
		std::cout << "Pop: " << stackArray[topIndex] << std::endl;
		topIndex--;	// スタックのトップのインデックスを更新
	}
	else {
		std::cout << "Stack is Empty" << std::endl;
		return;
	}
}

void Stack::Top() {
	if (isEmpty()) {
		std::cout << "Stack is Empty" << std::endl;
		return;
	}
	std::cout << "Top: " << stackArray[topIndex] << std::endl;
}

void Stack::Display() {
	// スタックの内容を表示する処理
	for (int i = 0; i < size(); i++) {
		std::cout << stackArray[i] << " ";
	}
}

void stack::top() {
	// スタックのトップのデータを表示する処理
	if (isEmpty()) {
		std::cout << "Stack is Empty" << std::endl;
		return;
	}
	std::cout << "Top: " << stackArray[topIndex] << std::endl;
}

bool Stack::isEmpty() {
	// スタックが空かどうかを表示する処理
	return topIndex == -1;	// スタックのトップのインデックスが-1の場合はスタックが空であると判断
}

int Stack::size() {
	// スタックのサイズを表示する処理
	return topIndex + 1; // スタックのトップのインデックスが０の場合はスタックのサイズは1である
}

void Stack::Clear() {
	// スタックを空にする処理
	topIndex = -1;	// スタックのトップのインデックスを更新
}

Stack::~Stack() {
	// スタックのデストラクタの処理
	delete[] stackArray;	// スタックの配列を解放
}

Stack::Stack(int cap) : topIndex(-1), capacity(cap) {
	// スタックのコンストラクタの処理
	stackArray = new int[capacity];	// スタックの配列を動的に確保
}