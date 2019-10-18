#include <iostream>

using namespace std;

int tam_cad(char cadena[])
{
    int tam=0;
    for(int i=0; cadena[i]!='\0';i++)
    {
        tam ++;
    }
    return tam;
}

int tam_cadPunteros(char *cadena)
{
    int tam=0;
    for(int i=0; *(cadena+i)!='\0';i++)
    {
        tam++;
    }
    return tam;
}

int tam_cadRecursiva(char cadena[])
{
    ///int i=0;
    if (cadena[0] == '\0'){
        return 0;
    }
    return 1 + tam_cadRecursiva(++cadena);
}


int tam_cadRecursivaPunteros(char *cadena)
{
    if(*cadena !='\0')
    {
        return 1 + tam_cadRecursivaPunteros( ++cadena);
    }
    else{
        return 0;
    }
}

void invertir_cad(char cadena[])
{
    char *fin = cadena + tam_cad(cadena) - 1;
    char a;
    while(fin > cadena)
    {
        a = *cadena;
        *cadena = *fin;
        *fin = a;
        cadena++;
        fin--;
    }
}

int invertir_cadRecursiva(char *cadena,  char c, char *fin)
{
    char a;
    c=*cadena;
    *fin = *(cadena + tam_cad(cadena) - 1);
    if(*cadena=='\0')
    {
        return 0;
    }
    else{
        a=*cadena;
        *cadena=*fin;
        *fin=a;
        return invertir_cadRecursiva(*cadena, ++c, --fin);
    }
}

int main()
{
    char cadena[]="Hola mundo";
    cout << " ' " <<cadena<< " ' ";
    cout << " posee " <<tam_cad(cadena)<< " caracteres"<< endl;
    char cadena1[]="Red";
    cout << " ' " <<cadena1<< " ' ";
    cout << " posee " <<tam_cadPunteros(cadena1)<< " caracteres"<< endl;
    char cadena2[]="Hola mundo";
    cout << " ' " <<cadena2<< " ' ";
    cout << " posee " <<tam_cadRecursiva(cadena2)<< " caracteres"<< endl;
    char cadena3[]="Wally";
    cout << " ' " <<cadena3<< " ' ";
    cout << " posee " <<tam_cadRecursivaPunteros(cadena3)<< " caracteres"<< endl;
    cout << " ' " <<cadena3<< " ' ";
    invertir_cad(cadena3);
    cout << " ' " <<cadena3<< " ' ";
    invertir_cadRecursiva(cadena1, cadena1[0], tam_cad(cadena1));
    cout << cadena1;

}
