 ///
 /// @file    lookup.cpp
 /// @author  ray(zsy466178965@gmail.com)
 /// @date    2020-01-14 15:32:29
 ///
#include "lookup.h"



void Lookup::read(string filename)
{
    ifstream ifs(filename);
    if(!ifs.good()) 
    {
        cerr<<"Wrong file name!"<<endl;
        return ;// To wait for improvement
    }
    string line;
    int num = 0;
    while(getline(ifs, line))
    {
        lines.push_back(line);
       // cout<<"line: "<<line<<endl;
        read_word(num,line);
        ++num;
    }
    ifs.close();
}

void Lookup:: read_word(int num, const string & line) 
{
    string word;
    istringstream iss(line);
    while(iss >> word)  //if add "! iss.eof()" as condition
                        //it will skip the last word
    {
      //  cout<<"word: "<<word<<endl;
        word = wash(word);
      //  cout<<"washed word: "<<word <<endl;
        if(word == string(" ")) continue; 
        ++dict[word];
        wordNumbers[word].insert(num);
        //cout<<"times: "<< dict[word]<<endl;
    }
}

void Lookup:: query(const string & word)
{
    if (dict.find(word) == dict.end())
    {
        cout << word << " dosen't occur. " <<endl;
        return ;
    }
    cout<<"--------------------------------------------" << endl;
    cout << word << " occurs " << dict[word] 
         << " times."<<endl;
    for(auto it = wordNumbers[word].begin(); it != wordNumbers[word].end(); ++it)//!!! use != instead of <
        cout << "\t(line "<< *it <<") "
             << lines[*it] << endl;
    cout<<"--------------------------------------------" << endl;
}
string wash(string word)
{
    int head_pos = 0,   // To record the new start 
        tail_count = 0; // To record #nonalpha in the end 
    int len = word.size();
    // check index no matter what !!!
    while(head_pos < len && !isalpha(word.at(head_pos))) 
    {++head_pos;} 
    while((len - 1 -tail_count) > 0 && !isalpha(word.at(len - 1 - tail_count)))
    {++tail_count;}
    len = word.size() - head_pos - tail_count;
    //cout<<"head:" <<head_pos << " tail: "<<tail_count <<endl;
    if (len == 0) return string(" "); // To avoid sth. like " & " or " 12 " 
    string rslt = word.substr(head_pos, len);
    transform(rslt.begin(), rslt.end(), rslt.begin(), tolower);
    //cout<<"substr: " << rslt <<endl; 
    return rslt;
}


