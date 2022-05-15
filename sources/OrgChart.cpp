

#include "OrgChart.hpp"
#include <unordered_map>
#include <vector>
using namespace std;

using namespace ariel;

OrgChart::OrgChart(){

}

OrgChart OrgChart::add_root(string s){

    return *this;
}


OrgChart OrgChart::add_sub(string s1,string s2){
    return *this;
}

ostream& ariel::operator<<(ostream& output, const OrgChart& org){
    cout<< "printing OrgChart"<<endl; 
    return output;
}



// string* OrgChart::begin_level_order(){}
// string* OrgChart::end_level_order(){}
// string* OrgChart::begin_reverse_order(){}
// string* OrgChart::end_reverse_order(){}
// string* OrgChart::begin_preorder(){}
// string* OrgChart::end_preorder(){}