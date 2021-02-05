//
// Created by Caeneus Garth on 2/5/21.
//

#ifndef CONTAINER_GIT_LISTITERATOR_HPP
#define CONTAINER_GIT_LISTITERATOR_HPP

#include <iostream>

namespace ft
{
    template <class T>
    struct Node
    {
        Node(): nodeNext(NULL), nodePrevious(NULL) {}
        Node(const T& t)
        {
            node = t;
            nodeNext = NULL;
            nodePrevious = NULL;
        }
        T node; //сама нода
        Node *nodeNext; //следующий элемент
        Node *nodePrevious; //предыдущий элемент
    };

    template <class T>
    class iterator: public std::iterator<std::input_iterator_tag, T>{
    public:
        iterator(): _index(NULL) {};
        iterator(Node* index): _index(index) {};
        bool operator==(iterator const & rhs){
            return _index == rhs._index;
        };
        bool operator!=(iterator const & rhs){
            return _index != rhs._index;
        };
        iterator & operator++() {
            _index = _index->nodeNext;
            return *this;
        };
        iterator operator++(int)
        {
            iterator tmp(_index);
            _index = _index->nodeNext;
            return tmp;
        }
        iterator & operator--() {
            _index= _index->nodePrevious;
            return *this;
        };
        iterator operator--(int)
        {
            iterator tmp(_index);
            _index= _index->nodePrevious;
            return tmp;
        }
        T & operator*(){
            return _index->node;
        };

    private:
        Node* _index;
    };

    template <class T>
    class reverse_iterator{
    public:
        reverse_iterator(): _index(NULL) {};
        reverse_iterator(Node* index): _index(index) {};
        bool operator==(reverse_iterator const & rhs){
            return _index == rhs._index;
        };
        bool operator!=(reverse_iterator const & rhs){
            return _index != rhs._index;
        };
        reverse_iterator & operator++() {
            _index= _index->nodePrevious;
            return *this;
        };
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp(_index);
            _index= _index->nodePrevious;
            return tmp;
        }
        reverse_iterator & operator--() {
            _index = _index->nodeNext;
            return *this;
        };
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp(_index);
            _index = _index->nodeNext;
            return tmp;
        }
        T & operator*(){
            return _index->node;
        };

    private:
        Node* _index;
    };
}

#endif //CONTAINER_GIT_LISTITERATOR_HPP
