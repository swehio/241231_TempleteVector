#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

 
template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize = 0;
	int currentCapacity = 0;
	void resize(int newCapacity) {
		currentCapacity = newCapacity <= currentCapacity ? currentCapacity : newCapacity;
	};

public:

	SimpleVector() {
		currentCapacity = 10;
		data = new T[currentCapacity];
	}
	SimpleVector(const SimpleVector& other) {
		data = other.data;
		currentSize = other.currentCapacity;
		currentCapacity = other.currentCapacity;
	}
	SimpleVector(int capacity) : currentCapacity(capacity) {
		data = new T[currentCapacity];
	}

	void push_back(const T& value) {
		if (currentSize >= currentCapacity) {
			resize(currentCapacity+5);

			SimpleVector tempVec(*this);
			data = new T[currentCapacity];
			for (int i = 0; i < tempVec.currentSize; ++i) {
				data[i] = tempVec.data[i];
			}
		}
		if (currentSize < currentCapacity)
		{
			data[currentSize] = value; //레퍼런스는 주소값을 받아오니까 * 안 붙임
			++currentSize;
		}

	}
	void pop_back() {
		if(currentSize > 0) 
			--currentSize;
	}

	int size() {
		return currentSize;
	}

	int capacity() {
		return currentCapacity;
	}

	void sortData() {
		sort(data, data+currentSize);
	}

	void printData() {
		for (int i = 0; i < currentSize; i++) {
			cout << data[i] <<endl;
		}
	}

	~SimpleVector() {
		delete[] data;
	}
};

int main() {
	srand(time(NULL));
	SimpleVector<int> myvec;
	for (int i = 0; i < 13; i++) {
		myvec.push_back(i+rand()%50);
	}
	for (int i = 0; i < 5; i++) {
		myvec.pop_back();
	}

	myvec.printData();
	myvec.sortData();
	myvec.printData();

	cout << myvec.size() << myvec.capacity();


	return 0;
}