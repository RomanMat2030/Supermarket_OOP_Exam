#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Item {
protected:
    string Name;
    string Category;
    int Price;
    int Quantity;
public:
    Item() {
        Name = "No name";
        Category = "No category";
        Price = 0;
        Quantity = 0;
    }
    Item(string n, string c, int p, int q) : Name(n), Category(c), Price(p), Quantity(q) {}

    void setName(string name) {
        Name = name;
    }
    string getName() const {
        return Name;
    }

    void setCategory(string category) {
        Category = category;
    }
    string getCategory() const {
        return Category;
    }

    void setPrice(int price) {
        Price = price;
    }
    int getPrice() const {
        return Price;
    }

    void setQuantity(int quantity) {
        Quantity = quantity;
    }
    int getQuantity() const {
        return Quantity;
    }
    virtual void Print() {
        cout << "=================" << endl;
        cout << "Name : " << Name << endl;
        cout << "Category: " << Category << endl;
        cout << "Price: " << Price << endl;
        cout << "Quantity: " << Quantity << endl;
    }
};

class Goods : public Item {
    int size;
public:
    Goods() :size(0), Item() {}
    Goods(string n, string c, int p, int q, int s) :size(s), Item(n, c, p, q) {}
    void Print() override {
        Item::Print();
        cout << "Size: " << size << endl;
        cout << "=================" << endl;
    }
};
class Food : public Item {
    string time_use;
public:
    Food() :time_use("none"), Item() {}
    Food(string n, string c, int p, int q, string t) :time_use(t), Item(n, c, p, q) {}
    void Print() override {
        Item::Print(); 
        cout << "Time use: " << time_use << endl;
        cout << "=================" << endl;
    }
};
class Supermarket {
private:
    vector<Food>foods;
    vector<Goods>goods;
    const char* filename = "products.txt";
 
public:

    void addFood() {
        string name, category, time;
        int price, quantity;
        cout << "Enter product name: " << endl;
        cin >> name;
        cout << "Enter product category: " << endl;
        cin >> category;
        cout << "Enter product price: " << endl;
        cin >> price;
        cout << "Enter product quantity: " << endl;
        cin >> quantity;
        cout << "Enter product time: " << endl;
        cin >> time;
        Food food(name, category, price, quantity, time);
        foods.push_back(food);
        
    }
    void addGood() {
        string name, category;
        int price, quantity, size;
        cout << "Enter product name: " << endl;
        cin >> name;
        cout << "Enter product category: " << endl;
        cin >> category;
        cout << "Enter product price: " << endl;
        cin >> price;
        cout << "Enter product quantity: " << endl;
        cin >> quantity;
        cout << "Enter product size: " << endl;
        cin >> size;
        Goods good(name, category, price, quantity, size);
        goods.push_back(good);
 

    }
    /*void loadProducts() {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }*/

    void removeFoods(const string& name) {

        for (int i = 0; i < foods.size(); i++)
        {
            if (foods[i].getName() == name) {
                foods.erase(foods.begin() + i);
                break;
            }
        }
        /*
         ifstream inFile(filename);
         ofstream outFile("temp.txt");

         string line;
         bool found = false;
         while (getline(inFile, line)) {

             size_t pos = line.find("Name: ");
             if (pos != string::npos) {
                 pos += 6;
                 size_t endPos = line.find(" ", pos);
                 string productName = line.substr(pos, endPos - pos);

                 if (productName != name) {
                     outFile << line << endl;
                 }
                 else {
                     found = true;
                 }

         }
         inFile.close();
         outFile.close();

         remove(filename);
         rename("temp.txt", filename);

         if (found) {
             cout << "Product: " << name << " removed successfully." << endl;
         }
         else {
             cout << "Product: " << name << " not found." << endl;
         }
          }*/
    }
    void removeGoods(const string& name) {

        for (int i = 0; i < foods.size(); i++)
        {
            if (goods[i].getName() == name) {
                goods.erase(goods.begin() + i);
                break;
            }
        }
    }
    void findGoods(const string& name) {
        for (int i = 0; i < goods.size(); i++)
        {
            if (goods[i].getName() == name) {
                goods[i].Print();
            }
        }
        /*  ifstream file(filename);
          if (file.is_open()) {
              string line;
              while (getline(file, line)) {
                  size_t pos = line.find("Name: ");
                  if (pos != string::npos) {
                      pos += 6;
                      size_t endPos = line.find(" ", pos);
                      string productName = line.substr(pos, endPos - pos);

                      if (productName == name) {
                          size_t categoryPos = line.find("Category: ");
                          size_t pricePos = line.find("Price: ");
                          size_t quantityPos = line.find("Quantity: ");

                          string category = line.substr(categoryPos + 10, pricePos - categoryPos - 11);
                          int price = stoi(line.substr(pricePos + 7, quantityPos - pricePos - 8));
                          int quantity = stoi(line.substr(quantityPos + 10));

                          Item foundProduct(name, category, price, quantity);
                          file.close();
                          return foundProduct;
                      }
                  }
              }
              file.close();
          }
          return Item("Not found", "", 0, 0);*/
    }
    void findFoods(const string& name) {
        for (int i = 0; i < foods.size(); i++)
        {
            if (goods[i].getName() == name) {
                foods[i].Print();
            }
        }
    }
    void ShowFoods()
    {
        for (int i = 0; i < foods.size(); i++)
        {
            foods[i].Print();
            cout << endl;
        }
    }
    void ShowGoods()
    {
        for (int i = 0; i < goods.size(); i++)
        {
            goods[i].Print();
            cout << endl;
        }
    }
    void BuyFood() {
        int money;
        int count;

        string foodName;
        cout << "Enter the name of the product you want to buy (or enter '0' to go back to the menu): ";
        cin >> foodName;
        cout << "How much money?: " << endl;
        cin >> money;
        cout << "How much quanitity food do you need?: " << endl;
        cin >> count;
        
        //if (money < Price)
        for (int i = 0; i < foods.size(); i++)
        {
            if (foods[i].getName() == foodName) {
                /*goods[i].Print();*/
                if (foods[i].getPrice()*count > money)
                {
                    cout << "Sorry, you do not have enough money to buy the food." << endl;
                }
                else
                {
                    //cout << "How much quanitity food do you need?: " << endl;
                    //cin >> count;
                    cout << "You are buy!!!" << endl;
                    int res=foods[i].getQuantity();
                    res -= count;
                    foods[i].setQuantity(res);
                    int change = foods[i].getPrice();
                    money -= change;
                    cout << "Here's your change: " << money << endl;
                    
                }
                if (foods[i].getQuantity() == 0) {
                    foods.erase(foods.begin() + i);
                }
            }
        }

    }
    void BuyGood() {
        int money;
        int count;
        string goodName;
        cout << "Enter the name of the product you want to buy (or enter '0' to go back to the menu): ";
        cin >> goodName;
        cout << "How much money?: " << endl;
        cin >> money;
        cout << "How much quanitity food do you need?: " << endl;
        cin >> count;
        
        for (int i = 0; i < goods.size(); i++)
        {
            if (foods[i].getName() == goodName) {
                /*goods[i].Print();*/
                if (foods[i].getPrice() * count > money)
                {
                    cout << "Sorry, you do not have enough money to buy the food." << endl;
                }
                else
                {
                    //cout << "How much quanitity food do you need?: " << endl;
                    //cin >> count;
                    cout << "You are buy!!!" << endl;
                    int res = goods[i].getQuantity();
                    res -= count;
                    goods[i].setPrice(res);
                    int change = goods[i].getPrice();
                    money -= change;
                    cout << "Here's your change: " << money << endl;

                }
            }
        }
    }
    void MainMenu()
    {
             int choice;
            
             do
             {
               cout << "=====SHOP=====" << endl;
               cout << "\nMenu:\n1. Show foods\n2. Show goods\n3. Add foods\n4. Add good\n5. Buy foods\n6. Buy goods\n7.Delete foods\n8.Delete goods\n9. Exit" << endl;
               cout << "Enter your choice: ";
               cin >> choice;

               switch (choice) {
               case 1:
                   ShowFoods();
                   break;
               case 2: {
                   /*
                   cout << "Enter product name: " << endl;
                   cin >> name;
                   cout << "Enter product category: " << endl;
                   cin >> category;
                   cout << "Enter product price: " << endl;
                   cin >> price;
                   cout << "Enter product quantity: " << endl;
                   cin >> quantity;
                   Goods product(name, category, price, quantity,45);
                   goods.push_back(product);
                   break;*/
                   ShowGoods();
                   break;
               }
               case 3: {
                       //supermarket.loadProducts();
                       /*ShowFoods();
                       cout << "Enter the name of the product you want to buy (or enter '0' to go back to the menu): ";
                       string productName;
                       cin >> productName;

                       if (productName == "0")
                           break;
                       findFoods(productName);*/
                     /*  Item foundProduct = supermarket.findProduct(productName);
                       if (foundProduct.getName() != "Not found") {
                           cout << "Product found:" << endl;
                           cout << "Name: " << foundProduct.getName() << endl;
                           cout << "Category: " << foundProduct.getCategory() << endl;
                           cout << "Price: " << foundProduct.getPrice() << endl;
                           cout << "Quantity: " << foundProduct.getQuantity() << endl;
                       }
                       else {
                           cout << "Product not found." << endl;
                       }*/
                      addFood();
                      break;
                   //break;
               }
               case 4: {
                   /*addFood();*/
                   addGood();
                   break;
               }
               case 5: {
                   /*ShowFoods();*/
                   BuyFood();
                   break;
                   /*cout << "Enter the name of the product you want to buy (or enter '0' to go back to the menu): ";
                   string productName;
                   cin >> productName;

                   if (productName == "0")
                        break;
                   findFoods(productName);*/
               }
               case 6: {
                   /*string nameToRemove;
                   cout << "Enter the name of the product to remove: ";
                   cin >> nameToRemove;
                   removeFoods(nameToRemove);
                   break;*/
                   ShowGoods();
                   cout << "Enter the name of the product you want to buy (or enter '0' to go back to the menu): ";
                   string productName;
                   cin >> productName;

                   if (productName == "0")
                       break;
                   findGoods(productName);
               }
               case 7: {
                  /* string nameToFind;
                   cout << "Enter the name of the product to find: ";
                   cin >> nameToFind;
                   Item foundProduct = supermarket.findProduct(nameToFind);
                   if (foundProduct.getName() != "Not found") {
                       cout << "Product found:" << endl;
                       cout << "Name: " << foundProduct.getName() << endl;
                       cout << "Category: " << foundProduct.getCategory() << endl;
                       cout << "Price: " << foundProduct.getPrice() << endl;
                       cout << "Quantity: " << foundProduct.getQuantity() << endl;
                   }
                   else {
                       cout << "Product *///not found." << endl;
                   //}
                   string nameToRemove;
                   cout << "Enter the name of the product to remove: ";
                   cin >> nameToRemove;
                   removeFoods(nameToRemove);
                   break;
               }
               case 8: {
                   
                   string nameToRemove;
                   cout << "Enter the name of the product to remove: ";
                   cin >> nameToRemove;
                   removeGoods(nameToRemove);
                   break;
                   /*cout << "Exiting..." << endl;
                   break;*/
               }
               case 9: {

                   //string nameToRemove;
                   //cout << "Enter the name of the product to remove: ";
                   //cin >> nameToRemove;
                   //removeGoods(nameToRemove);
                   //break;
                   cout << "Exiting..." << endl;
                   break;
               }

               default:
                   cout << "Invalid choice. Please try again." << endl;
               }
           } while (choice != 9);

          
           }
    
};
    int main() {
        Supermarket supermarket;
        supermarket.MainMenu();
    }