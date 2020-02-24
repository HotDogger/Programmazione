#include <iostream>

using namespace std;

int partition(int array[], int basso, int alto)
{
	int pivot = array[alto];
	int i = (basso - 1);
	for(int j = basso ; j <= alto-1 ; j++)
	{
		if(array[j] <= pivot)
		{
			i++;
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	int tmp = array[i+1];
	array[i+1] = array[alto];
	array[alto] = tmp;
	return (i+1);
}

void quickSort(int array[], int basso, int alto)
{
	if(basso < alto)
	{
		int pi = partition(array,basso,alto);

		quickSort(array,basso, pi - 1);
		quickSort(array,pi + 1,alto);
	}
}

void print(int array[], int n)
{
    for(int a = 0; a < n; a ++) cout << array[a] << " ";
    cout << endl;
}

int main ()
{
	int v[10] = {3,6,7,2,1,8,4,9,5,0};
	print(v,10);
	quickSort(v,0,9);
	print(v,10);
	return 0;
}
