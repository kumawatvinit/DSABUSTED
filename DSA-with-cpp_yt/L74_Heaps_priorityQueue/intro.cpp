/*
// O(logn)
        void insert(int val)
// O(logn)
        void deletefromHeap()       
// O(logn)
void heapify(int *arr, int n, int i)
// O(nlogn)
void heapsort(int *arr, int n)

Build heap -> O(n)
*/

#include<iostream>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;
        
        heap()
        {
            arr[0] = -1;
            size=0;
        }

        // O(logn)
        void insert(int val)
        {
            size = size+1;
            int index = size;
            arr[index] = val;

            while(index>1)
            {
                int parent = index/2;
                
                if(arr[parent] < arr[index])
                {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else
                {
                    return;
                }
            }
        }

        void print() {
            for(int i=1; i<=size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        // O(logn)
        void deletefromHeap()
        {
            if(size==0)
            {
                cout << "Nothing to delete" << endl;
                return;
            }
            
            // Put last element into first index
            arr[1] = arr[size];
            
            // Removes last element
            size--;

            int i=1;
            // TAke root node to its correct position
            while(i<size)
            {
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;

                /*
                if(leftIndex<size && arr[i]<arr[leftIndex])
                {
                    swap(arr[leftIndex], arr[i]);
                    i = leftIndex;
                }
                else if(rightIndex<size && arr[i]<arr[rightIndex])
                {
                    swap(arr[rightIndex], arr[i]);
                    i = rightIndex;
                }
                */
                if(leftIndex<size && rightIndex<size)
                {
                    if(arr[leftIndex]>arr[rightIndex] && arr[i]<arr[leftIndex]) {
                        swap(arr[leftIndex], arr[i]);
                        i = leftIndex;
                    }
                    else if(arr[leftIndex]<arr[rightIndex] && arr[i]<arr[rightIndex]) {
                        swap(arr[rightIndex], arr[i]);
                        i = rightIndex;
                    }
                }
                else if(leftIndex<size && arr[i]<arr[leftIndex]) {
                    swap(arr[leftIndex], arr[i]);
                    i = leftIndex;
                }
                else {
                    return;
                }
            }
        }
};

// O(logn)
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[left]>arr[largest])
    {
        largest = left;
    }
    if(right<=n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest!=i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// O(nlogn)
void heapsort(int *arr, int n)
{
    int size=n;
    
    while(size>1)
    {
        swap(arr[1], arr[size]);
        size--;

        heapify(arr,size,1);
    }
}

int main()
{
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletefromHeap();
    h.print();

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n=5;
    for(int i=n/2; i>0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "\nprinting the array now " << endl;
    for(int i=1; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;


    heapsort(arr,n);
    for(int i=0; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}