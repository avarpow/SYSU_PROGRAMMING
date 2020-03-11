//source.h
#include <stdlib.h>
void free_lists(double *lists[])
{
    for (int i = 0; i < 20; i++)
    {
        if (lists[i] != NULL)
        {
            free(lists[i]);
        }
    }
    free(lists);
}
double **make_list(double data[], int sizes[])
{
    int nownum = 0;
    double **datas = (double **)calloc(sizeof(double *), 20);
    for (int i = 0; i < 20; i++)
    {
        if (sizes[i] != 0)
        {
            datas[i] = (double *)calloc(sizeof(double), sizes[i]);
            for (int j = 0; j < sizes[i]; j++)
            {
                datas[i][j] = data[nownum];
                nownum++;
            }
        }
    }
    return datas;
}
//alloc.c

#include <stdio.h>
//#include "source.h"

void print_list(double list[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%.3lf ", list[i]);
    putchar('\n');
}

void print_lists(double *lists[], int sizes[])
{
    for (int i = 0;; ++i)
    {
        if (lists[i] == NULL)
            break;
        print_list(lists[i], sizes[i]);
    }
}

// read a number of double data in a signle line, returns the number of data red
int read_data_line(double data[])
{
    char line[1000];
    if (fgets(line, 1000, stdin) == NULL)
        return 0;
    return sscanf(line, "%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",
                  data, data + 1, data + 2, data + 3, data + 4, data + 5, data + 6, data + 7, data + 8, data + 9);
}

int main()
{
    double data[1000];
    int num_data_per_line[20] = {0};
    int total = 0;
    for (int i = 0; i < 20; ++i)
    {
        int num_data = read_data_line(data + total);
        if (num_data <= 0)
            num_data = 0;
        total += num_data;
        num_data_per_line[i] = num_data;
        if (num_data == 0)
            break;
    }
    // TODO: allocate a list of pointers to allocated lists of doubles
    double **lists = make_list(data, num_data_per_line);
    print_lists(lists, num_data_per_line);
    free_lists(lists);
}
/*
Description
Input multiple lines of numbers from the console, please to allocate arrays of double variable to store these lines.
Then, use a pointer array to store the addresses of these double arrays.
You need to implement the two functions: double** make_list(double data[], int sizes[]) and void free_lists(double* lists[]) .

Input format
There are N lines input and each line contains no more than M double number( 1<=N<=20, 1<=M<=10).

Output format
The same numbers as input.

Example input
0.288 0.919 0.130 0.610 0.696 0.616 0.779
0.949 0.982 0.861 0.608 0.156 0.617
0.294 0.384 0.980 0.203 0.502
0.286 0.157 0.866 0.329 0.733
0.269 0.370 0.669
0.473 0.829 0.509 0.714
Example output
0.288 0.919 0.130 0.610 0.696 0.616 0.779
0.949 0.982 0.861 0.608 0.156 0.617
0.294 0.384 0.980 0.203 0.502
0.286 0.157 0.866 0.329 0.733
0.269 0.370 0.669
0.473 0.829 0.509 0.714
*/