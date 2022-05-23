#include<iostream>
using namespace std;

template<typename T>
class vector
{
private:
    /* data */
    int sz = 0;
    T* elem = nullptr;
    int space = 0;

public:
    vector(initializer_list<T>);
    vector();
    vector(vector<T>&&);                       // move constructor
    vector(const vector<T>&);              // copy constructor
    ~vector();

    template<typename U>
    friend ostream& operator<<(ostream&, const vector<U>&);

    const T& operator[](int) const;     // [] for reading values
    T& operator[](int);                 // [] for assigning

    vector<T>& operator=(const vector<T>&);   // copy assignmnet

    vector<T>& operator=(vector<T>&&);         // move assignment

    // does not modify the members of vector
    int capacity() const; 
    int size() const; 
    int veclen();

    void push_back(const T&);
    void reserve(int);
    void resize(int);
    
    T* begin() const;
    T* end() const;
};

template<typename T>
void vector<T>::push_back(const T& item)
{
    if (sz == space) {
        reserve(space * 2);
    }
    elem[sz++] = item;
}

template<typename T>
void vector<T>::reserve(int new_space)
{
    cout << "************** reserve is called **************" << endl;
    if (new_space <= space) return;
    T* new_elem = new T[new_space];
    // copy(begin(), end(), new_elem);
    for (int i = 0; i<sz; i++) new_elem[i] = elem[i];
    delete[] elem;
    space = new_space;
    elem = new_elem;

}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) 
{
    for (int i = 0; i < vec.sz; ++i) {
        os << vec[i] << " ,";
    }

    return os << "\n";
}

template<typename T>
vector<T>::vector()
{
    cout << "empty constructor called" << endl;
    sz = 0;
    elem = new T[1];
    space = 1;
}

template<typename T>
vector<T>::vector(initializer_list<T> list_elems)
{
    // 1. allocate enough space
    // 2. copy the list_elems into elems
    cout << "initializer list constructor" << endl;

    elem = new T[list_elems.size()];
    copy(list_elems.begin(), list_elems.end(), elem);

    sz = list_elems.size();
    space = list_elems.size();

    // cout << *this;
}

template<typename T>
vector<T>::vector(const vector<T>& old_vec)
{
    cout << "***********copy constructor is called*****************" << endl;
    sz = 0, space = 0;
    reserve(old_vec.capacity());
    cout << "*********** reserve finished *****************" << endl;
    // copy(old_vec.begin(), old_vec.end(), elem);

    for (int i = 0; i < old_vec.size(); ++i) {
        elem[i] = old_vec[i];
    }

    sz = old_vec.size();
}

template<typename T>
vector<T>::vector(vector<T>&& old_vec)
{
    cout << "move constructor is called" << endl;
    elem = old_vec.elem;
    sz = old_vec.sz;
    space = old_vec.space;

    old_vec.elem = nullptr;
    old_vec.sz = 0, old_vec.space = 0;
}

template<typename T>
T& vector<T>::operator[](int idx)  
{
    return elem[idx];
}

template<typename T>
const T& vector<T>::operator[](int idx) const
{
    return elem[idx];
}

template<typename T>
vector<T>::~vector()
{
    delete[] elem;
}

template<typename T>
int vector<T>::capacity() const 
{
    return space;
}

template<typename T>
int vector<T>::size() const 
{
    return sz;
} 

template<typename T>
T* vector<T>::begin() const
{
    return &elem[0];
} 

template<typename T>
T* vector<T>::end() const
{
    return &elem[sz];
} 

template<typename T>
vector<T>& vector<T>::operator=(const vector<T>&rvec)
{
    cout << "copy assignment is called" << endl;
    delete[] elem;
    sz = rvec.sz;
    space = rvec.space;
    elem = new T[space];
    copy(rvec.begin(), rvec.end(), elem);

    return *this;
}

template<typename T>
vector<T>& vector<T>::operator=(vector<T>&& rvec) 
{
    cout << "move assignment is called" << endl;
    delete[] elem;
    elem = rvec.elem;
    sz = rvec.sz;
    space = rvec.space;
    rvec.elem = nullptr;
    return *this;
}
