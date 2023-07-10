#include <iostream>
using namespace std;
void bubbleSort(int array[], int size)
{
  for (int step = 0; step < size; ++step)
  {
    for (int i = 0; i < size - step; ++i)
     {
      if (array[i] > array[i + 1])
       {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
void printArray(int array[], int size) {
  for (int i = 1; i <= size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
int main()
 {
    int arr[5], i, elem;
    cout<<"Enter 5 Array Elements: ";
    for(i=0; i<5; i++)
        cin>>arr[i];
    cout<<"\nThe New Array is:\n";
    for(i=0; i<5; i++)
        cout<<arr[i]<<"  ";
  //int data[] = {-2, 45, 0, 11, -9};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);

  cout << "\nSorted Array in Ascending Order:\n";
  printArray(arr, size);
}
