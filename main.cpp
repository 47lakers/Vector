//
//  main.cpp
//  Vector
//
//  Created by Ira Xavier Porchia on 6/25/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
class Vector{
private:
    T *_arr;
    int _capacity, _current;
public:
    Vector(){
        _arr = new T[1];
        _capacity = 1;
        _current = 0;
    }
    
    ~Vector(){
        delete[] _arr;
        _arr = nullptr;
        _capacity = 0;
        _current = 0;
    }
    
    void push(T data){
        T *temp = nullptr;
        if(_current == _capacity){
            temp = new T[2 * _capacity];
            for(int i = 0; i < _capacity; i++){
                temp[i] = _arr[i];
            }
            delete[] _arr;
            _capacity *= 2;
            _arr = temp;
        }
        _arr[_current] = data;
        _current++;
    }
    
    void pop(){
        _current--;
    }
    
    void print(){
        for (int i = 0; i < _current; i++) {
            cout << _arr[i] << " ";
        }
        cout << endl << endl;
    }
    
    int size(){
        return _current;
    }
    
    bool empty(){
        return size() == 0;
    }
    
    int get(int index){
        return _arr[index];
    }
    
    void swap(int a, int b){
        int temp = _arr[a];
        _arr[a] = _arr[b];
        _arr[b] = temp;
    }
    
};

int main(int argc, const char * argv[]) {
    Vector<int> v;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.push(50);
    v.push(60);
    v.push(70);
    v.print();
    v.pop();
    v.print();
    return 0;
}
