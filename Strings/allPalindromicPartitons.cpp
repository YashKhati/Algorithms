#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string str)
{
    int n = str.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void getPartitons(string str, vector<string> &temp, vector<vector<string>> &ans, int index)
{
    if (index == str.size())
    {
        ans.push_back(temp);
        return;
    }

    string tempStr;
    for (int i = index; i < str.size(); i++)
    {
        tempStr.push_back(str[i]);

        if (checkPalindrome(tempStr))
        {
            temp.push_back(tempStr);
            getPartitons(str, temp, ans, index + 1);
            temp.pop_back();
        }
    }
}
int main()
{
    string str;
    cout << "Enter String : ";
    getline(cin, str);

    vector<vector<string>> ans;
    vector<string> temp;
    getPartitons(str, temp, ans, 0);

    for (auto element : ans)
    {
        for (auto itr : element)
        {
            cout << itr << " ";
        }
        cout << "\n";
    }
}