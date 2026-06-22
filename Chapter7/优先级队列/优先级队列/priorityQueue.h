#pragma once
template <class Type>
class priorityQueue {
public:
	priorityQueue(int capacity=100);
	priorityQueue(const Type data[], int size);
	~priorityQueue();
	bool isEmpty()const;
	void enQueue(const Type& x);
	Type deQueue();
	Type getHead()const;
private:
	int currentSize;
	Type* array;
	int maxSize;

	void doubleSpace();
	void buildHeap();
	void percolateDown(int hole);
};

template <class Type>
priorityQueue<Type>::priorityQueue(int capacity)
{
	array = new Type[capacity];
	maxSize = capacity;
	currentSize = 0;
}

template <class Type>
priorityQueue<Type>::~priorityQueue()
{
	delete[]array;
}

template <class Type>
bool priorityQueue<Type>::isEmpty() const
{
	return currentSize == 0;
}

template <class Type>
Type priorityQueue<Type>::getHead() const
{
	return array[1];//also you can do more in this part, like throw an exception when the queue is empty
}

template <class Type>
void priorityQueue<Type>::enQueue(const Type& x)
{
	if (currentSize == maxSize-1) doubleSpace();
	int hole = ++currentSize;
	for (;hole > 1 && x < array[hole];hole /= 2)
	{
		array[hole] = array[hole / 2];
	}
	array[hole] = x;
}
//O(logN)

template <class Type>
void priorityQueue<Type>::percolateDown(int hole)
{ 
	int child;
	Type temp = array[hole];
	for (;hole * 2 <= currentSize;hole = child)
	{
		child = hole * 2;
		if (child != currentSize && array[child + 1] < array[child])
			child++;
		if (array[child] < temp)
			array[hole] = array[child];
		else break;
	}
	array[hole] = temp;
}

template <class Type>
Type priorityQueue<Type>::deQueue()
{
	Type temp = array[1];
	array[1] = array[currentSize--];
	percolateDown(1);
	return temp;
}

template <class Type>
void priorityQueue<Type>::buildHeap()
{
	for (int i = currentSize / 2;i > 0;i--)
		percolateDown(i);
}
//O(N)


template <class Type>
priorityQueue<Type>::priorityQueue(const Type data[], int size):maxSize(size+10),currentSize(size)
{
	array = new Type[maxSize];
	for (int i = 0;i < size;i++)
	{
		array[i + 1] = data[i];
	}
	buildHeap();
}

template <class Type>
void priorityQueue<Type>::doubleSpace()
{
	Type* temp = array;
	maxSize *= 2;
	array = new Type[maxSize];
	for (int i = 0;i <= currentSize;i++)
		array[i] = temp[i];
	delete[]temp;
}