#pragma once
#include <vector>

/*
Euler 22

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over 
five-thousand first names, begin by sorting it into alphabetical order. Then working out 
the alphabetical value for each name, multiply this value by its alphabetical position in 
the list to obtain a name score.
 
For example, when the list is sorted into alphabetical order, COLIN, which is worth 
3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a 
score of 938 × 53 = 49714.
 
What is the total of all the name scores in the file?
*/

struct Euler22
{
    int get_total_of_scores() const;
    
private:
    std::vector<std::string> parse_names(const std::string& file_name) const;
    int score_name(std::string name, int alpha_pos) const;
    
    const std::string& get_names_path() const
    {
        static std::string path { "names.txt" };
        return path;
    }
};
