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

            struct Node{
                string data;
                vector<Node *> kids;
                Node* parent;

                Node(string &d) : data(d), parent(nullptr){}
            };

            Node* _root;

            //constructer
            OrgChart():_root(nullptr){}
            
            //create a "real root for the tree or change the string of the root
            OrgChart add_root(string s){
                if (this->_root==nullptr){
                    this->_root=new Node(s);
                }
                else{
                    this->_root->data=s;
                }
                return *this;
            }


            // add a kid to one of the nodes in the tree
            // we will find the parent node and add the kid to its vector
            OrgChart add_sub(string s1,string s2){
                if (this->_root==nullptr){
                    // throw an error
                }
                for (auto it = *this.begin_level_order(); it != *this.end_level_order(); ++it){
                    if (it->data==s1){
                        it->kids.add(new Node(s2));
                        return *this;
                    }
                }
                // throw error parent no in orgchart
                
            }


            // print the tree in a nice way
            friend ostream& operator<<(ostream& output, const OrgChart& org){
                cout<< "printing OrgChart"<<endl; 
                string s1="------------------";
                string s2="---------";
                string s3="|";
                return output;
            }
            
           
            
            class level_order_iterator{
                private:
                    queue<Node*> q;
                    Node* pointer_to_current_node;
                    
                public:
                    level_order_iterator(Node* n){
                        queue<Node*>helper;
                        helper.push(n);
                        while(helper.size()!=0){
                            Node* dad=helper.front();
                            this->q.push(dad);
                            helper.pop();
                            getkids(dad, &helper); 
                        }
                       pointer_to_current_node = n;
                    }

                    void getkids(Node* n, queue<Node*>* que){
                        for (unsigned long i =0; i< n->kids.size();i++){
                            que->push(n->kids[i]);
                        } 
                    }
 

                    string operator*(){
                       return this->q.front()->data; 
                    } 

                    level_order_iterator* operator->(){
                        return this;
                    }

                    level_order_iterator& operator++(){
                        this->q.pop();
                        pointer_to_current_node=q.front();
			            return *this;
                    }

                    level_order_iterator& operator++(int){
                        level_order_iterator iterator=*this;
                        ++(*this);
                        return iterator; 
                    }


                    bool operator==(const level_order_iterator& other) const{
                        return pointer_to_current_node == other.pointer_to_current_node;
                    }

                    bool operator!=(const level_order_iterator& other) const{
                        return !(*this==other);
                    }
                 
            };


            class reverse_level_order_iterator{
                private:
                    Node* pointer_to_current_node;
                    queue<Node*> q;
                    
                public:
                    reverse_level_order_iterator(Node* n){
                        
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
                 
            };

            class preorder_iterator{
                private:
                    queue<Node*> q;
                    Node* pointer_to_current_node;
                    
                public:
                   
                    preorder_iterator(Node* n){
                        stack<Node*> helper;
                        helper.push(n);
                        while(helper.size()!=0){
                            Node* dad=helper.top();
                            this->q.push(dad);
                            getkids(dad, &helper);
                        }
                        pointer_to_current_node = n;
                    }

                    void getkids(Node* n, stack<Node*>* st){
                        for (unsigned long i =n->kids.size()-1; i>=0;i--){
                            st->push(n->kids[i]);
                        } 
                    }
                    
                    string operator*(){
                       return this->q.front()->data; 
                    } 

                    preorder_iterator* operator->(){
                        return this;
                    }

                    preorder_iterator& operator++(){
                        this->q.pop();
                        pointer_to_current_node=this->q.front();
			            return *this;
                    }

                    preorder_iterator& operator++(int){
                        preorder_iterator iterator=*this;
                        ++(*this);
                        return iterator; 
                    }


                     bool operator==(const preorder_iterator& other) const{
                        return pointer_to_current_node == other.pointer_to_current_node;
                    }

                    bool operator!=(const preorder_iterator& other) const{
                        return !(*this==other);
                    }
            };

            level_order_iterator begin_level_order(){
               return level_order_iterator(this->_root);
            }
            level_order_iterator end_level_order(){
                Node* n =nullptr;
                return level_order_iterator(n);
            }

            reverse_level_order_iterator begin_reverse_order(){ 
                return reverse_level_order_iterator(this->_root);
            }
            reverse_level_order_iterator reverse_order(){
                Node* n =nullptr;
                return reverse_level_order_iterator(n); 
            }

            preorder_iterator begin_preorder(){
                return preorder_iterator(this->_root);
            }
            preorder_iterator end_preorder(){
                Node* n =nullptr;
                return preorder_iterator(n);
            }



            level_order_iterator begin();
            level_order_iterator end();

            // reverse_level_order_iterator begin();
            // reverse_level_order_iterator end();

            // level_order_iterator begin();
            // level_order_iterator end();

    };
            
}

  