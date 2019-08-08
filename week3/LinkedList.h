/*
 * LinkedList.h
 *
 *  Created on: 24.06.2019
 *      Author: daer
 */

#pragma once

template <typename T>
class LinkedList {
public:
  struct Node {
    T value;
    Node* next = nullptr;
  };

  ~LinkedList();

  void PushFront(const T& value);
  void InsertAfter(Node* node, const T& value);
  void RemoveAfter(Node* node);
  void PopFront();

  Node* GetHead() { return head; }
  const Node* GetHead() const { return head; }

private:
  Node* head = nullptr;
};


template <typename T>
LinkedList<T>::~LinkedList(){
	Node* temp = nullptr;
	while (head != nullptr){
		temp = head->next;
		delete head;
		head = temp;
	}
}




template <typename T>
void LinkedList<T>::PushFront(const T& value){
		Node* temp 	= new Node;
		temp->value = value;
		temp->next	= head;
		head = temp;

}
template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& value){
	if (!node ) {
		PushFront(value);
	}else{
		Node* temp = new Node;
		temp->value = value;
		temp->next = node->next ;
		node->next = temp;

	}
}
template <typename T>
void LinkedList<T>::RemoveAfter(Node* node){
	if (!node){
		PopFront();//as per spesification of the assignment
		return;
	}else{

		Node* temp = node->next;
		node->next = node->next->next;
		delete temp;
	}
}
template <typename T>
void LinkedList<T>::PopFront(){
	if (head){
		Node* temp = head->next;
		delete head;
		head = temp;
	}
}

