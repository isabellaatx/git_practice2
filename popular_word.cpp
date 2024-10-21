#include <iostream>

using namespace std;

void mostPopularWord(string words[], const int WORDS_SIZE)
{
    string word = "";
    int frequency = 0;
    for(int i = 0; i < WORDS_SIZE; i++)
    {
        int temp = 0;
        for(int j = 0; j < WORDS_SIZE; j++)
        {
            if(words[i] == words[j])
            {
                temp++;
            }
        }
        if(temp >= frequency)
        {
            word = words[i];
            frequency = temp;
        }
    }

    cout << "The most popular word: " << word << endl;
    cout << "Frequency: " << frequency << endl;
    cout << "Found at pos: ";
    for(int i = 0; i < WORDS_SIZE + 1; i++)
    {
        if(word == words[i])
        {
            cout << i << " "; 
        }
    }
}

int main()
{
    const int WORDS_SIZE = 5;
    string words[WORDS_SIZE] = {"apple", "corn", "corn", "apple", "lettuce"};
    mostPopularWord(words, WORDS_SIZE);
    return 0;
}
