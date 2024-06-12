#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "myQueue1.h"
#include "myExceptions.h"

namespace myNS {
	enum commandForList
	{
		DEFAULT = -1,
		HELP = 0,
		ADD,
		EXRACT,
		DISPLAY,
		AVERAGE,
		COPY,
		UNITE,
		EXIT
	};
}
using namespace myNS;

myQueue1 uniteQueue(const myQueue1& Source1, const myQueue1& Source2) {
	myQueue1 temp;
	temp.copyQueue(Source1);
	temp.copyQueue(Source2);
	return temp;
}

int main(void) {
	myQueue1 queue;
	myQueue1 queueForCopy;
	myQueue1 UnitedQueue;
	commandForList inputCode;
	int tempValue = 0;

	printf("%d - help", HELP);

	do
	{
		inputCode = commandForList::DEFAULT;
		printf("\nInput command:\n");

		try
		{
			if (scanf("%d", &inputCode) == 0)
			{
				throw NonNumericInputException("Exception. Wrong input! Non Numeric input found.");
			};

			switch (inputCode)
			{
			case commandForList::ADD: // Adding new element in queue
				printf("Input value of new element in queue\n");
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in add option.");
				}
				queue.addElement(tempValue);
				break;
			
			case commandForList::EXRACT: // Extracting an element from queue
				printf("Input index of element in queue you want to delete\n");
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in extract option.");
				}
				printf("Extracted element: %d\n", queue.delElement(tempValue));
				break;
			
			case commandForList::DISPLAY: // Displaying all queue
				printf("Displaying queue\n");
				printf("Queue for add, del - \t");
				queue.displayQueue();

				printf("Queue for copy - \t");
				queueForCopy.displayQueue();

				printf("Queue for uniting - \t");
				UnitedQueue.displayQueue(); 
				break;
			
			case commandForList::AVERAGE: // Finding average element
				printf("Finding average element\n");
				printf("%.3f\n", queue.getAverage());
				break;
			
			case commandForList::COPY: // Creating a copy of queue
				printf("Creating a copy of queue\n");
				queueForCopy.copyQueue(queue);
				break;
			
			case commandForList::UNITE: // Uniting two queues
				printf("Uniting two queues\n");
				UnitedQueue.renewingClass();
				UnitedQueue.copyQueue(uniteQueue(queue, queueForCopy));
				break;
			
			case commandForList::EXIT: // Exiting program
				printf("Exiting program...\n");
				break;

			case commandForList::HELP: // print all available commands
				printf("%d - help\n%d - add elem\n%d - extract and delete elem\n%d - display queue\n%d - average elem\n%d - copy queue\n%d - uniting two queues\n%d - exit program\n",\
					HELP, ADD, EXRACT, DISPLAY, AVERAGE ,COPY, UNITE, EXIT);
				break;
			
			default: // Default case
				printf("Invalid command\n");
				break;
			}
		}
		catch (const NonNumericInputException& MetNonNumericExeption)
		{
			char c;
			do
			{
				c = getc(stdin);
			} while ((c != EOF) and (c != '\n'));
			printf("%s\n", MetNonNumericExeption.what());
		}
		catch (...) {
			printf("Undefined exeption cought\n");
			break;
		}

	} while (inputCode != commandForList::EXIT); // Exiting program on code EXIT 

	return 1;
}