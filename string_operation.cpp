#include <bits/stdc++.h>
using namespace std;
class myString{
    private:
    string str;
    public:
    myString(const string& s)
    {
        this->str=s;
    }
    int length_str() const
    {
        return str.length();
    }
    int cntcharacter() const
    {
        int no_char=0;
        for(char c:str)
        {
            if(!isspace(c))
            {
                no_char++;
            }
        }
        return no_char;
    }
    string toUpperCase()const{
        string result;
        for(char c:str)
        {
            result+=toupper(c);
        }
        return result;
    }
    string toLowerCase()const{
        string result;
        for(char c:str)
        {
            result+=tolower(c);
        }
        return result;
    }
    string reverseString()
    {
        string re=str;
        reverse(re.begin(),re.end());
        return re;
    }
};
int main(){
    string ip,op;
    cout<<"Enter the string:";
    getline(cin,ip);
    myString str1(ip);
    cout<<"Length of string:"<<str1.length_str()<<endl;
    cout<<"Number of character in string :"<<str1.cntcharacter()<<endl;
    cout<<"String in Upper case:"<<str1.toUpperCase()<<endl;
    cout<<"String in Lower case:"<<str1.toLowerCase()<<endl;
    cout<<"After reverse the string:"<<str1.reverseString()<<endl;
    return 0;
}