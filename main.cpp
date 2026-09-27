#include<iostream>
#include<string>
#include<vector>
#include<cctype>

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
    do{
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
        cout<<"\nDo you want to add another product(Y/N): ";
        cin>>another;
        another = toupper(another);
        cout<<endl;
        while (another != 'Y' && another != 'N'){
            cout<<"Invalid Input! Please Enter(Y/N): ";
            cin>>another;
            cout<<endl;
        }
        cin.ignore();
    }while(another == 'Y');
}

void displayProduct(const vector<Product>& inventory){
    cout<<"+++++++++++++++++++++++++"<<endl;
    cout<<"+++++Display Product+++++"<<endl;
    for(int i=0; i<inventory.size(); i++){
    cout<<"+++++++++++++++++++++++++"<<endl;
    cout<<"Product I'd: "<<inventory[i].pId<<endl;
    cout<<"Product Name: "<<inventory[i].pName<<endl;
    cout<<"Product Price: "<<inventory[i].pPrice<<endl;
    cout<<"Products Quantity: "<<inventory[i].pQuantity<<endl;
    cout<<"+++++++++++++++++++++++++\n"<<endl;
    }
}

int main(){

    addProduct(inventory);
    displayProduct(inventory);
    return 0;
}