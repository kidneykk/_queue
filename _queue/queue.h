#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iosfwd>

struct empty_set {
	empty_set(const char* error) {
		printf("%s\n", error);
	}
};

template<class T>
struct node {
	node* next;
	T data;
};

template<class T>
class queue {
private:
	node<T>* head;
	node<T>* tail;

	int m_size;

	node<T>* create_node(const T& val) {
		node<T>* newNode = new node<T>;
		newNode->data = val;
		newNode->next = nullptr;
		return newNode;
	}

public:
	queue() : m_size(0) {
		head = tail = nullptr;
	}

	bool empty() const {
		return head == nullptr;
	}

	int size() const {
		return m_size;
	}

	T& front() { return head->data; }
	const T& front() const { return head->data; }

	T& back() { return tail->data; }
	const T& back() const { return tail->data; }

	void push(const T& val) {
		if (empty()) {
			head = tail = create_node(val);
			m_size++;
			return;
		}

		tail->next = create_node(val);
		tail = tail->next;
		m_size++;
	}

	void pop() {
		if (empty()) {
			throw empty_set("queue is empty");
		}

		node<T>* temp = new node<T>;
		temp = head;
		head = head->next;
		delete temp;

		m_size--;
	}

	friend std::ostream& operator<<(std::ostream& os, class queue<T>& q) {
		node<T>* temp = q.head;
		while (temp) {
			os << temp->data << ' ';
			temp = temp->next;
		}
		return os;
	}
};

#endif