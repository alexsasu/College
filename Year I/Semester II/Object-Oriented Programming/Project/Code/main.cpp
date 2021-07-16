#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
fstream in, out, app;


class product
{

protected:
    string type;
    char* product_name;
    double price_in_euros;
    char performance_class;
    bool recommended_for_gaming;
    int n_months;
    string* months;
    int* products_sold_during_last_n_months;
    int n_ratings;
    float* ratings;
    float average_rating;
    const int product_id;
    static int new_product_id;

public:
    product(string type, char* product_name, double price_in_euros, char performance_class, int* products_sold_during_last_n_months, bool recommended_for_gaming, int n_months, string* months, int n_ratings, float* ratings): product_id(new_product_id++)
    {
        this->type = type;

        this->product_name = new char[strlen(product_name)+1];
        strcpy(this->product_name, product_name);

        this->price_in_euros = price_in_euros;
        this->performance_class = performance_class;

        this->products_sold_during_last_n_months = new int[n_months];
        for (int i = 0; i < n_months; i++)
            this->products_sold_during_last_n_months[i] = products_sold_during_last_n_months[i];

        this->recommended_for_gaming = recommended_for_gaming;
        this->n_months = n_months;

        this->months = new string[n_months];
        for (int i = 0; i < n_months; i++)
            this->months[i] = months[i];

        this->n_ratings = n_ratings;

        float aux = 0;
        this->ratings = new float[n_ratings];
        for (int i = 0; i < n_ratings; i++)
        {
            this->ratings[i] = ratings[i];
            aux += ratings[i];
        }

        this->average_rating = aux/n_ratings;
    }
    product(string _type, char* _name, char _performance_class, bool _recommended_for_gaming): product_id(new_product_id++)
    {
        type = _type;
        product_name = new char[strlen(_name)+1];
        strcpy(product_name, _name);
        performance_class = _performance_class;
        recommended_for_gaming = _recommended_for_gaming;

        price_in_euros = 0;
        products_sold_during_last_n_months = nullptr;
        n_months = 0;
        months = nullptr;
        n_ratings = 0;
        ratings = nullptr;
        average_rating = -1;
    }
    product(): product_id(new_product_id++)
    {
        this->type = "-----";

        this->product_name = new char[strlen("-----")+1];
        strcpy(this->product_name, "-----");

        this->price_in_euros = 0;
        this->performance_class = '-';
        this->products_sold_during_last_n_months = nullptr;
        this->recommended_for_gaming = false;
        this->n_months = 0;
        this->months = nullptr;
        this->n_ratings = 0;
        this->ratings = nullptr;
        this->average_rating = 0;
    }
    product(const product& prod): product_id(prod.product_id)
    {
        type = prod.type;

        product_name = new char[strlen(prod.product_name)+1];
        strcpy(product_name, prod.product_name);

        price_in_euros = prod.price_in_euros;
        performance_class = prod.performance_class;

        products_sold_during_last_n_months = new int[prod.n_months];
        for (int i = 0; i < prod.n_months; i++)
            products_sold_during_last_n_months[i] = prod.products_sold_during_last_n_months[i];

        recommended_for_gaming = prod.recommended_for_gaming;
        n_months = prod.n_months;

        months = new string[prod.n_months];
        for (int i = 0; i < prod.n_months; i++)
            months[i] = prod.months[i];

        n_ratings = prod.n_ratings;

        ratings = new float[prod.n_ratings];
        for (int i = 0; i < prod.n_ratings; i++)
            ratings[i] = prod.ratings[i];

        average_rating = prod.average_rating;
    }
    virtual ~product()
    {
        if (this->products_sold_during_last_n_months != nullptr)
            delete []this->products_sold_during_last_n_months;

        if (this->ratings != nullptr)
            delete []this->ratings;

        if (this->product_name != nullptr)
            delete []this->product_name;

        if (this->months != nullptr)
            delete []this->months;
    }

    string get_type()
    {return this->type;}
    char* get_product_name()
    {return this->product_name;}
    double get_price_in_euros()
    {return this->price_in_euros;}
    char get_performance_class()
    {return performance_class;}
    int* get_products_sold_during_last_n_months()
    {return this->products_sold_during_last_n_months;}
    bool get_recommended_for_gaming()
    {return this->recommended_for_gaming;}
    int get_n_months()
    {return this->n_months;}
    string* get_months()
    {return this->months;}
    int get_n_ratings()
    {return this->n_ratings;}
    float* get_ratings()
    {return this->ratings;}
    float get_average_rating()
    {return this->average_rating;}
    int get_product_id()
    {return this->product_id;}
    static int get_new_product_id()
    {return new_product_id;}


    void set_type(string type)
    {this->type = type;}
    void set_product_name(char* product_name)
    {
        if (this->product_name != nullptr)
            delete [] this->product_name;
        this->product_name = new char[strlen(product_name)+1];
        strcpy(this->product_name, product_name);
    }
    void set_price_in_euros(double price_in_euros)
    {this->price_in_euros = price_in_euros;}
    void set_performance_class(char performance_class)
    {this->performance_class = performance_class;}
    void set_products_sold_during_last_n_months(int* products_sold_during_last_n_months)
    {
        if (this->products_sold_during_last_n_months != nullptr)
            delete [] this->products_sold_during_last_n_months;
        this->products_sold_during_last_n_months = new int[this->n_months];
        for (int i = 0; i < this->n_months; i++)
            this->products_sold_during_last_n_months[i] = products_sold_during_last_n_months[i];
    }
    void set_recommended_for_gaming(bool recommended_for_gaming)
    {this->recommended_for_gaming = recommended_for_gaming;}
    void set_n_months(int n_months)
    {this->n_months = n_months;}
    void set_months(string* months)
    {
        if (this->months != nullptr)
            delete [] this->months;
        this->months = new string[this->n_months];
        for (int i = 0; i < this->n_months; i++)
            this->months[i] = months[i];
    }
    void set_n_ratings(int n_ratings)
    {this->n_ratings = n_ratings;}
    void set_ratings(float* ratings)
    {
        if (this->ratings != nullptr)
            delete [] this->ratings;
        this->ratings = new float[this->n_ratings];
        for (int i = 0; i < this->n_ratings; i++)
            this->ratings[i] = ratings[i];
    }
    void set_average_rating(float average_rating)
    {this->average_rating = average_rating;}
    void set_new_product_id(int new_product_id)
    {product::new_product_id = new_product_id;}


    product& operator=(const product& prod);
    const product& operator++();
    const product operator++(int);
    const product& operator--();
    const product operator--(int);
    friend product operator+(product prod, double d);
    friend product operator+(double d, product prod);
    product operator+(product prod);
    product operator+=(double d);
    friend product operator-(product prod, double d);
    friend product operator-(double d, product prod);
    product operator-(product prod);
    friend product operator*(product prod, double d);
    friend product operator*(double d, product prod);
    friend product operator/(product prod, double d);
    friend product operator/(double d, product prod);
    bool operator==(const product& prod);
    bool operator<(const product& prod);
    bool operator>(const product& prod);
    operator int();

    virtual istream& read_product_info(istream& in);
    friend istream& operator>>(istream& in, product& prod);
    virtual ostream& print_product_info(ostream& out)const;
    friend ostream& operator<<(ostream& out, const product& prod);

    void products_success();
    virtual void print_to_file(ostream& out);
    void aux_print_to_file(ostream& out);

};


int product::new_product_id = 1;


product& product::operator=(const product& prod)
{
    if (this != &prod)
    {
        this->type = prod.type;

        if (this->product_name != nullptr)
            delete []this->product_name;
        this->product_name = new char[strlen(prod.product_name)+1];
        strcpy(this->product_name, prod.product_name);

        this->price_in_euros = prod.price_in_euros;
        this->performance_class = prod.performance_class;

        if (this->products_sold_during_last_n_months != nullptr)
            delete []this->products_sold_during_last_n_months;
        this->products_sold_during_last_n_months = new int[prod.n_months];
        for (int i = 0; i < prod.n_months; i++)
            this->products_sold_during_last_n_months[i] = prod.products_sold_during_last_n_months[i];

        this->recommended_for_gaming = prod.recommended_for_gaming;
        this->n_months = prod.n_months;

        if (this->months != nullptr)
            delete []this->months;
        this->months = new string[prod.n_months];
        for (int i = 0; i < prod.n_months; i++)
            this->months[i] = prod.months[i];

        this->n_ratings = prod.n_ratings;

        if (this->ratings != nullptr)
            delete []this->ratings;
        this->ratings = new float[prod.n_ratings];
        for (int i = 0; i < prod.n_ratings; i++)
            this->ratings[i] = prod.ratings[i];

        this->average_rating = prod.average_rating;
    }

    return *this;
}
const product& product::operator++()
{
    this->price_in_euros++;
    return *this;
}
const product product::operator++(int)
{
    product aux=*this;
    this->price_in_euros++;
    return aux;
}
const product& product::operator--()
{
    this->price_in_euros--;
    return *this;
}
const product product::operator--(int)
{
    product aux(*this);
    this->price_in_euros--;
    return aux;
}
product operator+(product prod, double d)
{
    prod.price_in_euros = prod.price_in_euros+d;
    return prod;
}
product operator+(double d, product prod)
{
    prod.price_in_euros = d+prod.price_in_euros;
    return prod;
}
product product::operator+(product prod)
{
    this->price_in_euros = this->price_in_euros+prod.price_in_euros;
    return *this;
}
product product::operator+=(double d)
{
    this->price_in_euros += d;
    return *this;
}
product operator-(product prod, double d)
{
    prod.price_in_euros = prod.price_in_euros-d;
    return prod;
}
product operator-(double d, product prod)
{
    prod.price_in_euros = d-prod.price_in_euros;
    return prod;
}
product product::operator-(product prod)
{
    this->price_in_euros = this->price_in_euros-prod.price_in_euros;
    return *this;
}
product operator*(product prod, double d)
{
    prod.price_in_euros = prod.price_in_euros*d;
    return prod;
}
product operator*(double d, product prod)
{
    prod.price_in_euros = d*prod.price_in_euros;
    return prod;
}
product operator/(product prod, double d)
{
    prod.price_in_euros = prod.price_in_euros/d;
    return prod;
}
product operator/(double d, product prod)
{
    prod.price_in_euros = d/prod.price_in_euros;
    return prod;
}
bool product::operator==(const product& prod)
{return this->price_in_euros==prod.price_in_euros;}
bool product::operator<(const product& prod)
{return this->price_in_euros<prod.price_in_euros;}
bool product::operator>(const product& prod)
{return this->price_in_euros>prod.price_in_euros;}
product::operator int()
{return (int)this->price_in_euros;}


istream& product::read_product_info(istream& in)
{
    cout<<"Insert the product type: ";
    getline(in, this->type);

    cout<<"Insert the product's name: ";
    if (this->product_name != nullptr)
        delete []this->product_name;
    char aux[1001];
    in>>ws;
    in.get(aux, 1001);
    this->product_name = new char[strlen(aux)+1];
    strcpy(this->product_name, aux);

    cout<<"Insert the product's price in EUROS: ";
    in>>this->price_in_euros;

    cout<<"Insert the product's performance class: ";
    in>>this->performance_class;

    cout<<"Is the product recommended for gaming? (1 - Yes/0 - No) ";
    in>>this->recommended_for_gaming;

    cout<<"Insert the number of months to retain: ";
    in>>this->n_months;

    cout<<"Insert the names of the last "<<this->n_months<<" months that are to be retained:\n";
    if (this->months != nullptr)
        delete []this->months;
    this->months = new string[this->n_months];
    for (int i = 0; i < this->n_months; i++)
        in>>this->months[i];

    cout<<"Insert the number of products sold during each of the last "<<this->n_months<<" months:\n";
    if (this->products_sold_during_last_n_months != nullptr)
        delete []this->products_sold_during_last_n_months;
    this->products_sold_during_last_n_months = new int[this->n_months];
    for (int i = 0; i < this->n_months; i++)
        in>>this->products_sold_during_last_n_months[i];

    cout<<"Insert the number of ratings given to the product: ";
    in>>this->n_ratings;

    cout<<"Insert the ratings given to the product:\n";
    float auxf = 0;
    if (this->ratings != nullptr)
        delete []this->ratings;
    this->ratings = new float[this->n_ratings];
    for (int i = 0; i < this->n_ratings; i++)
    {
        in>>this->ratings[i];
        auxf += this->ratings[i];
    }

    this->average_rating = auxf/this->n_ratings;

    return in;
}
istream& operator>>(istream& in, product& prod)
{return prod.read_product_info(in);}
ostream& product::print_product_info(ostream& out)const
{
    out<<"Product type: "<<this->type<<'\n';

    out<<"Product's name: "<<this->product_name<<'\n';

    out<<"Product's price in EUROS: "<<this->price_in_euros<<'\n';

    out<<"Product's performance class: "<<this->performance_class<<'\n';

    out<<"Recommended for gaming: ";
    if (this->recommended_for_gaming)
        out<<"YES";
    else
        out<<"NO";
    out<<'\n';

    out<<"Number of products sold during each of the last "<<this->n_months<<" months:\n";
    for (int i = 0; i < this->n_months; i++)
        out<<'x'<<this->products_sold_during_last_n_months[i]<<" "<<this->months[i]<<'\n';

    out<<"Number of clients' ratings: "<<this->n_ratings<<'\n';

    out<<"Clients' ratings: ";
    for (int i = 0; i < this->n_ratings-1; i++)
        out<<this->ratings[i]<<", ";
    if (this->n_ratings)
        out<<this->ratings[this->n_ratings-1];
    out<<'\n';

    out<<"Average clients' ratings: "<<this->average_rating<<'\n';

    out<<"Product's ID: "<<this->product_id<<'\n';

    return out;
}
ostream& operator<<(ostream& out, const product& prod)
{return prod.print_product_info(out);}


void product::products_success()
{
    if (this->n_ratings>=10)
    {
        if (this->average_rating>=3.5)
            cout<<"The product is well-regarded by clients\n";
        else
            cout<<"The product is not well-regarded by clients\n";
    }
    else
        cout<<"Not enough ratings to determine the product's success\n";
}


void product::print_to_file(ostream& out)
{
    out<<this->type<<'\n';

    out<<this->product_name<<'\n';

    out<<this->price_in_euros<<'\n';

    out<<this->performance_class<<'\n';

    out<<this->recommended_for_gaming<<'\n';

    out<<this->n_months<<'\n';

    for (int i = 0; i < this->n_months; i++)
        out<<this->months[i]<<'\n';

    for (int i = 0; i < this->n_months; i++)
        out<<this->products_sold_during_last_n_months[i]<<'\n';

    out<<this->n_ratings<<'\n';

    for (int i = 0; i < this->n_ratings; i++)
        out<<this->ratings[i]<<'\n';
}
void product::aux_print_to_file(ostream& out)
{
    out<<"Product\n";
    this->print_to_file(out);
    out<<'\n';
}


class prebuilt_system: public product
{

private:
    string system_type;
    int nr_components;
    product* components;

public:
    prebuilt_system(string type, char* product_name, double price_in_euros, char performance_class, int* products_sold_during_last_n_months, bool recommended_for_gaming, int n_months, string* months, int n_ratings, float* ratings, string System_type, int Nr_components, product* components): product(type, product_name, price_in_euros, performance_class, products_sold_during_last_n_months, recommended_for_gaming, n_months, months, n_ratings, ratings), system_type(System_type), nr_components(Nr_components)
    {
        this->components = new product[this->nr_components];
        this->components[0].set_new_product_id(this->components[0].get_new_product_id()-this->nr_components);
        for (int i = 0; i < this->nr_components; i++)
            this->components[i] = components[i];
    }
    prebuilt_system(string System_type, int Nr_components, product* components): product(), system_type(System_type), nr_components(Nr_components)
    {
        this->components = new product[this->nr_components];
        this->components[0].set_new_product_id(this->components[0].get_new_product_id()-this->nr_components);
        for (int i = 0; i < this->nr_components; i++)
            this->components[i] = components[i];
    }
    prebuilt_system(): product(), system_type("-----"), nr_components(0), components(nullptr){}
    prebuilt_system(const prebuilt_system& sys): product(sys), system_type(sys.system_type), nr_components(sys.nr_components)
    {
        this->components = new product[sys.nr_components];
        this->components[0].set_new_product_id(this->components[0].get_new_product_id()-sys.nr_components);
        for (int i = 0; i < sys.nr_components; i++)
            this->components[i] = sys.components[i];
    }
    ~prebuilt_system()
    {
        if (this->components != nullptr)
            delete []this->components;
    }


    string get_system_type()
    {return this->system_type;}
    int get_nr_components()
    {return this->nr_components;}
    product* get_components()
    {return this->components;}


    void set_system_type(string system_type)
    {this->system_type = system_type;}
    void set_nr_components(int nr_components)
    {this->nr_components = nr_components;}
    void set_components(product* components)
    {
        if (this->components != nullptr)
            delete []this->components;
        this->components = new product[this->nr_components];
        this->components[0].set_new_product_id(this->components[0].get_new_product_id()-this->nr_components);
        for (int i = 0; i < this->nr_components; i++)
            this->components[i] = components[i];
    }


    prebuilt_system& operator=(const prebuilt_system& syst)
    {
        if (this != &syst)
        {
            product::operator=(syst);

            this->system_type = syst.system_type;
            this->nr_components = syst.nr_components;

            if (this->components != nullptr)
                delete []this->components;
            this->components = new product[this->nr_components];
            this->components[0].set_new_product_id(this->components[0].get_new_product_id()-this->nr_components);
            for (int i = 0; i < this->nr_components; i++)
                this->components[i] = syst.components[i];
        }

        return *this;
    }


    istream& read_product_info(istream& in)
    {
        product::read_product_info(in);

        cout<<"Insert the type of the prebuilt system: ";
        in.get();
        getline(in, this->system_type);

        cout<<"Insert the number of components included in the system: ";
        in>>this->nr_components;

        cout<<"Insert the components included in the system:\n";
        if (this->components != nullptr)
            delete []this->components;
        this->components = new product[this->nr_components];
        this->components[0].set_new_product_id(this->components[0].get_new_product_id()-this->nr_components);
        for (int i = 0; i < this->nr_components; i++)
        {
            in.get();
            in>>this->components[i];
        }

        return in;
    }
    ostream& print_product_info(ostream& out)const
    {
        product::print_product_info(out);

        out<<"System's type: "<<this->system_type<<'\n';

        out<<"System's number of components: "<<this->nr_components<<'\n';

        out<<"System's components:\n";
        for (int i = 0; i < this->nr_components; i++)
        {
            out<<"-----------------------------\n";

            out<<"Product type: "<<this->components[i].get_type()<<'\n';

            out<<"Product's name: "<<this->components[i].get_product_name()<<'\n';

            out<<"Product's price in EUROS: "<<this->components[i].get_price_in_euros()<<'\n';

            out<<"Product's performance class: "<<this->components[i].get_performance_class()<<'\n';

            out<<"Recommended for gaming: ";
            if (this->components[i].get_recommended_for_gaming())
                out<<"YES";
            else
                out<<"NO";
            out<<'\n';
        }

        out<<"-----------------------------\n";

        return out;
    }


    void print_to_file(ostream& out)
    {
        out<<"Prebuilt_system\n";

        product::print_to_file(out);

        out<<this->system_type<<'\n';

        out<<this->nr_components<<'\n';

        for (int i = 0; i < this->nr_components; i++)
            this->components[i].print_to_file(out);

        out<<'\n';
    }

};


class client
{

private:
    char* client_name;
    int nr_of_membership_months;
    int n_months;
    string* months;
    int* nr_of_different_products_bought_each_month;
    int n_products;
    string* products;
    int* nr_of_products_bought;
    const int client_id;
    static int new_client_id;

public:
    client(char* _client_name, int _nr_of_membership_months, int _n_months, string* _months, int* _nr_of_different_products_bought_each_month, int _n_products, string* _products, int* _nr_of_products_bought): client_id(new_client_id++)
    {
        client_name = new char[strlen(_client_name)+1];
        strcpy(client_name, _client_name);

        nr_of_membership_months = _nr_of_membership_months;

        n_months = _n_months;

        months = new string[n_months];
        for (int i = 0; i < n_months; i++)
            months[i] = _months[i];

        nr_of_different_products_bought_each_month = new int[n_months];
        for (int i = 0; i < n_months; i++)
            nr_of_different_products_bought_each_month[i]=_nr_of_different_products_bought_each_month[i];

        n_products = _n_products;

        products = new string[_n_products];
        for (int i = 0; i < _n_products; i++)
            products[i] = _products[i];

        nr_of_products_bought = new int[_n_products];
        for (int i = 0; i < _n_products; i++)
            nr_of_products_bought[i] = _nr_of_products_bought[i];
    }
    client(char* _client_name): client_id(new_client_id++)
    {
        client_name = new char[strlen(_client_name)+1];
        strcpy(client_name, _client_name);

        nr_of_membership_months = 0;
        n_months = 0;
        months = nullptr;
        nr_of_different_products_bought_each_month = nullptr;
        n_products = 0;
        products = nullptr;
        nr_of_products_bought = nullptr;
    }
    client(): client_id(new_client_id++)
    {
        client_name = new char[strlen("-----")];
        strcpy(client_name, "-----");

        nr_of_membership_months = 0;
        n_months = 0;
        months = nullptr;
        nr_of_different_products_bought_each_month = nullptr;
        n_products = 0;
        products = nullptr;
        nr_of_products_bought = nullptr;
    }
    client(const client& cli): client_id(cli.client_id)
    {
        client_name = new char[strlen(cli.client_name)+1];
        strcpy(client_name, cli.client_name);

        nr_of_membership_months = cli.nr_of_membership_months;

        n_months = cli.n_months;

        months = new string[n_months];
        for (int i = 0; i < n_months; i++)
            months[i] = cli.months[i];

        nr_of_different_products_bought_each_month = new int[n_months];
        for (int i = 0; i < n_months; i++)
            nr_of_different_products_bought_each_month[i] = cli.nr_of_different_products_bought_each_month[i];

        n_products = cli.n_products;

        products = new string[cli.n_products];
        for (int i = 0; i < cli.n_products; i++)
            products[i] = cli.products[i];

        nr_of_products_bought = new int[cli.n_products];
        for (int i = 0; i < cli.n_products; i++)
            nr_of_products_bought[i] = cli.nr_of_products_bought[i];
    }
    ~client()
    {
        if (this->client_name != nullptr)
            delete []this->client_name;

        if (this->months != nullptr)
            delete []this->months;

        if (this->nr_of_different_products_bought_each_month != nullptr)
            delete []this->nr_of_different_products_bought_each_month;

        if (this->products != nullptr)
            delete []this->products;

        if (this->nr_of_products_bought != nullptr)
            delete []this->nr_of_products_bought;
    }


    char* get_client_name()
    {return client_name;}
    int get_nr_of_membership_months()
    {return nr_of_membership_months;}
    int get_n_months()
    {return n_months;}
    string* get_months()
    {return months;}
    int* get_nr_of_different_products_bought_each_month()
    {return nr_of_different_products_bought_each_month;}
    int get_n_products()
    {return n_products;}
    string* get_products()
    {return products;}
    int* get_nr_of_products_bought()
    {return nr_of_products_bought;}
    int get_client_id()
    {return client_id;}
    static int get_new_client_id()
    {return new_client_id;}


    void set_client_name(char* Client_name)
    {
        if (client_name != nullptr)
            delete []client_name;
        client_name = new char[strlen(Client_name)+1];
        strcpy(client_name, Client_name);
    }
    void set_nr_of_membership_months(int Nr_of_membership_months)
    {nr_of_membership_months = Nr_of_membership_months;}
    void set_n_months(int N_months)
    {n_months = N_months;}
    void set_months(string* Months)
    {
        if (months != nullptr)
            delete []months;
        months = new string[n_months];
        for (int i = 0; i < n_months; i++)
            months[i] = Months[i];
    }
    void set_nr_of_different_products_bought_each_month(int* Nr_of_different_products_bought_each_month)
    {
        if (nr_of_different_products_bought_each_month != nullptr)
            delete []nr_of_different_products_bought_each_month;
        nr_of_different_products_bought_each_month = new int[n_months];
        for (int i = 0; i < n_months; i++)
            nr_of_different_products_bought_each_month[i] = Nr_of_different_products_bought_each_month[i];
    }
    void set_n_products(int N_products)
    {n_products = N_products;}
    void set_products(string* Products)
    {
        if (products != nullptr)
            delete []products;
        products = new string[n_products];
        for (int i = 0; i < n_products; i++)
            products[i] = Products[i];
    }
    void set_nr_of_products_bought(int* Nr_of_products_bought)
    {
        if (nr_of_products_bought != nullptr)
            delete []nr_of_products_bought;
        nr_of_products_bought = new int[n_products];
        for (int i = 0; i < n_products; i++)
            nr_of_products_bought[i] = Nr_of_products_bought[i];
    }
    void set_new_client_id(int new_client_id)
    {client::new_client_id = new_client_id;}


    client& operator=(const client& cl);
    const client& operator++();
    const client operator++(int);
    friend client operator+(client cli, int x);
    friend client operator+(int x, client cli);
    client operator+(client cli);
    string operator[](int index);
    bool operator<(const client& cli)const;

    friend istream& operator>>(istream& in, client& cl);
    friend ostream& operator<<(ostream& out, const client& cl);

    void membership_status();
    void print_to_file(ostream& out)const;

};


int client::new_client_id = 100000;


client& client::operator=(const client& cli)
{
    if (this != &cli)
    {
        if (client_name != nullptr)
            delete []client_name;
        client_name = new char[strlen(cli.client_name)+1];
        strcpy(client_name, cli.client_name);

        nr_of_membership_months = cli.nr_of_membership_months;

        n_months = cli.n_months;

        if (months != nullptr)
            delete []months;
        months = new string[n_months];
        for (int i = 0; i < n_months; i++)
            months[i] = cli.months[i];

        if (nr_of_different_products_bought_each_month != nullptr)
            delete []nr_of_different_products_bought_each_month;
        nr_of_different_products_bought_each_month = new int[n_months];
        for (int i = 0; i < n_months; i++)
            nr_of_different_products_bought_each_month[i] = cli.nr_of_different_products_bought_each_month[i];

        n_products = cli.n_products;

        if (products != nullptr)
            delete []products;
        products = new string[cli.n_products];
        for (int i = 0; i < cli.n_products; i++)
            products[i] = cli.products[i];

        if (nr_of_products_bought != nullptr)
            delete []nr_of_products_bought;
        nr_of_products_bought = new int[cli.n_products];
        for (int i = 0; i < cli.n_products; i++)
            nr_of_products_bought[i] = cli.nr_of_products_bought[i];
    }

    return *this;
}
const client& client::operator++()
{
    this->nr_of_membership_months++;
    return *this;
}
const client client::operator++(int)
{
    client aux(*this);
    this->nr_of_membership_months++;
    return aux;
}
client operator+(client cli, int x)
{
    cli.nr_of_membership_months = cli.nr_of_membership_months+x;
    return cli;
}
client operator+(int x, client cli)
{
    cli.nr_of_membership_months = x+cli.nr_of_membership_months;
    return cli;
}
client client::operator+(client cli)
{
    this->nr_of_membership_months += cli.nr_of_membership_months;
    return *this;
}
string client::operator[](int index)
{
    if ((index>=0) && (index<this->n_products))
        return this->products[index];
    else
    {
        return  "WRONG INDEX";
    }
}
bool client::operator<(const client& cli)const
{
    if (strcmp(this->client_name, cli.client_name) < 0)
        return true;
    else
        if (!strcmp(this->client_name, cli.client_name))
            return (this->client_id < cli.client_id);
        else
            return false;
}


istream& operator>>(istream& in, client& cli)
{
    cout<<"Insert the client's name: ";
    if (cli.client_name != nullptr)
        delete []cli.client_name;
    char aux[101];
    in.get(aux, 101);
    cli.client_name = new char[strlen(aux)+1];
    strcpy(cli.client_name, aux);

    cout<<"Insert the client's number of membership months: ";
    in>>cli.nr_of_membership_months;

    cout<<"Insert the number of months that are to be interrogated: ";
    in>>cli.n_months;

    cout<<"Insert the names of the last "<<cli.n_months<<" that are to be interrogatred:\n";
    if (cli.months != nullptr)
        delete []cli.months;
    cli.months = new string[cli.n_months];
    for (int i = 0; i < cli.n_months; i++)
        in>>cli.months[i];

    cout<<"Insert how many different products the client has bought during each of the last "<<cli.n_months<<" months:\n";
    if (cli.nr_of_different_products_bought_each_month != nullptr)
        delete []cli.nr_of_different_products_bought_each_month;
    cli.nr_of_different_products_bought_each_month = new int[cli.n_months];
    for (int i = 0; i < cli.n_months; i++)
        in>>cli.nr_of_different_products_bought_each_month[i];

    cout<<"Insert the number of different products that the client has bought during the last "<<cli.n_months<<" months:\n";
    in>>cli.n_products;

    cout<<"Insert the names of the products that the client has bought during the last "<<cli.n_months<<" months:\n";
    in.get();
    if (cli.products != nullptr)
        delete []cli.products;
    cli.products = new string[cli.n_products];
    for (int i = 0; i < cli.n_products; i++)
        getline(in, cli.products[i]);

    cout<<"Insert how many of each distinct product the client has bought during the last "<<cli.n_months<<" months:\n";
    if (cli.nr_of_products_bought != nullptr)
        delete []cli.nr_of_products_bought;
    cli.nr_of_products_bought = new int[cli.n_products];
    for (int i = 0; i < cli.n_products; i++)
        in>>cli.nr_of_products_bought[i];
    in.get();

    return in;
}
ostream& operator<<(ostream& out, const client& cli)
{
    out<<"Client's name: "<<cli.client_name<<'\n';

    out<<"Months of membership: "<<cli.nr_of_membership_months<<'\n';

    out<<"Number of different products bought during the last "<<cli.n_months<<" months: "<<cli.n_products<<'\n';

    out<<"Number of different products bought during each of the last "<<cli.n_months<<" months:\n";
    for (int i = 0; i < cli.n_months; i++)
        out<<'x'<<cli.nr_of_different_products_bought_each_month[i]<<" "<<cli.months[i]<<'\n';

    out<<"Quantity and names of the products bought during the last "<<cli.n_months<<" months: "<<'\n';
    for (int i = 0; i < cli.n_products; i++)
        out<<'x'<<cli.nr_of_products_bought[i]<<" "<<cli.products[i]<<'\n';

    out<<"Client's ID: "<<cli.client_id<<'\n';

    return out;
}


void client::membership_status()
{
    if (this->nr_of_membership_months>=9)
        cout<<"The client is an old member of our community";
    else
        cout<<"The client is a new member of our community";

    if (this->n_months>=4)
    {
        int aux = 0, i;
        for (i = 0; i < this->n_months; i++)
            if (this->nr_of_different_products_bought_each_month[i])
                aux+=1;
            else
                aux-=1;

        if (aux>=0)
            cout<<" and has been constant in buying our products\n";
        else
            cout<<" and has not been constant in buying our products\n";
    }
    else
        cout<<" and their status cannot be determined based on the number of months interrogated\n";
}
void client::print_to_file(ostream& out)const
{
    out<<"Client\n";

    out<<this->client_name<<'\n';

    out<<this->nr_of_membership_months<<'\n';

    out<<this->n_months<<'\n';

    for (int i = 0; i < this->n_months; i++)
        out<<this->months[i]<<'\n';

    for (int i = 0; i < this->n_months; i++)
        out<<this->nr_of_different_products_bought_each_month[i]<<'\n';

    out<<this->n_products<<'\n';

    for (int i = 0; i < this->n_products; i++)
        out<<this->products[i]<<'\n';

    for (int i = 0; i < this->n_products; i++)
        out<<this->nr_of_products_bought[i]<<'\n';

    out<<'\n';
}


class service
{

protected:
    char* service_name;
    string description;
    double price_in_euros;
    const int service_id;
    static int new_service_id;

public:
    service(char* service_name, string description, double price_in_euros): service_id(new_service_id++)
    {
        this->service_name = new char[strlen(service_name)+1];
        strcpy(this->service_name, service_name);

        this->description = description;
        this->price_in_euros = price_in_euros;
    }
    service(char* service_name): service_id(new_service_id++)
    {
        this->service_name = new char[strlen(service_name)+1];
        strcpy(this->service_name, service_name);

        this->description = "-----";
        this->price_in_euros = 0;
    }
    service(): service_id(new_service_id++)
    {
        this->service_name = new char[strlen("-----")];
        strcpy(this->service_name, "-----");

        this->description = "-----";
        this->price_in_euros = 0;
    }
    service(const service& serv): service_id(serv.service_id)
    {
        this->service_name = new char[strlen(serv.service_name)+1];
        strcpy(this->service_name, serv.service_name);

        this->description = serv.description;
        this->price_in_euros = serv.price_in_euros;
    }
    virtual ~service()
    {
        if (this->service_name != nullptr)
            delete []this->service_name;
    }


    char* get_service_name()
    {return this->service_name;}
    string get_description()
    {return this->description;}
    double get_price_in_euros()
    {return this->price_in_euros;}
    int get_service_id()
    {return this->service_id;}
    static int get_new_service_id()
    {return new_service_id;}


    void set_service_name(char* service_name)
    {
        if (this->service_name != nullptr)
            delete []this->service_name;
        this->service_name = new char[strlen(service_name)+1];
        strcpy(this->service_name, service_name);
    }
    void set_description(string description)
    {this->description = description;}
    void set_price_in_euros(double price_in_euros)
    {this->price_in_euros = price_in_euros;}
    void set_new_service_id(int new_service_id)
    {service::new_service_id = new_service_id;}

    service& operator=(const service& serv);
    const service& operator++();
    const service operator++(int);
    friend service operator+(service serv, double d);
    friend service operator+(double d, service serv);
    friend service operator+(service serv, string str);
    friend service operator+(string str, service serv);
    friend service operator-(service serv, double d);
    friend service operator-(double d, service serv);
    friend service operator*(service serv, double d);
    friend service operator*(double d, service serv);
    friend service operator/(service serv, double d);
    friend service operator/(double d, service serv);

    virtual istream& read_service_info(istream& in);
    friend istream& operator>>(istream& in, service& serv);
    virtual ostream& print_service_info(ostream& out)const;
    friend ostream& operator<<(ostream& out, const service& serv);

    void service_type();
    virtual void print_to_file(ostream& out);
    void aux_print_to_file(ostream& out);

};


int service::new_service_id = 200000;


service& service::operator=(const service& serv)
{
    if (this != &serv)
    {
        if (this->service_name != nullptr)
            delete []this->service_name;
        this->service_name = new char[strlen(serv.service_name)+1];
        strcpy(this->service_name, serv.service_name);

        this->description = serv.description;
        this->price_in_euros = serv.price_in_euros;
    }

    return *this;
}
const service& service::operator++()
{
    this->price_in_euros++;
    return *this;
}
const service service::operator++(int)
{
    service aux=(*this);
    this->price_in_euros++;
    return aux;
}
service operator+(service serv, double d)
{
    serv.price_in_euros = serv.price_in_euros+d;
    return serv;
}
service operator+(double d, service serv)
{
    serv.price_in_euros = d+serv.price_in_euros;
    return serv;
}
service operator+(service serv, string str)
{
    serv.description = serv.description+str;
    return serv;
}
service operator+(string str, service serv)
{
    serv.description = str+serv.description;
    return serv;
}
service operator-(service serv, double d)
{
    serv.price_in_euros = serv.price_in_euros-d;
    return serv;
}
service operator-(double d, service serv)
{
    serv.price_in_euros = d-serv.price_in_euros;
    return serv;
}
service operator*(service serv, double d)
{
    serv.price_in_euros = serv.price_in_euros*d;
    return serv;
}
service operator*(double d, service serv)
{
    serv.price_in_euros = d*serv.price_in_euros;
    return serv;
}
service operator/(service serv, double d)
{
    serv.price_in_euros = serv.price_in_euros/d;
    return serv;
}
service operator/(double d, service serv)
{
    serv.price_in_euros = d/serv.price_in_euros;
    return serv;
}


istream& service::read_service_info(istream& in)
{
    if (this->service_name != nullptr)
        delete []this->service_name;
    cout<<"Insert the service's name: ";
    char aux[101];
    in.get(aux, 101);
    in.get();
    this->service_name = new char[strlen(aux)+1];
    strcpy(this->service_name, aux);

    cout<<"Insert the service's description: ";
    getline(in, this->description);

    cout<<"Insert the cost of the service in EUROS: ";
    in>>this->price_in_euros;

    return in;
}
istream& operator>>(istream& in, service& serv)
{return serv.read_service_info(in);}
ostream& service::print_service_info(ostream& out)const
{
    out<<"Service's name: "<<this->service_name<<'\n';

    out<<"Service's description: "<<this->description<<'\n';

    out<<"Service's price in EUROS: "<<this->price_in_euros<<'\n';

    out<<"Service's ID: "<<this->service_id<<'\n';

    return out;
}
ostream& operator<<(ostream& out, const service& serv)
{return serv.print_service_info(out);}


void service::service_type()
{
    if ((this->description).length()>=500)
    {
        if (this->price_in_euros>=50)
            cout<<"Complex, premium quality service\n";
        else
            cout<<"Complex, standard quality service\n";
    }
    else
    {
        if (this->price_in_euros>=50)
            cout<<"Simple, premium quality service\n";
        else
            cout<<"Simple, standard quality service\n";
    }
}
void service::print_to_file(ostream& out)
{
    out<<this->service_name<<'\n';

    out<<this->description<<'\n';

    out<<this->price_in_euros<<'\n';
}
void service::aux_print_to_file(ostream& out)
{
    out<<"Service\n";
    print_to_file(out);
    out<<'\n';
}


class diagnostic_service: public service
{

private:
    int nr_of_types_components_included;
    string* types_of_components_included;

public:
    diagnostic_service(char* service_name, string description, double price_in_euros, int Nr_of_types_components_included, string* types_of_components_included): service(service_name, description, price_in_euros), nr_of_types_components_included(Nr_of_types_components_included)
    {
        this->types_of_components_included = new string[nr_of_types_components_included];
        for (int i = 0; i < nr_of_types_components_included; i++)
            this->types_of_components_included[i] = types_of_components_included[i];
    }
    diagnostic_service(): service(), nr_of_types_components_included(0), types_of_components_included(nullptr){}
    diagnostic_service(const diagnostic_service& rep_serv): service(rep_serv), nr_of_types_components_included(rep_serv.nr_of_types_components_included)
    {
        this->types_of_components_included = new string[nr_of_types_components_included];
        for (int i = 0; i < this->nr_of_types_components_included; i++)
            this->types_of_components_included[i] = rep_serv.types_of_components_included[i];
    }
    ~diagnostic_service()
    {
        if (this->types_of_components_included != nullptr)
            delete []this->types_of_components_included;
    }


    int get_nr_of_types_components_included()
    {return this->nr_of_types_components_included;}
    string* get_types_of_components_included()
    {return this->types_of_components_included;}


    void set_nr_of_types_components_included(int nr_of_types_components_included)
    {this->nr_of_types_components_included = nr_of_types_components_included;}
    void set_types_of_components_included(string* types_of_components_included)
    {
        if (this->types_of_components_included != nullptr)
            delete []this->types_of_components_included;

        this->types_of_components_included = new string[this->nr_of_types_components_included];
        for (int i = 0; i < this->nr_of_types_components_included; i++)
            this->types_of_components_included[i] = types_of_components_included[i];
    }


    diagnostic_service& operator=(const diagnostic_service& diag_serv)
    {
        if (this != &diag_serv)
        {
            service::operator=(diag_serv);

            this->nr_of_types_components_included = diag_serv.nr_of_types_components_included;

            if (this->types_of_components_included != nullptr)
                delete []this->types_of_components_included;
            this->types_of_components_included = new string[this->nr_of_types_components_included];
            for (int i = 0; i < this->nr_of_types_components_included; i++)
                this->types_of_components_included[i] = diag_serv.types_of_components_included[i];
        }

        return *this;
    }


    istream& read_service_info(istream& in)
    {
        service::read_service_info(in);

        cout<<"Insert the number of types of products included in the diagnostic service's offer: ";
        in>>this->nr_of_types_components_included;

        cout<<"Insert the types of products included in the diagnostic service's offer:\n";
        if (this->types_of_components_included != nullptr)
            delete []this->types_of_components_included;
        this->types_of_components_included = new string[this->nr_of_types_components_included];
        in.get();
        for (int i = 0; i < this->nr_of_types_components_included; i++)
            getline(in, this->types_of_components_included[i]);

        return in;
    }
    ostream& print_service_info(ostream& out)const
    {
        service::print_service_info(out);

        out<<"The number of types of products included in the diagnostic service's offer: "<<this->nr_of_types_components_included<<'\n';

        out<<"The types of products included in the diagnostic service's offer:\n";
        for (int i = 0; i < this->nr_of_types_components_included; i++)
            out<<this->types_of_components_included[i]<<'\n';

        return out;
    }


    void print_to_file(ostream& out)
    {
        out<<"Diagnostic_service\n";

        service::print_to_file(out);

        out<<this->nr_of_types_components_included<<'\n';

        for (int i = 0; i < this->nr_of_types_components_included; i++)
            out<<this->types_of_components_included[i]<<'\n';

        out<<'\n';
    }

};


class promotion
{

private:
    string promotion_name;
    int promotion_type;
    int nr_prod_arr1;
    string* prod_arr1;
    int* nr_each_prod_arr1;
    int nr_prod_arr2;
    string* prod_arr2;
    int* nr_each_prod_arr2;
    double promotion_discount;
    const int promotion_id;
    static int new_promotion_id;

public:
    promotion(string promotion_name, int promotion_type, int nr_prod_arr1, string* prod_arr1, int* nr_each_prod_arr1, int nr_prod_arr2, string* prod_arr2, int* nr_each_prod_arr2);
    promotion(string promotion_name, int promotion_type, int nr_prod_arr1, string* prod_arr1, int* nr_each_prod_arr1, double promotion_discount);
    promotion();
    promotion(const promotion& promo);
    ~promotion();

    string get_promotion_name();
    int get_promotion_type();
    int get_nr_prod_arr1();
    string* get_prod_arr1();
    int* get_nr_each_prod_arr1();
    int get_nr_prod_arr2();
    string* get_prod_arr2();
    int* get_nr_each_prod_arr2();
    double get_promotion_discount();
    int get_promotion_id();
    static int get_new_promotion_id();

    void set_promotion_name(string promotion_name);
    void set_promotion_type(int promotion_type);
    void set_nr_prod_arr1(int nr_prod_arr1);
    void set_prod_arr1(string* prod_arr1);
    void set_nr_each_prod_arr1(int* nr_each_prod_arr1);
    void set_nr_prod_arr2(int nr_prod_arr2);
    void set_prod_arr2(string* prod_arr2);
    void set_nr_each_prod_arr2(int* nr_each_prod_arr2);
    void set_promotion_discount(double promotion_discount);
    void set_new_promotion_id(int new_promotion_id);

    promotion& operator=(const promotion& promo);

    friend istream& operator>>(istream& in, promotion& promo);
    friend ostream& operator<<(ostream& out, const promotion& promo);

    void promotion_details();
    void print_to_file(ostream& out);

};


int promotion::new_promotion_id = 300000;


promotion::promotion(string promotion_name, int promotion_type, int nr_prod_arr1, string* prod_arr1, int* nr_each_prod_arr1, int nr_prod_arr2, string* prod_arr2, int* nr_each_prod_arr2): promotion_id(new_promotion_id++)
{
    this->promotion_name = promotion_name;
    this->promotion_type = promotion_type;

    this->nr_prod_arr1 = nr_prod_arr1;
    this->prod_arr1 = new string[this->nr_prod_arr1];
    for (int i = 0; i < this->nr_prod_arr1; i++)
        this->prod_arr1[i] = prod_arr1[i];
    this->nr_each_prod_arr1 = new int[this->nr_prod_arr1];
    for (int i = 0; i < this->nr_prod_arr1; i++)
        this->nr_each_prod_arr1[i] = nr_each_prod_arr1[i];

    this->nr_prod_arr2 = nr_prod_arr2;
    this->prod_arr2 = new string[this->nr_prod_arr2];
    for (int i = 0; i < this->nr_prod_arr2; i++)
        this->prod_arr2[i] = prod_arr2[i];
    this->nr_each_prod_arr2 = new int[this->nr_prod_arr2];
    for (int i = 0; i < this->nr_prod_arr2; i++)
        this->nr_each_prod_arr2[i] = nr_each_prod_arr2[i];

    this->promotion_discount = 0;
}
promotion::promotion(string promotion_name, int promotion_type, int nr_prod_arr1, string* prod_arr1, int* nr_each_prod_arr1, double promotion_discount): promotion_id(new_promotion_id++)
{
    this->promotion_name = promotion_name;
    this->promotion_type = promotion_type;

    this->nr_prod_arr1 = nr_prod_arr1;
    this->prod_arr1 = new string[this->nr_prod_arr1];
    for (int i = 0; i < this->nr_prod_arr1; i++)
        this->prod_arr1[i] = prod_arr1[i];
    this->nr_each_prod_arr1 = new int[this->nr_prod_arr1];
    for (int i = 0; i < this->nr_prod_arr1; i++)
         this->nr_each_prod_arr1[i] = nr_each_prod_arr1[i];

    this->nr_prod_arr2 = 0;
    this->prod_arr2 = nullptr;
    this->nr_each_prod_arr2 = nullptr;

    this->promotion_discount = promotion_discount;
}
promotion::promotion(): promotion_id(new_promotion_id++)
{
    this->promotion_name = "-----";
    this->promotion_type = 0;
    this->nr_prod_arr1 = 0;
    this->prod_arr1 = nullptr;
    this->nr_each_prod_arr1 = nullptr;
    this->nr_prod_arr2 = 0;
    this->prod_arr2 = nullptr;
    this->nr_each_prod_arr2 = nullptr;
    this->promotion_discount = 0;
}
promotion::promotion(const promotion& promo): promotion_id(promo.promotion_id)
{
    this->promotion_name = promo.promotion_name;
    this->promotion_type = promo.promotion_type;

    this->nr_prod_arr1 = promo.nr_prod_arr1;
    this->prod_arr1 = new string[this->nr_prod_arr1];
    for (int i = 0; i < this->nr_prod_arr1; i++)
        this->prod_arr1[i] = promo.prod_arr1[i];
    this->nr_each_prod_arr1 = new int[this->nr_prod_arr1];
    for (int i = 0; i < this->nr_prod_arr1; i++)
        this->nr_each_prod_arr1[i] = promo.nr_each_prod_arr1[i];

    this->nr_prod_arr2 = promo.nr_prod_arr2;
    this->prod_arr2 = new string[this->nr_prod_arr2];
    for (int i = 0; i < this->nr_prod_arr2; i++)
        this->prod_arr2[i] = promo.prod_arr2[i];
    this->nr_each_prod_arr2 = new int[this->nr_prod_arr2];
    for (int i = 0; i < this->nr_prod_arr2; i++)
        this->nr_each_prod_arr2[i] = promo.nr_each_prod_arr2[i];

    this->promotion_discount = promo.promotion_discount;
}
promotion::~promotion()
{
    if (this->prod_arr1 != nullptr)
        delete []this->prod_arr1;

    if (this->nr_each_prod_arr1 != nullptr)
        delete []this->nr_each_prod_arr1;

    if (this->prod_arr2 != nullptr)
        delete []this->prod_arr2;

    if (this->nr_each_prod_arr2 != nullptr)
        delete []this->nr_each_prod_arr2;
}


string promotion::get_promotion_name()
{return this->promotion_name;}
int promotion::get_promotion_type()
{return this->promotion_type;}
int promotion::get_nr_prod_arr1()
{return this->nr_prod_arr1;}
string* promotion::get_prod_arr1()
{return this->prod_arr1;}
int* promotion::get_nr_each_prod_arr1()
{return this->nr_each_prod_arr1;}
int promotion::get_nr_prod_arr2()
{return this->nr_prod_arr2;}
string* promotion::get_prod_arr2()
{return this->prod_arr2;}
int* promotion::get_nr_each_prod_arr2()
{return this->nr_each_prod_arr2;}
double promotion::get_promotion_discount()
{return this->promotion_discount;}
int promotion::get_promotion_id()
{return this->promotion_id;}
int promotion::get_new_promotion_id()
{return new_promotion_id;}


void promotion::set_promotion_name(string promotion_name)
{this->promotion_name = promotion_name;}
void promotion::set_promotion_type(int promotion_type)
{this->promotion_type = promotion_type;}
void promotion::set_nr_prod_arr1(int nr_prod_arr1)
{this->nr_prod_arr1 = nr_prod_arr1;}
void promotion::set_prod_arr1(string* prod_arr1)
{
    if (this->prod_arr1 != nullptr)
        delete []this->prod_arr1;
    this->prod_arr1 = new string[this->nr_prod_arr1];
    for (int i = 0; i < this->nr_prod_arr1; i++)
        this->prod_arr1[i] = prod_arr1[i];
}
void promotion::set_nr_each_prod_arr1(int* nr_each_prod_arr1)
{
    if (this->nr_each_prod_arr1 != nullptr)
        delete []this->nr_each_prod_arr1;
    this->nr_each_prod_arr1 = new int[this->nr_prod_arr1];
    for (int i = 0; i < this->nr_prod_arr1; i++)
         this->nr_each_prod_arr1[i] = nr_each_prod_arr1[i];
}
void promotion::set_nr_prod_arr2(int nr_prod_arr2)
{this->nr_prod_arr2 = nr_prod_arr2;}
void promotion::set_prod_arr2(string* prod_arr2)
{
    if (this->prod_arr2 != nullptr)
        delete []this->prod_arr2;
    this->prod_arr2 = new string[this->nr_prod_arr2];
    for (int i = 0; i < this->nr_prod_arr2; i++)
        this->prod_arr2[i] = prod_arr2[i];
}
void promotion::set_nr_each_prod_arr2(int* nr_each_prod_arr2)
{
    if (this->nr_each_prod_arr2 != nullptr)
        delete []this->nr_each_prod_arr1;
    this->nr_each_prod_arr2 = new int[this->nr_prod_arr2];
    for (int i = 0; i < this->nr_prod_arr2; i++)
         this->nr_each_prod_arr2[i] = nr_each_prod_arr2[i];
}
void promotion::set_promotion_discount(double promotion_discount)
{this->promotion_discount = promotion_discount;}
void promotion::set_new_promotion_id(int new_promotion_id)
{promotion::new_promotion_id = new_promotion_id;}


promotion& promotion::operator=(const promotion& promo)
{
    if (this != &promo)
    {
        this->promotion_name = promo.promotion_name;
        this->promotion_type = promo.promotion_type;

        this->nr_prod_arr1 = promo.nr_prod_arr1;
        if (this->prod_arr1 != nullptr)
            delete []this->prod_arr1;
        this->prod_arr1 = new string[this->nr_prod_arr1];
        for (int i = 0; i < this->nr_prod_arr1; i++)
            this->prod_arr1[i] = promo.prod_arr1[i];
        if (this->nr_each_prod_arr1 != nullptr)
            delete []this->nr_each_prod_arr1;
        this->nr_each_prod_arr1 = new int[this->nr_prod_arr1];
        for (int i = 0; i < this->nr_prod_arr1; i++)
            this->nr_each_prod_arr1[i] = promo.nr_each_prod_arr1[i];

        this->nr_prod_arr2 = promo.nr_prod_arr2;
        if (this->prod_arr2 != nullptr)
            delete []this->prod_arr2;
        this->prod_arr2 = new string[this->nr_prod_arr2];
        for (int i = 0; i < this->nr_prod_arr2; i++)
            this->prod_arr2[i] = promo.prod_arr2[i];
        if (this->nr_each_prod_arr2 != nullptr)
            delete []this->nr_each_prod_arr2;
        this->nr_each_prod_arr2 = new int[this->nr_prod_arr2];
        for (int i = 0; i < this->nr_prod_arr2; i++)
            this->nr_each_prod_arr2[i] = promo.nr_each_prod_arr2[i];

        this->promotion_discount = promo.promotion_discount;
    }

    return *this;
}


istream& operator>>(istream& in, promotion& promo)
{
    cout<<"Insert the promotion's name: ";
    in.get();
    getline(in, promo.promotion_name);

    cout<<"Insert the number of different product tpyes eligible with the promotion: ";
    in>>promo.nr_prod_arr1;
    in.get();
    cout<<"Insert the products eligible with the promotion:\n";
    if (promo.prod_arr1 != nullptr)
        delete []promo.prod_arr1;
    promo.prod_arr1 = new string[promo.nr_prod_arr1];
    for (int i = 0; i < promo.nr_prod_arr1; i++)
        getline(in, promo.prod_arr1[i]);
    cout<<"Insert the number of each product type that has to be bought:\n";
    if (promo.nr_each_prod_arr1 != nullptr)
        delete []promo.nr_each_prod_arr1;
    promo.nr_each_prod_arr1 = new int[promo.nr_prod_arr1];
    for (int i = 0; i < promo.nr_prod_arr1; i++)
        in>>promo.nr_each_prod_arr1[i];

    cout<<"Insert the promotion's type: ";
    in>>promo.promotion_type;

    if (promo.promotion_type == 1)
    {
        cout<<"Insert the number of different bonus products: ";
        in>>promo.nr_prod_arr2;
        in.get();
        cout<<"Insert the bonus products of the promotion:\n";
        if (promo.prod_arr2 != nullptr)
            delete []promo.prod_arr2;
        promo.prod_arr2 = new string[promo.nr_prod_arr2];
        for (int i = 0; i < promo.nr_prod_arr2; i++)
            getline(in, promo.prod_arr2[i]);
        cout<<"Insert the number of each bonus product:\n";
        if (promo.nr_each_prod_arr2 != nullptr)
            delete []promo.nr_each_prod_arr2;
        promo.nr_each_prod_arr2 = new int[promo.nr_prod_arr2];
        for (int i = 0; i < promo.nr_prod_arr2; i++)
            in>>promo.nr_each_prod_arr2[i];
    }
    else
    {
        cout<<"Insert the promotion's discount (value from interval (0, 1)): ";
        in>>promo.promotion_discount;
    }

    return in;
}
ostream& operator<<(ostream& out, const promotion& promo)
{
    out<<"Promotion's name: "<<promo.promotion_name<<'\n';

    out<<"Promotion's type: ";
    if (promo.promotion_type == 1)
    {out<<"Bonus products\n";}
    else
        if (promo.promotion_type == 2)
        {out<<"Discount\n";}
        else
        {out<<"-----\n";}

    if ((promo.promotion_type == 1) || (promo.promotion_type == 2))
    {
        out<<"Upon buying ";
        {
            int i;
            for (i = 0; i < promo.nr_prod_arr1-1; i++)
                out<<'x'<<promo.nr_each_prod_arr1[i]<<" "<<promo.prod_arr1[i]<<" + ";
            out<<'x'<<promo.nr_each_prod_arr1[i]<<" "<<promo.prod_arr1[i];
        }
        out<<", the client will be given a ";

        if (promo.promotion_type == 1)
        {
            out<<"bonus of ";
            int i;
            for (i = 0; i < promo.nr_prod_arr2-1; i++)
                out<<'x'<<promo.nr_each_prod_arr2[i]<<" "<<promo.prod_arr2[i]<<" + ";
            out<<'x'<<promo.nr_each_prod_arr2[i]<<" "<<promo.prod_arr2[i];
            out<<" as part of the promotion\n";
        }
        else
        {
            out<<"discount of "<<promo.promotion_discount*100<<"% on the promotion's package\n";
        }
    }

    out<<"Promotion's ID: "<<promo.promotion_id<<'\n';

    return out;
}


void promotion::promotion_details()
{
    if (this->promotion_type==1)
    {
        if (this->nr_prod_arr2>=2)
        {
            int aux = 0, i;
            for (i = 0; i < this->nr_prod_arr2; i++)
                aux+=this->nr_each_prod_arr2[i];
            if (aux>=3)
                cout<<"Mega bonus!\n";
            else
                cout<<"Standard bonus\n";
        }
        else
            cout<<"Standard bonus\n";
    }
    else
        if (this->promotion_discount>=0.4)
            cout<<"Mega discount!\n";
        else
            cout<<"Standard discount\n";
}
void promotion::print_to_file(ostream& out)
{
    out<<"Promotion\n";

    out<<this->promotion_name<<'\n';

    out<<this->nr_prod_arr1<<'\n';

    for (int i = 0; i < this->nr_prod_arr1; i++)
        out<<this->prod_arr1[i]<<'\n';

    for (int i = 0; i < this->nr_prod_arr1; i++)
        out<<this->nr_each_prod_arr1[i]<<'\n';

    out<<this->promotion_type<<'\n';

    if (this->promotion_type == 1)
    {
        out<<this->nr_prod_arr2<<'\n';

        for (int i = 0; i < this->nr_prod_arr2; i++)
            out<<this->prod_arr2[i]<<'\n';

        for (int i = 0; i < this->nr_prod_arr2; i++)
            out<<this->nr_each_prod_arr2[i]<<'\n';
    }
    else
    {
        out<<this->promotion_discount<<'\n';
    }

    out<<'\n';
}


class account_interface
{

public:
    virtual istream& read_account_info(istream& in) = 0;
    virtual ostream& print_account_info(ostream& out)const = 0;
    virtual ~account_interface(){}

};


class account: public account_interface
{

protected:
    string username, password, email;

public:
    account(string Username, string Password, string Email);
    account();
    account(const account& acc);
    ~account();

    string get_username();
    string get_password();
    string get_email();
    virtual int get_account_id() = 0;

    void set_username(string username);
    void set_password(string password);
    void set_email(string email);

    account& operator=(const account& acc);

    istream& read_account_info(istream& in);
    friend istream& operator>>(istream& in, account& acc);
    ostream& print_account_info(ostream& out)const;
    friend ostream& operator<<(ostream& out, const account& acc);

    virtual void account_functionality() = 0;
    virtual void print_to_file(ostream& out);

};


account::account(string Username, string Password, string Email): username(Username), password(Password), email(Email){}
account::account(): username("-----"), password("-----"), email("-----"){}
account::account(const account& acc): username(acc.username), password(acc.password), email(acc.email){}
account::~account(){}


string account::get_username()
{return this->username;}
string account::get_password()
{return this->password;}
string account::get_email()
{return this->email;}


void account::set_username(string username)
{this->username = username;}
void account::set_password(string password)
{this->password = password;}
void account::set_email(string email)
{this->email = email;}


account& account::operator=(const account& acc)
{
    if (this != &acc)
    {
        this->username = acc.username;
        this->password = acc.password;
        this->email = acc.email;
    }

    return *this;
}


istream& account::read_account_info(istream& in)
{
    cout<<"Insert the username: ";
    getline(in, this->username);

    cout<<"Insert the password: ";
    in>>this->password;

    cout<<"Insert the e-mail address: ";
    in>>this->email;

    return in;
}
istream& operator>>(istream& in, account& acc)
{return acc.read_account_info(in);}
ostream& account::print_account_info(ostream& out)const
{
    out<<"Username: "<<this->username<<'\n';

    out<<"Password: "<<this->password<<'\n';

    out<<"E-mail: "<<this->email<<'\n';

    return out;
}
ostream& operator<<(ostream& out, const account& acc)
{return acc.print_account_info(out);}


void account::print_to_file(ostream& out)
{
    out<<this->username<<'\n';

    out<<this->password<<'\n';

    out<<this->email<<'\n';
}


class customer: public account
{

private:
    int nr_orders;
    string* orders_date;
    int* nr_product_types_of_order;
    int** nr_each_product_type_of_order;
    product** orders;
    int nr_types_of_hardware_interested_in;
    string* types_of_hardware_interested_in;
    const int customer_account_id;
    static int new_customer_account_id;

public:
    customer(string username, string password, string email, int Nr_types_of_hardware_interested_in, string* types_of_hardware_interested_in);
    customer();
    customer(const customer& cust);
    ~customer();

    int get_nr_orders();
    string* get_orders_date();
    int* get_nr_product_types_of_order();
    int** get_nr_each_product_type_of_order();
    product** get_orders();
    int get_nr_types_of_hardware_interested_in();
    string* get_types_of_hardware_interested_in();
    int get_account_id();
    static int get_new_customer_account_id();

    void set_nr_types_of_hardware_interested_in(int nr_types_of_hardware_interested_in);
    void set_types_of_hardware_interested_in(string* types_of_hardware_interested_in);
    void set_new_customer_account_id(int new_customer_account_id);

    customer& operator=(const customer& cust);

    istream& read_account_info(istream& in);
    ostream& print_account_info(ostream& out)const;

    void add_order(string new_order_date, int new_nr_product_types_of_order, int* new_nr_each_product_type_of_order, product* order);
    void account_functionality();
    void print_to_file(ostream& out);

};


int customer::new_customer_account_id = 400000;


customer::customer(string username, string password, string email, int Nr_types_of_hardware_interested_in, string* types_of_hardware_interested_in): account(username, password, email), nr_orders(0), orders_date(nullptr), nr_product_types_of_order(nullptr), nr_each_product_type_of_order(nullptr), orders(nullptr), nr_types_of_hardware_interested_in(Nr_types_of_hardware_interested_in), customer_account_id(new_customer_account_id++)
{
    this->types_of_hardware_interested_in = new string[this->nr_types_of_hardware_interested_in];
    for (int i = 0; i < this->nr_types_of_hardware_interested_in; i++)
        this->types_of_hardware_interested_in[i] = types_of_hardware_interested_in[i];
}
customer::customer(): account(), nr_orders(0), orders_date(nullptr), nr_product_types_of_order(nullptr), nr_each_product_type_of_order(nullptr), orders(nullptr), nr_types_of_hardware_interested_in(0), types_of_hardware_interested_in(nullptr), customer_account_id(new_customer_account_id++){}
customer::customer(const customer& cust): account(cust), nr_orders(cust.nr_orders), nr_types_of_hardware_interested_in(cust.nr_types_of_hardware_interested_in), customer_account_id(cust.customer_account_id)
{
    this->orders_date = new string[this->nr_orders];
    for (int i = 0; i < this->nr_orders; i++)
        this->orders_date[i] = cust.orders_date[i];

    this->nr_product_types_of_order = new int[this->nr_orders];
    for (int i = 0; i < this->nr_orders; i++)
        this->nr_product_types_of_order[i] = cust.nr_product_types_of_order[i];

    this->nr_each_product_type_of_order = new int*[this->nr_orders];
    for (int i = 0; i < this->nr_orders; i++)
        this->nr_each_product_type_of_order[i] = new int[this->nr_product_types_of_order[i]];
    for (int i = 0; i < this->nr_orders; i++)
        for (int j = 0; j < this->nr_product_types_of_order[i]; j++)
            this->nr_each_product_type_of_order[i][j] = cust.nr_each_product_type_of_order[i][j];

    this->orders = new product*[this->nr_orders];
    for (int i = 0; i < this->nr_orders; i++)
    {
        this->orders[i] = new product[this->nr_product_types_of_order[i]];
        this->orders[i][0].set_new_product_id(this->orders[i][0].get_new_product_id()-this->nr_product_types_of_order[i]);
    }
    for (int i = 0; i < this->nr_orders; i++)
        for (int j = 0; j < this->nr_product_types_of_order[i]; j++)
            this->orders[i][j] = cust.orders[i][j];

    this->types_of_hardware_interested_in = new string[this->nr_types_of_hardware_interested_in];
    for (int i = 0; i < this->nr_types_of_hardware_interested_in; i++)
        this->types_of_hardware_interested_in[i] = cust.types_of_hardware_interested_in[i];
}
customer::~customer()
{
    if (this->orders_date != nullptr)
        delete []this->orders_date;

    if (this->nr_product_types_of_order != nullptr)
        delete []this->nr_product_types_of_order;

    if (this->nr_each_product_type_of_order != nullptr)
    {
        for (int i = 0; i < this->nr_orders; i++)
            if (this->nr_each_product_type_of_order[i] != nullptr)
                delete []this->nr_each_product_type_of_order[i];
        delete []this->nr_each_product_type_of_order;
    }

    if (this->orders != nullptr)
    {
        for (int i = 0; i < this->nr_orders; i++)
            if (this->orders[i] != nullptr)
                delete []this->orders[i];
        delete []this->orders;
    }

    if (this->types_of_hardware_interested_in != nullptr)
        delete []this->types_of_hardware_interested_in;
}


int customer::get_nr_orders()
{return this->nr_orders;}
string* customer::get_orders_date()
{return this->orders_date;}
int* customer::get_nr_product_types_of_order()
{return this->nr_product_types_of_order;}
int** customer::get_nr_each_product_type_of_order()
{return this->nr_each_product_type_of_order;}
product** customer::get_orders()
{return this->orders;}
int customer::get_nr_types_of_hardware_interested_in()
{return this->nr_types_of_hardware_interested_in;}
string* customer::get_types_of_hardware_interested_in()
{return this->types_of_hardware_interested_in;}
int customer::get_account_id()
{return this->customer_account_id;}
int customer::get_new_customer_account_id()
{return new_customer_account_id;}


void customer::set_nr_types_of_hardware_interested_in(int nr_types_of_hardware_interested_in)
{
    this->nr_types_of_hardware_interested_in = nr_types_of_hardware_interested_in;
}
void customer::set_types_of_hardware_interested_in(string* types_of_hardware_interested_in)
{
    if (this->types_of_hardware_interested_in != nullptr)
        delete []this->types_of_hardware_interested_in;
    this->types_of_hardware_interested_in = new string[this->nr_types_of_hardware_interested_in];
    for (int i = 0; i < this->nr_types_of_hardware_interested_in; i++)
        this->types_of_hardware_interested_in[i] = types_of_hardware_interested_in[i];
}
void customer::set_new_customer_account_id(int new_customer_account_id)
{customer::new_customer_account_id = new_customer_account_id;}


customer& customer::operator=(const customer& cust)
{
    if (this != &cust)
    {
        account::operator=(cust);

        if (this->orders_date != nullptr)
            delete []this->orders_date;

        if (this->nr_product_types_of_order != nullptr)
            delete []this->nr_product_types_of_order;

        if (this->nr_each_product_type_of_order != nullptr)
        {
            for (int i = 0; i < this->nr_orders; i++)
                if (this->nr_each_product_type_of_order[i] != nullptr)
                    delete []this->nr_each_product_type_of_order[i];
            delete []this->nr_each_product_type_of_order;
        }

        if (this->orders != nullptr)
        {
            for (int i = 0; i < this->nr_orders; i++)
                if (this->orders[i] != nullptr)
                    delete []this->orders[i];
            delete []this->orders;
        }

        if (this->types_of_hardware_interested_in != nullptr)
            delete []this->types_of_hardware_interested_in;

        this->nr_orders = cust.nr_orders;

        this->orders_date = new string[this->nr_orders];
        for (int i = 0; i < this->nr_orders; i++)
            this->orders_date[i] = cust.orders_date[i];

        this->nr_product_types_of_order = new int[this->nr_orders];
            for (int i = 0; i < this->nr_orders; i++)
        this->nr_product_types_of_order[i] = cust.nr_product_types_of_order[i];

        this->nr_each_product_type_of_order = new int*[this->nr_orders];
        for (int i = 0; i < this->nr_orders; i++)
            this->nr_each_product_type_of_order[i] = new int[this->nr_product_types_of_order[i]];
        for (int i = 0; i < this->nr_orders; i++)
            for (int j = 0; j < this->nr_product_types_of_order[i]; j++)
                this->nr_each_product_type_of_order[i][j] = cust.nr_each_product_type_of_order[i][j];

        this->orders = new product*[this->nr_orders];
        for (int i = 0; i < this->nr_orders; i++)
        {
            this->orders[i] = new product[this->nr_product_types_of_order[i]];
            this->orders[i][0].set_new_product_id(this->orders[i][0].get_new_product_id()-this->nr_product_types_of_order[i]);
        }
        for (int i = 0; i < this->nr_orders; i++)
            for (int j = 0; j < this->nr_product_types_of_order[i]; j++)
                this->orders[i][j] = cust.orders[i][j];

        this->nr_types_of_hardware_interested_in = cust.nr_types_of_hardware_interested_in;

        this->types_of_hardware_interested_in = new string[this->nr_types_of_hardware_interested_in];
        for (int i = 0; i < this->nr_types_of_hardware_interested_in; i++)
            this->types_of_hardware_interested_in[i] = cust.types_of_hardware_interested_in[i];
    }

    return *this;
}


istream& customer::read_account_info(istream& in)
{
    account::read_account_info(in);

    cout<<"Insert the number of types of hardware that you are interested in: ";
    in>>this->nr_types_of_hardware_interested_in;

    in.get();
    cout<<"Insert the types of hardware that you are interested in:\n";
    if (this->types_of_hardware_interested_in != nullptr)
        delete []this->types_of_hardware_interested_in;
    this->types_of_hardware_interested_in = new string[this->nr_types_of_hardware_interested_in];
    for (int i = 0; i < this->nr_types_of_hardware_interested_in; i++)
        getline(in, this->types_of_hardware_interested_in[i]);

    return in;
}
ostream& customer::print_account_info(ostream& out)const
{
    account::print_account_info(out);

    out<<"The number of types of hardware interested in: "<<this->nr_types_of_hardware_interested_in<<'\n';

    out<<"The types of hardware interested in:\n";
    for (int i = 0; i < this->nr_types_of_hardware_interested_in; i++)
        out<<this->types_of_hardware_interested_in[i]<<'\n';

    out<<"Account ID: "<<this->customer_account_id<<'\n';

    return out;
}


void customer::add_order(string new_order_date, int new_nr_product_types_of_order, int* new_nr_each_product_type_of_order, product* new_order)
{
    string* aux_strings = new string[this->nr_orders];
    for (int i = 0; i < this->nr_orders; i++)
        aux_strings[i] = this->orders_date[i];

    int* aux_ints1 = new int[this->nr_orders];
    for (int i = 0; i < this->nr_orders; i++)
        aux_ints1[i] = this->nr_product_types_of_order[i];

    int** aux_ints2 = new int*[this->nr_orders];
    for (int i = 0; i < this->nr_orders; i++)
        aux_ints2[i] = new int[this->nr_product_types_of_order[i]];
    for (int i = 0; i < this->nr_orders; i++)
        for (int j = 0; j < this->nr_product_types_of_order[i]; j++)
            aux_ints2[i][j] = this->nr_each_product_type_of_order[i][j];

    product** aux_products = new product*[this->nr_orders];
    for (int i = 0; i < this->nr_orders; i++)
    {
        aux_products[i] = new product[this->nr_product_types_of_order[i]];
        aux_products[i][0].set_new_product_id(aux_products[i][0].get_new_product_id()-this->nr_product_types_of_order[i]);
    }
    for (int i = 0; i < this->nr_orders; i++)
        for (int j = 0; j < this->nr_product_types_of_order[i]; j++)
            aux_products[i][j] = this->orders[i][j];

    if (this->orders_date != nullptr)
        delete []this->orders_date;

    if (this->nr_product_types_of_order != nullptr)
        delete []this->nr_product_types_of_order;

    if (this->nr_each_product_type_of_order != nullptr)
    {
        for (int i = 0; i < this->nr_orders; i++)
            if (this->nr_each_product_type_of_order[i] != nullptr)
                delete []this->nr_each_product_type_of_order[i];
        delete []nr_each_product_type_of_order;
    }

    if (this->orders != nullptr)
    {
        for (int i = 0; i < this->nr_orders; i++)
            if (this->orders[i] != nullptr)
                delete []this->orders[i];
        delete []this->orders;
    }

    this->nr_orders++;

    this->orders_date = new string[this->nr_orders];
    for (int i = 0; i < this->nr_orders-1; i++)
        this->orders_date[i] = aux_strings[i];
    this->orders_date[this->nr_orders-1] = new_order_date;

    this->nr_product_types_of_order = new int[this->nr_orders];
    for (int i = 0; i < this->nr_orders-1; i++)
        this->nr_product_types_of_order[i] = aux_ints1[i];
    this->nr_product_types_of_order[this->nr_orders-1] = new_nr_product_types_of_order;

    this->nr_each_product_type_of_order = new int*[this->nr_orders];
    for (int i = 0; i < this->nr_orders-1; i++)
        this->nr_each_product_type_of_order[i] = new int[this->nr_product_types_of_order[i]];
    this->nr_each_product_type_of_order[this->nr_orders-1] = new int[this->nr_product_types_of_order[this->nr_orders-1]];
    for (int i = 0; i < this->nr_orders-1; i++)
        for (int j = 0; j < this->nr_product_types_of_order[i]; j++)
            this->nr_each_product_type_of_order[i][j] = aux_ints2[i][j];
    for (int i = 0; i < this->nr_product_types_of_order[this->nr_orders-1]; i++)
        this->nr_each_product_type_of_order[this->nr_orders-1][i] = new_nr_each_product_type_of_order[i];

    this->orders = new product*[this->nr_orders];
    for (int i = 0; i < this->nr_orders-1; i++)
    {
        this->orders[i] = new product[this->nr_product_types_of_order[i]];
        this->orders[i][0].set_new_product_id(this->orders[i][0].get_new_product_id()-this->nr_product_types_of_order[i]);
    }
    this->orders[this->nr_orders-1] = new product[this->nr_product_types_of_order[this->nr_orders-1]];
    this->orders[0][0].set_new_product_id(this->orders[0][0].get_new_product_id()-this->nr_product_types_of_order[this->nr_orders-1]);
    for (int i = 0; i < this->nr_orders-1; i++)
        for (int j = 0; j < this->nr_product_types_of_order[i]; j++)
            this->orders[i][j] = aux_products[i][j];
    for (int i = 0; i < this->nr_product_types_of_order[this->nr_orders-1]; i++)
        this->orders[this->nr_orders-1][i] = new_order[i];

    delete []aux_strings;

    delete []aux_ints1;

    for (int i = 0; i < this->nr_orders-1; i++)
        delete []aux_ints2[i];
    delete []aux_ints2;

    for (int i = 0; i < this->nr_orders-1; i++)
        delete []aux_products[i];
    delete []aux_products;
}
void customer::account_functionality()
{
    if (this->nr_orders < 1)
        cout<<"You have not placed any orders.\n";
    else
    {
        cout<<"You have placed "<<this->nr_orders<<" orders. Which order would you like to interrogate? (Enter a number from 1 to "<<this->nr_orders<<") ";
        int order;
        cin>>order;
        while ((order < 1) || (order > this->nr_orders))
            cin>>order;

        order--;
        cout<<"Order's arrival date: "<<this->orders_date[order]<<'\n';
        cout<<"Order's products and the quantity of each product:\n";
        for (int i = 0; i < this->nr_product_types_of_order[order]; i++)
            cout<<'x'<<this->nr_each_product_type_of_order[order][i]<<' '<<this->orders[order][i].get_product_name()<<" ("<<this->orders[order][i].get_type()<<") - "<<this->orders[order][i].get_price_in_euros()<<" EUROS\n";
        cout<<"Order's total price: ";
        float sum = 0;
        for (int i = 0; i < this->nr_product_types_of_order[order]; i++)
            sum += this->nr_each_product_type_of_order[order][i]*this->orders[order][i].get_price_in_euros();
        cout<<sum<<" EUROS\n";
    }
}
void customer::print_to_file(ostream& out)
{
    out<<"Customer\n";

    account::print_to_file(out);

    out<<this->nr_types_of_hardware_interested_in<<'\n';

    for (int i = 0; i < this->nr_types_of_hardware_interested_in; i++)
        out<<this->types_of_hardware_interested_in[i]<<'\n';
    out<<'\n';
}


class staff: public account
{

private:
    string role;
    int nr_of_customers_helped, nr_customer_reviews;
    float* customer_reviews;
    float average_customer_reviews;
    const int staff_account_id;
    static int new_staff_account_id;

public:
    staff(string Username, string Password, string Email, string Role);
    staff();
    staff(const staff& s);
    ~staff();

    string get_role();
    int get_nr_of_customers_helped();
    int get_nr_customer_reviews();
    float* get_customer_reviews();
    float get_average_customer_reviews();
    int get_account_id();
    static int get_new_staff_account_id();

    void set_role(string role);
    void set_nr_of_customers_helped(int nr_of_customers_helped);
    void set_new_staff_account_id(int new_staff_account_id);

    staff& operator=(const staff& s);
    const staff& operator++();
    const staff operator++(int);

    istream& read_account_info(istream& in);
    ostream& print_account_info(ostream& out)const;

    void add_review(float review);
    void account_functionality();
    void print_to_file(ostream& out);

};


int staff::new_staff_account_id = 500000;


staff::staff(string Username, string Password, string Email, string Role): account(Username, Password, Email), role(Role), nr_of_customers_helped(0), nr_customer_reviews(0), customer_reviews(nullptr), average_customer_reviews(0), staff_account_id(new_staff_account_id++){}
staff::staff(): account(), role("-----"), nr_of_customers_helped(0), nr_customer_reviews(0), customer_reviews(nullptr), average_customer_reviews(0), staff_account_id(new_staff_account_id++){}
staff::staff(const staff& s): account(s), role(s.role), nr_of_customers_helped(s.nr_of_customers_helped), nr_customer_reviews(s.nr_customer_reviews), average_customer_reviews(s.average_customer_reviews), staff_account_id(s.staff_account_id)
{
    this->customer_reviews = new float[this->nr_customer_reviews];
    for (int i = 0; i < this->nr_customer_reviews; i++)
        this->customer_reviews[i] = s.customer_reviews[i];
}
staff::~staff()
{
    if (this->customer_reviews != nullptr)
        delete []this->customer_reviews;
}


string staff::get_role()
{return this->role;}
int staff::get_nr_of_customers_helped()
{return this->nr_of_customers_helped;}
int staff::get_nr_customer_reviews()
{return this->nr_customer_reviews;}
float* staff::get_customer_reviews()
{return this->customer_reviews;}
float staff::get_average_customer_reviews()
{return this->average_customer_reviews;}
int staff::get_account_id()
{return this->staff_account_id;}
int staff::get_new_staff_account_id()
{return new_staff_account_id;}


void staff::set_role(string role)
{this->role = role;}
void staff::set_nr_of_customers_helped(int nr_of_customers_helped)
{this->nr_of_customers_helped = nr_of_customers_helped;}
void staff::set_new_staff_account_id(int new_staff_account_id)
{staff::new_staff_account_id = new_staff_account_id;}


staff& staff::operator=(const staff& s)
{
    if (this != &s)
    {
        account::operator=(s);

        this->role = s.role;
        this->nr_of_customers_helped = s.nr_of_customers_helped;
        this->nr_customer_reviews = s.nr_customer_reviews;

        if (this->customer_reviews != nullptr)
            delete []this->customer_reviews;
        this->customer_reviews = new float[this->nr_customer_reviews];
        for (int i = 0; i < this->nr_customer_reviews; i++)
            this->customer_reviews[i] = s.customer_reviews[i];

        this->average_customer_reviews = s.average_customer_reviews;
    }

    return *this;
}
const staff& staff::operator++()
{
    this->nr_of_customers_helped++;
    return *this;
}
const staff staff::operator++(int)
{
    staff aux(*this);
    this->nr_of_customers_helped++;
    return aux;
}


istream& staff::read_account_info(istream& in)
{
    account::read_account_info(in);

    cout<<"Insert the staff role: ";
    in.get();
    getline(in, this->role);

    return in;
}
ostream& staff::print_account_info(ostream& out)const
{
    account::print_account_info(out);

    out<<"Role: "<<this->role<<'\n';

    out<<"Number of customers helped: "<<this->nr_of_customers_helped<<'\n';

    out<<"Account ID: "<<this->staff_account_id<<'\n';

    return out;
}


void staff::add_review(float review)
{
    float* aux_floats = new float[this->nr_customer_reviews];
    for (int i = 0; i < this->nr_customer_reviews; i++)
        aux_floats[i] = this->customer_reviews[i];

    if (this->customer_reviews != nullptr)
        delete []this->customer_reviews;

    this->nr_of_customers_helped++;

    this->nr_customer_reviews++;

    this->customer_reviews = new float[this->nr_customer_reviews];
    for (int i = 0; i < this->nr_customer_reviews-1; i++)
        this->customer_reviews[i] = aux_floats[i];
    this->customer_reviews[this->nr_customer_reviews-1] = review;

    this->average_customer_reviews = ((this->average_customer_reviews*(this->nr_customer_reviews-1))+review)/this->nr_customer_reviews;
}
void staff::account_functionality()
{
    cout<<"Staff account status: ";
    if (this->average_customer_reviews > 3.5)
    {
        if (this->nr_customer_reviews < 25)
            cout<<"Newbie problem solver\n";
        else
            if (this->nr_customer_reviews < 75)
                cout<<"Experienced problem solver\n";
            else
                cout<<"Veteran problem solver\n";
    }
    else
        cout<<"Helper\n";
}
void staff::print_to_file(ostream& out)
{
    out<<"Staff\n";

    account::print_to_file(out);

    out<<this->role<<"\n\n";
}


class menu
{

private:
    static menu* instance;

    menu();

public:
    ~menu();

    menu* create_instance();
    void start_menu();

};


menu* menu::instance = nullptr;


menu::menu(){}
menu::~menu()
{
    if (instance != nullptr)
        delete instance;
}


menu* menu::create_instance()
{
    if (!instance)
        instance = new menu;

    return instance;
}
void menu::start_menu()
{
    cout<<"Welcome back, administrator!\n\n";

    out.open("products.out", ios::out);
    out<<"";
    out.close();
    out.open("clients.out", ios::out);
    out<<"";
    out.close();
    out.open("services.out", ios::out);
    out<<"";
    out.close();
    out.open("promotions.out", ios::out);
    out<<"";
    out.close();
    out.open("accounts.out", ios::out);
    out<<"";
    out.close();

    vector<product*> products;
    set<client> clients; client* Client;
    list<service*> services;
    list<promotion*> promotions;
    map<int, account*> accounts;
    bool val = true;
    int option;

    while(val)
    {
        cout<<"What do you wish to do?\n";
        cout<<"Import data from file - 1\n";
        cout<<"Export data to file - 2\n";
        cout<<"Add new entry - 3\n";
        cout<<"Remove entry - 4\n";
        cout<<"Print entry on screen - 5\n";
        cout<<"Print entry to file - 6\n";
        cout<<"Exit menu - 7\n\n";
        cout<<"Select option: ";
        cin>>option;
        system("cls");

        switch(option)
        {
            case 1:
            {
                while (true)
                {
                    cout<<"Go back - 0\n\n";
                    cout<<"Import data from \"products.txt\" - 1\n";
                    cout<<"Import data from \"clients.txt\" - 2\n";
                    cout<<"Import data from \"services.txt\" - 3\n";
                    cout<<"Import data from \"promotions.txt\" - 4\n";
                    cout<<"Import data from \"accounts.txt\" - 5\n\n";
                    cout<<"Insert option: ";
                    cin>>option;
                    system("cls");

                    if ((option < 0) || (option > 5))
                    {
                        cout<<"Wrong input!";
                        Sleep(2000);
                        system("cls");
                    }
                    else
                        if (option)
                            switch (option)
                            {
                                case 1:
                                {
                                    string prod_type;

                                    in.open("products.txt", ios::in);

                                    while (!in.eof())
                                    {
                                        in>>prod_type;
                                        in.get();

                                        if (prod_type != "END_OF_FILE")
                                        {
                                            if (prod_type == "Product")
                                                products.push_back(new product);
                                            else
                                                products.push_back(new prebuilt_system);
                                            in>>*products.back();

                                            system("cls");
                                        }
                                    }

                                    in.close();

                                    cout<<"Import complete!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }

                                case 2:
                                {
                                    string cli;

                                    in.open("clients.txt", ios::in);

                                    while (!in.eof())
                                    {
                                        in>>cli;
                                        in.get();

                                        if (cli != "END_OF_FILE")
                                        {
                                            Client = new client;
                                            in>>*Client;
                                            clients.insert(*Client);
                                            delete Client;

                                            system("cls");
                                        }
                                    }

                                    in.close();

                                    cout<<"Import complete!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }

                                case 3:
                                {
                                    string serv;

                                    in.open("services.txt", ios::in);

                                    while (!in.eof())
                                    {
                                        in>>serv;
                                        in.get();

                                        if (serv != "END_OF_FILE")
                                        {
                                            if (serv == "Service")
                                                services.push_back(new service);
                                            else
                                                services.push_back(new diagnostic_service);
                                            in>>*services.back();

                                            system("cls");
                                        }
                                    }

                                    in.close();

                                    cout<<"Import complete!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }

                                case 4:
                                {
                                    string promo;

                                    in.open("promotions.txt", ios::in);

                                    while (!in.eof())
                                    {
                                        in>>promo;

                                        if (promo != "END_OF_FILE")
                                        {
                                            promotions.push_back(new promotion);
                                            in>>*promotions.back();

                                            system("cls");
                                        }
                                    }

                                    in.close();

                                    cout<<"Import complete!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }

                                case 5:
                                {
                                    int poz = 1;
                                    string acc_type;

                                    in.open("accounts.txt", ios::in);

                                    while (!in.eof())
                                    {
                                        in>>acc_type;
                                        in.get();

                                        if (acc_type != "END_OF_FILE")
                                        {
                                            if (acc_type == "Customer")
                                                accounts.emplace(poz++, new customer);
                                            else
                                                accounts.emplace(poz++, new staff);
                                            in>>*accounts[poz-1];

                                            system("cls");
                                        }
                                    }

                                    in.close();

                                    cout<<"Import complete!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }
                            }
                        else
                            break;
                }

                break;
            }

            case 2:
            {
                while (true)
                {
                    cout<<"Go back - 0\n\n";
                    cout<<"Export data to \"products.txt\" - 1\n";
                    cout<<"Export data to \"clients.txt\" - 2\n";
                    cout<<"Export data to \"services.txt\" - 3\n";
                    cout<<"Export data to \"promotions.txt\" - 4\n";
                    cout<<"Export data to \"accounts.txt\" - 5\n\n";
                    cout<<"Insert option: ";
                    cin>>option;
                    system("cls");

                    if ((option < 0) || (option > 5))
                    {
                        cout<<"Wrong input!";
                        Sleep(2000);
                        system("cls");
                    }
                    else
                        if (option)
                            switch (option)
                            {
                                case 0:
                                {
                                    break;
                                }

                                case 1:
                                {
                                    out.open("products.txt", ios::out);

                                    vector<product*>::iterator it;
                                    for (it = products.begin(); it != products.end(); it++)
                                        if (typeid(**it) == typeid(product))
                                            (**it).aux_print_to_file(out);
                                        else
                                            (**it).print_to_file(out);

                                    out<<"END_OF_FILE";

                                    out.close();

                                    cout<<"Export complete!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }

                                case 2:
                                {
                                    out.open("clients.txt", ios::out);

                                    set<client>::iterator it;
                                    for (it = clients.begin(); it != clients.end(); it++)
                                        (*it).print_to_file(out);

                                    out<<"END_OF_FILE";

                                    out.close();

                                    cout<<"Export complete!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }

                                case 3:
                                {
                                    out.open("services.txt", ios::out);

                                    list<service*>::iterator it;
                                    for (it = services.begin(); it != services.end(); it++)
                                        if (typeid(**it) == typeid(service))
                                            (**it).aux_print_to_file(out);
                                        else
                                            (**it).print_to_file(out);

                                    out<<"END_OF_FILE";

                                    out.close();

                                    cout<<"Export complete!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }

                                case 4:
                                {
                                    out.open("promotions.txt", ios::out);

                                    list<promotion*>::iterator it;
                                    for (it = promotions.begin(); it != promotions.end(); it++)
                                        (**it).print_to_file(out);

                                    out<<"END_OF_FILE";

                                    out.close();

                                    cout<<"Export complete!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }

                                case 5:
                                {
                                    out.open("accounts.txt", ios::out);

                                    map<int, account*>::iterator it;
                                    for (it = accounts.begin(); it != accounts.end(); it++)
                                        (*((*it).second)).print_to_file(out);

                                    out<<"END_OF_FILE";

                                    out.close();

                                    cout<<"Export complete!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }
                            }
                        else
                            break;
                }

                break;
            }

            case 3:
            {
                while (true)
                {
                    cout<<"Go back - 0\n\n";
                    cout<<"Add new product - 1\n";
                    cout<<"Add new client info - 2\n";
                    cout<<"Add new service - 3\n";
                    cout<<"Add new promotion - 4\n";
                    cout<<"Add new account - 5\n\n";
                    cout<<"Select option: ";
                    cin>>option;
                    system("cls");

                    if ((option < 0) || (option > 5))
                    {
                        cout<<"Wrong input!";
                        Sleep(2000);
                        system("cls");
                    }
                    else
                        if (option)
                            switch (option)
                            {
                                case 1:
                                {
                                    while (true)
                                    {
                                        cout<<"Go back - 0\n\n";
                                        cout<<"Add new normal product - 1\n";
                                        cout<<"Add new prebuilt system - 2\n\n";
                                        cout<<"Select option: ";
                                        cin>>option;
                                        system("cls");

                                        if ((option < 0) || (option > 2))
                                        {
                                            cout<<"Wrong input!";
                                            Sleep(2000);
                                            system("cls");
                                        }
                                        else
                                            break;
                                    }

                                    switch (option)
                                    {
                                        case 0:
                                        {
                                            break;
                                        }

                                        case 1:
                                        {
                                            products.push_back(new product);
                                            cin.sync();
                                            cin>>*products.back();
                                            system("cls");
                                            cout<<"Normal product successfully added!";
                                            Sleep(2000);
                                            system("cls");

                                            break;
                                        }

                                        case 2:
                                        {
                                            products.push_back(new prebuilt_system);
                                            cin.sync();
                                            cin>>*products.back();
                                            system("cls");
                                            cout<<"Prebuilt system successfully added!";
                                            Sleep(2000);
                                            system("cls");

                                            break;
                                        }
                                    }

                                    break;
                                }

                                case 2:
                                {
                                    Client = new client;
                                    cin.sync();
                                    cin>>*Client;
                                    clients.insert(*Client);
                                    system("cls");
                                    cout<<"Client info successfully added!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }

                                case 3:
                                {
                                    while (true)
                                    {
                                        cout<<"Go back - 0\n\n";
                                        cout<<"Add new normal service - 1\n";
                                        cout<<"Add new diagnostic service - 2\n\n";
                                        cout<<"Select option: ";
                                        cin>>option;
                                        system("cls");

                                        if ((option < 0) || (option > 2))
                                        {
                                            cout<<"Wrong input!";
                                            Sleep(2000);
                                            system("cls");
                                        }
                                        else
                                            break;
                                    }

                                    switch (option)
                                    {
                                        case 0:
                                        {
                                            break;
                                        }

                                        case 1:
                                        {
                                            services.push_back(new service);
                                            cin.sync();
                                            cin>>*services.back();
                                            system("cls");
                                            cout<<"Normal service successfully added!";
                                            Sleep(2000);
                                            system("cls");

                                            break;
                                        }

                                        case 2:
                                        {
                                            services.push_back(new diagnostic_service);
                                            cin.sync();
                                            cin>>*services.back();
                                            system("cls");
                                            cout<<"Diagnostic service successfully added!";
                                            Sleep(2000);
                                            system("cls");

                                            break;
                                        }
                                    }

                                    break;
                                }

                                case 4:
                                {
                                    promotions.push_back(new promotion);
                                    cin>>*promotions.back();
                                    system("cls");
                                    cout<<"Promotion successfully added!";
                                    Sleep(2000);
                                    system("cls");

                                    break;
                                }

                                case 5:
                                {
                                    while (true)
                                    {
                                        cout<<"Go back - 0\n\n";
                                        cout<<"Add new customer account - 1\n";
                                        cout<<"Add new staff account - 2\n\n";
                                        cout<<"Select option: ";
                                        cin>>option;
                                        system("cls");

                                        if ((option < 0) || (option > 2))
                                        {
                                            cout<<"Wrong input!";
                                            Sleep(2000);
                                            system("cls");
                                        }
                                        else
                                            break;
                                    }

                                    switch (option)
                                    {
                                        case 0:
                                        {
                                            break;
                                        }

                                        case 1:
                                        {
                                            accounts.emplace(accounts.size()+1, new customer);
                                            cin.sync();
                                            cin>>*accounts[accounts.size()];
                                            system("cls");
                                            cout<<"Customer account successfully added!";
                                            Sleep(2000);
                                            system("cls");

                                            break;
                                        }

                                        case 2:
                                        {
                                            accounts.emplace(accounts.size()+1, new staff);
                                            cin.sync();
                                            cin>>*accounts[accounts.size()];
                                            system("cls");
                                            cout<<"Staff account successfully added!";
                                            Sleep(2000);
                                            system("cls");

                                            break;
                                        }
                                    }

                                    break;
                                }
                            }
                        else
                            break;
                }

                break;
            }

            case 4:
            {
                while (true)
                {
                    cout<<"Go back - 0\n\n";
                    cout<<"Remove product - 1\n";
                    cout<<"Remove client info - 2\n";
                    cout<<"Remove service - 3\n";
                    cout<<"Remove promotion - 4\n";
                    cout<<"Remove account - 5\n\n";
                    cout<<"Select option: ";
                    cin>>option;
                    system("cls");

                    if ((option < 0) || (option > 5))
                    {
                        cout<<"Wrong input!";
                        Sleep(2000);
                        system("cls");
                    }
                    else
                        if (option)
                            switch (option)
                            {
                                case 1:
                                {
                                    if (products.size())
                                    {
                                        while (true)
                                        {
                                            cout<<"Which product do you wish to remove?\n\n";
                                            cout<<"Insert a number from 1 to "<<products.size()<<" (the number of products available for deletion): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > products.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        products.erase(products.begin()+(option-1));

                                        cout<<"Product no. "<<option<<" successfully removed!";
                                        Sleep(2000);
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout<<"There are no products to remove!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 2:
                                {
                                    if (clients.size())
                                    {
                                        while (true)
                                        {
                                            cout<<"Which client entry do you wish to remove?\n\n";
                                            cout<<"Insert a number from 1 to "<<clients.size()<<" (the number of entries of clients available for deletion): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > clients.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        auto it = clients.begin();
                                        advance(it, option-1);
                                        clients.erase(it);

                                        cout<<"Client entry no. "<<option<<" successfully removed!";
                                        Sleep(2000);
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout<<"There are no entries of clients to remove!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 3:
                                {
                                    if (services.size())
                                    {
                                        while (true)
                                        {
                                            cout<<"Which service do you wish to remove?\n\n";
                                            cout<<"Insert a number from 1 to "<<services.size()<<" (the number of services available for deletion): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > services.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        auto it = services.begin();
                                        advance(it, option-1);
                                        services.erase(it);

                                        cout<<"Service no. "<<option<<" successfully removed!";
                                        Sleep(2000);
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout<<"There are no services to remove!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 4:
                                {
                                    if (promotions.size())
                                    {
                                        while (true)
                                        {
                                            cout<<"Which promotion do you wish to remove?\n\n";
                                            cout<<"Insert a number from 1 to "<<promotions.size()<<" (the number of promotions available for deletion): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > promotions.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        auto it = promotions.begin();
                                        advance(it, option-1);
                                        promotions.erase(it);

                                        cout<<"Promotion no. "<<option<<" successfully removed!";
                                        Sleep(2000);
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout<<"There are no promotions to remove!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 5:
                                {
                                    if (accounts.size())
                                    {
                                        while (true)
                                        {
                                            cout<<"Which account do you wish to remove?\n\n";
                                            cout<<"Insert a number from 1 to "<<accounts.size()<<" (the number of accounts available for deletion): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > accounts.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        accounts.erase(option);

                                        cout<<"Account no. "<<option<<" successfully removed!";
                                        Sleep(2000);
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout<<"There are no accounts to remove!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }
                            }
                        else
                            break;
                }

                break;
            }

            case 5:
            {
                while (true)
                {
                    cout<<"Go back - 0\n\n";
                    cout<<"Print product on screen - 1\n";
                    cout<<"Print client info on screen - 2\n";
                    cout<<"Print service on screen - 3\n";
                    cout<<"Print promotion on screen - 4\n";
                    cout<<"Print account on screen - 5\n\n";
                    cout<<"Select option: ";
                    cin>>option;
                    system("cls");

                    if ((option < 0) || (option > 5))
                    {
                        cout<<"Wrong input!";
                        Sleep(2000);
                        system("cls");
                    }
                    else
                        if (option)
                            switch (option)
                            {
                                case 1:
                                {
                                    if (products.size())
                                    {
                                        while (true)
                                        {
                                            cout<<"Which product do you wish to print?\n\n";
                                            cout<<"Insert a number from 1 to "<<products.size()<<" (the number of products available for printing): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > products.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        if (typeid(*products[option-1]) == typeid(product))
                                            cout<<"NORMAL PRODUCT\n";
                                        else
                                            cout<<"PREBUILT SYSTEM\n";
                                        cout<<*products[option-1]<<'\n';

                                        system("pause");
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout<<"There are no products to print!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 2:
                                {
                                    if (clients.size())
                                    {
                                        while (true)
                                        {
                                            cout<<"Which client entry do you wish to print?\n\n";
                                            cout<<"Insert a number from 1 to "<<clients.size()<<" (the number of client entries available for printing): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > clients.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        auto it = clients.begin();
                                        advance(it, option-1);
                                        cout<<(*it)<<'\n';

                                        system("pause");
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout<<"There are no entries of clients to print!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 3:
                                {
                                    if (services.size())
                                    {
                                        while (true)
                                        {
                                            cout<<"Which service do you wish to print?\n\n";
                                            cout<<"Insert a number from 1 to "<<services.size()<<" (the number of services available for printing): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > services.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        auto it = services.begin();
                                        advance(it, option-1);
                                        if (typeid(**it) == typeid(service))
                                            cout<<"NORMAL SERVICE\n";
                                        else
                                            cout<<"DIAGNOSTIC SERVICE\n";
                                        cout<<(**it)<<'\n';

                                        system("pause");
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout<<"There are no services to print!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 4:
                                {
                                    if (promotions.size())
                                    {
                                        while (true)
                                        {
                                            cout<<"Which promotion do you wish to print?\n\n";
                                            cout<<"Insert a number from 1 to "<<promotions.size()<<" (the number of promotions available for printing): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > promotions.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        auto it = promotions.begin();
                                        advance(it, option-1);
                                        cout<<(**it)<<'\n';

                                        system("pause");
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout<<"There are no promotions to print!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 5:
                                {
                                    if (accounts.size())
                                    {
                                        while (true)
                                        {
                                            cout<<"Which account do you wish to print?\n\n";
                                            cout<<"Insert a number from 1 to "<<accounts.size()<<" (the number of accounts available for printing): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > accounts.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        if (typeid(*accounts[option]) == typeid(customer))
                                            cout<<"CUSTOMER\n";
                                        else
                                            cout<<"STAFF\n";
                                        cout<<*accounts[option]<<'\n';

                                        system("pause");
                                        system("cls");
                                    }
                                    else
                                    {
                                        cout<<"There are no accounts to print!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }
                            }
                        else
                            break;
                }

                break;
            }

            case 6:
            {
                while (true)
                {
                    cout<<"Go back - 0\n\n";
                    cout<<"Print product to file - 1\n";
                    cout<<"Print client info to file - 2\n";
                    cout<<"Print service to file - 3\n";
                    cout<<"Print promotion to file - 4\n";
                    cout<<"Print account to file - 5\n\n";
                    cout<<"Select option: ";
                    cin>>option;
                    system("cls");

                    if ((option < 0) || (option > 5))
                    {
                        cout<<"Wrong input!";
                        Sleep(2000);
                        system("cls");
                    }
                    else
                        if (option)
                            switch (option)
                            {
                                case 1:
                                {
                                    if (products.size())
                                    {
                                        app.open("products.out", ios::app);

                                        while (true)
                                        {
                                            cout<<"Which product do you wish to print?\n\n";
                                            cout<<"Insert a number from 1 to "<<products.size()<<" (the number of products available for printing): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > products.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        app<<"Product no. "<<option<<":\n";
                                        if (typeid(*products[option-1]) == typeid(product))
                                            app<<"NORMAL PRODUCT\n";
                                        else
                                            app<<"PREBUILT SYSTEM\n";
                                        app<<*products[option-1]<<'\n';

                                        cout<<"Product successfully printed to file!";
                                        Sleep(2000);
                                        system("cls");

                                        app.close();
                                    }
                                    else
                                    {
                                        cout<<"There are no products to print!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 2:
                                {
                                    if (clients.size())
                                    {
                                        app.open("clients.out", ios::app);

                                        while (true)
                                        {
                                            cout<<"Which client entry do you wish to print?\n\n";
                                            cout<<"Insert a number from 1 to "<<clients.size()<<" (the number of client entries available for printing): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > clients.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        app<<"Client info no. "<<option<<":\n";
                                        auto it = clients.begin();
                                        advance(it, option-1);
                                        app<<(*it)<<'\n';

                                        cout<<"Client info successfully printed to file!";
                                        Sleep(2000);
                                        system("cls");

                                        app.close();
                                    }
                                    else
                                    {
                                        cout<<"There are no entries of clients to print!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 3:
                                {
                                    if (services.size())
                                    {
                                        app.open("services.out", ios::app);

                                        while (true)
                                        {
                                            cout<<"Which service do you wish to print?\n\n";
                                            cout<<"Insert a number from 1 to "<<services.size()<<" (the number of services available for printing): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > services.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        app<<"Service no. "<<option<<":\n";
                                        auto it = services.begin();
                                        advance(it, option-1);
                                        if (typeid(**it) == typeid(service))
                                            app<<"NORMAL SERVICE\n";
                                        else
                                            app<<"DIAGNOSTIC SERVICE\n";
                                        app<<(**it)<<'\n';

                                        cout<<"Service successfully printed to file!";
                                        Sleep(2000);
                                        system("cls");

                                        app.close();
                                    }
                                    else
                                    {
                                        cout<<"There are no services to print!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 4:
                                {
                                    if (promotions.size())
                                    {
                                        app.open("promotions.out", ios::app);

                                        while (true)
                                        {
                                            cout<<"Which promotion do you wish to print?\n\n";
                                            cout<<"Insert a number from 1 to "<<promotions.size()<<" (the number of promotions available for printing): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > promotions.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        app<<"Promotion no. "<<option<<":\n";
                                        auto it = promotions.begin();
                                        advance(it, option-1);
                                        app<<(**it)<<'\n';

                                        cout<<"Promotion successfully printed to file!";
                                        Sleep(2000);
                                        system("cls");

                                        app.close();
                                    }
                                    else
                                    {
                                        cout<<"There are no promotions to print!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }

                                case 5:
                                {
                                    if (accounts.size())
                                    {
                                        app.open("accounts.out", ios::app);

                                        while (true)
                                        {
                                            cout<<"Which account do you wish to print?\n\n";
                                            cout<<"Insert a number from 1 to "<<accounts.size()<<" (the number of accounts available for printing): ";
                                            cin>>option;
                                            system("cls");

                                            if ((option < 1) || ((long long unsigned)option > accounts.size()))
                                            {
                                                cout<<"Wrong input!";
                                                Sleep(2000);
                                                system("cls");
                                            }
                                            else
                                                break;
                                        }

                                        app<<"Account no. "<<option<<":\n";
                                        if (typeid(*accounts[option]) == typeid(customer))
                                            app<<"CUSTOMER\n";
                                        else
                                            app<<"STAFF\n";
                                        app<<*accounts[option]<<'\n';

                                        cout<<"Account successfully printed to file!";
                                        Sleep(2000);
                                        system("cls");

                                        app.close();
                                    }
                                    else
                                    {
                                        cout<<"There are no accounts to print!";
                                        Sleep(2000);
                                        system("cls");
                                    }

                                    break;
                                }
                            }
                        else
                            break;
                }

                break;
            }

            case 7:
            {
                cout<<"Goodbye!\n";
                Sleep(2200);
                val = false;
                break;
            }

            default:
            {
                cout<<"Wrong input!";
                Sleep(2500);
                system("cls");
            }
        }
    }
}


int main()
{

/// Start the menu:
menu* Menu = Menu->create_instance();
Menu->start_menu();


/// Tests for the class "product":
///========================================
cout<<"Tests for the class \"product\":\n";
cout<<"========================================\n";
cout<<"========================================\n\n";

int nr_prods_bought_each_month1[] = {37, 0, 77, 2, 24};
string months1[] = {"April", "May", "June", "July", "August"};
float ratings1[] = {4.5, 5, 4.7, 4.2, 4, 5, 5, 5, 4.2, 3, 3, 3.5}, sum1 = 0;
for (int i = 0; i < (int)(sizeof(ratings1)/sizeof(ratings1[0])); i++)
    sum1 += ratings1[i];

product prod1("Video card", (char*)"RTX 3080", 6900.75, 'S', nr_prods_bought_each_month1, true, 5, months1, sizeof(ratings1)/sizeof(float), ratings1);
cout<<prod1;
prod1.products_success();
cout<<'\n';

product prod2("Video card", (char*)"RTX 3090", 'S', 2);
cout<<prod2<<'\n';

product prod3(prod2);
cout<<prod3<<'\n';

product prod4;
cout<<prod4<<'\n';

prod4 = prod1;
cout<<prod4<<'\n';

prod2.set_price_in_euros(420);

prod1 = 1000.0+prod1+prod2+1000.0;
cout<<prod1.get_price_in_euros()<<'\n';
prod1+=1;
cout<<prod1.get_price_in_euros()<<'\n';
prod1++;
cout<<prod1.get_price_in_euros()<<'\n';
++prod1;
cout<<prod1.get_price_in_euros()<<'\n';
prod1--;
cout<<prod1.get_price_in_euros()<<'\n';
--prod1;
cout<<prod1.get_price_in_euros()<<'\n';
prod1 = prod1-1000.0-prod2-1001.0;
cout<<prod1.get_price_in_euros()<<'\n';
prod1 = prod1*2.0;
cout<<prod1.get_price_in_euros()<<'\n';
prod1 = 2.0*prod1;
cout<<prod1.get_price_in_euros()<<'\n';
prod1 = prod1/2.0;
cout<<prod1.get_price_in_euros()<<'\n';
prod1 = ((prod1.get_price_in_euros()*prod1.get_price_in_euros())/2)/prod1;
cout<<prod1.get_price_in_euros()<<"\n\n";

cout<<(prod1 == prod3)<<'\n';
cout<<(prod1 == prod4)<<'\n';
cout<<(prod1 < prod3)<<'\n';
cout<<(prod3 < prod1)<<'\n';
cout<<(prod1 > prod3)<<'\n';
cout<<(prod3 > prod1)<<"\n\n";

cout<<(int)prod1<<'\n';
cout<<(int)prod2<<'\n';
cout<<(int)prod3<<'\n';
cout<<(int)prod4<<"\n\n";

// prod1 = 0.0-prod1+prod2;
// cout<<'\n'<<prod1<<'\n';
// cout<<prod2<<'\n';

string months2[] = {"May", "June", "July"};
float ratings2[] = {4.5, 5, 4.7, 4.2, 4};
int nr_prods_bought_each_month2[] = {4, 5, 10};
sum1 = 0;
for (int i = 0; i < (int)(sizeof(ratings2)/sizeof(float)); i++)
    sum1 += ratings2[i];
prod1.set_type("Processor");
prod1.set_product_name((char*)"Intel Core i5-9600K");
prod1.set_price_in_euros(1000.5);
prod1.set_performance_class('A');
prod1.set_n_months(3);
prod1.set_months(months2);
prod1.set_products_sold_during_last_n_months(nr_prods_bought_each_month2);
prod1.set_recommended_for_gaming(1);
prod1.set_n_ratings(5);
prod1.set_ratings(ratings2);
prod1.set_average_rating(sum1/((int)(sizeof(ratings2)/sizeof(float))));

cout<<prod1.get_type()<<'\n';
cout<<prod1.get_product_name()<<'\n';
cout<<prod1.get_price_in_euros()<<'\n';
cout<<prod1.get_performance_class()<<'\n';
cout<<prod1.get_n_months()<<'\n';
cout<<*(prod1.get_months())<<'\n';
cout<<*(prod1.get_products_sold_during_last_n_months())<<'\n';
cout<<prod1.get_recommended_for_gaming()<<'\n';
cout<<prod1.get_n_ratings()<<'\n';
cout<<*(prod1.get_ratings())<<'\n';
cout<<prod1.get_average_rating()<<'\n';
cout<<prod1.get_product_id()<<'\n';
prod1.products_success();

cout<<"\n========================================\n";
cout<<"========================================\n\n\n";
///========================================


/// Tests for the class "prebuilt_system":
///========================================
cout<<"Tests for the class \"prebuilt_system\":\n";
cout<<"========================================\n";
cout<<"========================================\n\n";

int nr_prebuilt_systems_bought_each_month1[] = {0, 0, 20, 75};
string months3[] = {"September", "October", "November", "December"};
float ratings3[] = {4.5, 5, 4.7, 4.2, 4, 5, 5, 5, 4.2, 3, 3, 3.5}, sum2 = 0;
for (int i = 0; i < (int)(sizeof(ratings3)/sizeof(ratings3[0])); i++)
    sum2 += ratings3[i];
product prods[2];
prods[0].set_new_product_id(prods[0].get_new_product_id()-2);
prods[0] = prod1;
prods[1] = prod2;

prebuilt_system sys1("PC", (char*)"Ultra Gaming PC", 3000.75, 'S', nr_prebuilt_systems_bought_each_month1, true, 4, months3, sizeof(ratings3)/sizeof(float), ratings3, "Gaming PC", 2, prods);
cout<<sys1;
sys1.products_success();
cout<<'\n';

// cout<<"********************\n\n";

prebuilt_system sys2("Gaming Laptop", 2, prods);
cout<<sys2<<'\n';

prebuilt_system sys3(sys2);
cout<<sys3<<'\n';

prebuilt_system sys4;
cout<<sys4<<'\n';

sys4 = sys1;
cout<<sys4<<'\n';

sys2.set_price_in_euros(420);

(product&)sys1 = 1000.0+(product&)sys1+(product&)sys2+1000.0;
cout<<sys1.get_price_in_euros()<<'\n';
sys1+=1;
cout<<sys1.get_price_in_euros()<<'\n';
sys1++;
cout<<sys1.get_price_in_euros()<<'\n';
++sys1;
cout<<sys1.get_price_in_euros()<<'\n';
sys1--;
cout<<sys1.get_price_in_euros()<<'\n';
--sys1;
cout<<sys1.get_price_in_euros()<<'\n';
(product&)sys1 = (product&)sys1-1000.0-(product&)sys2-1001.0;
cout<<sys1.get_price_in_euros()<<'\n';
(product&)sys1 = (product&)sys1*2.0;
cout<<sys1.get_price_in_euros()<<'\n';
(product&)sys1 = 2.0*(product&)sys1;
cout<<sys1.get_price_in_euros()<<'\n';
(product&)sys1 = (product&)sys1/2.0;
cout<<sys1.get_price_in_euros()<<'\n';
(product&)sys1 = ((sys1.get_price_in_euros()*sys1.get_price_in_euros())/2)/(product&)sys1;
cout<<sys1.get_price_in_euros()<<"\n\n";

cout<<(sys1 == sys3)<<'\n';
cout<<(sys1 == sys4)<<'\n';
cout<<(sys1 < sys3)<<'\n';
cout<<(sys3 < sys1)<<'\n';
cout<<(sys1 > sys3)<<'\n';
cout<<(sys3 > sys1)<<"\n\n";

cout<<(int)sys1<<'\n';
cout<<(int)sys2<<'\n';
cout<<(int)sys3<<'\n';
cout<<(int)sys4<<"\n\n";

// sys1 = 0.0-sys1+sys2;
// cout<<'\n'<<sys1<<'\n';
// cout<<sys2<<'\n';

string months4[] = {"May", "June", "July"};
float ratings4[] = {4.5, 5, 4.7, 4.2, 4};
int nr_prebuilt_systems_bought_each_month2[] = {4, 5, 10};
sum2 = 0;
for (int i = 0; i < (int)(sizeof(ratings4)/sizeof(float)); i++)
    sum2 += ratings4[i];
sys1.set_type("Laptop");
sys1.set_product_name((char*)"Ultra Gaming Laptop");
sys1.set_price_in_euros(7000.5);
sys1.set_performance_class('S');
sys1.set_n_months(3);
sys1.set_months(months4);
sys1.set_products_sold_during_last_n_months(nr_prebuilt_systems_bought_each_month2);
sys1.set_recommended_for_gaming(1);
sys1.set_n_ratings(5);
sys1.set_ratings(ratings4);
sys1.set_average_rating(sum2/((int)(sizeof(ratings4)/sizeof(float))));
sys1.set_system_type("Gaming Laptop");
sys1.set_nr_components(2);
sys1.set_components(prods);

cout<<sys1.get_type()<<'\n';
cout<<sys1.get_product_name()<<'\n';
cout<<sys1.get_price_in_euros()<<'\n';
cout<<sys1.get_performance_class()<<'\n';
cout<<sys1.get_n_months()<<'\n';
cout<<*(sys1.get_months())<<'\n';
cout<<*(sys1.get_products_sold_during_last_n_months())<<'\n';
cout<<sys1.get_recommended_for_gaming()<<'\n';
cout<<sys1.get_n_ratings()<<'\n';
cout<<*(sys1.get_ratings())<<'\n';
cout<<sys1.get_average_rating()<<'\n';
cout<<sys1.get_product_id()<<'\n';
sys1.products_success();
cout<<sys1.get_system_type()<<'\n';
cout<<sys1.get_nr_components()<<'\n';
cout<<*(sys1.get_components());

cout<<"\n========================================\n";
cout<<"========================================\n\n\n";
///========================================


/// Tests for the class "client":
///========================================
cout<<"Tests for the class \"client\":\n";
cout<<"========================================\n";
cout<<"========================================\n\n";

string prods1[] = {"Ryzen 9 3950X", "RX 6900 XT", "DDR4 32GB"};
int nr_prods1[] = {1, 1, 1};
string months5[] = {"August", "September", "October", "November"};
int nr_prods_each_month2[] = {1, 0, 2, 0};

client cli1((char*)"Sasu Alexandru-Cristian", 7, 4, months5, nr_prods_each_month2, 3, prods1, nr_prods1);
cout<<cli1;
cli1.membership_status();
cout<<'\n';

client cli2((char*)"Andrei Ciocan");
cout<<cli2<<'\n';

client cli3;
cout<<cli3<<'\n';

client cli4(cli1);
cout<<cli4<<'\n';

cli4 = cli2;
cout<<cli4<<'\n';

cli1++;
cout<<cli1.get_nr_of_membership_months()<<'\n';
++cli1;
cout<<cli1.get_nr_of_membership_months()<<'\n';
cli1 = 1+cli1+2+cli2+1;
cout<<cli1.get_nr_of_membership_months()<<"\n\n";

cout<<cli1[2]<<"\n\n";

string months6[] = {"August", "September", "October", "November", "December"};
int nr_prods_each_month3[] = {1, 0, 1, 1, 1};
string prods2[] = {"Intel Core i5 9600K", "RTX 2060 Super", "DDR4 8GB"};
int nr_prods2[] = {1, 1, 2};
cli3.set_client_name((char*)"Popescu Marius");
cli3.set_nr_of_membership_months(4);
cli3.set_n_months(5);
cli3.set_months(months6);
cli3.set_nr_of_different_products_bought_each_month(nr_prods_each_month3);
cli3.set_n_products(3);
cli3.set_products(prods2);
cli3.set_nr_of_products_bought(nr_prods2);

cout<<cli3.get_client_name()<<'\n';
cout<<cli3.get_nr_of_membership_months()<<'\n';
cout<<cli3.get_n_months()<<'\n';
cout<<*(cli3.get_months()+1)<<'\n';
cout<<*(cli3.get_nr_of_different_products_bought_each_month()+1)<<'\n';
cout<<cli3.get_n_products()<<'\n';
cout<<*(cli3.get_products()+2)<<'\n';
cout<<*(cli3.get_nr_of_products_bought()+2)<<'\n';
cout<<cli3.get_client_id()<<'\n';
cli3.membership_status();
cout<<'\n';

cout<<"\n========================================\n";
cout<<"========================================\n\n\n";
///========================================


/// Tests for the class "service":
///========================================
cout<<"Tests for the class \"service\":\n";
cout<<"========================================\n";
cout<<"========================================\n\n";

service serv1((char*)"PC assembly", "The service consists of...", 59.25);
cout<<serv1;
serv1.service_type();
cout<<'\n';

service serv2((char*)"PC repair");
cout<<serv2<<'\n';

service serv3;
cout<<serv3<<'\n';

service serv4(serv1);
cout<<serv4<<'\n';

serv4 = serv2;
cout<<serv4<<'\n';

serv1++;
cout<<serv1.get_price_in_euros()<<'\n';
++serv1;
cout<<serv1.get_price_in_euros()<<'\n';
serv1 = 20+serv1+20;
cout<<serv1.get_price_in_euros()<<'\n';
serv1 = 120-serv1-120+42+118.5;
cout<<serv1.get_price_in_euros()<<'\n';
serv1 = 2*serv1*2;
cout<<serv1.get_price_in_euros()<<'\n';
serv1 = serv1/4;
cout<<serv1.get_price_in_euros()<<'\n';
serv1 = 1/serv1;
cout<<serv1.get_price_in_euros()<<'\n';
serv1 = 59.25*59.25*serv1;
serv2 = "ceva "+serv2+" ceva";
cout<<serv2.get_description()<<"\n\n";

serv2.set_service_name((char*)"Service");
serv2.set_description("Description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description");
serv2.set_price_in_euros(49.99);

cout<<serv2.get_service_name()<<'\n';
cout<<serv2.get_description()<<'\n';
cout<<serv2.get_price_in_euros()<<'\n';
serv2.service_type();

cout<<"\n========================================\n";
cout<<"========================================\n\n\n";
///========================================


/// Tests for the class "diagnostic_service":
///========================================
cout<<"Tests for the class \"diagnostic_service\":\n";
cout<<"========================================\n";
cout<<"========================================\n\n";

string comps1[] = {"CPU", "GPU", "RAM memory", "Storage space"};

diagnostic_service diag_serv1((char*)"Diagnostic Service 1", "The diagnostic service consists of...", 59.25, 4, comps1);
cout<<diag_serv1;
diag_serv1.service_type();
cout<<'\n';

diagnostic_service diag_serv2;
cout<<diag_serv2<<'\n';

diagnostic_service diag_serv3(diag_serv2);
cout<<diag_serv3<<'\n';

diag_serv3 = diag_serv1;
cout<<diag_serv3<<'\n';

diag_serv1++;
cout<<diag_serv1.get_price_in_euros()<<'\n';
++diag_serv1;
cout<<diag_serv1.get_price_in_euros()<<'\n';
(service&)diag_serv1 = 20+(service&)diag_serv1+20;
cout<<diag_serv1.get_price_in_euros()<<'\n';
(service&)diag_serv1 = 120-(service&)diag_serv1-120+42+118.5;
cout<<diag_serv1.get_price_in_euros()<<'\n';
(service&)diag_serv1 = 2*(service&)diag_serv1*2;
cout<<diag_serv1.get_price_in_euros()<<'\n';
(service&)diag_serv1 = (service&)diag_serv1/4;
cout<<diag_serv1.get_price_in_euros()<<'\n';
(service&)diag_serv1 = 1/(service&)diag_serv1;
cout<<diag_serv1.get_price_in_euros()<<'\n';
(service&)diag_serv1 = 59.25*59.25*(service&)diag_serv1;
(service&)diag_serv2 = "ceva "+(service&)diag_serv2+" ceva";
cout<<diag_serv2.get_description()<<"\n\n";

string comps2[] = {"Motherboard", "PSU"};
diag_serv2.set_service_name((char*)"Diagnostic Service 2");
diag_serv2.set_description("Description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description description");
diag_serv2.set_price_in_euros(49.0);
diag_serv2.set_nr_of_types_components_included(2);
diag_serv2.set_types_of_components_included(comps2);

cout<<diag_serv2.get_service_name()<<'\n';
cout<<diag_serv2.get_description()<<'\n';
cout<<diag_serv2.get_price_in_euros()<<'\n';
cout<<diag_serv2.get_nr_of_types_components_included()<<'\n';
cout<<*(diag_serv2.get_types_of_components_included())<<'\n';
diag_serv2.service_type();

cout<<"\n========================================\n";
cout<<"========================================\n\n\n";
///========================================


/// Tests for the class "promotion":
///========================================
cout<<"Tests for the class \"promotion\":\n";
cout<<"========================================\n";
cout<<"========================================\n\n";

string v_prods1[] = {"prod 1", "prod 2", "prod 3"};
string v_prods2[] = {"prod 4", "prod 5", "prod 6"};
int v_nr_prods1[] = {1, 2, 1};
promotion promo1("Promotion 1", 1, 3, v_prods1, v_nr_prods1, 3, v_prods2, v_nr_prods1);
cout<<promo1;
promo1.promotion_details();
cout<<'\n';

string v_prods3[] = {"prod 7", "prod 8"};
int v_nr_prods2[] = {2, 2};
promotion promo2("Promotion 2", 2, 2, v_prods3, v_nr_prods2, 0.4);
cout<<promo2;
promo2.promotion_details();
cout<<'\n';

promotion promo3;
cout<<promo3<<'\n';

promotion promo4(promo1);
cout<<promo4<<'\n';

promo4 = promo2;
cout<<promo4<<'\n';

string v_prods4[] = {"pr 1", "pr 2"};
int v_nr_prods3[] = {1, 1};
promo1.set_promotion_name("Promotion 3");
promo1.set_promotion_type(2);
promo1.set_nr_prod_arr1(2);
promo1.set_prod_arr1(v_prods4);
promo1.set_nr_each_prod_arr1(v_nr_prods3);
promo1.set_promotion_discount(0.39);

cout<<promo1.get_promotion_name()<<'\n';
cout<<promo1.get_promotion_type()<<'\n';
cout<<promo1.get_nr_prod_arr1()<<'\n';
cout<<promo1.get_prod_arr1()[1]<<'\n';
cout<<promo1.get_nr_each_prod_arr1()[1]<<'\n';
cout<<promo1.get_promotion_discount()<<'\n';
cout<<promo1.get_promotion_id()<<'\n';
promo1.promotion_details();
cout<<'\n';

promo2.set_promotion_name("Promotion 4");
promo2.set_promotion_type(1);
promo2.set_nr_prod_arr1(3);
promo2.set_prod_arr1(v_prods2);
promo2.set_nr_each_prod_arr1(v_nr_prods1);
promo2.set_nr_prod_arr2(2);
promo2.set_prod_arr2(v_prods4);
promo2.set_nr_each_prod_arr2(v_nr_prods3);

cout<<promo2.get_promotion_name()<<'\n';
cout<<promo2.get_promotion_type()<<'\n';
cout<<promo2.get_nr_prod_arr1()<<'\n';
cout<<promo2.get_prod_arr1()[0]<<'\n';
cout<<promo2.get_nr_each_prod_arr1()[0]<<'\n';
cout<<promo2.get_nr_prod_arr2()<<'\n';
cout<<promo2.get_prod_arr2()[1]<<'\n';
cout<<promo2.get_nr_each_prod_arr2()[1]<<'\n';
cout<<promo2.get_promotion_id()<<'\n';
promo2.promotion_details();

cout<<"\n========================================\n";
cout<<"========================================\n\n\n";
///========================================


/// Tests for the class "promotion":
///========================================
cout<<"Tests for the class \"account\":\n";
cout<<"========================================\n";
cout<<"========================================\n\n";

account* accs1[10];
/*
account** accs2[10];
for (int i = 0; i < 10; i++)
    accs2[i] = new account*[10];
account*** accs3[10];
account**** accs4[10];
*/

cout<<"\n========================================\n";
cout<<"========================================\n\n\n";
///========================================


/// Tests for the class "customer":
///========================================
cout<<"Tests for the class \"customer\":\n";
cout<<"========================================\n";
cout<<"========================================\n\n";

string hardware_interested_in1[] = {"GPU", "CPU", "CPU fans"};

accs1[0] = new customer("xXGigelXx", "gigelecelmaitare1", "gigelut@gmail.com", 3, hardware_interested_in1);
cout<<*accs1[0];
accs1[0]->account_functionality();
cout<<'\n';

accs1[1] = new customer;
cout<<*accs1[1];
accs1[1]->account_functionality();
cout<<'\n';

customer customer_aux;

accs1[2] = new customer(customer_aux);
cout<<*accs1[2]<<'\n';

accs1[3] = new customer;
*accs1[3] = *accs1[0];
cout<<*accs1[3]<<'\n';

/*
cin>>*accs1[3];
cout<<'\n'<<*accs1[3]<<'\n';
*/

accs1[0]->set_username("GigelFlorel");
accs1[0]->set_password("gigelcelmare");
accs1[0]->set_email("gigel1298@gmail.com");

cout<<accs1[0]->get_username()<<'\n';
cout<<accs1[0]->get_password()<<'\n';
cout<<accs1[0]->get_email()<<'\n';
cout<<accs1[0]->get_account_id()<<"\n\n";

int nr_prods[] = {11};
string months[] = {"April"};
float nr_ratings[] = {4.2, 5};
product p1("GPU", (char*)"RTX 3090", 1975.25, 'S', nr_prods, true, 1, months, 1, nr_ratings);
product p2("CPU", (char*)"Ryzen 5 3600", 250.75, 'A', nr_prods, false, 1, months, 1, nr_ratings);
product prods71[] = {p1, p2, p1}, prods72[] = {p2, p1};
int nr_each_prod1[] = {2, 1, 2}, nr_each_prod2[] = {1, 1};
customer cust1("xXGigelXx", "gigelecelmaitare1", "gigelut@gmail.com", 3, hardware_interested_in1);
cust1.add_order("17/04/2021", 3, nr_each_prod1, prods71);
cust1.add_order("10/04/2021", 2, nr_each_prod2, prods72);

cust1.set_nr_types_of_hardware_interested_in(2);
string hardware_interested_in2[] = {"CPU", "GPU"};
cust1.set_types_of_hardware_interested_in(hardware_interested_in2);
cust1.set_new_customer_account_id(1000);

cout<<cust1.get_nr_types_of_hardware_interested_in()<<'\n';
cout<<*(cust1.get_types_of_hardware_interested_in())<<'\n';
cout<<cust1.get_nr_orders()<<'\n';
cout<<cust1.get_orders_date()[0]<<'\n';
cout<<cust1.get_nr_product_types_of_order()[0]<<'\n';
cout<<cust1.get_nr_each_product_type_of_order()[0][0]<<'\n';
cout<<cust1.get_orders()[0][0]<<'\n';
cout<<cust1.get_new_customer_account_id()<<'\n';

cust1.set_new_customer_account_id(400005);

cust1.account_functionality();
cout<<'\n';

customer cust2;
cust2 = cust1;
cust2.account_functionality();
cout<<'\n';

customer cust3;
cust3 = cust2;
cust3.account_functionality();

cout<<"\n========================================\n";
cout<<"========================================\n\n\n";
///========================================


/// Tests for the class "staff":
///========================================
cout<<"Tests for the class \"staff\":\n";
cout<<"========================================\n";
cout<<"========================================\n\n";

accs1[4] = new staff("Andrew Davis", "passAndrew", "davis.andrew@gmail.com", "Site administration");
cout<<*accs1[4];
accs1[4]->account_functionality();
cout<<'\n';

accs1[5] = new staff;
cout<<*accs1[5]<<'\n';

staff staff_aux;

accs1[6] = new staff(staff_aux);
cout<<*accs1[6]<<'\n';

accs1[7] = new staff;
*accs1[7] = *accs1[4];
cout<<*accs1[7]<<'\n';

cin.get();
// cin>>*accs1[7];
// cout<<'\n'<<*accs1[7]<<'\n';

accs1[4]->set_username("John Harvey");
accs1[4]->set_password("harveyjohn");
accs1[4]->set_email("harveyjohn@gmail.com");

cout<<accs1[4]->get_username()<<'\n';
cout<<accs1[4]->get_password()<<'\n';
cout<<accs1[4]->get_email()<<'\n';
cout<<accs1[4]->get_account_id()<<"\n\n";

staff s1("Name", "Password", "Email", "Role");
s1.add_review(4.5); s1.add_review(5); s1.add_review(3.2); s1.add_review(2.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(3.5); s1.add_review(5);

s1.set_role("Role 2");
s1.set_nr_of_customers_helped(1000);
s1.set_new_staff_account_id(2000);

cout<<s1.get_role()<<'\n';
cout<<s1.get_nr_of_customers_helped()<<'\n';
cout<<s1.get_nr_customer_reviews()<<'\n';
cout<<s1.get_customer_reviews()[0]<<'\n';
cout<<s1.get_average_customer_reviews()<<'\n';
cout<<s1.get_account_id()<<'\n';

s1.set_new_staff_account_id(500004);

s1.account_functionality();
cout<<'\n';

staff s2;
s2 = s1;
s2.account_functionality();
cout<<'\n';

staff s3;
s3 = s2;
s3.account_functionality();

cout<<"\n========================================\n";
cout<<"========================================\n";
///========================================

for (int i = 0; i < 8; i++)
    delete accs1[i];

return 0;}