#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int N, i, j, temp, temp1, Length = 0, len, a, b;
    int  X[1000], H[1000];

    cout << "Number of trees in a row: ";
    cin >> N;

    cout << "Co-ordinate X and Height: "<<endl;

    for(i = 0; i<N; i++)
    {
        cin >> X[i] >>  H[i];

    }

    //activity selection

    for(i=1; i<N; i++)
    {
        temp = H[i];
        temp1 = X[i];

        for(j = i-1; j >= 0 && temp <H[j] ; j--)
        {
            H[j+1] = H[j];
            X[j+1] = X[j];
        }
        H[j+1] = temp;
        X[j+1] = temp1;
    }

    //condition apply

    for(a=0, b=1, i=0; i<N-1; i++)
    {
        if((a < b) && ((H[b] - H[a]) < (X[b] - X[a])))
        {
            len = (pow((X[b]-X[a]),2) + pow((H[b]-H[a]),2));

            if(len > Length) // increase length if calculated length is greater
            {
                Length = len;
            }
            a = b; //if come from first tree to any tree
            b++; //i will increase position b because i am going to the next tree to check
        }

        else
        {
            b++; //if condition is not fulfilled position of a is same but b is changed
            //checking going to the next tree is possible or not
        }
    }

    if(a == N - 1) //after checking every tree any tree is left or not
    {
        cout << "Length: " << Length << endl;
    }
    else // if all given conditions are not applied
    {
        cout << "-1\n" << endl;
    }


    return 0;

}

