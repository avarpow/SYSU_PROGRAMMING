#include <iostream>
#include <vector>
#include <string>
//#include <iterator>

using namespace std;

struct Customer
{
    string name;
    string phone;
    string address;
};

struct mysort
{
    Customer customer;
    int pre_index;
};

vector<int> accessArray(const vector<Customer> &table)
{
    vector<mysort> sort_customer;
    vector<int> ret;
    for (int i = 0; i < table.size(); i++)
    {
        mysort temp;
        temp.customer = table[i];
        temp.pre_index = i;
        sort_customer.push_back(temp);
    }
    for (int i = sort_customer.size() - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (sort_customer[j - 1].customer.name > sort_customer[j].customer.name)
            {
                mysort temp = sort_customer[j - 1];
                sort_customer[j - 1] = sort_customer[j];
                sort_customer[j] = temp;
            }
        }
    }
    for (int i = 0; i < sort_customer.size(); i++)
    {
        ret.push_back(sort_customer[i].pre_index);
    }
    return ret;
}

int main()
{
    Customer a = {"Wang", "123456", "address1"};
    Customer b = {"Gao", "23456", "address2"};
    Customer c = {"Li", "55688", "address3"};
    Customer d = {"Hao", "56788", "address4"};
    vector<Customer> table;
    table.push_back(a);
    table.push_back(b);
    table.push_back(c);
    table.push_back(d);
    vector<int> ret = accessArray(table);
    for (int i = 0; i < 4; i++)
    {
        cout << ret[i] << endl;
    }
    return 0;
}
