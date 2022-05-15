

#include "OrgChart.hpp"
#include <unordered_map>
#include <vector>
using namespace std;

using namespace ariel;


int x =0;

OrgChart::OrgChart(){
this->_head=nullptr;
}

OrgChart OrgChart::add_root(string s){
    // if(this->_head==nullptr){
    //     this->_head=&s;
    //     vector<string*> v;
    //     this->_tree.insert(pair<string*,vector<string*>>(&s,v));
    //     return *this;
    // }
    // else{
    //    // find the row in the map change the key, or copy the vector, delete the row add in new row with new key old vector update _head
    // }
    return *this;
}


OrgChart OrgChart::add_sub(string s1,string s2){
    // if(this->_tree.find(&s1)==this->_tree.end()){ // will need to change to a different iterator
    //     throw std::invalid_argument( "parent key not found" );
    // }
    // this->_tree[&s1].push_back(&s2);
    // vector<string*> v;
    // this->_tree.insert(pair<string*,vector<string*>>(&s2,v));
    return *this;
}

ostream& ariel::operator<<(ostream& output, const OrgChart& org){
    
    cout<< "printing OrgChart"<<endl; 
    string s1="------------------";
    string s2="---------";
    string s3="|";
    return output;
}



string* OrgChart::begin_level_order(){
    return nullptr;
}
string* OrgChart::end_level_order(){
    return nullptr;
}
string* OrgChart::begin_reverse_order(){
    return nullptr;
}
string* OrgChart::reverse_order(){
    return nullptr;
}
string* OrgChart::begin_preorder(){
    return nullptr;
}
string* OrgChart::end_preorder(){
    return nullptr;
}

int* OrgChart::begin(){
    int* ans=&x;
    return ans;
}

int* OrgChart::end(){
    int* ans=&x;
    return ans;
}