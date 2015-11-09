import sys
import random
def select_pivot(array):
	lowerIndex=0;
	midIndex=len(array)-1)/2
	upperIndex=len(array)-1
	pList = [array[lowerIndex], array[midIndex], array[upperIndex]]
	
	for indexI in range(2):
		for indexJ in range(indexI+1, 3):
			if(pList[indexI]>pList[indexJ]):
				temp = pList[indexI]
				pList[indexI] = pList[indexJ]
				pList[indexJ] = temp
	return pList[1]



def quick_sort(array):
	left=[]
	right=[]
	if len(array)<=2:
		return array.sort()
	pivot=select_pivot(array)
	array.remove(pivot)
	for item in array:
		if item<pivot:
			left.append(item)
		if item>pivot:
			right.append(item)
	
	return quick_sort(left)+[pivot]+quick_sort(right)
	
files=open(sys.argv[1])
array=[]
for line in files:
	array.append(int(line))

print quick_sort(array)