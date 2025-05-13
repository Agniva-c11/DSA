#include<iostream>
#include<string>
using namespace std;
void reverse_sentence(string& words)
{
    int start = 0;
    int end = words.length()-1;
    while(start<=end)
    {
        swap(words[start], words[end]);
        start++;
        end--;
    }
}
void reverse_words_in_sentence(string& words)
{
    reverse_sentence(words);
    int n = words.length();
    int start = 0;
    for(int i = 0;i<=n;i++)
    {
        if(i==n || words[i]==' ')
        {
            int end = i-1;
            while(start<end)
            {
                swap(words[start], words[end]);
                start++;
                end--;
            }
            start = i+1;
        }
    }

}
int main()
{
    string words;
    cout<<"Enter words:";
    getline(cin, words);

    reverse_words_in_sentence(words);

    cout<<words;
    cout<<endl;


}