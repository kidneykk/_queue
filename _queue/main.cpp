#include <iostream>
#include "queue.h"

int main() {
	queue<int> q;

	for (int i = 0; i < 10; ++i)
		q.push(i + 1);

	std::cout << q << '\n';
	
	for (int i = 0; i < 5; ++i)
		q.pop();

	std::cout << q << '\n';

	std::cout << "front: " << q.front() << '\n';
	std::cout << "back: " << q.back() << '\n';

	return 0;
}