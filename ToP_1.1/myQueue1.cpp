#include <myQueue1.h>
#include <stdlib.h>

double myQueue1::getAverage() {
	Dlist* pList = this->getQueue();
	double average = 0.0;	// Average value of Queue
	int sum = 0;			// The sum of elements

	while (pList != NULL)
	{
		sum += pList->value;
		pList = pList->ptr;
	}
	average = (1.0) * sum / this->getSize();
	return average;
}