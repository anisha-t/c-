#include<iostream>
#include<string>
using namespace std;
int main()
{   /*Input Output of the string*/
    
    string str;
    cin>>str;
    cout<<str<<endl;
    
    /*Normal declaration */
    string stri ="Apple";
    cout<<stri<<endl;

   /*Declares a string of size 5 with all characters ‘N’.*/
   string str_1(5,'n');
   cout<<str_1<<endl;

   /*Concate function using append()*/
   string str1 ="fam";
   string str2 ="ily";
   str1.append(str2);
   cout<<str1<<endl;
   
   /*Concate function using (+) operator*/
    string str1_ ="fam";
    string str2_ ="ily";
    cout<<str1_+str2_<<endl;

    /*Input the whole sentence*/
    string str3;
    getline(cin,str);
    cout<<str<<endl;
    
    /*Acessing a character in string*/
    cout<<str1_[2];

    /*How to clear a string*/
    string ab="ssasasaddfgfghjkjhftrethg"
    abc.clear();
    cout<<abc<<endl;

    /*Comparing 2 strings*/
    string s1 = "abc";
    string s2 ="xyz";
    cout<<s2.compare(s1)<<endl;

    /*Will return a bool value that is if the string is empty it will be true i.e 1 or else 0*/
    if (s1.empty())
    {
        cout<<"s1 is empty "<<endl;
    }
    else
    {
        cout<<"s1 is not empty"<<endl;
    }
    
    
    /*Deletes a substring of the string. Its time complexity is O(N)*/
    string s ="nincompoop";
    s.erase(3,3);/*First argument is the start index from which it will delete till 3 character*/
    cout<<s<<endl;

    /*Searches the string and returns the first occurrence of the parameter in the string..*/
    cout<<s.find("poop")<<endl;
    
    /*Inserts additional characters into the string at a particular position.*/
    string a = "Anisha";
    a.insert(2,"lol");
    cout<<a<<endl;

    /*Returns the length of the string.*/
    cout<<s.length()<<endl;

    /*Returns a string which is the copy of the substring.*/
     cout<<a.substr(2,4);
    
    /*Returns the strings converted to int datatype.*/
    string b ="786";
    int x =stoi(b);
    cout<<x+2<<endl;

    /*To convert an integer to a string, we use to_string() function.*/
    int c = 88;
    cout<<to_string(c) + "2"<<endl;
        return 0;

}