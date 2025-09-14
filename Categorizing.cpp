#include<iostream>
using namespace std;

// Error function handler
void ThrowValueExceptionError(int expected, int actual){
    cout << "The value you have entered (" << actual;
    if (expected < actual)
        cout << ") is too big. It must be at most" << expected << endl;
    else cout << ") is too small. It must be at least (" << expected << ")" << endl;

}

class ArrayManager{
    static void merge(int arr[], int low, int mid, int high){
        int index = 0;
        int temp[high + 1];
        int 
            left = low,
            right = mid + 1;

        while (left <= mid && right <= high)
            if (arr[left] < arr[right])
                temp[index++] = arr[left++];
            else 
                temp[index++] = arr[right++];

        while (left <= mid)
            temp[index++] = arr[left++];

        while (right <= high)
            temp[index++] = arr[right++];
        
        for (int i = low; i <= high; ++i)
            arr[i] = temp[i - low];
    }

    public:
        static void printArray(string message, const int arr[], int n){
            cout << message;
            for (int i = 0; i < n; ++i)
                cout << arr[i] << " ";
        }

        static void printArray(const int arr[], int n){ // function overloading "printArray"
            for (int i = 0; i < n; ++i)
                cout << arr[i] << " ";
        }

        static void selectionSort(int arr[], int size){
            for (int i = 0; i < size; ++i){
                int smallestDataIndex = size - 1;
                for (int j = size - 1; j >= i; --j)
                    if (arr[j] < arr[smallestDataIndex])
                        smallestDataIndex = j;

                int data = arr[smallestDataIndex];
                if (arr[i] > arr[smallestDataIndex]){
                    arr[smallestDataIndex] = arr[i];
                    arr[i] = data;
                }
            }
        }

        static void mergeSort(int arr[], int low, int high){
            int mid = (low + high) / 2;
            if (low >= high) return;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }

        static int linearSearch(int searchKey, int arr[], int size){
            for (int i = 0; i < size; ++i)
                if (searchKey == arr[i])
                    return i;
            return -1;
        }

        static int binarySearch(int searchKey, int arr[], int size){
            int first = 0;
            int last = size - 1;
            
            while (first <= last){
                int mid = (first + last) / 2;
                int value = arr[mid];
                if (searchKey == value) return mid;
                if (searchKey < value) last = mid - 1;
                else first = mid + 1;
            }
            return -1;
        }
};

int main(){
    int choice, size, value;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    do {
        cout << endl;
        cout << "### Array Management System ###" << endl;
        cout << "1. Manage Array Data" << endl;
        cout << "2. Sort Array" << endl;
        cout << "3. Search for key in Array" << endl;
        cout << "4. Print array" << endl;
        cout << "5. Fetch the value from the index" << endl;
        cout << "0. Exit System" << endl;
        cout << "Your Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice){
            case 0:
                cout << "Exiting System, Thank you for using it" << endl;
                break;

            case 1: {
                    cout << "Choose how you want to manage data:" << endl;
                    cout << "    1. Add Data from first to last" << endl;
                    cout << "    2. Update data from specific index" << endl;
                    cout << "    0. Return Back" << endl;
                    cout << "    Your choice: ";
                    cin >> choice;
                    cout << endl;

                    switch (choice){
                        case 0: break;
                        case 1:
                            cout << "Adding data from 0 to " << size - 1 << endl;
                            for (int i = 0; i < size; ++i){
                                cout << "Enter element for array of " << i << " index: ";
                                cin >> arr[i];
                            }
                            cout << endl;
                            ArrayManager::printArray("Added data in the array, now: ", arr, size);
                            cout << endl;
                            break;

                        case 2:
                            cout << endl << "Enter index value: ";
                            cin >> value;
                            if (value >= size)
                                ThrowValueExceptionError(size - 1, value);
                            else{
                                cout << "Enter new element data: ";
                                cin >> arr[value];
                                cout << "Changed value of the array in index " << value << ", ";
                                ArrayManager::printArray("now: ", arr, size);
                                cout << endl;
                            }
                            break;

                        default:
                            cout << "Invalid choice ... Exiting without managing data" << endl;
                    }
                    choice = -1;
                }
                break;

            case 2:
                cout << "Sorting Algorithm options:" << endl;
                cout << "    1. Merge Sort" << endl;
                cout << "    2. Selection Sort" << endl;
                cout << "    0. Return Back" << endl;
                cout << "    Your choice: ";
                cin >> choice;
                cout << endl;
                switch (choice){
                    case 0: break;
                    case 1:
                        ArrayManager::printArray("original Array: ", arr, size);
                        cout << endl;
                        ArrayManager::mergeSort(arr, 0, size - 1);
                        ArrayManager::printArray("Sorted Array: ", arr, size);
                        cout << endl;
                        break;

                    case 2:
                        ArrayManager::printArray("original Array: ", arr, size);
                        cout << endl;
                        ArrayManager::selectionSort(arr, size);
                        ArrayManager::printArray("Sorted Array: ", arr, size);
                        cout << endl;
                        break;

                    default:
                        cout << "Invalid choice ... Exiting without managing data" << endl;
                }

                choice = -1;
                break;

            case 3:
                cout << "Searching Algorithm options:" << endl;
                cout << "    1. Binary Search" << endl;
                cout << "    2. Linear Search" << endl;
                cout << "    0. Return Back" << endl;
                cout << "    Your choice: ";
                cin >> choice;
                cout << endl;

                cout << "Enter key to search: ";
                cin >> value;

                switch (choice){
                    case 0: break;

                    case 1:
                        cout << value;
                        value = ArrayManager::binarySearch(value, arr, size);
                        if (value == -1)
                            cout << " was not found" << endl;
                        else 
                            cout  << " was found at index " << value << endl;
                        cout << endl;
                        break;

                    case 2:
                        cout << value;
                        value = ArrayManager::linearSearch(value, arr, size);
                        if (value == -1)
                            cout << " was not found" << endl;
                        else 
                            cout << " was found at index " << value << endl;
                        cout << endl;
                        break;
                    default:
                        cout << "Invalid choice ... Exiting without managing data" << endl;
                }
                choice = -1;
                break;

            case 4:
                cout << "There are " << size << " elements in the array:" << endl;
                ArrayManager::printArray(arr, size);
                cout << endl;
                break;

            case 5:
                cout << "Enter the index of the array: ";
                cin >> value;
                if (value >= size)
                    ThrowValueExceptionError(size - 1, value);
                else 
                    cout << "Value at index " << value << " is " << arr[value] << endl;
                break;
            default:
                cout << "Invalid choice ... try again" << endl;
        }
    } while (choice != 0);
    return 0;
}