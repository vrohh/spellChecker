// spellChecker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

bool binary_search(string words[], string word_one, unsigned int elements);

int main()
{
    ifstream dictionary;

    dictionary.open("C:/Users/smith/source/repos/CS121/Data/dictionary_four_letter_words.txt");

    if (!dictionary)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string word;
    int k = 0;
    string words[4030];
   
    while (k <= 4030 && dictionary >> word) 
    {
        words[k] = word;
        k++;
    }
    
    dictionary.close();

    cout << "Enter a four letter test word: ";
    string test_Word;

    cin >> test_Word;

	bool found = binary_search(words, word, k);


	if (found)
	{
		cout << test_Word << " is spelled correctly." << endl;
	}

	else
	{
		cout << test_Word << " is not spelled correctly. " << endl;
	}

	cout << endl;
    system("PAUSE");
}


//binary search function pulled from in class assignment
bool binary_search(string words[], string word_one, unsigned int elements)
{
	unsigned int j = 0, k = 0; // variables for the for loops
	unsigned int middle, first, last, comparisons; //variables for loops and counters
	bool found; // true or false for if word is found

	first = 0;
	last = elements;  //initializing the loop variables
	comparisons = 0;

	while (first <= last) //loop while first is less than or equal to last and found is false
	{
		middle = (first + last) / 2; // first word in array + last word in array divided by 2

		if (words[middle] == word_one) //if the middle word equals user input word
		{
			//cout << comparisons << " Comparisons were made." << endl << endl; //print number of comparisons to screen
			return true; // word was found
		} //end if

		else if (words[middle] > word_one) //if middle word is greater than user input word
		{
			last = middle - 1; //takes away words greater than middle word and middle word becomes new last
		} //end else if

		else if (words[middle] < word_one) //if middle word is less than user input word
		{
			first = middle + 1; //takes away words less than middle and middle word becomes new first
		} //end else if
		comparisons++; //increment how many times the program has to look for the word
	} //end while
	cout << comparisons << " Comparisons were made." << endl << endl; //print number of comparisons to screen
	return false;
} //end function