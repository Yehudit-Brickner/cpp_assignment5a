#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

namespace ariel{
    

    class OrgChart{
        public:
            string* _head;
            unordered_map<string* , std::vector<string*>> _tree;
            // data structer to hold the n tree
            // map of tree key the node val, value vector of node sons
            
            OrgChart();
            
            OrgChart add_root(string s);
            OrgChart add_sub(string s1,string s2);
            friend ostream& operator<<(ostream& output, const OrgChart& org);
            
            string* begin_level_order();
            string* end_level_order();
            string* begin_reverse_order();
            string* reverse_order();
            string* begin_preorder();
            string* end_preorder();

            int* begin();
            int* end();
            
            class level_order_iterator{
                private:
                    queue<string*> q;
                    string* pointer_to_current_node;

                    
                public:
                    level_order_iterator(){
                       
                    }

                    level_order_iterator(string* ptr = nullptr): pointer_to_current_node(ptr) {
		            }  

                    level_order_iterator& operator*(){
                       return *this; 
                    } 

                    level_order_iterator* operator->(){
                        return this;
                    }

                    level_order_iterator& operator++();
                    // {
                    //     pointer_to_current_node = pointer_to_current_node++;
			        //     return *this;
                    // }

                    level_order_iterator& operator++(int);
                    // {
                    //     level_order_iterator iterator=*this;
                    //     ++(*this);
                    //     return iterator; 
                    // }


                     bool operator==(const level_order_iterator& other) const{
                        return pointer_to_current_node == other.pointer_to_current_node;
                    }

                    bool operator!=(const level_order_iterator& other) const{
                        return !(*this==other);
                    }
                 
                    level_order_iterator begin_level_order(){
                        return pointer_to_current_node;
                    }
                    level_order_iterator end_level_order(){
                        return nullptr;
                    }
            };


    class reverse_level_order_iterator{
                private:
                    string* pointer_to_current_node;
                    
                public:
                    reverse_level_order_iterator(string* ptr = nullptr): pointer_to_current_node(ptr) {
		            }  

                    reverse_level_order_iterator& operator*(){
                       return *this; 
                    } 

                    reverse_level_order_iterator* operator->(){
                        return this;
                    }

                    reverse_level_order_iterator& operator++();
                    // {
                    //     pointer_to_current_node = pointer_to_current_node++;
			        //     return *this;
                    // }

                    reverse_level_order_iterator& operator++(int);
                    // {
                    //     level_order_iterator iterator=*this;
                    //     ++(*this);
                    //     return iterator; 
                    // }


                    bool operator==(const reverse_level_order_iterator& other) const{
                        return pointer_to_current_node == other.pointer_to_current_node;
                    }

                    bool operator!=(const reverse_level_order_iterator& other) const{
                        return !(*this==other);
                    }
                 
                    reverse_level_order_iterator begin_reverse_order(){
                        return pointer_to_current_node;
                    }
                    reverse_level_order_iterator reverse_order(){
                        return nullptr;
                    }
            };

            class preorder_iterator{
                private:
                    string* pointer_to_current_node;
                    
                public:
                    preorder_iterator(string* ptr = nullptr): pointer_to_current_node(ptr) {
		            }  

                    preorder_iterator& operator*(){
                       return *this; 
                    } 

                    preorder_iterator* operator->(){
                        return this;
                    }

                    reverse_level_order_iterator& operator++();
                    // {
                    //     pointer_to_current_node = pointer_to_current_node++;
			        //     return *this;
                    // }

                    reverse_level_order_iterator& operator++(int);
                    // {
                    //     level_order_iterator iterator=*this;
                    //     ++(*this);
                    //     return iterator; 
                    // }


                     bool operator==(const preorder_iterator& other) const{
                        return pointer_to_current_node == other.pointer_to_current_node;
                    }

                    bool operator!=(const preorder_iterator& other) const{
                        return !(*this==other);
                    }
                 
                    preorder_iterator begin_preorder(){
                        return pointer_to_current_node;
                    }
                    preorder_iterator end_preorder(){
                        return nullptr;
                    }
            };
    };
            
}

    // template<typename Vector>
    // class VectorIterator{
    //     public:
    //         using ValueType = typename Vector::ValueType;
    //         using PointerType = ValueType*;
    //         using ReferenceType = valueTyoe&;
    //     public:
    //         VectorIterator(PointerType ptr)
    //             : m_Ptr(ptr){}

    //         VectorIterator& operatpr++(){
    //             m_Ptr++;
    //             return *this;
    //         }

    //          VectorIterator& operatpr++(int){
    //              VectorIterator iterator=*this;
    //              ++(*this);
    //              return iterator; 
    //         }

    //          VectorIterator& operatpr--(){
    //             m_Ptr--;
    //             return *this;
    //         }

    //          VectorIterator& operatpr--(int){
    //              VectorIterator iterator=*this;
    //              --(*this);
    //              return iterator; 
    //         }

    //         ReferenceType operator[](int index){
    //             return *(m_ptr + index)
    //         }


    //         PointerType operator->(){
    //             return m_ptr;
    //         }

    //         ReferenceType operator*(){
    //             return *m_Ptr;
    //         }

    //         bool operator==(const VectorIterator& other) const{
    //             return m_Ptr == other.m_Ptr;
    //         }

    //         bool operator!=(const VectorIterator& other) const{
    //             return I(*this==other);
    //         }

    //     private:
    //         PointerType m_ptr;
    // };

