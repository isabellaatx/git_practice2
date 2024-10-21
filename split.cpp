#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    bool found_separator = false;
    int temp_index = 0;
    int arr_count = 0;
    int index = 0;
    int placeholder = 0;
    if((int)input_string.length() == 0)
    {
        return 0;
    }
    for(int i = 0; i < (int)input_string.length(); i++)
    {
        if(input_string[i] == separator)
        {
            arr_count++;
            if(arr_count >= ARR_SIZE)
            { 
                placeholder = i - temp_index;
                arr[index] = input_string.substr(temp_index, placeholder);
                return -1;
            }
            placeholder = i - temp_index;
            arr[index] = input_string.substr(temp_index, placeholder);
            index++;
            temp_index = i + 1;
            found_separator = true;
        }
    }
    if(found_separator == true)
    {
        arr[index] = input_string.substr(temp_index, (int)input_string.length() - temp_index);
        index++;
    }
    if(!found_separator)
    {
        arr[0] = input_string;
        return 1;
    }
    return index;
}

void printArray(string arr[], const int NUM_ELEMENTS)
{
    for (int i=0; i < NUM_ELEMENTS; i++)
    {
        cout << "arr["<< i << "]:" << arr[i] << endl;
    }
}

int main()
{
    string testcase = "Bangkok,Berlin,Birmingham,Bogota,Busan,Baton Rouge,Beaumont,Boise,Budapest";
    char separator = ',';
    const int ARR_SIZE = 5;
    string arr[ARR_SIZE];
    int num_splits = split(testcase, separator, arr, ARR_SIZE);
    cout << "Function returned value: " << num_splits << endl;
    printArray(arr, ARR_SIZE);
}