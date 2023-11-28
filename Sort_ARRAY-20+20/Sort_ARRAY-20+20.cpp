////В функцию передаётся массив случайных
//чисел в диапазоне от - 20 до + 20. Необходимо найти позиции крайних отрицательных элементов(самого левого
//	отрицательного элемента и самого правого отрицательного элемента) и отсортировать элементы, находящиеся
//	между ними.
#include <iostream>
using namespace std;
const int Size = 40;

void Print_Array(int arr[]);
void Fill_Array(int arr[]);
void Sort_Array(int arr[]);


int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int Ar_sort[Size] = {};
	Fill_Array(Ar_sort);
	Print_Array(Ar_sort);
	Sort_Array(Ar_sort);
	Print_Array(Ar_sort);
	
}



void Sort_Array(int arr[])
{
	int leftNeg=0, rightNeg=0;
	for (int i = 0; i < Size; i++)
	{
		if (arr[i]<0)
		{
			rightNeg = i;
		}
	}
	for (int i = Size-1	; i>=0; i--)
	{
		if (arr[i] < 0)
		{
			leftNeg= i;
		}
	}
	cout << rightNeg<< " 2 \n" << leftNeg  << " 1 \n" << endl;

	for (int i =0 ; i < Size; i++)
	{
		for (int j = leftNeg; j < rightNeg-1; j++)
		{
			for (int n = j+1; n < rightNeg-1; n++)
			{
				if (arr[n]>arr[n+1])
				{
					swap(arr[n], arr[n + 1]);
				}
			}
			
		}
	}

}


void Fill_Array(int arr[])
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = 20 - rand() % 40;
	}
}

void Print_Array(int arr[])
{
	for (int i = 0; i < Size; i++)
	{
		cout << "[" << i + 1 << "]\t" << arr[i] << "\n ";
	}
	cout << endl;
}


