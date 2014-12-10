#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  int numItems;
  std::pair<Pri, T>* backingArray;

  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};

#include <string>

template<class Pri, class T>
Heap<Pri, T>::Heap(){
	numItems = 0;
	arrSize = START_SIZE;
	backingArray = new std::pair<Pri, T>[START_SIZE];
}

template<class Pri, class T>
Heap<Pri, T>::~Heap(){
	delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri, T>::grow(){
	arrSize = arrSize * 2;
	std::pair<Pri, T>* tempArray = new std::pair<Pri, T>[arrSize];

	for (int i = 0; i < numItems; i++) {
		tempArray[i] = backingArray[i];
	}

	backingArray = tempArray;
	delete[] tempArray;
}

template<class Pri, class T>
void Heap<Pri, T>::add(std::pair<Pri, T> toAdd){
	if (numItems == arrSize) {
		grow();
	}

	backingArray[numItems] = toAdd;
	bubbleUp(numItems);
	numItems++;
}

template<class Pri, class T>
void Heap<Pri, T>::bubbleUp(unsigned long index){
	if (index <= 0) {
		return;
	}

	int parentNum = (index - 1) / 2;

	if (backingArray[parentNum].first > backingArray[index].first) {
		backingArray[parentNum].swap(backingArray[index]);
		bubbleUp(parentNum);
	}
}

template<class Pri, class T>
void Heap<Pri, T>::trickleDown(unsigned long index){
	bool swapped;
	unsigned long int rightChild;
	unsigned long int leftChild;
	do{
		swapped = false;
		rightChild = (2 * index) + 2;
		leftChild = (2 * index) + 1;

		if (rightChild < numItems && backingArray[index].first > backingArray[rightChild].first){
			if (backingArray[leftChild].first < backingArray[rightChild].first){
				swap(backingArray[index], backingArray[leftChild]);
				index = leftChild;
				swapped = true;
			}
			else{
				swap(backingArray[index], backingArray[rightChild]);
				index = rightChild;
				swapped = true;
			}
		}
		else{
			if (leftChild < numItems && backingArray[index].first > backingArray[leftChild].first){
				swap(backingArray[index], backingArray[leftChild]);
				index = leftChild;
				swapped = true;
			}
			else{
				swapped = true;
			}
		}
	} while (swapped == false);
}

template<class Pri, class T>
std::pair<Pri, T> Heap<Pri, T>::remove(){
	if (numItems == 0) {
		throw std::string("In remove(), tried to remove from an empty array.");
	}

	std::pair<Pri, T> temp = backingArray[0];
	backingArray[0] = backingArray[(numItems - 1)];
	numItems--;
	trickleDown(0);

	return temp;
}

template<class Pri, class T>
unsigned long Heap<Pri, T>::getNumItems(){
	return numItems;
}
