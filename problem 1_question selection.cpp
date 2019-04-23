#include <iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

void mergeSort(int [], int, int, int, int);
void merging(int [],int, int, int);

int main()
{
    int N, Q,  qi, i;
    int *T, *S, *qa; //using as array
    int time = 0;
    int temp;

    cout << "Number of Questions & Queries: " << endl;
    cin >> N >> Q;

    /* Allocate space(memory) for an array with given number of elements of type
   int. */
    qa = (int*)malloc(sizeof(int)*Q);//allocate space for qa array with Q number of elements of type int
    T = (int*)malloc(sizeof(int)*N);//allocate space for T array with N number of elements of type int
    S = (int*)malloc(sizeof(int)*N);//allocate space for S array with N number of elements of type int

    cout << "Time for each questions: " << endl;
    for(i=0; i<N; i++)
    {
        scanf("%d", T+i); //Time of each question+question number
    }

    cout << "Score for each questions: " << endl;
    for(i=0;i<N;i++)
    {
       scanf("%d", S+i); //Score of each question+question number
    }


    cout << "How many question for each query: " << endl;

    for(qi=0; qi<Q; qi++) //loop will contain until Q(queries)
    {
        scanf("%d", qa+qi); //Number of question she wants to solve
    }

    merging(T, 0, N - 1, N);
    merging(S, 0, N - 1, N);

    //after merge
    cout << "Total time required :" << endl;
    for(qi=0;qi<Q;qi++) //loop will continue until how many question (queries) she wants to solve
    {
        temp = qa[qi]; //temp variable will contain 1st query number..2nd query number...

        for(i=0; i<temp; i++)
        {
            time = time + T[N-i-1];

        }
        cout << time << endl;
        time = 0;
    }
  return 0;
}

void merging(int data[], int low, int high, int n)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;
        merging(data, low, mid, n);
        merging(data, mid + 1, high, n);
        mergeSort(data, low, mid, high, n);
    }
}
void mergeSort(int data[],int low,int mid,int high,int n)
{
    int i, mi, k, lo, temp[n];

    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (data[lo] <= data[mi])
        {
            temp[i] = data[lo];
            lo++;
        }
        else
        {
            temp[i] = data[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = data[k];
            i++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
             temp[i] = data[k];
             i++;
        }
    }

    for (k = low; k <= high; k++)
    {
        data[k] = temp[k];
    }
}
