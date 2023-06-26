Function overloading happens when two functions have same names by different
1) Number of parameters or
2) Sequence of parameters or
3) Types of parameters

If a class has two functions
void foo()
void foo() const
then const object will call the const foo and non const object will call hte non const foo

1) These can be overloaded
   void foo( int* p )
   void foo( const int* p )

2) These cannot be overloaded
   void foo( int p )
   void foo( const int p )

3) These can be overloaded
   void foo( int& p )
   void foo( const int& p )

4) void foo( int* const p ) is same as void foo( int* p ). So cannot be overloaded.
   foo( int* const p ) and foo( const int* p ) can be overloaded.

5) void foo( int& const ref ) is not possible

6) Cannot be overloaded
   void foo( int x, int y )
   void foo( int x, int y = 5 );

7) If we call foo( 23.4, 56.4 ); then it is considered as double and will cause CTE with overloaded void foo( float x, float y )
we need to call it as foo( 23.4f, 56.4f );

8) main can be overloaded if main is present within the class

9) These cannot be overloaded
   void foo( int* ptr )
   void foo( int ptr[] )
