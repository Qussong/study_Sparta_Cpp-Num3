
#include <iostream>

template<typename T> //	typename == class 
class SimpleVector
{
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	SimpleVector();
	SimpleVector(int capacity);
	~SimpleVector();

public:
	void push_back(const T& value);
	void pop_back();
	int size();
	int capacity();
};

int main()
{
	SimpleVector<int> simpleVec;

	std::cout << "case 1)\n";
	std::cout << "Capacity : " << simpleVec.capacity() << "\n";
	std::cout << "Size : " << simpleVec.size() << "\n";

	std::cout << "\ncase 2)\n";
	simpleVec.push_back(1);
	simpleVec.push_back(2);
	simpleVec.push_back(3);
	std::cout << "Capacity : " << simpleVec.capacity() << "\n";
	std::cout << "Size : " << simpleVec.size() << "\n";

	std::cout << "\ncase 3)\n";
	simpleVec.pop_back();
	std::cout << "Capacity : " << simpleVec.capacity() << "\n";
	std::cout << "Size : " << simpleVec.size() << "\n";
}

template<typename T>
SimpleVector<T>::SimpleVector()
{
	currentCapacity = 10;
	data = new T[currentCapacity];
	if (nullptr != data)
	{
		currentSize = 0;
		std::cout << "\n[simpleVector Created Successfully]\n";
	}
}

template<typename T>
SimpleVector<T>::SimpleVector(int capacity)
	: currentCapacity(capacity)
{
	data = new T;
	if (nullptr != data)
	{
		currentSize = 0;
		std::cout << "\n[simpleVector Created Successfully]\n";
	}
}

template<typename T>
SimpleVector<T>::~SimpleVector()
{
	if (nullptr != data)
	{
		delete[] data;
		currentSize = 0;
		currentCapacity = 0;

		std::cout << "\n[simpleVector Deleted Successfully]\n";
	}
}

template<typename T>
void SimpleVector<T>::push_back(const T& value)
{
	bool bIsCapacity = currentCapacity > currentSize;
	if (false == bIsCapacity) return;

	data[currentSize] = value;
	++currentSize;
}

template<typename T>
void SimpleVector<T>::pop_back()
{
	bool bIsExist = currentSize > 0;
	if (false == bIsExist) return;

	--currentSize;
}

template<typename T>
int SimpleVector<T>::size()
{
	return currentSize;
}

template<typename T>
int SimpleVector<T>::capacity()
{
	return currentCapacity;
}
