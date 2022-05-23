#include "vector.h"

template <typename T>
void test_push_back(vector<T>& vec, int cnt = 1000)
{
    for (int i = 0; i < cnt; i++)
        vec.push_back(i);
}

template <typename T>
vector<T> test_move_helper_val(const vector<T>& vec)
{
    vector<T> temp{vec};
    cout << "test move helper" << endl;
    return temp;
}

template <typename T>
void test_move_constructor(const vector<T>& vec) 
{
    cout << "--------- test_move_construct ----------" << endl;
    vector<T> new_vec{test_move_helper_val(vec)};
    cout << new_vec;
}


template <typename T>
void test_move_assignment(const vector<T>& vec) 
{
    cout << "--------- test_move_assignment ----------" << endl;
    vector<T> new_vec;
    new_vec = test_move_helper_val(vec);
}


template <typename T>
void test_copy_assignment(const vector<T>& vec) 
{
    vector<T> new_vec = vec;
}

template <typename T>
void test_copy_construct(const vector<T>& vec) 
{
    cout << "--------- test_copy_construct ----------" << endl;
    vector<T> new_vec{vec};
    cout << new_vec;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> test{0, 1, 2};
    cout << test;

    test_copy_construct(test);
    test_push_back(test, 10);
    test_move_assignment(test);
    test_move_constructor(test);

    return 0;
}
