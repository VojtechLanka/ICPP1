#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
struct Queue {
private:
	struct El {
		T value;
		El* next;
		El* previous;
	};
	El* first;
	El* last;
public:
	Queue() {
		first = last = nullptr;
	}

	Queue(const Queue& aQueue) {
		El* it = aQueue.first;
		while (it) {
			insert(it->value);
			it = it->next;
		}
	}

	~Queue() {
		while (first) {
			El* tmp = first;
			first = first->next;
			delete tmp;
		}
	}

	void insert(T aValue) {
		last = new El{ aValue, nullptr, last };
		if (!first) {
			first = last;
		}
		else {
			last->previous->next = last;
		}
	}

	T pop() {
		T value = last->value;
		El* tmp = last;

		if (last->previous) {
			last = last->previous;
			last->next = nullptr;
		}
		else {
			last = nullptr;
			first = nullptr;
		}

		delete tmp;
		return value;
	}

	bool contains(T value) const {
		El* el = first;
		while (el) {
			if (el->value == value) {
				return true;
			}
			el = el->next;
		}
		return false;
	}

	using ApplyFunction = void(*) (T);

	void processNode(ApplyFunction applyFunction) {
		El* el = first;
		while (el) {
			applyFunction(el->value);
			el = el->next;
		}
	}

	bool isEmpty() const {
		return first == nullptr;
	}
};

#endif // !QUEUE_H