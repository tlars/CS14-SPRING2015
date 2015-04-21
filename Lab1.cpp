//Todd Larson
//Lab1 4/7/2015
// sid 861106862
#include <iostream>
#include <list>
using namespace std;

template <typename Type>
 list <Type> mergeList(list<Type> &first, list<Type> &second)
{
   int size= first.size()+second.size();
   list<Type> c;
   typename list<Type>:: iterator l;
   typename list<Type>:: iterator k;
   l= first.begin();
   k=second.begin();
   for(int i =0; i<size; i++)
   {
       if(i%2==0) // if the first location is even then it will be filled with the number from the first list
       {
           if(l != first.end())// if the first list has not reached the end
           {
                c.push_back(*l);
                l++;
           }
           else
           {
               c.push_back(*k);
               k++;
           }
           
       }
       else if(i%2==1)// if the location is odd, then it fills the space with the second list
       {
         if(k!= second.end())
         {
            c.push_back(*k);
            k++;
         }
         else
         {
             c.push_back(*l);
             l++;
         }
           
       }
   }
   return c;
}
template <typename Type>
list <Type> mergeSortList(list <Type> &list1, list <Type> &list2)
{
    list <Type> c = mergeList(list1, list2); // merges the two lists
    c.sort();// thens resorts it just in case
    return c;
}
template <typename Type>
list <Type> rotate(int num, list <Type> &stuff)
{
    list<Type> c= stuff;
    for(int i=0; i<num; i++)
    {
        c.push_back(c.front()); // takes the front value and puts it at the back
        c.pop_front();// gets rid the the first value
    }
    return c;
}

int main()
{
    list<string> a;
    list<string> b;
    a.push_back("sally");
    a.push_back("micheal");
    b.push_back("amanda");
    b.push_back("frank");
   // b.push_back(77);
    //b.push_back(88);
    //b.push_back(0);
    list<string> c = mergeSortList(a,b);
    c=rotate(2,c);
    list<string>:: iterator j;
    for(j=c.begin(); j != c.end();j++)
    {
        cout<< *j<<" ";
    }
    
    return 0;
}
