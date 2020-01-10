//Dumitrascu Andrada Gabriela 253 compilator 14
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
static int increment_dosar=1;
string convert_int_to_string(int x)
{
    char c[10];
    int aux=0;
    while(x)
    {
        aux=aux*10+x%10;
        x=x/10;
    }
    int i=0;
    while(aux)
    {
        c[i++]=aux%10+'0';
        aux=aux/10;
    }
    c[i]='\0';
    return c;
}
class a_doua_facultate
{
    int locuri_taxa;
public:
    virtual void citire()
    {
        cout<<"Cititi nr de locuri la taxa"<<endl;
        cin>>locuri_taxa;
    }
};
int try_int()
{
    char sir[100];
    cin>>sir;
    while(1)
    {
        try
        {
            for(int i=0; i<strlen(sir); i++)
                if(sir[i]<'0'||sir[i]>'9')
                    throw 1.5;
            break;
        }
        catch(double x)
        {
            cout<<"Mai introduceti o data";
            cin>>sir;
        }
    }
    int y=0;
    for(int i=0; i<strlen(sir); i++)
        y=y*10+sir[i];
    return y;
}
float try_float()
{

}
class frecventa
{
    int locuri_frecventa;
public:
    void citire()
    {
        cout<<"Cititi nr de locuri la frecventa"<<endl;
        locuri_frecventa=try_int();
    }
};
class distanta
{
    int locuri_distanta;
public:
    virtual void citire()
    {
        cout<<"Cititi nr de locuri la distanta"<<endl;
        locuri_distanta=try_int();
    }
};
class candidati
{
    string nume;
    float nota_bac;
    float nota_mate;
    string program_studii;
    float nota_absolvire;
    int nr_leg;
    string string_leg;
    float media;
    float nota_oral;
public:
    candidati()
    {
        nr_leg=increment_dosar++;
    }
    virtual void citire()
    {
        cout<<"Introduceti numele candidatului"<<endl;
        cin>>nume;
        cout<<"Introduceti nota la bac a candidatului"<<endl;
        cin>>nota_bac;
    }
    virtual void afisare()
    {
        cout<<"Candidatul se numeste "<<nume<<", are nota la bac "<<nota_bac;
    }
    float get_mate()
    {
        return nota_mate;
    }
    void set_mate(float x)
    {
        nota_mate=x;
    }
    float get_absolv()
    {
        return nota_absolvire;
    }
    void set_absolv(float x)
    {
        nota_absolvire=x;
    }
    string get_program()
    {
        return program_studii;
    }
    void set_program(string x)
    {
        program_studii=x;
    }
    int get_nr_leg()
    {
        return nr_leg;
    }
    void set_string_leg(string x)
    {
        string_leg=x;
    }
    string get_string_leg()
    {
        return string_leg;
    }
    float get_media()
    {
        return media;
    }
    void set_media(float x)
    {
        media=x;
    }
    float get_nota_bac()
    {
        return nota_bac;
    }
    void set_nota_oral(float x)
    {
        nota_oral=x;
    }
    float get_nota_oral()
    {
        return nota_oral;
    }
};
class candidati_frecventa : public candidati, public frecventa
{
    float sub1;
    float sub2;
public:
    void citire()
    {
        candidati :: citire();
        cout<<"Cititi nota obtinuta la subiectul 1"<<endl;
        cin>>sub1;
        cout<<"Cititi nota obtinuta la subiectul 2"<<endl;
        cin>>sub2;
        set_media((sub1+sub2)*0.4+get_nota_bac()*0.2);
    }
    void afisare()
    {
        candidati :: afisare();
        cout<<", are nr de legitimatie "<< get_nr_leg()<<",  nota la subiectul 1 "<<sub1<<", nota la subiectul 2 "<<sub2<<" si media "<<get_media();
    }
};
class candidati_distanta : public candidati, public distanta
{
public:
    void citire()
    {
        candidati :: citire();
        cout<<"Cititi nota obtinuta la matematica"<<endl;
        float nr;
        cin>>nr;
        set_mate(nr);
        string temp=convert_int_to_string(get_nr_leg());
        string temp2;
        temp2="ID_";
        for(int i=0; i<=temp.size(); i++)
            temp2[3+i]=temp[i];
        set_string_leg(temp2);
        cout<<"Cititi nota obtinuta la proba orala";
        cin>>nr;
        set_nota_oral(nr);
        set_media(get_nota_oral()*0.6+get_mate()*0.4);
    }
    void afisare()
    {
        candidati :: afisare();
        cout<<", are nr de legitimatie "<< get_string_leg()<<",  nota la matematica "<<get_mate()<<", nota la proba orala "<<get_nota_oral()<<" si media "<<get_media();
    }
};
class candidati_frecventa_a_doua_facultate : public candidati, public frecventa, public a_doua_facultate
{
public:
    void citire()
    {
        candidati :: citire();
        cout<<"Cititi programul de studii"<<endl;
        string prog;
        cin>>prog;
        set_program(prog);
        cout<<"Cititi nota de absolvire"<<endl;
        float nr;
        cin>>nr;
        set_absolv(nr);
        string temp=convert_int_to_string(get_nr_leg());
        string temp2;
        temp2="IF_";
        for(int i=0; i<=temp.size(); i++)
            temp2[3+i]=temp[i];
        set_string_leg(temp2);
        cout<<"Cititi nota obtinuta la proba orala";
        cin>>nr;
        set_nota_oral(nr);
        set_media(get_nota_oral()*0.6+get_absolv()*0.4);
    }
    void afisare()
    {
        candidati :: afisare();
        cout<<", are nr de legitimatie "<< get_string_leg()<<", a absolvit programul de studii "<<get_program()<<" cu nota "<<get_absolv();
        cout<<", a obtinut nota la proba orala "<<get_nota_oral()<<" si media "<<get_media();
    }
};
class candidati_distanta_a_doua_facultate : public candidati, public distanta, public a_doua_facultate
{
public:
    void citire()
    {
        candidati :: citire();
        cout<<"Cititi programul de studii"<<endl;
        string prog;
        cin>>prog;
        set_program(prog);
        cout<<"Cititi nota de absolvire"<<endl;
        float nr;
        cin>>nr;
        set_absolv(nr);
        string temp=convert_int_to_string(get_nr_leg());
        string temp2;
        temp2="ID_";
        for(int i=0; i<=temp.size(); i++)
            temp2[3+i]=temp[i];
        set_string_leg(temp2);
        cout<<"Cititi nota obtinuta la proba orala";
        cin>>nr;
        set_nota_oral(nr);
        set_media(get_nota_oral()*0.6+get_absolv()*0.4);
    }
    void afisare()
    {
        candidati :: afisare();
        cout<<", are nr de legitimatie "<< get_string_leg()<<", a absolvit programul de studii "<<get_program()<<" cu nota "<<get_absolv();
        cout<<", a obtinut nota la proba orala "<<get_nota_oral()<<" si media "<<get_media();
    }
};
class facultate
{
    vector <candidati*> v;
    int nr_candidati;
public:

    void citire_candidat()
    {
        cout<<"Pe ce loc candidati? 1.ID  2.IF  3.ID a 2a facultate  4.IF a 2a facultate"<<endl;
        int c;
        cin>>c;
        switch (c)
        {
        case 1:
        {
            candidati_distanta vv;
            cout<<"ok";
            vv.citire();
            v.push_back(&vv);
            break;
        }
        case 2:
        {
            candidati_frecventa vv;
            vv.citire();
            v.push_back(&vv);
            break;
        }
        case 3:
        {
            candidati_distanta_a_doua_facultate vv;
            vv.citire();
            v.push_back(&vv);
            break;
        }
        case 4:
        {
            candidati_frecventa_a_doua_facultate vv;
            vv.citire();
            v.push_back(&vv);
            break;
        }
        default:
        {
            cout<<"Ati introdus gresit"<<endl;
        }
        }
    }
    void citire()
    {
        cout<<"Cititi nr de candidati la admitere"<<endl;
        nr_candidati=try_int();
        for(int i=0; i<nr_candidati; i++)
        {
            citire_candidat();
        }
    }
    void afisare()
    {
        cout<<"Exista candidati in nr de "<<nr_candidati<<endl<<endl;
        for(int i=0; i<nr_candidati; i++)
            v[i]->afisare();
    }
    void afisare_admisi()
    {
        for(int i=0; i<nr_candidati; i++)
        {
            float nr=v[i]->get_media();
     //               if(nr>=5&&)
        }
    }
};
int main()
{
/*a_doua_facultate.citire();
distanta.citire();*/
    facultate f;
    f.citire();
    f.afisare();

    string sir;
    cout<<"Ce mai doriti sa faceti?"<<endl;
    cin>>sir;


    return 0;
}
