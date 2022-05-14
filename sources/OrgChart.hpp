#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <vector>
using namespace std;

namespace ariel{
    

    class OrgChart{
        public:
            string * _head;
            unordered_map<string , std::vector<string *>> _tree;
            // data structer to hold the n tree
            // map of tree key the node val, value vector of node sons
            
            OrgChart();
            
            OrgChart add_root(string s);
            OrgChart add_sub(string s1,string s2);
            friend ostream& operator<<(ostream& output, const OrgChart& org);
            void begin_level_order();
            void end_level_order();
            void begin_reverse_order();
            void reverse_order();
            void begin_preorder();
            void end_preorder();
    };

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

}