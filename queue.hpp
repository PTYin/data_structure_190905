//
// Created by peter on 19-9-7.
//

#ifndef DATA_STRUCTURE_190905_QUEUE_HPP
#define DATA_STRUCTURE_190905_QUEUE_HPP

#include "doubleLinkedList.hpp"
namespace pty
{
    template <typename T>
    class queue:protected doubleLinkedList<T>
    {
        using Node = typename doubleLinkedList<T>::Node;
        using iterator = typename doubleLinkedList<T>::iterator;
    public:
        queue():doubleLinkedList<T>(){}
        queue(std::initializer_list<T> list)  // 给定列表依次入队列
        {
            push_all(list);
        }
        void push(T _data)
        {
            this->push_front(_data);
        }
        T push_all(std::initializer_list<T> list)
        {
            for(auto element:list)
            {
                push(element);
            }
        }
        T pop()  // 出队
        {
            return this->pop_back();
        }
        T head()  // 返回队首元素
        {
            return *(this->front());
        }
        T tail()  // 返回队尾元素
        {
            return *(this->back());
        }
        void clear()
        {
            doubleLinkedList<T>::clear();
        }
        unsigned int size() const
        {
            return this->length;
        }

        bool is_empty() const
        {
            return this->length==0;
        }
        friend std::ostream& operator<<(std::ostream& io, const queue& queue)
        {
            if(queue.length != 0)
                for(iterator it = queue.it_head; it != queue.it_tail; it++)
                {
                    io<<*it<<" -> ";
                }
            io<<*queue.it_tail;
            return io;
        }
    };
}

#endif //DATA_STRUCTURE_190905_QUEUE_HPP
