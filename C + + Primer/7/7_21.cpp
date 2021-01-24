#include<iostream>
#include<string>
using namespace std;

class Sales_data
{
	friend istream &read(istream &is, Sales_data &item);
	friend ostream &print(ostream &os, const Sales_data &item);
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s) {}
	Sales_data(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data(istream &is) { read(is, *this); }

	string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);

private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

int main()
{
        Sales_data total;
        print(cout,total);
        cout<<endl;
        Sales_data item1("23333-888");
        print(cout,item1);
        cout<<endl;
        Sales_data item2("23333-888",5,23);
        print(cout,item2);
        cout<<endl;
        Sales_data item3(cin);
        print(cout,item3);
        cout<<endl;
        return 0;
}
