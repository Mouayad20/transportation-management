#include <iostream>
#include<string.h>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
class date
{
protected:
    int day,month,year;
public:
    date() {}
    date(int day,int month,int year)
    {
        this -> day = day;
        this -> month = month ;
        this -> year = year ;
    }
    void set_date()
    {
pipi:
        cout<<"\n:::::::enter date of made:::::: \n";
        cout<<"enter day :: ";
        cin>>day;
        if ( day > 30 || day <=0 )
        {
            cout<<"\n **** wrong date **** \n";
            goto pipi;
        }
        cout<<"enter month :: ";
        cin>>month;
        if (  month > 12 || month <= 0 )
        {
            cout<<"\n **** wrong date **** \n";
            goto pipi;
        }
        cout<<"enter year :: ";
        cin>>year;
        if ( year < 1990 || year <= 0)
        {
            cout<<"\n **** wrong date **** \n";
            goto pipi;
        }
    }
    void set_date_jo()
    {
pipi:
        cout<<"::::::enter date of journey :::::: \n";
        cout<<"enter day :: ";
        cin>>day;
        if ( day > 30 || day <=0 )
        {
            cout<<"\n **** wrong date **** \n";
            goto pipi;
        }
        cout<<"enter month :: ";
        cin>>month;
        if (  month > 12 || month <= 0 )
        {
            cout<<"\n **** wrong date **** \n";
            goto pipi;
        }
        cout<<"enter year :: ";
        cin>>year;
        if ( year < 1990 || year <= 0)
        {
            cout<<"\n **** wrong date **** \n";
            goto pipi;
        }
    }
    int get_day()
    {
        return day;
    }
    int get_m()
    {
        return month;
    }
    int get_y()
    {
        return year;
    }
};
class transport
{
protected:
    int id;
    char  name_company[30];
    int speed;
    char type_have[30];
    char type_trans[30];
public:
    date date_of_made;
    transport() {}
    transport(int id,char name_company[],date x, char type_have[]) :date_of_made(x)
    {
        this->id=id;
        this->name_company[30]=name_company[30];
        this->type_have[30]=type_have[30];
    }
    void input_trans( int y )
    {
        id = y;
        cout<<"enter name of company :: ";
        scanf("%s",&name_company);
        date_of_made.set_date();
momo:
        cout<<"enter type of have ( 1 ) for private transport\n";
        cout<<"                   ( 2 ) for company transport\n";
        cout<<"                   ( 3 ) for international transport  :: ";
        int x;
        cin>>x;
        if ( x == 1 )
            strcpy(type_have, "private");
        else if ( x == 2 )
            strcpy(type_have, "company");
        else if ( x == 3 )
            strcpy(type_have, "international");
        else
        {
            cout<<"\nenter number 1 or 2 or 3 \n\n ";
            goto momo;
        }
    }
    virtual void display()
    {
        cout<<"\n*****************\n";
        cout<<"id of transport :: "<<id<<endl;
        cout<<"name of company :: "<<name_company<<endl;
        cout<<"date of made "<<date_of_made.get_day()<<"/"<<date_of_made.get_m()<<"/"<<date_of_made.get_y()<<endl;
        cout<<"type of have  :: "<<type_have<<endl;
        cout<<"type of this transport :: "<<type_trans<<endl;
    }
    virtual void get_name() {}
    virtual int get_alwzn_alfargh () {}
    virtual int get_alwzn_alaksa () {}
    virtual int get_sites() {}
    int get_id()
    {
        return id;
    }
    char *gett_type_trans()
    {
        return type_trans;
    }
    void set_id ( int x )
    {
        id = x ;
    }
};
class aerial :public transport
{
protected:
    int num_of_engine;
    int length;
public:
    aerial() {}
    aerial(int x,int y)
    {
        num_of_engine = x;
        length = y;
    }
    void input_aerial(int x)
    {
        input_trans(x);
        cout<<"enter number of engines :: ";
        cin>>num_of_engine;
        cout<<"enter length :: ";
        cin>>length;
        cout<<"enter speed in knots :: ";
        cin>>speed;
    }
    void display()
    {
        transport ::display();
        cout<<"number of engines :: "<<num_of_engine<<endl;
        cout<<"length :: "<<length<<endl;
    }
};
class passengres : public aerial
{
protected:
    int sits;
    int max_wigth_bags;
public:
    passengres()
    {
        strcpy(type_trans,"plane Of Passengers");
    }
    passengres(int x,int y)
    {
        sits =x;
        max_wigth_bags=y;
    }
    void input_passengres(int x)
    {
        input_aerial(x);
error:
        cout<<"enter number of sits :: ";
        cin>>sits;
        if (sits < 0)
        {
            cout<<"wrong number "<<endl;
            goto error;
        }
        max_wigth_bags = 25 * sits ;
        cout<<"the max  weight of bags :: " << max_wigth_bags;;

    }
    void display()
    {
        aerial::display();
        cout<<"number of sits :: "<<sits<<endl;
        cout<<"the max  weight of bags :: "<<max_wigth_bags<<endl;
    }
    char *  gett_type_trans()
    {
        return type_trans;
    }
    int get_sites()
    {
        return sits ;
    }
};
class goods : public aerial
{
protected:
    int empty_wigth;
    int max_wigth;
public:
    goods()
    {
        strcpy(type_trans,"plane of goods");
    }
    goods(int x,int y)
    {
        empty_wigth = x;
        max_wigth  = y;
    }
    void input_goods(int x)
    {
        input_aerial(x);
        cout<<"enter the empty weight :: ";
        cin>>empty_wigth;
        cout<<"enter the max weight :: ";
        cin>>max_wigth;
    }
    void display()
    {
        aerial::display();
        cout<<"the empty weight :: "<<empty_wigth<<endl;
        cout<<"the max weight :: "<<max_wigth<<endl;
    }
    char *gett_type_trans()
    {
        return type_trans;
    }
    int get_alwzn_alfargh()
    {
        return empty_wigth;
    }
    int get_alwzn_alaksa()
    {
        return max_wigth;
    }
};
class wilderness : public transport
{
protected:
    int volume_engine;
    int length;
public:
    wilderness() {}
    wilderness(int x,int y)
    {
        volume_engine = x;
        length = y;
    }
    void input_wilderness(int x)
    {
        input_trans(x);
        cout<<"enter the volume of engine :: ";
        cin>>volume_engine;
        cout<<"enter length :: ";
        cin>>length;
        cout<<"enter speed in kilometer:: ";
        cin>>speed;
    }
    void display()
    {
        transport :: display();
        cout<<"the volume of engine :: "<<volume_engine<<endl;
        cout<<"length :: "<<length<<endl;
    }
};
class bus : public wilderness
{
protected:
    int sets;
public:
    bus()
    {
        strcpy  ( type_trans, "bus of passengers" );
    }
    bus(int x)
    {
        sets = x;
    }
    void input_bus(int x)
    {
        input_wilderness( x);
        cout<<"enter number of sets :: ";
        cin>>sets;
    }
    void display()
    {
        wilderness :: display();
        cout<<"number of sets is :: "<<sets<<endl;
    }
    char*  gett_type_trans()
    {
        return type_trans;
    }
    int get_sites()
    {
        return sets;
    }
};
class car : public wilderness
{
protected:
    int num_of_doors;
public:
    car()
    {
        strcpy( type_trans, "car of passengers" );
    }
    car(int x)
    {
        num_of_doors = x;
    }
    void input_car(int x)
    {
        input_wilderness(x);
        cout<<"enter number of doors :: ";
        cin>>num_of_doors;
    }
    void display()
    {
        wilderness :: display();
        cout<<"number of doors is :: "<<num_of_doors<<endl;
    }
    char*  gett_type_trans()
    {
        return type_trans;
    }
};
class truck : public wilderness
{
protected:
    int tare_weight;
    int max_weight;
    int higth_goods;
public:
    truck()
    {
        strcpy( type_trans, "truck of goods" );
    }
    truck(int x,int y,int z)
    {
        tare_weight =x;
        max_weight = y;
        higth_goods = z;
    }
    void input_truck(int x)
    {
        input_wilderness(x);
        cout<<"enter the tare weight :: ";
        cin>>tare_weight;
        cout<<"enter the max weight :: ";
        cin>>max_weight;
        cout<<"enter the height :: ";
        cin>>higth_goods;
    }
    void display()
    {
        wilderness :: display();
        cout<<"the tare weight is :: "<<tare_weight<<endl;
        cout<<"the max weight :: "<<max_weight<<endl;
        cout<<"the height of goods is :: "<<higth_goods<<endl;
    }
    char*  gett_type_trans()
    {
        return type_trans ;
    }
    int get_alwzn_alfargh()
    {
        return tare_weight ;
    }
    int get_alwzn_alaksa()
    {
        return max_weight ;
    }
};
class Booking
{
private:
    bool statu_of_site ;
    int weigth_bags_passenger ;
public:
    Booking()
    {
        weigth_bags_passenger = 0 ;
    }
    void set_statu ( bool x  )
    {
        statu_of_site = x ;
    }
    bool get_statu()
    {
        return statu_of_site ;
    }
    int get_weigth_bags_passenger()
    {
        return weigth_bags_passenger;
    }
    void set_wzn_bags_rakeb(int i)
    {
toto:
        cout<<"\nenter weight bag of  passenger ( "<<i<<  ")  :: ";
        cin>>weigth_bags_passenger ;
        if ( weigth_bags_passenger > 25  || weigth_bags_passenger < 0 )
        {
            cout<<"\n\n*****  weight of bag must be less than 25  *****\n\n     try again   ";
            goto toto;
        }
    }
};
class journey
{
protected:
    int num_of_journey ;
    int id ;
    int num_passengres ;
    char type_trans[30] ;
    char from[30] ;
    char to[30] ;
    int weigth_of_homola ;
    int weigth_of_ka2m ;
    int warning_weigth ;
    int num_sits;
public:
    Booking *B ;
    date date_of_journey ;
    journey () {}
    void set_id(int x)
    {
        id = x;
    }
    void set_type_trans(char *x)
    {
        strcpy( type_trans, x );
    }
    void set_num_of_journey( int x )
    {
        num_of_journey = x;
    }
    void set_from_and_to ()
    {
        cout<<"this journey from  :: ";
        scanf("%s",&from);
        cout<<"this journey to  :: ";
        scanf("%s",&to);
    }
    void set_weigth_of_homola ()
    {
        cout<<"\n enter Cargo weight :: ";
        cin>>weigth_of_homola;
    }
    void set_warning_weigth ( int x )
    {
        warning_weigth = x;
        if( x == 1 )
            cout<<"\n\n===> WARNING <=== \n\n";
    }
    void set_weigth_of_ka2m (int x)
    {
        weigth_of_ka2m = x;
    }
    void set_passengers()
    {
        cout<<"\n enter number of passengers :: ";
        cin>>num_passengres ;
    }
    void set_num_sits(int x)
    {
        num_sits = x ;
    }
    int get_num_sits()
    {
        return num_sits ;
    }
    int get_weigth_of_homola()
    {
        return weigth_of_homola ;
    }
    int get_weigth_of_ka2m ()
    {
        return weigth_of_ka2m;
    }
    int get_passengers()
    {
        return num_passengres ;
    }
    char * get_from()
    {
        return from ;
    }
    char *  get_to()
    {
        return to;
    }
    int get_id()
    {
        return id ;
    }
    char * get_type_trans()
    {
        return type_trans ;
    }
    int get_num_journey()
    {
        return num_of_journey;
    }
    void display_jp()
    {
        cout<<"\n***************************************\n";
        cout<<"the number of journey is  :: "<<num_of_journey<<endl;
        cout<<"the id of used transport is  :: "<<id<<endl;
        cout<<"this journey from  ( "<<from<<" ) to  ( "<<to<<" )"<<endl;
        cout<<"the history of journey is ( "<<date_of_journey.get_day()<<"/"<<date_of_journey.get_m()<<"/"<<date_of_journey.get_y()<<" )"<<endl;
        cout<<"the type of this transport is :: "<<type_trans<<endl;
        cout<<"\n************************************************\n";
        for(int i=1 ; i<=num_sits ; i++ )///n = number of sites
        {
            cout<<"the statue of set number ( "<<i<<" ) is  :: "<<B[i].get_statu()<<endl;
            cout<<"the weight of passenger number ( "<<i<<" ) is  :: "<<B[i].get_weigth_bags_passenger()<<endl;
            cout<<"\n************************************************\n";
        }
        cout<<"\n***************************************\n";
    }
    void display_jg()
    {
        cout<<"\n***************************************\n";
        cout<<"the number of journey is  :: "<<num_of_journey<<endl;
        cout<<"the id of used transport is  :: "<<id<<endl;
        cout<<"this journey from  ( "<<from<<" ) to  ( "<<to<<" )"<<endl;
        cout<<"the history of journey is ( "<<date_of_journey.get_day()<<"/"<<date_of_journey.get_m()<<"/"<<date_of_journey.get_y()<<" )"<<endl;
        cout<<"the type of this transport is :: "<<type_trans<<endl;
        cout<<"Cargo weight is  :: "<<weigth_of_homola<<endl;
        cout<<"Gross weight is  :: "<<weigth_of_ka2m<<endl;
        cout<<"\n***************************************\n";
    }
};
struct node
{
    transport *t ;
    journey *j ;
    node *next ;
};
class Linked
{
private:
    node *head;
public:
    Linked()
    {
        head=NULL;
    }
    void insert_Linked(transport *x)
    {
        node *newnode = new node ;
        newnode->t = x;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            newnode->next = NULL ;
        }
        else
        {
            newnode->next = head;
            head = newnode ;
        }
    }
    void insert_Linked_journy(journey *x)
    {
        node *newnode = new node ;
        newnode->j = x;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            newnode->next = NULL ;
        }
        else
        {
            newnode->next = head;
            head = newnode ;
        }
    }
    transport * search_id(int x)
    {
        node *temp = new node;
        temp = head;
        if (temp == NULL)
            return NULL ;
        while(temp != NULL)
        {
            if ( temp->t->get_id() == x)
            {
                return temp->t ;
            }
            temp = temp ->next;
        }
        return NULL ;
    }
    journey * search_id_journey(int x)
    {
        node *temp = new node;
        temp = head;
        if (temp == NULL)
            return NULL ;
        while(temp != NULL)
        {
            if ( temp->j->get_id() == x)
            {
                return temp->j ;
            }
            temp = temp ->next;
        }
        return NULL ;
    }
    int search_num_journey(int x)
    {
        node *temp = new node;
        temp = head;
        if (temp == NULL)
            return 0 ;
        while(temp != NULL)
        {
            if ( temp->j->get_num_journey() == x)
            {
                return 1 ;
            }
            temp = temp ->next;
        }
        return -1 ;
    }
    void search_f_t( char *fr, char *t  )
    {
        node *temp = new node;
        temp = head;
        int i = 1 ;
        if ( temp == NULL )
            cout<<"\n\n*****Linked list of journey is empty*****\n\n";
        while ( temp != NULL )
        {
            if (strcmp(temp->j->get_from(),fr )==0&&strcmp(temp->j->get_to(),t)==0 )
            {
                cout<<"the number of journey ("<<i<<") is ::  "<<temp->j->get_num_journey()<<endl;
                i++;
            }

            temp = temp -> next ;
        }
        if ( i == 0)
            cout<<"\n\n\n\n      not found number of journey    \n\n\n\n";
    }
    void print()
    {
        node *newnode=new node;
        newnode = head;
        while(newnode!=NULL)
        {
            newnode->t->display();
            newnode=newnode->next;
        }
    }
    int pass(int y)
    {
        int sum = 0 ;
        node *temp = new node;
        temp = head;
        if ( temp == NULL )
            cout<<"\n\n*****Linked list of journey is empty*****\n\n";
        while ( temp != NULL )
        {
            if (temp->j->date_of_journey.get_y() == y)
            {
                if(strcmp(temp->j->get_type_trans(),"bus of passengers")==0)
                    sum+=temp->j->get_passengers();
                if( strcmp(temp->j->get_type_trans(),"plane Of Passengers")==0)
                    sum+=temp->j->get_passengers();
            }
            temp = temp -> next ;
        }
        return sum;
        //cout<<"\n\nall number of passengers is :: "<<sum<<endl;
    }
};
template < class T >
void insert_in_file( T t, char x )
{
    fstream f;
    f.open("transport.bin",ios::binary|ios::app);
    f.write((char *)&x,sizeof (x));
    f.write((char *)&t,sizeof(T));
    f.close();
}
void insert_journey_in_file( journey t, char x )
{
    fstream j;
    j.open("journey.bin",ios::binary|ios::app);
    j.write((char *)&x,sizeof (x));
    j.write((char *)&t,sizeof(journey));
    j.close();
}
void swap_file_to_Linked( Linked *l )
{
    char x;
    fstream f;
    f.open("transport.bin",ios::binary|ios::in);
    while(f.read((char *)&x, sizeof(x)))
    {
        switch(x)
        {
        case 'p':
        {
            passengres *p = new passengres ;
            f.read((char *)p,sizeof(passengres));
            l->insert_Linked(p);
            break;
        }
        case 'g':
        {
            goods *g = new goods ;
            f.read((char *)g,sizeof(goods)) ;
            l->insert_Linked(g);
            break;
        }
        case 'b':
        {
            bus *b = new bus ;
            f.read((char *)b,sizeof(bus));
            l->insert_Linked(b);
            break;
        }
        case 'c':
        {
            car *c = new car ;
            f.read((char *)c, sizeof(car));
            l->insert_Linked(c);
            break;
        }
        case 't':
        {
            truck *t = new truck ;
            f.read((char *)t,sizeof(truck));
            l->insert_Linked(t);
            break;
        }
        default:
        {
            cout<<"\nerror in swap from transport file to Linked list\n";
            break;
        }
        }
    }
    f.close();
}
void swap_filejourney_to_Linked( Linked *l )
{
    char x;
    fstream j;
    j.open("journey.bin",ios::binary|ios::in);
    while(j.read((char *)&x, sizeof(x)))
    {
        switch(x)
        {
        case 'p':
        {
            journey *jpp = new journey ;
            j.read((char *)jpp,sizeof(journey));
            l->insert_Linked_journy(jpp);
            break;
        }
        case 'g':
        {
            journey *jgg = new journey ;
            j.read((char *)jgg,sizeof(journey));
            l->insert_Linked_journy(jgg);
            break;
        }
        case 'b':
        {
            journey *jpb = new journey ;
            j.read((char *)jpb,sizeof(journey));
            l->insert_Linked_journy(jpb);
            break;
        }
        case 't':
        {
            journey *jgt = new journey ;
            j.read((char *)jgt,sizeof(journey));
            l->insert_Linked_journy(jgt);
            break;
        }
        default:
        {
            cout<<"\nerror in swap from journey file to Linked list\n";
            break;
        }
        }
    }
    j.close();
}
int test_date(date j, date t)
{
    if (j.get_y() < t.get_y())
        return -1 ;
    else if (j.get_y() == t.get_y())
        if (j.get_m() < t.get_m())
            return -1 ;
        else if (j.get_y() == t.get_y())
            if ( j.get_m() ==t.get_m() )
                if (j.get_day() < t.get_day())
                    return -1 ;
                else if (j.get_y() == t.get_y())
                    if ( j.get_m() ==t.get_m() )
                        if (j.get_day() == t.get_day())
                            return -1 ;
                        else
                            return 1;
}
int main()
{
    Linked l;
    Linked lj;
    swap_file_to_Linked(&l);
    swap_filejourney_to_Linked(&lj);
    int choic ;
    while(choic!=8)
    {
        cout<<"\n*****************\n"<<endl;
        cout<<"1_insert information of transport :: \n"<<endl;
        cout<<"2_search about transport by transport id :: \n"<<endl;
        cout<<"3_insert information of journey :: \n"<<endl;
        cout<<"4_display numbers of journeys between two cites :: \n"<<endl;
        cout<<"5_display numbers of passengers for journey :: \n"<<endl;
        cout<<"6_display information of journeys :: \n"<<endl;
        cout<<"7_display information of transports :: \n"<<endl;
        cout<<"8_***********   EXITE   ************  \n"<<endl;
        cout<<"*****************\n"<<endl;
        cout<<"your choice ->  ";
        cin>>choic;
        cout<<"\n*****************\n"<<endl;
        switch(choic)
        {
        case 1:
        {
            int x;
error6:
            cout<<"\nenter ( 1 ) for aerial transport\n      ( 2 ) for wilderness transport\n      your choice ->  ";
            cin>>x;
            if ( x == 1 )
            {
error3:
                char y;
                cout<<"enter ( p ) for passengers plane\n      ( g ) for goods plane\n      your choice ->  ";
                cin>>y;
                if ( y == 'p' )
                {
                    int x ;
                    cout<<"\n*****************\n";
                    cout<<"enter id of transport :: ";
popo:
                    cin>> x;
                    transport *r = l.search_id(x);
                    if ( r != NULL )
                    {
                        cout<<"*****this id is exist*****\n    enter  another one  ::";
                        goto popo;
                    }
                    else
                    {
                        passengres *p = new passengres;
                        p->input_passengres(x);
                        l.insert_Linked(p);
                        insert_in_file(*p,y);
                        break;
                    }
                }
                else if ( y == 'g' )
                {
                    int x ;
                    cout<<"\n*****************\n";
                    cout<<"enter id of transport :: ";
popa:
                    cin>> x;
                    transport *r = l.search_id(x);
                    if (  r != NULL  )
                    {
                        cout<<"*****this id is exist*****\n    enter  another one  ::";
                        goto popa;
                    }
                    else
                    {
                        goods *g = new goods ;
                        g->input_goods(x);
                        l.insert_Linked(g);
                        insert_in_file(*g,y);
                        break;
                    }
                }
                else
                {
                    cout<<"you entered  not p or g \n      try again      \n";
                    goto error3;
                }
            }
            else if ( x == 2 )
            {
error5:
                cout<<"\nenter ( b ) for bus wilderness \n      ( c ) for car wilderness \n      ( t ) for truck wilderness\n      your choice ->  ";
                char z;
                cin>>z;
                if ( z == 'b' )
                {

                    int x ;
                    cout<<"\n*****************\n";
                    cout<<"enter id of transport :: ";
popi:
                    cin>> x;
                    transport *r = l.search_id(x);
                    if ( r != NULL )
                    {
                        cout<<"*****this id is exist*****\n    enter  another one  ::";
                        goto popi;
                    }
                    else
                    {
                        bus *b = new bus ;
                        b->input_bus(x);
                        l.insert_Linked(b);
                        insert_in_file(*b,z);
                        break;
                    }
                }
                else if ( z == 'c' )
                {
                    int x ;
                    cout<<"\n*****************\n";
                    cout<<"enter id of transport :: ";
popia:
                    cin>> x;
                    transport *r = l.search_id(x);
                    if ( r != NULL )
                    {
                        cout<<"*****this id is exist*****\n    enter  another one  ::";
                        goto popia;
                    }
                    else
                    {
                        car *c = new car ;
                        c->input_car(x);
                        l.insert_Linked(c);
                        insert_in_file(*c,z);
                        break;
                    }
                }
                else if ( z == 't' )
                {
                    int x ;
                    cout<<"\n*****************\n";
                    cout<<"enter id of transport :: ";
popio:
                    cin>> x;
                    transport *r = l.search_id(x);
                    if ( r != NULL )
                    {
                        cout<<"*****this id is exist*****\n    enter  another one  ::";
                        goto popio;
                    }
                    else
                    {
                        truck *t = new truck ;
                        t->input_truck(x);
                        l.insert_Linked(t);
                        insert_in_file(*t,z);
                        break;
                    }
                }
                else
                    cout<<"\n***********you entered not b or c or t***********\n      try again      \n";
                goto error5;
            }
            else
            {
                cout<<"you entered number not 1 or 2 \n      try again      \n";
                goto error6;
            }
            break;
        }
        case 2:
        {
            int g;
            cout<<"enter number of id you would to search it :: ";
            cin>>g;
            transport *r = l.search_id(g);
            if ( r == NULL )
                cout<<"\n *****not found my baby***** \n";
            else
            {
                cout<<"\n *****found***** \n\n  the type of trans to this transport is ==> "<<r->gett_type_trans();
            }
            break;
        }
        case 3:
        {
error10:
            cout<<"\nenter ( p ) for passenger journey :: \n      ( g ) for goods journey :: \n      your choice ->  ";
            char x ;
            cin>>x;
            if ( x == 'p' )
            {
error11:
                cout<<"\nenter ( p ) for passengers plane :: \n      ( b ) for bus ::\n      your choice ->  ";
                char y;
                cin>>y;
                if ( y == 'p' )
                {
                    int x;
error12:
                    cout<<"\nenter id of transport you would to travel with :: ";
                    cin>>x;
                    transport *r = l.search_id(x);
                    if ( r != NULL && (strcmp(r->gett_type_trans(), "plane Of Passengers" ))==0)
                    {
soso:
                        cout<<"enter number of journey  :: ";
                        int z;
                        cin>>z;
                        int j = lj.search_num_journey(z);
                        if ( j != 1 )
                        {
                            journey *jpp = new journey ;
                            jpp->set_num_of_journey(z);
                            jpp->set_id(x);
                            jpp->set_type_trans("plane Of Passengers");
                            jpp->set_from_and_to();
vovo:
                            jpp->date_of_journey.set_date_jo();
                            if (test_date(jpp->date_of_journey, r->date_of_made) == -1 )
                            {
                                cout<<"\n\n***you entered wrong date ***\n\n     try again   \n\n";
                                goto vovo;
                            }
                            jpp->set_num_sits(r->get_sites());
yoyo:
                            jpp->set_passengers();
                            if (  jpp->get_passengers()   <    r->get_sites()  )
                            {
                                jpp->B = new Booking[r->get_sites()];
                                for ( int i=1 ; i <=  r->get_sites() ; i++ )
                                {
                                    if ( i <= jpp->get_passengers())
                                    {
                                        jpp->B[i].set_statu(1) ;
                                        jpp->B[i].set_wzn_bags_rakeb(i);
                                    }
                                    else
                                        jpp->B[j].set_statu(0);
                                }
                            }
                            else
                            {
                                cout<<"\n\n number of passengers more than number of sites \n";
                                cout<<"enter number less than "<<r->get_sites()<<endl;
                                goto yoyo;
                            }
                            lj.insert_Linked_journy(jpp);
                            insert_journey_in_file(*jpp,y);
                        }
                        else
                        {
                            cout<<"\n\n*****this number is exist*****\n\n    try again   \n";
                            goto soso;
                        }
                    }
                    else
                    {
                        cout<<"\n\nyou entered wrong id my baby\n      try again      \n";
                        goto error12;
                    }
                }
                else if ( y == 'b' )
                {
                    int x;
error30:
                    cout<<"\nenter id of transport you would to travel in it :: \n";
                    cin>>x;
                    transport *r = l.search_id(x);
                    if ( r != NULL && strcmp(r->gett_type_trans(), "bus of passengers") == 0 )
                    {
sisi:
                        cout<<"enter number of journey  :: ";
                        int z;
                        cin>>z;
                        int j = lj.search_num_journey(z);
                        if ( j != 1 )
                        {
                            journey *jpb = new journey ;
                            jpb->set_num_of_journey(z);
                            jpb->set_id(x);
                            jpb->set_type_trans("bus of passengers");
                            jpb->set_from_and_to();
vava:
                            jpb->date_of_journey.set_date_jo();
                            if (test_date(jpb->date_of_journey, r->date_of_made) == -1 )
                            {
                                cout<<"\n\n***you entered wrong date ***\n\n     try again   \n\n";
                                goto vava;
                            }
                            jpb->set_num_sits(r->get_sites());
yiyi:
                            jpb->set_passengers();
                            if (  jpb->get_passengers()   <    r->get_sites()  )
                            {
                                jpb->B = new Booking[r->get_sites()];
                                for ( int i=1 ; i <=  r->get_sites() ; i++ )
                                {
                                    if ( i <= jpb->get_passengers())
                                    {
                                        jpb->B[i].set_statu(1) ;
                                        jpb->B[i].set_wzn_bags_rakeb(i);
                                    }
                                    else
                                        jpb->B[j].set_statu(0);
                                }
                            }
                            else
                            {
                                cout<<"\n\n number of passengers more than number of sites \n\n";
                                cout<<"enter number less than "<<r->get_sites()<<endl;
                                goto yiyi;
                            }
                            lj.insert_Linked_journy(jpb);
                            insert_journey_in_file(*jpb,y);
                        }
                        else
                        {
                            cout<<"\n\n*****this number is exist*****\n\n    try again   \n";
                            goto sisi;
                        }
                    }
                    else
                    {
                        cout<<"\n\nyou entered wrong id my baby\n      try again      \n";
                        goto error30;
                    }
                }
                else
                {
                    cout<<"\n\nyou entered not ( p ) or ( g ) \n      try again      \n";
                    goto error11;
                }
            }
            else if ( x == 'g' )
            {
error13:
                cout<<"\nenter ( g ) for goods plane :: \n      ( t ) for truck ::\n      your choice ->  ";
                char z;
                cin>>z;
                if ( z == 'g' )
                {
                    int x;
error20:
                    cout<<"\nenter id of transport you would to travel in it :: \n";
                    cin>>x;
                    transport *r = l.search_id(x);
                    if ( r != NULL && strcmp(r->gett_type_trans(), "plane of goods") == 0 )
                    {
ioio:
                        cout<<"enter number of journey  :: ";
                        int q;
                        cin>> q;
                        int j = lj.search_num_journey(q);
                        if ( j != 1 )
                        {
                            journey *jgg = new journey ;
                            jgg->set_num_of_journey(q);
                            jgg->set_id(x);
                            jgg->set_type_trans( "plane of goods" );
                            jgg->set_from_and_to();
vivi:
                            jgg->date_of_journey.set_date_jo();
                            if (test_date(jgg->date_of_journey, r->date_of_made) == -1 )
                            {
                                cout<<"\n\n***you entered wrong date ***\n\n     try again   \n\n";
                                goto vivi;
                            }
klkl:
                            jgg->set_weigth_of_homola();
                            int A = jgg->get_weigth_of_homola() + r->get_alwzn_alfargh();
                            jgg->set_weigth_of_ka2m(A);
                            if (r ->get_alwzn_alaksa() > jgg->get_weigth_of_ka2m() )
                                jgg->set_warning_weigth(0);
                            else
                            {
                                jgg->set_warning_weigth(1);
                                cout<<"enter cargo weight must be less than  "<<r->get_alwzn_alaksa()<<endl;
                                goto klkl;
                            }
                            lj.insert_Linked_journy(jgg);
                            insert_journey_in_file(*jgg,z);
                        }
                        else
                        {
                            cout<<"\n\n*****this number is exist*****\n\n    try again   \n";
                            goto ioio;
                        }
                    }
                    else
                    {
                        cout<<"\n\nyou entered wrong id my baby\n      try again      \n";
                        goto error20;
                    }
                }
                else if ( z == 't' )
                {
                    int x;
error21:
                    cout<<"\nenter id of transport you would to travel in it :: \n";
                    cin>>x;
                    transport *r = l.search_id(x);
                    if ( r != NULL && strcmp(r ->gett_type_trans(), "truck of goods") == 0 )
                    {
gogo:
                        cout<<"enter number of journey  :: ";
                        int q;
                        cin>> q;
                        int j = lj.search_num_journey(q);
                        if ( j != 1 )
                        {
                            journey *jgt = new journey ;
                            jgt->set_num_of_journey(q);
                            jgt->set_id(x);
                            jgt->set_type_trans("truck of goods");
                            jgt->set_from_and_to();
veve:
                            jgt->date_of_journey.set_date_jo();
                            if (test_date(jgt->date_of_journey, r->date_of_made) == -1 )
                            {
                                cout<<"\n\n***you entered wrong date ***\n\n     try again   \n\n";
                                goto veve;
                            }
kokl:
                            jgt->set_weigth_of_homola();
                            int A = jgt->get_weigth_of_homola() + r->get_alwzn_alfargh() ;
                            jgt->set_weigth_of_ka2m(A);
                            if (r ->get_alwzn_alaksa() > jgt->get_weigth_of_ka2m() )
                                jgt->set_warning_weigth(0);
                            else
                            {
                                jgt->set_warning_weigth(1);
                                cout<<"enter cargo weight must be less than   "<<r->get_alwzn_alaksa()<<endl;
                                goto kokl;
                            }
                            lj.insert_Linked_journy(jgt);
                            insert_journey_in_file(*jgt,z);
                        }
                        else
                        {
                            cout<<"\n\n*****this number is exist*****\n\n    try again   \n";
                            goto gogo;
                        }
                    }
                    else
                    {
                        cout<<"\n\nyou entered wrong id my baby\n      try again      \n";
                        goto error21;
                    }
                }
                else
                {
                    cout<<"\n\nyou entered not ( p ) or ( g ) \n      try again      \n";
                    goto error13;
                }
            }
            else
            {
                cout<<"\n\nyou entered not ( p ) or ( g ) \n      try again      \n";
                goto error10;
            }
            break;
        }
        case 4:
        {
            char fr[30],t[30];
            cout<<"\n\nenter city from :: ";
            cin>>fr;
            cout<<"\n\nenter city to  :: ";
            cin>>t;
            cout<<"\n*****************\n"<<endl;
            lj.search_f_t(fr,t);
            break;
        }
        case 5:
        {
            int year;
            cout<<"\n\nenter the year you would to display number of passengers in it :: ";
            cin>>year;
            int sum = lj.pass(year);
            cout<<"\n\nall number of passengers is :: "<<sum<<endl;
            break;
        }
        case 6:
        {
            int y;
            cout<<"\n\n\n*****************************************\n\n\n";
bobo:
            cout<<"enter id of transport would like display its information :: ";
            cin>>y;
            journey *j = lj.search_id_journey(y);
            if ( j != NULL )
            {
                char x;
                fstream fj;
                fj.open("journey.bin",ios::binary|ios::in);
                while(fj.read((char *)&x, sizeof(x)))
                {
                    switch(x)
                    {
                    case 'p':
                    {
                        journey *jpp = new journey ;
                        fj.read((char *)jpp,sizeof(journey));
                        if (jpp->get_id() == y)
                            jpp->display_jp();
                        break;
                    }
                    case 'g':
                    {
                        journey *jgg = new journey ;
                        fj.read((char *)jgg,sizeof(journey));
                        if (jgg->get_id() == y)
                            jgg->display_jg();
                        break;
                    }
                    case 'b':
                    {
                        journey *jpb = new journey ;
                        fj.read((char *)jpb,sizeof(journey));
                        if (jpb->get_id() == y)
                            jpb->display_jp();
                        break;
                    }
                    case 't':
                    {
                        journey *jgt = new journey ;
                        fj.read((char *)jgt,sizeof(journey));
                        if(jgt->get_id() == y)
                            jgt->display_jg();
                        break;
                    }
                    default:
                    {
                        cout<<"\nerror in swap from journey file to Linked list\n";
                        break;
                    }
                    }
                }
            }
            else
            {
                cout<<"\n     this id is not exist\n\n     try again  \n";
                goto bobo;
            }
            break;
        }
        case 7:
        {
            cout<<"\n\n\n*****************************************\n\n\n";
            l.print();
            break;
        }
        case 8:
            return 0;
        default:
        {
            cout<<"\nenter number from ( 1 ) to ( 6 ) \n"<<endl;
            break;
        }
        }
    }
}
