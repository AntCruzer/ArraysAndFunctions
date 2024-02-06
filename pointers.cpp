// INCLUDES
#include <iostream>
#include <string>


// RESOURCES
using namespace std;



// DISABLE WARNINGS
#pragma warning(disable: 4996)



// FUNCTION PROTOTYPES
bool getDouble(double *pNumber);
void calculateStats(double d1, double d2, double d3, double d4, double *pAverage, double *pSum);
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage);
void fillArray(double values[], int numArray, int fillValue);


// ARRAY SIZE
int main ()
{
    cout << "----- BEGINNING OF STATS TESTS -----" << endl;

    // VARIABLES
    double var1, var2, var3, var4;
    double avg, sum;
    bool status = true;
    
    // PROMPT FOR AND OBTAIN VALUES
    cout << "Enter a number: ";
    status = getDouble(&var1);
    if (!status)
    {
        cout << "Invalid double provided.";
        return 1;
    }

    cout << "Enter another number: ";
    status = getDouble(&var2);
    if (!status)
    {
        cout << "Invalid double provided.";
        return 1;
    }

    cout << "Enter another number: ";
    status = getDouble(&var3);
    if (!status)
    {
        cout << "Invalid double provided.";
        return 1;
    }

    cout << "Enter another number: ";
    status = getDouble(&var4);
    if (!status)
    {
        cout << "Invalid double provided.";
        return 1;
    }

    calculateStats(var1, var2, var3, var4, &avg, &sum);

    // DISPLAY RESULTS
    cout << "Average: " << avg << endl;
    cout << "Sum: " << sum << endl;
    cout << "----- END OF STATS TESTS -----" << endl;


    cout << "----- BEGINNING OF ARRAY STATS TESTS -----" << endl;
    // ARRAY TESTS
    double array[7] = {};

    for (int i = 0; i < 7; ++i )
    {
        if (i == ( 7 - 1 ) )
        {
            cout << "Enter one more value: ";
            status = getDouble(&array[i]);
            if (!status)
            {
                cout << "Invalid double provided.";
                return 1;
            }
        }
        else
        {
            cout << "Enter a value: ";
            status = getDouble(&array[i]);
            if (!status)
            {
                cout << "Invalid double provided.";
                return 1;
            }
        }
    }

    size_t arraySize = sizeof(array) / sizeof(array[0]);

    calculateArrayStats(array, arraySize, &sum, &avg);
    
    cout << "Average: " << avg << endl;
    cout << "Sum: " << sum << endl;

    fillArray(array, arraySize, 40);

    cout << "Here are all the elements in the array modified..." << endl;

    for (int i = 0; i < arraySize; ++i)
    {
        if (i == arraySize - 1)
        {
            cout << array[i] << "." << endl;
        }
        else
        {
            cout << array[i] << ", ";
        }
    }
    
    cout << "----- END OF STATS TESTS -----" << endl;
    return 0;
}



/*
    Function:       getDouble()
    Parameter:      double *pNumber: pointer to a variable that is
                    filled in by the user input, if valid
    Return Value:   bool: 'true' if the user entered a valid floating-
                    point number, 'false' otherwise
    Description:    This function gets a floating-point number
                    from the user. If the user enters a valid 
                    floating-point number, the value is put into the 
                    variable pointed to by the parameter and 1 is returned. 
                    If the user-entered value is not valid, 0 is returned.
*/
bool getDouble(double *pNumber)
{
    bool isValid = true;                    // to be returned
    char record[121] = {0};                 // string is stored in this character array

	// use fgets() to get a string from the keyboard input
	fgets(record, sizeof(record), stdin);
        
    // Use sscanf to extract number from the string
	// sscanf() returns a number corresponding with the number of items 
    // it found in the string
	if( sscanf(record, "%lf", pNumber) != 1 )
	{
		isValid = false;                    
        cout << "Invalid number provided (getDouble)" << endl;
	}
	return isValid;
}



/*
    Function:       calculateStats()
    Parameters:     double d1, d2, d3, d4: 
                        four floating-point numbers
                    double *pAverage: 
                        pointer to a variable that is filled in 
                        by this function with the average of 
                        d1, d2, d3, and d4
                    double *pSum: 
                        pointer to a variable that is filled in by 
                        this function with the sum of d1, d2, d3, and d4
    Return Value:   none
    Description:    This function takes four floating-point numbers 
                    passed as doubles and calculates the average and
                    sum of the numbers. Once calculated, the average 
                    gets put into the variable pointed to by the 
                    pAverage parameter and the sum gets put into the 
                    variable pointed to by the pSum parameter.
*/
void calculateStats(double d1, double d2, double d3, double d4, double *pAverage, double *pSum)
{    
    // calculate sum
    *pSum = d1 + d2 + d3 + d4;
    // calculate average 
    *pAverage = *pSum / 4.0;
}



/*
    Function:       calculateArrayStats()
    Parameters:     double values[]: 
                        floating-point numbers
                    int numArray: 
                        number of array elements
                    double *pSum: 
                        pointer to a variable that is
                        filled in by this function with the sum of all elements in
                        the array
                    double *pAverage: 
                        pointer to a variable that
                        is filled in by this function with the average of all
                        elements in the array
    Return Value:   none
    Description:    This function takes an array of floating-point
                    (double) numbers, given the number of elements in the array
                    as a parameter, and calculates the average and sum of the
                    numbers. Once calculated, the average gets put into the
                    variable pointed to by the pAverage parameter and the sum
                    gets put into the variable pointed to by the pSum
                    parameter.
*/
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage)
{
    // sum calculation
    for (int i = 0; i < numArray; ++i) 
    {
        *pSum += values[i];
    }

    // avg calc
    *pAverage = *pSum / numArray;
}



/*
    Function:       fillArray()
    Parameters:     double values[]: floating-point numbers
                    int numArray: number of array elements
                    double fillValue: value to put into array
                    elements
    Return Value:   none
    Description:    This function takes an array of floating-point
                    (double) numbers, given the number of elements in the array
                    as a parameter, and puts the fillValue into each element of
                    the array.
*/
void fillArray(double values[], int numArray, int fillValue)
{
    for (int i = 0; i < numArray; ++i)
    {
        values[i] = fillValue;
    }
}