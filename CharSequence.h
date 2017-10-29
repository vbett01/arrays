//
//  CharSequence.h
//  hw1
//
//  Created by Vincent Bett on 9/13/16.
//  Header file for Charsequence.cpp
//  Defines a class that stores a sequence of characters and holds
//  certain functions to manipulate the sequence.

#ifndef CharSequence_h
#define CharSequence_h

#include <iostream>
using namespace std;
const int CAPACITY = 1;
class CharSequence
{
        public:
                /*
                   The default constructor takes no parameters and initializes 
                  an empty sequence.
                   */
                CharSequence();
                /*
                   takes in a single character as a
                   paramter and creates a one element sequence consisting of
                   that character.
                   */
                CharSequence(char c);
                // Destructor.
                ~CharSequence();

                /*
                   function that takes no parameters and returns a
                   boolean value that is true if this specific instance of the
                   sequence class is empty and false otherwise
                   */
                bool isEmpty();

                /*
                   Function that takes no parameters and has a void
                   return type.
                   It makes the sequence into an empty sequence.
                   */
                void clear();

                /*
                   function that takes no parameters and returns an
                   integer value that is the number of characters in the
                   sequence
                   */
                int size();

                /*
                   function that takes in a pointer to a second
                   CharSequence and has a void return type. Adds a copy of the
                   sequence pointed to by the parameter value to the end of the
                   sequence the function was called from.
                   */
                void concatenate(CharSequence *ScndSqnc);

                /*
                   function that takes no parameters and returns the
                   first element (char) in the sequence.  Throws an exception of
                   the sequence is empty.
                   */
                char first();

                /*
                   function that takes no parameters and returns the last
                   element (char) in the sequence.  Throws an exception of the
                   sequence is empty.
                   */
                char last();

                /*
                   function that takes an integer index and returns
                   the element (char) in the sequence at that index.Indices are
                   0-based.  Throws an exception if index is out of range.
                   */
                char elementAt(int indx);

                /*
                   function that takes no parameters and has a void
                   return type.  It prints the sequence of characters to the
                   screen (cout).
                   */
                void print();

                /*
                   function that takes an element (char) and has a
                   void return type.  It inserts the given new element after the
                   end of the existing elements of the sequence.
                   */
                void insertAtBack(char bck);

                /*
                   function that takes an element (char) and has
                   a void return type.  It inserts the given new element in 
                   front of the existing elements of the sequence.
                   */
                void insertAtFront(char frnt);

                /*
                   function that takes an element (char) and an
                   integer index as parameters and has a void return type.  It
                   inserts the new element in at the specified index and shifts
                   the existing elements as necessary.  Throws an exception if
                   index is out of range, though it is allowed to insert at the
                   index afterthe last element.
                   */
                void insertAt(char insrt, int at);
                /*
                   function that takes no parameters and has a
                   void return type.  It removes the first element from the
                   sequence.  Throws an exception of the sequence is empty.
                   */
                void removeFromFront();

                /*
                   function that takes no parameters and has a
                   void return type.  It removes the last element from the
                   sequence.   Throws an exception if the sequence is empty.
                   */
                void removeFromBack();
                /*
                   function that takes an integer index and has a
                   void return type.  It removes the element at the specified
                   index.  Throws an exception if index is out of range.
                   */
                void removeFrom(int rmv);


                /*
                   function that takes an element (char) and an integer
                   index as parameters and has a void return type.  It replaces
                   the element at the specified index with the new element. 
                   Throws an exception if index is out of range.
                   */
                void replace(char rplc, int n);

        private:
                char *sequence;
                int capacity;
                int num_elements;
                void expand();
                // keep track of the number of elements that are added.
                void countup();
                // keept track of the subtracted elements
                void countdown();
                void check_if_full();

};


#endif /* CharSequence_h */
