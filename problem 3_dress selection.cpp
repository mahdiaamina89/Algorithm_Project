#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define S 21

int i,o,j,k=0,p,p1=1, choose ,used[80],temp[10],not_available[10],not_a,E,count=0,f1,f2,f3,f4;
double temparature;

char* dress[S]={'\0',"blue_jeans","black_jeans","brown_pants","black_pants",
    "blue_shirt","red_shirt","sweatshirt","sweater",
    "sandals","shoes","sneakers","boots",
    "white_socks","black_socks","orange_socks","wool_socks",
    "shorts","t_shirt","belt","jacket"};

int hot[4]={17,18,13,9}; // list of clothes for hot weather
int warm[9]={3,4,5,6,19,14,15,10,11}; // list of clothes for warm weather
int cold[7]={1,2,7,8,20,16,12}; // list of clothes for cold weather

void put_on(int cloth);
int is_dirty(int cloth);
int is_missing(int cloth);

void printC(int temp[], int p, int not_available[], int not_a);

int main()
{
    do
    {
        cout << "Enter temperature in Celsius: ";
        cin >> temparature;

        if(temparature >= 40)
        {
            not_a = 0;
            p = 0;

            cout << "It's hot out " << endl;
            cout << "Choose Your dress from the given list: " << endl;

            for(i=0; i<4; i++)
            {
                printf("%d. %s  ", i+1, dress[hot[i]]);
            }
            cout << endl;
            cout << "Enter -1 if done." <<endl;
            do
            {
                scanf("%d", &choose);
                if(choose == -1)
                {
                    break;
                }
                if(choose < 0 || choose > 4)
                {
                    cout << "WRONG!!!!" << endl;
                }
                else
                {
                    put_on(hot[choose - 1]);
                }
            }

            while(1);

        }


        if(temparature >= 26 && temparature <= 39)
        {
            not_a = 0;
            p=0;

            cout << "It's warm out " << endl;
            cout << "Choose Your dress from the given list: " << endl;

            for(i=0; i<9; i++)
            {
                printf("%d. %s  ",i+1,dress[warm[i]]);
            }

            cout << endl;
            cout << "Enter -1 if done." <<endl;

            do
            {
                scanf("%d", &choose);
                if(choose == -1)
                {
                    break;
                }
                if(choose < 0 || choose > 9)
                {
                    cout << "WRONG!!!!" << endl;
                }
                else
                {
                    put_on(warm[choose - 1]);
                }
            }
            while(1);
        }

        if(temparature < 0 || (temparature >= 0 && temparature <= 25))
        {
            not_a = 0;
            p = 0;

            cout << "It's cold out " << endl;
            cout << "Choose Your dress from the given list: " << endl;

            for(i=0;i<7;i++)
            {
                printf("%d. %s  ", i+1, dress[cold[i]]);
            }

            cout << endl;
            cout << "Enter -1 if done." << endl;

            do
            {
                scanf("%d", &choose);
                if(choose == -1)
                {
                    break;
                }
                if(choose < 0 || choose > 7)
                {
                    cout << "WRONG!!!!" << endl;
                }
                else
                {
                    put_on(cold[choose - 1]);
                }
            }
            while(1);
        }

        printC(temp,p,not_available,not_a);

        cout << "1. Exit 2. Not Exit" << endl;

        scanf("%d",&E);

       // d++;

        /*if(d>7)
        {
            d=1;
            week++;
        } */

        f1=0;
        f2=0;
        f3=0;
        f4=0;

    }

    while(E!=1);

    return 0;
}
void put_on(int cloth)
{
    //checking my chosen cloth dirty or missing

    if(is_dirty(cloth)==1 || is_missing(cloth)==1)
    {
        not_available[not_a] = cloth;
        not_a++;
    }
    else
    {
        used[k] = cloth;
        k++;
        temp[p] = cloth;
        p++;
    }
}
int is_dirty(int cloth)
{
    count = 0;
    for(p1=0;used[p1]!=0;p1++)
    {
        if(used[p1] == cloth)
        {
            count++;
        }
    }
    if(count>=3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_missing(int cloth)
{
    for(p1=0; used[p1]!=0; p1++)
    {
        if(cloth>S)
        {
            return 1;
        }
    }
    return 0;
}
void printC(int temp[], int p, int not_available[], int not_a)
{
    if(p == 0)
    {
        cout << "No cloth is available" << endl;
    }
    else
    {
        cout << "Available dresses are: " << endl;

        for(p1 = 0; p1 < p; p1++)
        {
            if((f1==0) && (temp[p1]==1 || temp[p1]==2 || temp[p1]==3 || temp[p1]==4))
            {
                cout << dress[temp[p1]] << endl;
                f1 = 1;
            }
            if((f2==0) && (temp[p1]==5 || temp[p1]==6))
            {
                cout << dress[temp[p1]] << endl;
                f2 = 1;
            }
            if((f3==0) && (temp[p1]==9 || temp[p1]==10 || temp[p1]==11 || temp[p1]==12))
            {
                cout << dress[temp[p1]] << endl;
                f3 = 1;
            }
            if((f4==0) && (temp[p1]==13 || temp[p1]==14 || temp[p1]==15 || temp[p1]==16))
            {
                cout << dress[temp[p1]];
                f4 = 1;
            }
            if(temp[p1]==7 || temp[p1]==8 || temp[p1]==17 || temp[p1]==18 || temp[p1]==19 || temp[p1]==20)
            {
                cout << dress[temp[p1]];
            }
        }
        cout << endl;
    }
    if(not_a>0)
    {
        cout << "Unavailable dresses are: " << endl;

        for(p1=0; p1<not_a; p1++)
        {
            cout << dress[not_available[p1]] << endl;
        }
        cout << endl;
    }
}
