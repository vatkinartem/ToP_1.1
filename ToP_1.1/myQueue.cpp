#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <myQueue.h>

myQueue::myQueue()
{
	this->size = 0;
	// mem allocation for our 1 lenght Queue and making it zero
	this->Queue = NULL;
	this->Queue = (Dlist*)calloc(1, sizeof(Dlist));
	if (this->Queue == NULL)
	{
		printf("Failed to allocate memory for first element\n");
	}
}

myQueue::~myQueue()
{
	Dlist* temp = NULL;
	// freeing Queue list
	do {
		temp = this->Queue;
		this->Queue = this->Queue->ptr;
		free(temp);
	} while (this->Queue != NULL);
}

void myQueue::renewingClass() {
	// Copy of destructor
	Dlist* temp = NULL;
	// freeing Queue list
	do {
		temp = this->Queue;
		this->Queue = this->Queue->ptr;
		free(temp);
	} while (this->Queue != NULL);

	// Copy of constructor
	this->size = 0;
	// mem allocation for our 1 lenght Queue and making it zero
	this->Queue = NULL;
	this->Queue = (Dlist*)calloc(1, sizeof(Dlist));
	if (this->Queue == NULL)
	{
		printf("Failed to allocate memory for first element\n");
	}
}

const int myQueue::delElement(int index) {

	if ((index >= this->size) || (index < 0))	// checking if out of range
	{
		printf("Wrong index. Index was bigger then size of queue OR lesser then 0\n");
		return 0;
	}
	if (this->size == 0)	// checking if queue is empty
	{
		printf("Nothing to delete\n");
		return 0;
	}

	Dlist* pList = this->Queue;		// ptr on cur element
	Dlist* temp = NULL;				// element that will be deleted
	int tempValue = 0;

	if (index == 0) // 0 case is exeption (bc of how the rest of cases work)
	{
		temp = pList;				// remebering adress of needed-to-delete element
		tempValue = temp->value;	// remembering value of element
		pList = temp->ptr;			// (removing needed-to-delete element from chain)
		this->Queue = pList;		// replacing genesis block
	}
	else
	{
		for (int i = 0; i < index - 1; i++)	// reaching element before needed one
		{
			pList = pList->ptr;
		}
		temp = pList->ptr;			// remebering adress of needed-to-delete element
		tempValue = temp->value;	// remembering value of element
		pList->ptr = temp->ptr;		// (removing needed-to-delete element from chain)
	};

	free(temp);					// deleting found element
	this->size--;
	return tempValue;
}

void myQueue::addElement(int valueX)
{
	this->size++;
	Dlist* temp = (Dlist*)calloc(1, sizeof(Dlist));		// creating ptr for temp new element
	if (temp == NULL)
	{
		printf("Failed to allocate memory for 1 element in func addElement\n");
		return;
	}
	temp->value = valueX;
	temp->ptr = this->Queue;
	this->Queue = temp;
}

void myQueue::displayQueue()
{
	Dlist* pList = this->Queue;
	for (int i = 0; i < this->size; i++)
	{
		printf("%d ", pList->value);
		pList = pList->ptr;
	}
	printf("\n");
}

void myQueue::copyQueue(const myQueue& Source) {

	if (Source.size == 0) // checking if source is empty
	{
		return;
	}

	int* temp = (int*)calloc(Source.size, sizeof(int)); // allocating mem for 1 big blob of source values
	Dlist* pList = Source.Queue;						// ptr on Source Queue

	for (int i = 0; i < Source.size; i++)		// setting blob with all "values" of source elements
	{
		*(temp + i) = pList->value;
		pList = pList->ptr;
	}

	for (int i = Source.size - 1; i >= 0; i--)		// reverse transporting from blob to this queue
	{
		this->addElement(*(temp + i));
	}
	free(temp);
}

int myQueue::getSize() {
	return this->size;
}

Dlist* myQueue::getQueue() {
	return this->Queue;
}