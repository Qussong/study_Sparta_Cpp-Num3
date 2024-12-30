
#include <iostream>
#include <algorithm>

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

	SimpleVector(const SimpleVector& other);

public:
	void push_back(const T& value);
	void pop_back();
	int size();
	int capacity();

	void resize(int newCapacity);
	void sortData();

public:
	SimpleVector<T>& operator==(const SimpleVector& other)
	{
		// �ڱ� ���� ����
		if (this == other) return *this;
		// ���� �����̳� ����
		delete[] data;
		// size, capacity ũ�� ����
		currentSize = other.currentSize;
		currentCapacity = other.currentCapacity;
		// ���ο� �����̳� ����
		data = new T[currentCapacity];
		// �� ����
		for (int i = 0; i < currentSize; i++)
		{
			data[i] = other.data[i];
		}

		return *this;
	}
};

int main()
{
	SimpleVector<int> simpleVec;
	simpleVec.push_back(1);
	simpleVec.push_back(2);
	simpleVec.push_back(3);

	// ���������
	SimpleVector<int> simpleVec2(simpleVec);

	// push_back
	for (int i = 0; i < 8; i++)
	{
		simpleVec2.push_back(i);
	}
	std::cout << simpleVec2.capacity() << std::endl;
	std::cout << simpleVec2.size() << std::endl;

	// resize
	simpleVec2.resize(16);
	std::cout << simpleVec2.capacity() << std::endl;
	std::cout << simpleVec2.size() << std::endl;

	// sortData
	simpleVec2.sortData();

	// ���� ������
	SimpleVector<int> simpleVec3 = simpleVec2;
	std::cout << simpleVec2.capacity() << std::endl;
	std::cout << simpleVec2.size() << std::endl;

	return 0;
}

template<typename T>
SimpleVector<T>::SimpleVector()
{
	currentCapacity = 10;
	data = new T[currentCapacity];
	if (nullptr != data)
	{
		currentSize = 0;
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
	}
}

template<typename T>
void SimpleVector<T>::push_back(const T& value)
{
	bool bIsCapacity = currentCapacity > currentSize;
	if (false == bIsCapacity)
	{
		// capacity ���� (+5)
		currentCapacity += 5;
		// �ӽ� �����̳� ����
		T* tempData = new T[currentCapacity];
		// �� ����
		for (int i = 0; i < currentSize; i++)
		{
			tempData[i] = data[i];
		}
		// ���� �����̳� ����
		delete[] data;
		// �����̳� ����
		data = tempData;
	}

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

template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& other)
{
	currentSize = other.currentSize;
	currentCapacity = other.currentCapacity;
	data = new T[currentCapacity];

	if (nullptr != data)
	{
		for (int i = 0; i < currentSize; i++)
		{
			data[i] = other.data[i];
		}
	}
}

template<typename T>
void SimpleVector<T>::resize(int newCapacity)
{
	// ���Ҵ� ���� �Ǻ�
	bool bResize = newCapacity > currentCapacity;
	if (false == bResize) return;
	// �ӽ� �����̳� ����
	T* newData = new T[newCapacity];
	// �� ����
	for (int i = 0; i < currentSize; i++)
	{
		newData[i] = data[i];
	}
	// ���� �����̳� ����
	delete[] data;
	// capacity ����
	currentCapacity = newCapacity;
	// �����̳� ����
	data = newData;
}

template<typename T>
void SimpleVector<T>::sortData()
{
	if (currentSize > 1)
	{
		std::sort(data, &data[currentSize]);
	}
}
