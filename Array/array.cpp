#include <iostream>

//void print( int arr[], int size )
//{
//    for( int i = 0; i < size; ++i )
//    {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//}

void print( int* arr, int size )
{
    for( int i = 0; i < size; ++i )
    {
        std::cout << *( arr + i ) << " ";
    }
    std::cout << std::endl;
}

void foo( int arr[3] )
{
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << std::endl;
}

int main()
{
    int arr[10];
    for( int i = 0; i < 10; ++i )
    {
        arr[i] = i;
    }
    print( arr, sizeof( arr )/sizeof( int ) );

    int arr2[3] = { 34, 5, 88 };
    foo( arr2 );
    int arr3[4] = { 4, 66 };
    foo( arr3 );

    int* ptr = new int;
    *ptr = 44;
    std::cout << *ptr << std::endl;

    int* ptrarr = new int[3];
    for ( int i = 0; i < 3; ++i )
    {
        ptrarr[i] = i * 10 + i;
    }
    for ( int i = 0; i < 3; ++i )
    {
        std::cout << ptrarr[i] << " ";
    }
    std::cout << std::endl;
    delete[] ptrarr;

    int* xptr[3];
    for ( int i = 0; i < 3; ++i )
    {
        xptr[i] = &( arr2[i] );
    }
    for ( int i = 0; i < 3; ++i )
    {
        std::cout << *xptr[i] << " ";
    }
    std::cout << std::endl;

    int** yptr = new int*[5];
    int arr5[5] = { 5, 7, 2, 6, 88 };
    for ( int i = 0; i < 5; ++i )
    {
        yptr[i] = &( arr5[i] );
    }
    for ( int i = 0; i < 5; ++i )
    {
        std::cout << *yptr[i] << " ";
    }
    std::cout << std::endl;
    delete[] yptr;
}
