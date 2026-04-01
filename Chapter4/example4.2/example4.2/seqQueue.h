#pragma once
template <class elemType>
class seqQueue {
private:
	elemType* elem;
	int currentLength;
	int front;
	int maxSize;

	void doubleSpace() {
		elemType* temp = elem;
		elem = new elemType[maxSize * 2];
		for (int i = 0;i < maxSize;i++)
		{
			elem[i] = temp[(front + 1 + i) % maxSize];
		}
		front = -1;
		maxSize *= 2;
		delete temp;
	}
public:
	seqQueue(int size = 10) {
		currentLength = 0;
		maxSize = size;
		front = -1;
		elem = new elemType[size];
	}
	~seqQueue() { delete[] elem; }
	bool isEmpty() const
	{
		return currentLength == 0;
	}

	void enQueue(const elemType& x)
	{
		if (currentLength == maxSize)
			doubleSpace();
		currentLength += 1;
		elem[(front + currentLength) % maxSize] = x;
	}
	elemType deQueue()
	{
		if (!isEmpty())
		{
			int value = elem[front];
			front = (front + 1) % maxSize;
			currentLength -= 1;
			return value;
		}
		elemType getHead() const
		{
			if (!isEmpty())return elem[(front + 1) % maxSize];
		}
	}
};