#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
	string const& isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);

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

int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
        Sales_data trans;
        while(cin >> total.bookNo >> total.units_sold >> total.revenue)
        {
            if(total.isbn()==trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total=trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	}
	else
	{
		cerr <<"No data?!"<<endl;
        return -1;
	}
	return 0;
}