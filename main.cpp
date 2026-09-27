#include<iostream>
#include<string>

using namespace std;

class Product{
    public:
    string pId;
    string pName;
    float pPrice;
    int pQuantity;
};

int main(){
    Product obj;
    obj. pId = "S123";
    obj.pName = "Shoe";
    obj.pPrice = 11808;
    obj.pQuantity =20;

    cout<<"Product: "<<obj.pName<<endl;
    cout<<"I'd: "<<obj.pId<<endl;
    cout<<"Price: "<<obj.pPrice<<endl;
    cout<<"pQuantity: "<<obj.pQuantity<<endl;
    
    return 0;
}