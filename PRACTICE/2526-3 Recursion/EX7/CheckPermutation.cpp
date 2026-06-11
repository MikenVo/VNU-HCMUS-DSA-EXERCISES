#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool recursiveSlide(int right_index, vector<int> &count1, vector<int> &count2, const string &s2, int window_size)
{

    if (count1 == count2)
    {
        return true;
    }

    if (right_index == s2.size())
    {
        return false;
    }

    count2[s2[right_index] - 'a']++;

    int left_index = right_index - window_size;
    count2[s2[left_index] - 'a']--;

    return recursiveSlide(right_index + 1, count1, count2, s2, window_size);
}

bool checkInclusion(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;

    vector<int> count1(26, 0);
    vector<int> count2(26, 0);
    int window_size = s1.size();

    for (int i = 0; i < window_size; i++)
    {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    return recursiveSlide(window_size, count1, count2, s2, window_size);
}