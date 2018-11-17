/**
Course:  CS213 - Programming II  - 2018
Title:   Assignment III - Task 2 - Problem 9
Program: CS213-2018-A3-T2-P9
Purpose: prints the substring of any English word in a correct order chars.
Authors: 1- Name :- Nada Nasser Al-Said El-Azab .................. ID :- 20170369
Date:    10 November 2018
Version: 2.0
*/
//________________________________________________________________________
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

string Embedded(string word);
string EmbeddedWords(string tempWord , string word);
string toUpper(string str);
bool isExist(string word);


int indx = -1; // its a start point ( - 1 + 1 )in the string

//----------------------------------------------------
int main()
{
    string word ;
    cin >> word;

    cout << Embedded(word);

    return 0;
}
//----------------------------------------------------
// This function prints the substring of the word .. and then send it to the Embedded function
// to resize a new sub.strings of the original to find its sub.s
string EmbeddedWords(string tempWord , string word) // word does not change here.. Temp word does
{
    if(tempWord.size() <= 0){ // return the original word to embedded function.

        return Embedded(word);
    }

    if(isExist(toUpper(tempWord)))
        cout <<"Founded  " <<tempWord << endl; // print sub of the word...
    else
        cout << "UNfounded  " <<tempWord << endl;
    return EmbeddedWords(tempWord.substr(0 , tempWord.size()-1) ,word); // return the sub word without the last letter...
}
//----------------------------------------------------
// it send the word that we are going to print its subs to the EmbeddedWords
string Embedded(string word)
{
    indx++; // start at 0;
    if(indx > word.size()-1) // stop the code when the word is finished
        exit(1);

    EmbeddedWords(word.substr(indx) , word); // send the word without the first # indx.s
}
//----------------------------------------------------
// To check if the printed word is an English word or not
bool isExist(string word){

    ifstream wordsFile;
    wordsFile.open("words.txt" , ios::in); // The dictionary of all English Words

    while(!wordsFile.eof() && !wordsFile.fail()){
        string tempWord ;
        wordsFile >> tempWord ;
        tempWord = toUpper(tempWord);
        if(word == tempWord){
            return 1;
        }
    }
    return 0;
}
//----------------------------------------------------
// Convert the string to uppercase letters
string toUpper(string str){
    for(int i = 0 ;i < str.size() ; i++)
        str[i] = toupper(str[i]);
    return str;
}
