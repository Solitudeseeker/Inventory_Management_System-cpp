#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Product{
    public:
    string pId;
    string pName;
    float pPrice;
    int pQuantity;
};

vector<Product> inventory;

void addProduct(vector<Product>& inventory){
    char another;
    string pId, pName;
    float pPrice;
    int pQuantity;
    cout<<"Enter Product I'd: ";
    getline(cin, pId);
    cout<<"Enter Product Name: ";
    getline(cin, pName);
    cout<<"Enter Product Price: ";
    cin>>pPrice;
    cout<<"Enter Product Quantity: ";
    cin>>pQuantity;
    Product P1{pId, pName, pPrice, pQuantity};
    inventory.push_back(P1);
}

int main(){

    addProduct(inventory);
    for(int i=0; i<inventory.size(); i++){
        cout<<"\n+++++++++++++++++++++++++"<<endl;
        cout<<"Product I'd: "<<inventory[i].pId<<endl;
        cout<<"Product Name: "<<inventory[i].pName<<endl;
        cout<<"Product Price: "<<inventory[i].pPrice<<endl;
        cout<<"Products Quantity: "<<inventory[i].pQuantity<<endl;
        cout<<"+++++++++++++++++++++++++"<<endl;
    }
    
    return 0;
}