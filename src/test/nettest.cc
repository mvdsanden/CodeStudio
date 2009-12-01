#include <iostream>

using namespace std;

template <typename Type>
struct TypeInfo {
  static const uint26_t version = 0x0001; // Net type version.
};

template <> struct TypeInfo<int> { static const char type = 'i'; };
template <> struct TypeInfo<double> { static const char type = 'd'; };
//template <> struct TypeInfo<int> { static const char type = 1; };
//template <> struct TypeInfo<int> { static const char type = 1; };
//template <> struct TypeInfo<int> { static const char type = 1; };

template <typename ...Tail>
struct NetTest;

template <typename Head, typename ...Tail>
struct NetTest<Head,Tail...> {

  static const size_t size = sizeof(Head) + NetTest<Tail...>::size;

  static const size_t count = 1 + NetTest<Tail...>::count;

  static void head(char *buffer)
  {
    (*buffer) = TypeInfo<Head>::type;
    NetTest<Tail...>::head(buffer+1);
  }

};

template <> struct NetTest<> {
  static const size_t size = 0;
  static const size_t count = 0;

  static void head(char *buffer)
  {
    (*buffer) = 0;
  }
};

int main()
{
  cout << "Size: " << NetTest<int,int,double,int>::size << endl;
  cout << "Count: " << NetTest<int,int,double,int>::count << endl;

  char buffer[NetTest<int,int,double,int>::count+1];

  NetTest<int,int,double,int>::head(buffer);

  cout << "Header: " << buffer << endl;

  return 0;
}
