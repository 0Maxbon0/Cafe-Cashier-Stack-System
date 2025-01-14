#include <iostream>
#include <string>
#include <limits>

using namespace std;

void clearConsole()
{
    system("cls");
}
void menu()
{
cout << "1. Tea (7.5 EGP)\n";
cout << "2. Coffee (15 EGP)\n";
cout << "3. Nescafe (20 EGP)\n";
cout << "4. Sahlab (20 EGP)\n";
cout << "5. Sahlab nuts (27 EGP)\n";
cout << "6. Anise (15 EGP)\n";
cout << "7. Mango Drink (30 EGP)\n";
cout << "8. Grape Drink (20 EGP)\n";
cout << "9. Tea and Milk (15 EGP)\n";
cout << "10. Pepsi - Cola  Drink (15 EGP)\n";
cout << "11. Shesha Fruits (20 EGP)\n";
cout << "12. Shesha (10 EGP)\n";
cout << "0. Done placing orders\n";
cout << "Enter product number to add to order (0 to finish): ";
}
void waitForEnter()
{
    cout << "\n\nPress Enter to continue...\n";
    cout.flush();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    clearConsole();
}

class Node
{
public:
    string order;
    float price;
    Node* next;

    Node(string order, float price)
    {
        this->order=order;
        this->price=price;
        this->next=nullptr;
    }
};

class Stack
{
private:
    Node* top;


public:
    float totalPrice;
    Stack()
    {
        this->totalPrice=0;
        this->top=nullptr;
    }

    void push(string order, float price)
    {
        clearConsole();
        Node* newNode = new Node(order, price);
        newNode->next = top;
        top = newNode;
        totalPrice += price;
        cout << "Order placed successfully: " << order << " (Price: " << price << " EGP)\n";
    }

    void popLast()
    {
        string choice;
        if (isEmpty())
        {
            cout << "No orders to process.\n";
            waitForEnter();
            return;
        }

        cout << "Are you sure you want to delete the last order ? (last order is : " << top->order << " )\nEnter Y/y for confirming or anything else to get back: ";
        cin >> choice;
        if (choice == "Y" || choice == "y")
        {
        string order = top->order;
        float price = top->price;
        Node* temp = top;
        top = top->next;
        delete temp;
        totalPrice -= price;
        cout << "Deleted last order: " << order << " (Price: " << price << " EGP)\n";
            waitForEnter();
        }
        else
        {
            cout << "nothing effect the orders";
            waitForEnter();
        }
        clearConsole();
        return ;
        
        
    }

    void popAll()
    {   string choice;
        if (isEmpty())
        {
            cout << "No orders to process.\n";
            waitForEnter();
            return;
        }

        cout << "Are you sure you want to delete all the orders ? there is no return for this choice\nEnter Y/y for confirming or anything else to get back: ";
        cin >> choice;
        if (choice == "Y" || choice == "y")
        {
           
            do {
                string order = top->order;
                float price = top->price;
                Node* temp = top;
                top = top->next;
                delete temp;
                totalPrice -= price;
            }
             while (top!=nullptr);

            cout << "All the orders have been deleted successfully.\n";
            waitForEnter();
        }
        else
        {
            cout << "nothing effect the orders";
            waitForEnter();
        }
        return;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No orders to display.\n";
            return;
        }
        Node* current = top;
        cout << "Orders in the stack:\n";
        while (current != nullptr)
        {
            cout << current->order << " (Price: " << current->price << " EGP)\n";
            current = current->next;
        }
        cout << "Total Price: " << totalPrice << " EGP\n";
    }

    // ~Stack()
    // {
    //     while (!isEmpty())
    //     {
    //         popLast();
    //     }
    // }
};

int main()
{
    Stack stack;
    int choice;

    do
    {
        cout << "\nCafe Cashier System Menu:                           "
             << "Total price for the current order is : " << stack.totalPrice << " EGP\n";
        cout << "1. Place Order\n";
        cout << "2. Display Orders\n";
        cout << "3. Reset Orders\n";
        cout << "4. Delete Last Order\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        string input;
        cin >> input;

        try
        {
            choice = stoi(input);
            switch (choice)
            {
            case 1:
            {
                clearConsole();
                while (true)
                {
                    cout << endl
                         << "Menu:                                               Total price for the current order is : " << stack.totalPrice << " EGP\n";
                         menu();

                    string input_product;
                    cin >> input_product;
                    int productChoice = stoi(input_product);

                    if (productChoice == 0)
                    {
                        clearConsole();
                        break;
                    }
                    if (productChoice < 1 || productChoice > 12)
                    {
                        clearConsole();
                        cout << "Invalid product choice.\n";

                        continue;
                    }

                    string product;
                    float price;
                    switch (productChoice)
                    {
                    case 1:
                        product = "Tea";
                        price=7.5;
                        break;
                    case 2:
                        product = "Coffee";
                        price=15;
                        break;
                    case 3:
                        product = "Nescafe";
                        price=20;
                        break;
                    case 4:
                        product = "Sahlab";
                        price=20;
                        break;
                    case 5:
                        product = "Sahlab nuts";
                        price=27;
                        break;
                    case 6:
                        product = "Anise";
                        price=15;
                        break;
                    case 7:
                        product = "Mango Drink";
                        price=30;
                        break;
                    case 8:
                        product = "Grape Drink";
                        price=20;
                        break;
                    case 9:
                        product = "Tea and Milk";
                        price=15;
                        break;
                    case 10:
                        product = "Pepsi - Cola  Drink";
                        price=15;
                        break;
                    case 11:
                        product = "Shesha Fruits";
                        price=20;
                        break;
                    case 12:
                        product = "Shesha";
                        price=10;
                        break;
                    }

                    stack.push(product, price);
                }
                break;
            }
            case 2:
            {
                clearConsole();
                stack.display();
                waitForEnter();

                break;
            }
            case 3:
            {
                clearConsole();
                stack.popAll();

                break;
            }
            case 4:
            {
                clearConsole();
                stack.popLast();
                break;
            }
            case 5:
            {
                clearConsole();
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            }
        }
        catch (const invalid_argument &e)
        {
            clearConsole();
            cout << "Invalid choice. Please enter an integer.\n";
            choice = -1;
        }
    } while (choice != 5);

    return 0;
}
