//============================================================================
// Name        : Fibonacci.cpp
// Author      : Nick House
// Description : Fibonnaci Sequence
//============================================================================

//Nick House Project 1 Question D


#include <iostream>

using namespace std;

void fib(int);

int main()
{
    //Define user input variable
    int n=0;

    //Prompt user for input
    cout<< "Enter the nth term you would like to know from "
    "the fibonacci sequence. (Enter a value of 2 or greater.)" << endl;

    //User input validation
    while(!(cin >> n) || n<2)
    {

        cout<< "The requested term must be 2 or greater, please"
        " try again."<< endl;
        cin.clear();
        cin.ignore(123, '\n');

        //cin >> n;
    }

    //Call Fibonacci Function
    fib(n);

    return 0;
}

//Fibonacci Function
void fib(int n)
{
    //create arrays for sequence
    int array1[100], array2[100], array3[100];

    //Set all elements within arrays to 0
    for(int i=0; i<100; i++)
    {
        array1[i]=0;
        array2[i]=0;
        array3[i]=0;
    }

    //Set array2's last element to 1
    array2[99]=1;

    //For loop to run i to n iterations of Fibonacci Sequence
    for(int i = 1; i<n; i++)
    {
        int carry = 0, temp = 0;

        //Array addition loops
        for(int j=99; j>=0; j--)
        {

            //If/Else - Set Carry and Array Addition
            if(array2[j]+array1[j]+carry > 9)
            {
                temp = array2[j]+array1[j]+carry-10;
                carry = 1;
            }
            else
            {
                temp = array2[j]+array1[j]+carry;
                carry = 0;
            }

            //Set Arrays equal to previous
            array3[j]=temp;
            array1[j]=array2[j];
            array2[j]=array3[j];

            //Error Message, Show error that the Fibonacci
            //number has reached 100 or more digits, display
            //Fibonacci number with 99 digits.
            if(array3[0]!=0)
            {
                cout << "ERROR: The number of terms requested "
                "has 100 digits or more. " << endl;
                cout<< "\nThe biggest Fibonacci number with "
                "less than 100 digits is " << endl;

                cout << "F(" << i << "): ";

                for(int k = 1; k<100; k++)
                {
                    cout<< array1[k];

                    if(k<99 && k%3==0)
                    {
                        cout<<",";
                    }
                }

                exit (1);
            }
        }
    }


    //How Many Displayed Places
    int Display=0;

    //Linear Search to find appropriate number of
    //digits to be displayed
    for(int i=0 ; i < 100; i++)
    {
        if(array3[i]!=0)
        {
            Display = i;
            break;
        }
    }


    //Display Fibonacci number with terms
    cout << "\nF(" << n << ") is ";

    for(int i = Display; i<100; i++)
    {
        cout<< array3[i];

        if(i<99 && i%3==0)
        {
            cout<<",";
        }
    }
}

