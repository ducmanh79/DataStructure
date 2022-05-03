#pragma once

#include <stack>

#include "BNode.h"

template <typename T>
class BinarySearchTreeIterator
{
private:
    const BNode<T>* fBNodeTree;          // binary search tree
    std::stack<const BNode<T>*> fStack; // DFS traversal stack

public:
    using Iterator = BinarySearchTreeIterator<T>;

    BinarySearchTreeIterator(const BNode<T>* aBNodeTree)
    {
        fBNodeTree = aBNodeTree;
        if (!fBNodeTree->empty())
        {
            fStack.push(fBNodeTree); //push in root
            // push descents from the root along the left nodes to a leaf
            while (!fStack.top()->left->empty()) //check whether the left node of the root is exist
            {
                fStack.push(fStack.top()->left); //push onto the stack if exits until reached the leaf of left most node
            }
        }
    }

    const T& operator*() const
    {
        //provide access to the top node in the stack
        return fStack.top()->key;
    }

    Iterator& operator++()
    {
        if (fStack.empty())
        {
            fStack.push(&BNode<T>::NIL);
        }
        else
        {
            const BNode<T>* lNode = fStack.top();
            fStack.pop(); //pop the leaf
            if (!lNode->right->empty()) //inspect right node
            {
                fStack.push(lNode->right); //push if exist

                while (!fStack.top()->left->empty()) // check left node
                {
                    fStack.push(fStack.top()->left); //push if exits
                }
            }
        }
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const Iterator& aOther) const
    {
        return fStack == aOther.fStack;
    }

    bool operator!=(const Iterator& aOther) const
    {
        return !(*this == aOther);
    }

    Iterator begin() const
    {
        return Iterator(fBNodeTree);
    }

    Iterator end() const
    {
        return Iterator(BNode<T>::NIL);
    }
};