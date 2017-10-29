//
//  TestCharSequence.cpp
//
//  Created by Vincent Bett on 9/15/16.

/*
   This Cpp program is used to test the Charsequence class 
   to see if all the functions are accurate.
   */

#include <iostream>
#include "CharSequence.h"


// Characters to use in testing the Charsequence
// Class.
char c1 = 'V';
char c2 = 'i';
char c3 = 'n';
char c4 = 'c';
char c5 = 'e';
char c6 = 'n';
char c7 = 't';
char c8 = 'B';
char c9 = 'e';
char c10 = 't';
char c11 = ' ';

// Declare instances of the class tha t will be used for testing
CharSequence *frstnm = new CharSequence();
CharSequence *lstnm = new CharSequence();
CharSequence *Seq = new CharSequence();

// Declaration of testing functions.
void testForAddAtFront(CharSequence *Sqnc, char c );
void testForAddAtBack(CharSequence *Sqnc, char c);
void testForInsertAt(CharSequence *sqnc, char c, int n);
void testForConcatenate(CharSequence *Sqnc1, CharSequence *Sqnc2);
void testForRemoveFromBack(CharSequence *Sqnc);
void testForPrint(CharSequence *Sqnc);
void testForRemoveFromLoc(CharSequence *Sqnc, int at);
void testForReplace(CharSequence *Sqnc, char put, int at);
void testForRemoveFromFront(CharSequence *Sqnc);
void clearSqnc(CharSequence *Sqnc);
bool IfisEmpty(CharSequence *Sqnc);


int main() {

        // Test for add at front.
        testForAddAtFront(frstnm, c7);
        testForAddAtFront(frstnm, c6);
        testForAddAtFront(frstnm, c5);
        testForAddAtFront(frstnm, c3);
        testForAddAtFront(frstnm, c2);
        testForAddAtFront(frstnm, c1);

        // Test for add at back
        testForAddAtBack(lstnm, c8);
        testForAddAtBack(lstnm, c10);
        testForAddAtBack(lstnm, c10);

        // Test for insert at a particular location
        testForInsertAt(frstnm, c4, 3);
        testForInsertAt(lstnm, c9, 1);

        // Test for Print
        testForPrint(frstnm);
        testForPrint(lstnm);

        // Test for Concatenate.
        testForConcatenate(frstnm, lstnm);

        // Print.
        testForPrint(frstnm);

        // Test for remove from front.
        testForRemoveFromFront(lstnm);

        // Test clear.
        clearSqnc(lstnm);

        // Check if cleared sequence is empty.
        bool empty;
        empty = IfisEmpty(lstnm);

        if(empty)
        {
                cout<<"Sequence is empty"<< endl;
        }else
                cout<<"Sequence not empty"<<endl;

        return 0;
}


/*
Function: TestForAddAtFront.
Arguments: A CharSequence Class, A Character.
Tests if the class can correctly add a character up front.
Return Value: None, It's a void function.
*/
void testForAddAtFront(CharSequence *Sqnc, char  add )
{
        Sqnc->insertAtFront(add);
}

/*
Function: testForAddAtBack.
Arguments: A CharSequence Class, A Character.
Tests if the class can correctly add a character at the
back.
Return Value: None, It's a void function.
*/

void testForAddAtBack(CharSequence *Sqnc, char c)
{
        Sqnc->insertAtBack(c);
}

/*
Function: testForInsertAt
Arguments: A CharSequence Class, A Character, an integer.
Tests if the class can correctly add a character at a
specified location.
Return Value: None, It's a void function.
*/
void testForInsertAt(CharSequence *sqnc, char c, int n)
{
        sqnc->insertAt(c, n);
}

/*
Function:testForConcatenate
Argumnets: 2 CharSequences.
tests if the class can add a second character sequence onto 
another to make a long one.
Return Value: None.
*/
void testForConcatenate(CharSequence *Sqnc1, CharSequence *Sqnc2)
{
        Sqnc1->concatenate(Sqnc2);
}

/*
Function: testForPrint
Arguments: A CharaSequence.
Purpose: Tests if the class can print the sequence correctly.
Return value: None.
*/
void testForPrint(CharSequence *Sqnc)
{
        Sqnc->print();
}

/*
Function: testForRemoveFromBack
Arguments: A charsequence.
Purpose: tests if the class can correctly remove a 
character from the back of the sequence.
Return value: None.
*/
void testForRemoveFromBack(CharSequence *Sqnc)
{
        Sqnc->removeFromBack();
}

/*
Function: testForRemoveFromLoc
Arguments: A Charsequence, An int.
Purpose: test is the class can correctly remove an elements from
a specified location.
*/
void testForRemoveFromLoc(CharSequence *Sqnc, int at)
{
        Sqnc->removeFrom(at);
}

/*
Function: testForReplace
Arguments: A chaesequence, a char, an int.
Purpose: Test if the class can correctly replace an element at a 
specified location.
*/
void testForReplace(CharSequence *Sqnc, char put, int at)
{
        Sqnc->replace(put, at);
}

/*
Function: testForRemoveFromFront
Arguments: A charsequence
Purpose: To test if the class can correctly remove from  the front.
*/
void testForRemoveFromFront(CharSequence *Sqnc)
{
        Sqnc->removeFromFront();
}

/*
Function: clearSqnc
Arguments: A charsequence.
Purpose: Test if the class can correctly clear a sequence.
*/
void clearSqnc(CharSequence *Sqnc)
{
        Sqnc->clear();
}

/*
   Function IFisempty
Arguments: A charsequence
Returns true if a sequence is empty.
*/

bool IfisEmpty(CharSequence *Sqnc)
{
        return Sqnc->isEmpty();
}

