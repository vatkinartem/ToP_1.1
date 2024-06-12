#pragma once

typedef struct mydList
{
	int value;
	mydList* ptr;// Pointer to pevious element
} Dlist;

class myQueue
{
public:

	myQueue();
	~myQueue();
	void renewingClass();
	const int delElement(int index);
	void addElement(int valueX);
	void displayQueue();
	void copyQueue(const myQueue& Source);
	int getSize();

protected:
	Dlist* getQueue();

private:
	Dlist* Queue;
	int size;
};