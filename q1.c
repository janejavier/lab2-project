#include <stdio.h>
#include <stdbool.h>

#define SIZE 24
#define nRows 8
#define nCols 3

void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void set_array(int arr[], int length);
void rem_align(int arr[], int length, int pos);
void insert_align(int arr[], int length, int pos, int value);
void reshape(int arr[], int length, int arr2d[nRows][nCols]);
void print_trans_matrix(int arr2d[nRows][nCols]);
bool found_duplicate(int arr[], int length);
void flip_array(int arr[], int length, int flippedArray[]);

int main()
{
    int arr[SIZE];
    int arr2d[nRows][nCols];
    int flippedArray[SIZE];

    printf("Bullet point 1\n");
    set_array(arr, SIZE);//1
    print_array(arr, SIZE);

    printf("Bullet point 2\n");
    rem_align(arr, SIZE, 3);//2
    print_array(arr, SIZE);

    printf("Bullet point 3\n");
    insert_align(arr, SIZE, 2, 80);//3
    print_array(arr, SIZE);

    printf("Bullet point 4\n");
    reshape(arr, SIZE, arr2d);//4
    print_matrix(arr2d, nRows);

    printf("Bullet point 5\n");
    print_trans_matrix(arr2d);//5

    printf("Bullet point 6\n");
    bool hasDuplicate = found_duplicate(arr, SIZE);//6
    printf("duplicate found: %s\n", hasDuplicate ? "true" : "false");

    printf("Bullet point 7\n");
    flip_array(arr, SIZE, flippedArray);//7
    printf("flipped array: ");
    print_array(flippedArray, SIZE);

    return 0;
}

void print_array(int array[], int length){
    for(int i = 0; i < length; i++)
        printf("array[%d] = %d\n", i, array[i]);
    printf("\n");
}

void print_matrix(int mat[][nCols], int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < nCols; j++)
            printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);
        puts("");
    }
}

void set_array(int arr[], int length){
    for(int i = 0; i < length; i++){
        arr[i] = i;
    }
}

void rem_align(int arr[], int length, int pos){
    if(pos < 0 || pos >= length){
        printf("Invalid position\n");
        return;
    }

    for(int i = pos; i < length - 1; i++){
        arr[i] = arr[i + 1];
    }

    arr[length - 1] = 0;
}

void insert_align(int arr[], int length, int pos, int value){
    if(pos < 0 || pos >= length){
        printf("Invalid position\n");
        return;
    }

    for(int i = length - 1; i > pos; i--){
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
}

void reshape(int arr[], int length, int arr2d[nRows][nCols]){
    if(length != nRows * nCols){
        printf("Invalid array length for reshaping\n");
        return;
    }

    int index = 0;
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            arr2d[i][j] = arr[index++];
        }
    }
}

void print_trans_matrix(int arr2d[nRows][nCols]){
    for(int j = 0; j < nCols; j++){
        for(int i = 0; i < nRows; i++){
            printf("arr2d[%d][%d] = %d\n", i, j, arr2d[i][j]);
        }
        puts("");
    }
}

bool found_duplicate(int arr[], int length){
    for(int i = 0; i < length - 1; i++){
        for(int j = i + 1; j < length; j++){
            if(arr[i] == arr[j]){
                return true;
            }
        }
    }
    return false;
}

void flip_array(int arr[], int length, int flippedArray[]){
    for(int i = 0; i < length; i++){
        flippedArray[i] = arr[length - i - 1];
    }
}