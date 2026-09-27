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
        getline(cin>>ws, pId);
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
        another = toupper(static_cast<unsigned char>(another));
        cout<<endl;
        while (another != 'Y' && another != 'N'){
            cout<<"Invalid Input! Please Enter(Y/N): ";
            cin>>another;
            another = toupper(static_cast<unsigned char>(another));
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

void searchProduct(const vector<Product>& inventory){
    string search;
    bool found = false;
    cout<<"+++++++++++++++++++++++++"<<endl;
    cout<<"+++++Search Product+++++"<<endl;
    cout<<"+++++++++++++++++++++++++"<<endl;
    cout<<"\nEnter the I'd of the Product you want to find: ";
    getline(cin>>ws, search);
    for(const auto& Product: inventory){
        if(Product.pId == search){
            cout<<"\n-----Product Founded-----"<<endl;
            cout<<"Product: "<<Product.pName<<endl;
            cout<<"Price: "<<Product.pPrice<<endl;
            cout<<"Quantity: "<<Product.pQuantity<<endl;
            cout<<"+++++++++++++++++++++++++"<<endl;
            found = true;
            break;
        }

    }
    if(!found){
        cout<<"The Product is not present in Inventory"<<endl;
        cout<<endl;
    }
}

void updateQuantity(vector<Product>& inventory){
    string search;
    int newQuantity;
    bool found = false;
    cout<<"+++++++++++++++++++++++++"<<endl;
    cout<<"+++++Update Quantity+++++"<<endl;
    cout<<"+++++++++++++++++++++++++"<<endl;
    cout<<"\nEnter the I'd of the Product you want to change its Quantity: ";
    getline(cin>>ws, search);
    for(int i=0; i<inventory.size(); i++){
        if(inventory[i].pId == search){
            cout<<"\n-----Product Found-----"<<endl;
            cout<<"Product previous quantity is: "<<inventory[i].pQuantity<<endl;
            cout<<"Enter the new quantity: ";
            cin>>newQuantity;
            inventory[i].pQuantity = newQuantity;
            cout<<endl;
            cout<<"Update Product Quantity Successfully!"<<endl;
            cout<<"+++++++++++++++++++++++++"<<endl;
            found = true;
            break;
        }

    }
    if(!found){
        cout<<"The Product is not present in Inventory"<<endl;
        cout<<"+++++++++++++++++++++++++"<<endl;
        cout<<endl;
    }
}

void removeProduct(vector<Product>& inventory){
    string removeId;
    bool found = false;
    cout<<"\n++++++Remove Product+++++"<<endl;
    cout<<"Enter I'd to remove Product: ";
    getline(cin>>ws, removeId);
    for(int i=0; i<inventory.size(); i++){
        if(inventory[i].pId == removeId){
            inventory.erase(inventory.begin() + i);
            cout<<"The Product "<<removeId<<" has been remove successfully."<<endl;
            cout<<"+++++++++++++++++++++++++"<<endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"The Product does not present in yout inventory!"<<endl;
        cout<<"+++++++++++++++++++++++++"<<endl;
    }
}

int main(){
    int choice;
    do{
        cout<<"\n+++++++++++++++++++++++++"<<endl;
        cout<<"+++Inventory Management++"<<endl;
        cout<<"+++++++++System++++++++++"<<endl;
        cout<<"+++++++++++++++++++++++++"<<endl;
        cout<<"1.Add Product"<<endl;
        cout<<"2.Display Product"<<endl;
        cout<<"3.Search Product"<<endl;
        cout<<"4.Update Product"<<endl;
        cout<<"5.Remove Product"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"+++++++++++++++++++++++++"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
        case 1:
            addProduct(inventory);
            break;
        case 2:
            displayProduct(inventory);
            break;
        case 3:
            searchProduct(inventory);
            break;
        case 4:
            updateQuantity(inventory);
            break;
        case 5:
            removeProduct(inventory);
            break;
        case 6:
            cout << "Thank you for using our Inventory Management System!" << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    }while(choice!=6);  
    return 0;
}