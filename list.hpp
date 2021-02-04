#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

namespace ft
{

template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };

    template <class T>
    class list
    {
        typedef T   value_type;
        
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
    
        public:
            explicit list (const std::allocator<value_type>& alloc = std::allocator<value_type>())
			{
				Node *nodeEnd = new Node();
				
				nodeEnd->nodePrevious = nodeEnd;
				nodeEnd->nodeNext = nodeEnd;
				
				_listBegin = nodeEnd;
				_listEnd = nodeEnd;
				_sizelist = 0;
				_sizeNode = sizeof(Node);
			};
            explicit list (size_t n, const value_type& val = value_type(), const std::allocator<value_type>& alloc = std::allocator<value_type>())
			{
				Node *nodeEnd = new Node();

				nodeEnd->nodePrevious = nodeEnd;
				nodeEnd->nodeNext = nodeEnd;

				_listBegin = nodeEnd;
				_listEnd = nodeEnd;
				_sizelist = 0;
				_sizeNode = sizeof(Node);

				while (n-- > 0)
					push_front(val);
			};
            template <class InputIterator>
            list (InputIterator first, InputIterator last, const std::allocator<value_type>& alloc = std::allocator<value_type>(), typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0)
			{
				Node *nodeEnd = new Node();

				nodeEnd->nodePrevious = nodeEnd;
				nodeEnd->nodeNext = nodeEnd;

				_listBegin = nodeEnd;
				_listEnd = nodeEnd;
				_sizelist = 0;
				_sizeNode = sizeof(Node);

				while (first != last )
				{
					push_back(*first);
					++first;
				}
			};
            list (const list& rhs)
			{
				Node *nodeEnd = new Node();
			
				nodeEnd->nodePrevious = nodeEnd;
				nodeEnd->nodeNext = nodeEnd;
				
				_listBegin = nodeEnd;
				_listEnd = nodeEnd;
				_sizelist = 0;
				_sizeNode = sizeof(Node);
				
				*this = rhs;
			};
            list & operator=(const list & rhs)
			{
				if (this == &rhs)
					return *this;
				clear();
				if (rhs._sizelist != 0)
				{
					Node* tmp = rhs._listEnd->nodeNext;
					while (tmp != rhs._listEnd)
					{
						push_back(tmp->node);
						tmp = tmp->nodeNext;
					}
				}
				return *this;
			};

            template <class InputIterator>
            void assign (InputIterator first, InputIterator last, typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
                if (_sizelist != 0)
                    clear();
                while (first != last){
                    push_back(*first);
                    first++;
                }
            }
            void assign (size_t n, const value_type& val){
                if (_sizelist != 0)
                    clear();
                while (n > 0){
                    push_back(val);
                    n--;
                }
            }
            void push_front(const value_type& t){
                if (Node *node = new Node(t))
                {
                    if (_sizelist != 0)
                    {
                        node->nodeNext = _listEnd->nodeNext;
                        node->nodeNext->nodePrevious = node;
                    }
                    else
                    {
                        node->nodeNext = _listEnd;
                        _listEnd->nodePrevious = node;
                    }
                    _listEnd->nodeNext = node;
                    node->nodePrevious = _listEnd;
                    _sizelist++;
                    _listEnd->node = _sizelist;
                }
            }
            void push_back(const value_type& t){
                if (Node *node = new Node(t))
                {

                    if (_sizelist != 0)
                    {
                        node->nodePrevious = _listEnd->nodePrevious;
                        node->nodePrevious->nodeNext = node;
                    }
                    else
                    {
                        node->nodePrevious = _listEnd;
                        _listBegin->nodeNext = node;
                    }
                    node->nodeNext = _listEnd;
                    _listEnd->nodePrevious = node;
                    _sizelist++;
                    _listEnd->node = _sizelist;
                }
            }
            void pop_front (){
                if (_sizelist != 0)
                {
                    _listEnd->nodeNext = _listEnd->nodeNext->nodeNext;
                    delete _listEnd->nodeNext->nodePrevious;
                    _listEnd->nodeNext->nodePrevious = _listEnd;
                 _sizelist--;
                    _listEnd->node = _sizelist;
                }
            }
            void pop_back(){
            if (_sizelist != 0)
            {
                _listEnd->nodePrevious = _listEnd->nodePrevious->nodePrevious;
                delete _listEnd->nodePrevious->nodeNext;
                _listEnd->nodePrevious->nodeNext = _listEnd;
                _sizelist--;
                _listEnd->node = _sizelist;
            }
        }
            void remove();
            size_t size(){
                return _sizelist;
            }
            size_t max_size() const{
                return std::numeric_limits<size_t>::max() / _sizeNode;
            }
            bool empty() const{
                if (_sizelist == 0)
                    return true;
                return false;
            }
            value_type& front(){
                return _listEnd->nodeNext->node;
            }
            const value_type& front() const{
                return _listEnd->nodeNext->node;
            }
            value_type& back(){
                return _listEnd->nodePrevious->node;
            }
            const value_type& back() const{
                return _listEnd->nodePrevious->node;
            }
            void clear (){
                erase(_listEnd->nodeNext, _listEnd);
            }
            void swap (list & x){
                list tmp;
                tmp = *this;
                *this = x;
                x = tmp;
            }
            void resize (size_t n, value_type val = value_type ()){
                if (n >= _sizelist)
                {
                    while (_sizelist != n)
                        push_back(val);
                }
                else
                {
                    while (_sizelist != n)
                        pop_back();
                }
            }
            void remove (const T& val){
                list<T>::iterator it = _listEnd->nodeNext;
                while (it != _listEnd)
                {
                    if (*it == val)
                        erase(it);
                    ++it;
                }
            }
            template <class Predicate>
            void remove_if (Predicate pred){
                list<T>::iterator it = _listEnd->nodeNext;
                while (it != _listEnd)
                {
                    if (pred(*it))
                        erase(it);
                    ++it;
                }
            }
            void sort(){
                T tmp;
                T tmpNext;
                list<T>::iterator it = _listEnd->nodeNext;
                list<T>::iterator count = _listEnd->nodeNext;
                list<T>::iterator countIn = _listEnd->nodePrevious;
                while (count != _listEnd->nodePrevious)
                {
                    it = _listEnd->nodeNext;
                    while (it != countIn)
                    {
                        tmp = *(it);
                        if (it != _listEnd->nodePrevious && tmp > *(++it))
                        {
                            tmpNext = *it;
                            *(--it) = tmpNext;
                            *(++it) = tmp;
                        }
                    }
                    --countIn;
                    ++count;
                }
            }
            template <class Compare>
            void sort(Compare comp){
                T tmp;
                T tmpNext;
                list<T>::iterator it = _listEnd->nodeNext;
                list<T>::iterator count = _listEnd->nodeNext;
                list<T>::iterator countIn = _listEnd->nodePrevious;
                while (count != _listEnd->nodePrevious)
                {
                    it = _listEnd->nodeNext;
                    while (it != countIn)
                    {
                        tmp = *(it);
                        if (it != _listEnd->nodePrevious && comp(*(++it), tmp) > 0)
                        {
                            tmpNext = *it;
                            *(--it) = tmpNext;
                            *(++it) = tmp;
                        }
                    }
                    --countIn;
                    ++count;
                }
            }
            void reverse(){
                T tmp;
                size_t count = 0;
                list<T>::iterator it = _listEnd->nodeNext;
                list<T>::reverse_iterator itRev = _listEnd->nodePrevious;

                while (count != _sizelist / 2)
                {
                    tmp = *it;
                    *it = *itRev;
                    *itRev = tmp;
                    ++it;
                    ++itRev;
                    count++;
                }
            }
            void unique(){
                T tmp;
                list<T>::iterator it = _listEnd->nodeNext;
                while (it != _listEnd->nodePrevious)
                {
                    tmp = *it;
                    if (*(++it) == tmp)
                        while (*it == tmp)
                        {
                            erase(it);
                            ++it;
                        }
                }
            }
            template <class BinaryPredicate>
            void unique (BinaryPredicate binary_pred){
                T tmp;
                list<T>::iterator it = _listEnd->nodeNext;
                while (it != _listEnd->nodePrevious)
                {
                    tmp = *it;
                    if (binary_pred(*(++it), tmp))
                        while (it != _listEnd && binary_pred(*it, tmp))
                        {
                            std::cout <<"in="<<*it<< " tmp="<<tmp<< std::endl;
                            erase(it);
                            ++it;
                            std::cout <<"out="<<*it<< std::endl;
                        }
                }
            }

            class iterator: public std::iterator<std::input_iterator_tag, value_type>{
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
            iterator begin()
            {
                return _listEnd->nodeNext;
            };
            iterator end()
            {
                return _listEnd;
            };
            reverse_iterator rbegin(){
                return _listEnd->nodePrevious;
            };
            reverse_iterator rend(){
                return _listEnd;
            };
            list<T>::iterator erase(ft::list<T>::iterator position){
                return erase(position, ++position);
            }
            list<T>::iterator erase(ft::list<T>::iterator first, ft::list<T>::iterator last){
                list<T>::iterator it = _listEnd->nodeNext;
                if (_sizelist != 0 && first != _listEnd)
                {
                    Node * tmp;
                    Node * tmpB;
                    tmp = _listEnd->nodeNext;
                    while (it != first && it != _listEnd)
                    {
                        tmp = tmp->nodeNext;
                        ++it;
                    }
                    tmpB = tmp->nodePrevious;
                    while (it != last && it != _listEnd)
                    {
                        tmpB->nodeNext = tmp->nodeNext;
                        delete tmp;
                        tmp = tmpB->nodeNext;
                        _sizelist--;
                        _listEnd->node = _sizelist;
                        ++it;
                    }
                    tmp->nodePrevious = tmpB;
                    return it;
                }
                it = _listEnd;
                return it;
            }
            iterator insert (iterator position, const value_type& val){
                ft::list<T>::iterator begin = _listEnd->nodeNext;
                ft::list<T>::iterator end = _listEnd;
                Node * tmp = _listEnd->nodeNext;;

                while (begin != position && begin != end) {
                    tmp = tmp->nodeNext;
                    begin++;
                }
                if (Node *node = new Node(val)){
                    node->nodeNext = tmp;
                    node->nodePrevious = tmp->nodePrevious;
                    tmp->nodePrevious->nodeNext = node;
                    tmp->nodePrevious = node;
                    _sizelist++;
                    _listEnd->node = _sizelist;
                    return node;
                }
                return _listEnd;
            }
            void insert (iterator position, size_t n, const value_type& val){
                while (n > 0){
                    position = insert(position, val);
                    n--;
                }
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
                while (first != last){
                    position = insert(position, *first);
                    first++;
                }
            }
            //~list();

        private:
            Node *_listBegin;
            Node *_listEnd;
            size_t _sizelist;
            size_t _sizeNode;
    };

}

#endif
