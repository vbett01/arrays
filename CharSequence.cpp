//
//  CharSequence.cpp
//  hw1
//
//  Created by Vincent Bett on 9/13/16.
//  cpp file that contains the implementation of the function headers declared 
//  in CharSequence.h

#include "CharSequence.h"

/*
   The default constructor takes no parameters and initializes an
   empty sequence.
   */


CharSequence::CharSequence()
{
        num_elements = 0;
        capacity = CAPACITY;
        sequence  = new char[capacity];
        sequence[0] = '\0';

}

/*
   takes in a single character as a
   paramter and creates a one element sequence consisting of
   that character.
   */

CharSequence::CharSequence(char c)
{
        num_elements = 1;
        capacity = CAPACITY;
        sequence = new char[capacity];
        sequence[0] = c;
        //sequence[capacity] = '\0';
}

// Destructor.

CharSequence::~CharSequence()
{
        delete[] sequence;
}

/*
   function that takes no parameters and returns a
   boolean value that is true if this specific instance of the
   sequence class is empty and false otherwise
   */

bool CharSequence::isEmpty()
{
        if(num_elements ==0)
        {
                return true;
        }
        else 
                return false;
        //return num_elements = 0; // Not sure about this.
}

/*
   Function that takes no parameters and has a void
   return type.
   It makes the sequence into an empty sequence.
   */

void CharSequence::clear()
{
        for(int i = 0; i < num_elements; i++)
        {
                sequence[i] = '\0';
        }
        num_elements = 0;

}

/*
   function that takes no parameters and returns an
   integer value that is the number of characters in the sequence
   */

int CharSequence::size()
{
        return num_elements;
}

/*
   function that takes in a pointer to a second
   CharSequence and has a void return type.  It adds a copy of the
   sequence pointed to by the parameter value to the end of the
   sequence the function was called from.
   */

void CharSequence::concatenate(CharSequence *ScndS)
{
        int size  = ScndS->size();

        for (int i = 0; i < size; i++)
        {
                insertAtBack(ScndS->elementAt(i));

        }

}

/*
   function that takes no parameters and returns the
   first element (char) in the sequence.  Throws an exception of
   the sequence is empty.
   */

char CharSequence::first()
{
        if (num_elements == 0) // sequence[0] == ' '
        {
                throw "sequence is empty";
        }
        else
                return sequence[0];
}

/*
   function that takes no parameters and returns the last
   element (char) in the sequence.  Throws an exception of the
   sequence is empty.
   */

char CharSequence::last()
{
        if(num_elements == 0)
        {
                throw "sequence is empty";
        }
        else
                return sequence[num_elements-1];
}

/*
   function that takes an integer index and returns
   the element (char) in the sequence at that index.  Indices are
   0-based.  Throws an exception if index is out of range.
   */

char CharSequence::elementAt(int indx)
{
        if (indx > num_elements - 1)
        {
                throw "index out of range";
        }
        else
                return sequence[indx];
}

/*
   function that takes no parameters and has a void
   return type.  It prints the sequence of characters to the
   screen (cout).
   */

void CharSequence::print()
{
        cout<<"[CharSequence of size " << num_elements;
        cout<<" <<";
        for(int i = 0; i<num_elements; i++)
        {
                if(sequence[i] != '\0')
                {
                        cout<<sequence[i];
                }
        }
        cout<< ">>]";


}

// keep track of the number of elements that are added.
void CharSequence::countup()
{
        num_elements++;
}

// keept track of the number of elements that have been subtracted
void CharSequence::countdown()
{
        num_elements--;
}

/*
   function that takes an element (char) and has a
   void return type.  It inserts the given new element after the end
   of the existing elements of the sequence.
   */

void CharSequence::insertAtBack(char bck)
{
        check_if_full();
        sequence[num_elements] = bck;
        countup();
}

// Function to expand if the sequence is full.

void CharSequence::expand()
{
        char *newArray;
        newArray = new char[capacity*2];
        for(int i = 0; i<capacity; i++)
        {
                newArray[i] = sequence[i];
        }
        delete[] sequence;
        sequence = newArray;
        capacity*=2;
}

/*
   function that takes an element (char) and has
   a void return type.  It inserts the given new element in front
   of the existing elements of the sequence.
   */

void CharSequence::insertAtFront(char frnt)
{
        check_if_full();

        for(int i = num_elements; i>0; i--)
        {
                sequence[i] = sequence[i-1];
        }
        sequence[0] = frnt;
        countup();
}


/*
   function that takes an element (char) and an
   integer index as parameters and has a void return type.  It
   inserts the new element in at the specified index and shifts the
   existing elements as necessary.  Throws an exception if index is
   out of range, though it is allowed to insert at the index after
   the last element.
   */

void CharSequence::insertAt(char insrt, int at)
{
        check_if_full();
        if( at > num_elements)
        {
                throw out_of_range( " Index is out of range");
        }
        for(int i = num_elements+1; i> at; i--)
        {
                sequence[i] = sequence[i-1];

        }
        sequence[at] = insrt;
        countup();

}

/*
   function that takes no parameters and has a
   void return type.  It removes the first element from the
   sequence.  Throws an exception if the sequence is empty.
   */

void CharSequence::removeFromFront()
{
        if(num_elements == 0)
        {
                throw string("The sequence is empty");
        }

        for(int i = num_elements - 1; i>0; i--)
        {
                sequence[i - 1] = sequence[i];
        }
        sequence[num_elements - 1] = ' ';
        countdown();
}

/*
   function that takes no parameters and has a
   void return type.  It removes the last element from the
   sequence.   Throws an exception if the sequence is empty.
   */

void CharSequence::removeFromBack()
{
        if(num_elements == 0)
        {
                throw out_of_range( " Index is out of range");
        }
        sequence[num_elements - 1] = ' ';
        countdown();
}

/*
   function that takes an integer index and has a
   void return type.  It removes the element at the specified
   index.  Throws an exception if index is out of range.
   */

void CharSequence::removeFrom(int rmv)
{
        if( rmv > num_elements - 1)
        {
                throw out_of_range( " Index is out of range");
        }

        for(int i = rmv; i<num_elements - 1; i++)
        {
                sequence[i] = sequence[i + 1];
        }
        sequence[num_elements - 1] = '\0 ';
        countdown();

}

/*
   function that takes an element (char) and an integer
   index as parameters and has a void return type.  It replaces the
   element at the specified index with the new element.  Throws an
   exception if index is out of range.
   */

void CharSequence::replace(char rplc, int n)
{
        if (n > num_elements - 1)
        {
                throw out_of_range( " Index is out of range");
        }
        sequence[n] = rplc;
}

// Function to check if the sequence is full;
void CharSequence::check_if_full()
{
        if(capacity == num_elements)
        {
                expand();
        }
}


