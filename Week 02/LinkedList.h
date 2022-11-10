#pragma once
#include <iostream>

template <typename T>
class LinkedList {
	struct Node {
		T value;
		Node* next;

		Node(const T& value, Node* next) {
			this->value = value;
			this->next = next;
		}
	};

	Node* start;
	Node* last;
	size_t size;

public:
	LinkedList() {
		start = NULL;
		last = NULL;
		size = 0;
	}

	~LinkedList() {
		while (start) {
			Node* tmp = start->next;
			delete start;
			start = tmp;
		}
	}

	void push_back(const T& value) {
		if (last) {
			last->next = new Node(value, NULL);
			last = last->next;
		}
		else {
			start = new Node(value, NULL);
			last = start;
		}
		size++;
	}

	void insertAt(size_t index, const T& value) {
		if (index > size) {
			throw std::out_of_range("Index is out of range");
		}
		else if (index == size) {
			push_back(value);
		}
		else if (index == 0) {
			Node* tmp = new Node(value, start);
			start = tmp;
			if (size == 0) {
				last = start;
			}
			size++;
		}
		else {
			Node* tmp = start;
			while (index > 1) {
				tmp = tmp->next;
				index--;
			}
			Node* newNode = new Node(value, tmp->next);
			tmp->next = newNode;
			size++;
		}
	}

	int getSize() const {
		return size;
	}

	const T& getAt(size_t index) const {
		if (index >= size) {
			throw std::out_of_range("Index is out of range");
		}

		Node* tmp = start;
		while (index) {
			tmp = tmp->next;
			index--;
		}

		return tmp->value;
	}
};
