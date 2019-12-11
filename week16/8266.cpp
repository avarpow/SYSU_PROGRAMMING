/*
Description
Write a sort function that uses the bubble-sort algorithm. The bubble-sort algorithm makes several passes through the array. On each pass, successive neighboring pairs are compared. If a pair is in decreasing order, its values are swapped; otherwise, the values remain unchanged. The technique is called a bubble sort or sinking sort because the smaller values gradually "bubble" their way to the top and the larger values sink to the bottom.

void bubbleSort(double list[], int size)
Hint
You should submit the implementation of the function but do not submit the main() function.

Problem Source: 程序设计I Chapter6 Arrays
*/
void bubbleSort(double arr[], int n){
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(arr[j]>arr[j+1]){double t=arr[j];arr[j]=arr[j+1];arr[j+1]=t;}
        }
    }
}
