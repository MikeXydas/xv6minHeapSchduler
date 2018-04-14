#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"
#include "traps.h"
#include "spinlock.h"

#include "minHeap.h"

//A static array which contains the RUNNABLE procs
struct proc * heapOfProcs[64];


void initialiseMinHeap()
{
	for(int i = 0; i < 64; i++)
		heapOfProcs[i] = 0;
}


//USED FOR DEBUGGING
void printHeap()
{
	cprintf("Printing heap:\n");
	for(int i = 0; i < returnSizeOfMinHeapArray(); i++)
	{
		double dPrio = heapOfProcs[i]->priority;
		int prio = (int) (dPrio * 100000);
		cprintf("Pid: %d username: %s, Prio: %d\n", heapOfProcs[i]->pid,heapOfProcs[i]->name, prio);
	}
}


//Used if we inserted a new node
//Finds the correct place for the inserted node
void refreshMinHeapInsert()
{
	int currentSize = returnSizeOfMinHeapArray();

	if(currentSize > 1)
	{
		//Parent of the last inserted node
		int start = (currentSize - 1)/ 2;
		while(1)
		{
			int left = start * 2 + 1;
			int right = start * 2 + 2;
			int minNode = start;
			//if left child exists, compare with parent
			if(left < currentSize)
			{
                                if(heapOfProcs[left]->priority ==1)
                                        heapOfProcs[left]->priority = 0.5;
                                if(heapOfProcs[start]->priority == 1)
                                        heapOfProcs[start]->priority = 0.5;
				//On a tie the the newly inserted node does not climb the heap
				if(heapOfProcs[left]->priority < heapOfProcs[start]->priority)
					minNode = left;
			}

			//if right child exists, compare with min between left child and parent
			if(right < currentSize)
			{
                                if(heapOfProcs[right]->priority ==1)
                                        heapOfProcs[right]->priority = 0.5;

				if(heapOfProcs[right]->priority < heapOfProcs[minNode]->priority)
					minNode = right;
			}

			if(minNode != start)
			{
				struct proc * temp = heapOfProcs[start];
				heapOfProcs[start] = heapOfProcs[minNode];
				heapOfProcs[minNode] = temp;
				start = (start - 1)/2;

				if(start < 0)
					break;
				continue;
			}
			break;
		}	
	}
	return;
}


//Used if the root node was extracted
//Placing the new root in the correct place

//Similar with refreshMinHeapInsert() but we now start from the top (root) and move downwards
//This time the ties are won from lower children since the new root used to be the last node

void refreshMinHeapPop()
{
	int currentSize = returnSizeOfMinHeapArray();
	int start = 0;
	while(1)
	{
		int left = start * 2 + 1;
		int right = start * 2 + 2;
		int minNode = start;
        	
		if(left < currentSize)        	
		{
			if(heapOfProcs[left]->priority >=1)
                		heapOfProcs[left]->priority = 0.5;
                	if(heapOfProcs[start]->priority >= 1)
                		heapOfProcs[start]->priority = 0.5;
                	if(heapOfProcs[left]->priority <= heapOfProcs[start]->priority)
                 	       minNode = left;
		}
		if(right < currentSize)
		{
			if(heapOfProcs[right]-> priority == 1)
				heapOfProcs[right]->priority = 0.5;
			if(heapOfProcs[right]->priority <= heapOfProcs[minNode]->priority)
				minNode = right;
		}
		if(minNode != start)
		{
			struct proc * temp = heapOfProcs[start];
			heapOfProcs[start] = heapOfProcs[minNode];
			heapOfProcs[minNode] = temp;
			start = minNode;
			continue;
		}
		break;
	}	
	return;
}




//Returns the size of the array
int returnSizeOfMinHeapArray()
{
	int size = 0;
	for(size = 0; size < 64; size++)
		if(heapOfProcs[size] == 0)
			return size;
	return 64;	//maximum number of procs is reached
} 
