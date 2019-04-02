#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

class coada;

class nod
{
    char date;
    nod *urmatorul;
  public:
    char caracter()
    {
        return date;
    }
    nod* next()
    {
        return urmatorul;
    }
    friend class coada;
    friend ostream & operator<<(ostream& out, coada& dt);
};
class coada
{
  nod *inceput;
  nod *sfarsit;
    public:
      coada()
        {
            inceput=NULL;
            sfarsit=NULL;
        }
      void push(char );
      void pop();
      void top();
    bool isempty()
    {
        return inceput==NULL;
    }
    friend ostream & operator<<(ostream& out,coada& dt); //supraincarcarea operatorului <<
    friend istream & operator>>(istream& in, coada& dt);
    coada operator+(coada& );
    coada operator-(coada );
    ~coada();
    friend class nod;
};

void coada::push(char c)
{
        nod *a;
        a=new nod;
        a->date = c;

        a->urmatorul=NULL;
        if(inceput==NULL)
        {
            inceput=a;
            sfarsit=a;
        }
        else
        {
           sfarsit->urmatorul=a;
           sfarsit = a;
        }
}
void coada::pop()
{
      if(sfarsit!=NULL)
      {
            nod *q=inceput;
            inceput=inceput->urmatorul;
            delete q;
            if(inceput==NULL)
                  sfarsit=NULL;

      }
      else
        {
            cout<<"Coada este goala";
        }
}
void coada::top()
{
    if(inceput!=NULL)
     {
        cout<<inceput->date<<endl;
     }
}
coada::~coada()
{
      while(sfarsit!=NULL)
      {
            nod *a=sfarsit;
            sfarsit=sfarsit->urmatorul;
            delete a;
      }
}
ostream& operator<<(ostream& out,coada& dt)
{
    while(!dt.isempty())
    {
        out<<(dt.inceput)->caracter()<<" ";
        dt.pop();
    }out<<endl;
    return out;
}

istream& operator>>(istream& in, coada& dt)
{
    int n,i;
    char c;
    in>>n;
    for(i=0;i<n;i++)
    {
        in>>c;
        dt.push(c);
    }
    return in;
}
coada coada::operator+(coada& c2)
{
    nod *n1=inceput;
    nod *n2=c2.inceput;
    coada suma;

    while(n1!=NULL)
    {
        suma.push(n1->date);
        n1 = n1->urmatorul;
    }
    while(n2!=NULL)
    {
        suma.push(n2->date);
        n2 = n2->urmatorul;
    }
    return suma;
}
coada coada::operator-(coada c2)
{
    coada dif= (*this);
    nod *n1 = dif.inceput;
    nod *n2 = c2.inceput;
    while (!dif.isempty()&&!c2.isempty()&&n1!=NULL)
    {
        if(n1->date == n2->date)
        {
             dif.pop();
             c2.pop();
             n1 = dif.inceput;
             n2 = c2.inceput;
        }
        else
        {
            n1 = n1->urmatorul;
            n2 = n2->urmatorul;
        }
    }
    return dif;
}
int display_menu()
{
 int ch;
 cout<<endl;
 cout<<"[ 1 ] Push"<<endl;
 cout<<"[ 2 ] Pop"<<endl;
 cout<<"[ 3 ] Top"<<endl;
 cout<<"[ 4 ] Operator +"<<endl;
 cout<<"[ 5 ] Operator -"<<endl;
 cout<<"[ 6 ] Exit"<<endl;
 cout<<"Enter your choice :";
 cin>>ch;
 return ch;
}

int main()
{
coada c1;
coada c2,c3;
char k;
ifstream f1;
f1.open("date.in");
f1>>c1;
f1>>c2;
//cout<<c1;
//cout<<c2;
 while(1)
 {
  switch(display_menu())
  {
    case 1:cin>>k; c1.push(k);
        break;
    case 2:c1.pop();
        break;
    case 3:c1.top();
        break;
    case 4:
        c3 = c1+c2;
        cout<<c3;
        break;
    case 5:
        c3 = c1-c2;
        cout<<c3;
        break;
    case 6: exit(1);
  }
 }
}
