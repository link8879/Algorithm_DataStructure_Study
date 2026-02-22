#include <iostream>
#include "LinkedList.h"

// リストの表示	
void LinkedList::Display() {
	
	// headから始めて、次のノードがnullptrまで
	for (Node* n = head; n != nullptr; n = n->next) {
		std::cout << n->data << " ";	// ノードのデータを表示
	}
}

// ノードの検索
void LinkedList::Search(int data) {
	
	// headから始めて、データを見つける
	for (Node* n = head; n != nullptr; n = n->next) {
		
		if (n->data == data) {	// ノードのポインタが指すデータを見つけたら
			std::cout << "Found: " << data << std::endl;
			return;
		}
	}
	std::cout << "Not Found: " << data << std::endl;
}

// ノードの削除
void LinkedList::Delete(int data) {

	// headノードが削除対象の場合
	if (head->data == data) {
		Node* temp = head;
		head = head->next;
		delete temp;
		std::cout << "Deleted head: " << data << std::endl;
		return;
	}

	for (Node* n = head; n->next != nullptr; n = n->next) {
		
		if (n->next->data == data) {	//次のノードのデータを見つけたら
			// ノードを削除する処理
			Node* temp = n->next;	//次のノードのポインタを一時保存

			n->next = n->next->next;	//次のノードをスキップして、その次のノードに接続
			delete temp;				//次のノードはもう使わないからメモリを解放
			
			std::cout << "Deleted: " << data << std::endl;
			return;
		}
	}
	std::cout << "Not Found: " << data << std::endl;
}

// ノードの挿入
void LinkedList::Insert(int data) {
	//最後にノードを追加する
	Node* newNode = new Node();
	newNode->data = data;	//新しいノードにデータを設定
	newNode->next = nullptr;	//新しいノードの次のポインタをnullptrに設定

	if (head == nullptr) {
		head = newNode;
		return;
	}
	else {
		for (Node* n = head; n != nullptr; n = n->next) {
			if (n->next == nullptr) {
				n->next = newNode;	//最後のノードの次に新しいノードを接続
				return;
			}
		}
	}
}

void LinkedList::~LinkedList() {
	//リストの全ノードを削除してメモリを解放する
	Node* current = head;
	while (current != nullptr) {
		Node* temp = current;	//現在のノードを一時保存
		current = current->next;	//次のノードに移動
		delete temp;			//現在のノードを削除
	}
}
