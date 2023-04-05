#include <iostream>
#include<vector>
using namespace std;

vector<int> lps(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);
    int j = 0;
    // whatever pi[i] will store will be 1-based indexing
    // while... 0 means no match with prefix
    // if pi[i]=> 1 then it matches with first character
    // hence will will do pi[j-1]-> since we are actually
    // 0-indexed
    for (int i = 1; i < n; i++)
    {
        j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
void findPattern(string p, string s)
{

    int j = -1, i = 0, n = s.size(), m = p.size(),flag=1;
    vector<int> pi = lps(p);
    // since pi table is 1-based index...
    // hence j=-1
    //  compare s[i]=p[j+1]
    // if not match... i want my prefix upto p[j] save
    // in string it is.. therefore check pi[j]
    // I will go one step back because... pi is one based indexing
    for (int i = 0; i < n; i++)
    {

        while (j >= 0 && s[i] != p[j + 1])
        {

            j = pi[j] - 1;
        }
        if (s[i] == p[j + 1])
        {
            j++;
        }

        if (j == m - 1){
            cout<<"Pattern found at: "<<i-m+1<<" shifts"<<endl;
            flag=0;
        }
    }

    if(flag)
        cout<<"No patter found"<<endl;
    return;
}
int main()
{

    cout << "\n------------String Matching - KMP Algorithm--------------------\n\n";

    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern: ";
    cin >> pattern;

    findPattern(pattern,text);

    return 0;
}