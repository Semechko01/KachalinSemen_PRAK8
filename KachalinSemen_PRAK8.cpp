
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
struct Employee {
    std::string name;
    std::string position;
    double salary;
};
struct Node {
    Employee data;
    Node* next = nullptr; //после
    Node* prev = nullptr; //пред
};
class Table
{
public:
    Node* head = nullptr; //начало
    Node* tail = nullptr; //конец
    void push_back(Node* element)
    {
        if (tail != nullptr)
        {
            element->next = nullptr;
            element->prev = tail;
            tail->next = element;
            tail = element;
        }
        else
        {
            head = element;
            tail = element;
        }
    }
    void push_front(Node* element)
    {
        if (head != nullptr)
        {
            element->next = head;
            element->prev = nullptr;
            head->prev = element;
            head = element;
        }
        else
        {        
            head = element;
            tail = element;
        }
    }
    void pop_front()
    {     
        Node* heads = head->next;
        delete head;
        head = heads;
        head->prev = nullptr;     

        heads = nullptr;
        delete heads;
    }
    void pop_back()
    {
        Node* tails = tail->prev;
        delete tail;
        tail = tails;
        tail->next = nullptr;

        tails = nullptr;
        delete tails;
    }
    void display_forward()
    {
        Node* s = head;
        while (s != nullptr)
        {
            std::cout << "Имя: " << s->data.name << " | Должность: " << s-> data.position << " | Зарплата: " << s->data.salary << "\n";
            s = s->next;
        }
        s = nullptr;
        delete s;
    }
    void display_backward()
    {
        Node* s = tail;
        while (s != nullptr)
        {
            std::cout << "Имя: " << s->data.name << " | Должность: " << s->data.position << " | Зарплата: " << s->data.salary << "\n";
            s = s->prev;
        }
        s = nullptr;
        delete s;
    }
    void search_element(Employee obj, int element)
    {
        Node* s = head;
        while (s != nullptr)
        {
            if (element == 1)
            {
                if (s->data.name == obj.name)
                {
                    std::cout << "Имя: " << s->data.name << " | Должность: " << s->data.position << " | Зарплата: " << s->data.salary << "\n";
                    s = nullptr;
                    delete s;
                    return;
                }
            }
            else if (element == 2)
            {
                if (s->data.position == obj.position)
                {
                    std::cout << "Имя: " << s->data.name << " | Должность: " << s->data.position << " | Зарплата: " << s->data.salary << "\n";
                    s = nullptr;
                    delete s;
                    return;
                }
            }
            else
            {
                if (s->data.salary == obj.salary)
                {
                    std::cout << "Имя: " << s->data.name << " | Должность: " << s->data.position << " | Зарплата: " << s->data.salary << "\n";
                    s = nullptr;
                    delete s;
                    return;
                }
            }
            s = s->next;
        }
        s = nullptr;
        delete s;
    }
    void search_element_and_delete(Employee obj, int element)
    {
        Node* s = head;
        while (s != nullptr)
        {
            if (element == 1)
            {
                if (s->data.name == obj.name)
                {
                    Node* gg = s->prev;                    
                    Node* gg2 = s->next;
                    if(gg != nullptr)
                        gg->next = gg2;
                    if(gg2 != nullptr)
                        gg2->prev = gg;                    
                    s->next = nullptr;
                    s->prev = nullptr;
                    if (s == head && s != tail)
                    {
                        head = gg2;
                    }
                    else if (s == tail && s != head)
                    {
                        tail = gg;
                    }
                    else if (s == head && s == tail)
                    {
                        head = gg2;
                        tail = gg2;
                    }
                    gg = nullptr;
                    gg2 = nullptr;
                    s = nullptr;
                    delete gg;
                    delete gg2;
                    delete s;
                    return;
                }
            }
            else if (element == 2)
            {
                if (s->data.position == obj.position)
                {
                    Node* gg = s->prev;
                    Node* gg2 = s->next;
                    if (gg != nullptr)
                        gg->next = gg2;
                    if (gg2 != nullptr)
                        gg2->prev = gg;
                    s->next = nullptr;
                    s->prev = nullptr;
                    if (s == head && s != tail)
                    {
                        head = gg2;
                    }
                    else if (s == tail && s != head)
                    {
                        tail = gg;
                    }
                    else if (s == head && s == tail)
                    {
                        head = gg2;
                        tail = gg2;
                    }
                    gg = nullptr;
                    gg2 = nullptr;
                    s = nullptr;
                    delete gg;
                    delete gg2;
                    delete s;
                    return;
                }
            }
            else
            {
                if (s->data.salary == obj.salary)
                {
                    Node* gg = s->prev;
                    Node* gg2 = s->next;
                    if (gg != nullptr)
                        gg->next = gg2;
                    if (gg2 != nullptr)
                        gg2->prev = gg;
                    s->next = nullptr;
                    s->prev = nullptr;
                    if (s == head && s != tail)
                    {
                        head = gg2;
                    }
                    else if (s == tail && s != head)
                    {
                        tail = gg;
                    }
                    else if (s == head && s == tail)
                    {
                        head = gg2;
                        tail = gg2;
                    }
                    gg = nullptr;
                    gg2 = nullptr;
                    s = nullptr;
                    delete gg;
                    delete gg2;
                    delete s;
                    return;
                }
            }
            s = s->next;
        }
        s = nullptr;
        delete s;
    }
    void clear_elements()
    {
        Node* s = head;
        while (s != nullptr)
        {
            Node* heads = s->next;
            delete s;
            s = heads;
            if(s != nullptr)
                s->prev = nullptr;

        }
        head = nullptr;
        tail = nullptr;
    }
    void MAX_PRICE()
    {
        Node* max = head;
        Node* maxi = nullptr;
        double g = -1;
        while (max != nullptr)
        {
            if (max->data.salary > g)
            {
                g = max->data.salary;
                maxi = max;
            }       
            max = max->next;
        }
        
        std::cout << "Имя: " << maxi->data.name << " | Должность: " << maxi->data.position << " | Зарплата: " << maxi->data.salary << "\n";

        max = nullptr;
        maxi = nullptr;
        delete max;
        delete maxi;

    }
    void DELETE_EMPLOYERS_IN_PRICE_MIN(double price)
    {
        Node* s = head;
        while (s != nullptr)
        {
            if (s->data.salary < price)
            {
                Node* gg = s->prev;
                Node* gg2 = s->next;
                if (gg != nullptr)
                    gg->next = gg2;
                if (gg2 != nullptr)
                    gg2->prev = gg;
                s->next = nullptr;
                s->prev = nullptr;
                if(s == head && s != tail)
                { 
                    head = gg2;
                }
                else if (s == tail && s != head)
                {
                    tail = gg;
                }
                else if (s == head && s == tail)
                {
                    head = gg2;
                    tail = gg2;
                }
                s = head;
                gg = nullptr;
                gg2 = nullptr;
                delete gg;
                delete gg2;
                continue;
            }
            s = s->next;
        }
        s = nullptr;
        delete s;
    }
    void GO_IN_TABLE_IN_NAME(Node* obj,std::string name)
    {
        Node* max = head;
        while (max != nullptr)
        {
            if (max->data.name == name)
            {
                Node* gg2 = max->next;
                obj->next = gg2;
                obj->prev = max;
                max->next = obj;
                if (max == tail)
                {
                    tail = obj;
                }
                max = nullptr;
                gg2 = nullptr;
                delete max;
                delete gg2;
                return;
            }
            max = max->next;
        }
        max = nullptr;
        delete max;
        
    }
};
Node* GetEmployer()
{
    try
    {
        std::cout << "Введите имя: ";
        std::string hello = "";
        std::cin.ignore();
        std::getline(std::cin, hello);
        
        if (hello.length() > 50 || hello.length() == 0)
        {
            throw std::invalid_argument("\nИмя должно быть до 50 символов и не пустое");
        }
        std::cout << "\nВведите позицию сотрудника в компании: ";
        std::string hello2 = "";
        std::cin.ignore();
        std::getline(std::cin, hello2);
        if (hello2.length() > 50 || hello2.length() == 0)
        {
            throw std::invalid_argument("\nПозиция сотрудника должна быть до 50 символов и не пустое");
        }
        std::cout << "\nВведите зарплату сотрудника: ";
        double price;
        std::cin >> price;
        if (price < 0)
        {
            throw std::invalid_argument("\nЗарплата не может уходить в минус");
        }
        Employee s = {hello,hello2,price};
        Node* h = new Node{ s };
        return h;
    }
    catch (const std::exception(e))
    {
        std::cout << e.what() << "\n";
        return nullptr;
    }
}

int main()
{
    std::setlocale(LC_ALL,"Russian");
    Table* T_A = new Table();
    Node* obj = new Node{ Employee{"hello","123",123}};
    Node* obj2 = new Node{ Employee{"no_hello","321",999} };
    Node* obj3 = new Node{ Employee{"hello_no","999",133} };
    T_A->push_front(obj);
    T_A->push_front(obj2);
    T_A->push_front(obj3);
    int INT = 0;
    while (true)
    {
        std::cout << "1. Добавить элемент в начало \n2. Добавить элемент в конец \n3. Удалить первый элемент  \n4. Удалить последний элемент  \n5. Вывести список  \n6. Вывести список в обратном порядке \n7. Найти элемент \n8. Найти элемент и удалить \n9. Выполнить индивидуальную операцию №1 \n10. Выполнить индивидуальную операцию №2 \n11. Выполнить индивидуальную операцию №3 \n12. Выход \n13.Очистить все элементы" << "\n";
        std::cin >> INT;
        try
        {
            if (INT < 1 || INT > 13)
            {
                throw std::invalid_argument("Число больше 13 или меньше 1");
            }
            if (INT == 1)
            {
                Node* objzz = GetEmployer();
                if(objzz != nullptr)
                    T_A->push_front(objzz);
            }
            else if (INT == 2)
            {
                Node* objzz = GetEmployer();
                if (objzz != nullptr)
                    T_A->push_back(objzz);
            }
            else if (INT == 3)
            {
                T_A->pop_front();
            }
            else if (INT == 4)
            {
                T_A->pop_back();
            }
            else if (INT == 5)
            {
                T_A->display_forward();
            }
            else if (INT == 6)
            {
                T_A->display_backward();
            }
            else if (INT == 7)
            {
                std::cout << "1. Имя\n2. Должность\n3.Зарплата \n";
                int ij = 0;
                std::cin >> ij;
                if (ij == 1)
                {
                    std::cout << "Введите имя: ";
                    std::string gg;
                    std::cin.ignore();
                    std::getline(std::cin, gg);
                    Employee g = { gg,"-",-1 };
                    T_A->search_element(g,1);
                }
                else if(ij == 2)
                {
                    std::cout << "Введите дожность: ";
                    std::string gg;
                    std::cin.ignore();
                    std::getline(std::cin, gg);
                    Employee g = { "-",gg,-1};
                    T_A->search_element(g, 2);
                }
                else if(ij == 3)
                {
                    std::cout << "Введите зарплату: ";
                    double gg;
                    std::cin >> gg;
                    Employee g = { "-","-",gg};
                    T_A->search_element(g, 3);
                }
                else
                {
                    throw std::invalid_argument("Число больше 3 или меньше 1");
                }
            }
            else if (INT == 8)
            {
                std::cout << "1. Имя\n2. Должность\n3.Зарплата \n";
                int ij = 0;
                std::cin >> ij;
                if (ij == 1)
                {
                    std::cout << "Введите имя: ";
                    std::string gg;
                    std::cin.ignore();
                    std::getline(std::cin, gg);
                    Employee g = { gg,"-",-1 };
                    T_A->search_element_and_delete(g, 1);
                }
                else if (ij == 2)
                {
                    std::cout << "Введите дожность: ";
                    std::string gg;
                    std::cin.ignore();
                    std::getline(std::cin, gg);
                    Employee g = { "-",gg,-1 };
                    T_A->search_element_and_delete(g, 2);
                }
                else if (ij == 3)
                {
                    std::cout << "Введите зарплату: ";
                    double gg;
                    std::cin >> gg;
                    Employee g = { "-","-",gg };
                    T_A->search_element_and_delete(g, 3);
                }
                else
                {
                    throw std::invalid_argument("Число больше 3 или меньше 1");
                }
            }
            else if (INT == 9)
            {
                T_A->MAX_PRICE();
            }
            else if (INT == 10)
            {

                std::cout << "Введите зарплату минимальную: ";
                double f;
                std::cin >> f;
                T_A->DELETE_EMPLOYERS_IN_PRICE_MIN(f);
            }
            else if (INT == 11)
            {
                std::cout << "Введите имя перед которым будет ставить нового сотрудника: ";
                std::string f;
                std::cin.ignore();
                std::getline(std::cin,f);
                Node* newEployer = GetEmployer();
                T_A->GO_IN_TABLE_IN_NAME(newEployer,f);
            }
            else if (INT == 12)
            {
                return 0;
            }
            else if (INT == 13)
            {
                T_A->clear_elements();
            }
            
        }
        catch (const std::exception(e))
        {
            delete obj;
            delete obj2;
            delete obj3;
            delete T_A;
            std::cout << e.what() << "\n";
        }
    }
    delete obj;
    delete obj2;
    delete obj3;
    delete T_A;

}

