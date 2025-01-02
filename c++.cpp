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
    void deleteOrder(const string &orderName)
{
    if (isEmpty())
    {   clearConsole();

        cout << "No orders to delete.\n";
        waitForEnter();
        return;
    }

    Node *current = top;
    Node *prev = nullptr;

    while (current != nullptr && current->order != orderName)
    {
        prev = current;
        current = current->next;
    }


    if (current != nullptr)
    {

        if (prev == nullptr)
        {
            top = current->next;
        }
        else
        {
            prev->next = current->next;
        }
        totalPrice -= current->price;
        delete current;
        clearConsole();
        cout << "Order \"" << orderName << "\" deleted successfully.\n";
        display();
        waitForEnter();
    }
    else
    {   clearConsole();
        cout << "Order \"" << orderName << "\" not found.\n";
        waitForEnter();
    }
}
    void sortOrders(bool byPrice, bool ascending)
{
    if (isEmpty())
    {   clearConsole();
        cout << "No orders to sort.\n";
        waitForEnter();
        return;
    }

    int size = 0;
    Node *current = top;
    while (current != nullptr)
    {
        size++;
        current = current->next;
    }

    Node **ordersArray = new Node *[size];
    current = top;
    for (int i = 0; i < size; i++)
    {
        ordersArray[i] = current;
        current = current->next;
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            bool swapNeeded = false;
            if (byPrice)
            {
                if (ascending)
                {
                    if (ordersArray[j]->price > ordersArray[j + 1]->price)
                        swapNeeded = true;
                }
                else
                {
                    if (ordersArray[j]->price < ordersArray[j + 1]->price)
                        swapNeeded = true;
                }
            }
            else
            {
                if (ascending)
                {
                    if (ordersArray[j]->order > ordersArray[j + 1]->order)
                        swapNeeded = true;
                }
                else
                {
                    if (ordersArray[j]->order < ordersArray[j + 1]->order)
                        swapNeeded = true;
                }
            }

            if (swapNeeded)
            {
                Node *temp = ordersArray[j];
                ordersArray[j] = ordersArray[j + 1];
                ordersArray[j + 1] = temp;
            }
        }
    }
    top = nullptr;
    for (int i = 0; i < size; i++)
    {
        Node* newNode = new Node(ordersArray[i]->order, ordersArray[i]->price);
        newNode->next = top;
        top = newNode;
    }
    clearConsole();

    delete[] ordersArray;
    cout<<"Orders Sorted Successfully.\n";
    display();
    waitForEnter();
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
        cout << "Orders :\n";
        while (current != nullptr)
        {
            cout << current->order << " (Price: " << current->price << " EGP)\n";
            current = current->next;
        }
        cout << "Total Price: " << totalPrice << " EGP\n";
    }

    // ~Stack()
    // {
    //     if (!isEmpty())
    //         {
    //           popAll();
    //        }
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
        cout << "5. Delete Specific Order\n";
        cout << "6. Sort Orders\n";
        cout << "7. Exit\n";
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
            {   if (!stack.isEmpty()){
                clearConsole();
                stack.display();
                cout<< "\nWhat is the order number you want to delete? \n";
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
                cout<< "Enter your Choice (from 1 to 12): ";
                int deleteChoice;
                cin >> deleteChoice;

                switch (deleteChoice)
                {
                    case 1:
                        stack.deleteOrder("Tea");
                        break;
                    case 2:
                        stack.deleteOrder("Coffee");
                        break;
                    case 3:
                        stack.deleteOrder("Nescafe");
                        break;
                    case 4:
                        stack.deleteOrder("Sahlab");
                        break;
                    case 5:
                        stack.deleteOrder("Sahlab nuts");
                        break;
                    case 6:
                        stack.deleteOrder("Anise");
                        break;
                    case 7:
                        stack.deleteOrder("Mango Drink");
                        break;
                    case 8:
                        stack.deleteOrder("Grape Drink");
                        break;
                    case 9:
                        stack.deleteOrder("Tea and Milk");
                        break;
                    case 10:
                        stack.deleteOrder("Pepsi - Cola  Drink");
                        break;
                    case 11:
                        stack.deleteOrder("Shesha Fruits");
                        break;
                    case 12:
                        stack.deleteOrder("Shesha");
                        break;
                    default:
                        clearConsole();
                        cout << "Invalid order number.\n";
                        waitForEnter();
                        break;
                }
                break;
            }
                else {
                    clearConsole();
                    cout<<"No Orders to delete.";
                    waitForEnter();
                    break;
                }
                break;

            }
            case 6:
            {   if (!stack.isEmpty()){
                clearConsole();
                cout<< "How you need to sort the orders? \n";
                cout<< "1. According to order name - A - Z .\n";
                cout<< "2. According to order name - Z - A .\n";
                cout<< "3. According to order price - Ascending .\n";
                cout<< "4. According to order price - Descending .\n";
                cout<< "Enter your choice: ";
                int nameprice;
                cin>>nameprice;
                switch (nameprice)
                {
                    case 1:
                    {
                        stack.sortOrders(false , false);
                        break;
                    }
                    case 2:
                    {
                        stack.sortOrders(false , true);
                        break;
                    }
                    case 3:
                    {
                        stack.sortOrders(true , false);
                        break;
                    }
                    case 4:
                    {
                        stack.sortOrders(true , true);
                        break;
                    }
                    default:
                    clearConsole();
                    cout << "Invalid choice. Please enter a number between 1 and 4.\n";

                }

                break;}
                else {
                    clearConsole();
                    cout<<"No Orders to sort.";
                    waitForEnter();
                    break;
                }
                break;
            }
            case 7:
            {
                clearConsole();
                cout << "Exiting...\n";
                break;
            }
            default:
                clearConsole();
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            }
        }
        catch (const invalid_argument &e)
        {
            clearConsole();
            cout << "Invalid choice. Please enter an integer.\n";
            choice = -1;
        }
    } while (choice != 7);

    return 0;
}
