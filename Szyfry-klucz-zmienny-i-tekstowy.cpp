#include <iostream>

using namespace std;

string Szyfruj( string tekst, int klucz )
{
    const unsigned R = 95;

    while( klucz < 0 )
    {
        klucz += R;
    }

    for( unsigned i = 0; i < tekst.length(); i++ )
    {
        unsigned znak = tekst[ i ];

        znak -= ' ';

        znak += klucz;

        znak %= R;

        znak += ' ';

        tekst[ i ] = znak;
    }

    return tekst;
}

string Szyfruj_dynamicznie( string tekst, int klucz )
{
    const unsigned R = 95;
    bool kluczUjemny = ( klucz < 0 ? true : false );

    while( klucz < 0 )
    {
        klucz += R;
    }

    for( unsigned i = 0; i < tekst.length(); i++ )
    {
        int znak = tekst[ i ];

        znak -= ' ';

        if( kluczUjemny == false )
        {
            znak += klucz + 13 * i;
        }
        else
        {
            znak += klucz - 13 * i;

            while( klucz < 0 )
            {
                klucz += R;
            }
        }

        znak %= R;

        znak += ' ';

        tekst[ i ] = znak;
    }

    return tekst;
}

string Szyfruj_kluczem_tekstowym( string tekst, string str_klucz )
{
    const unsigned R = 95;
    bool kluczUjemny = false;

    if( str_klucz[ 0 ] == '-' )
    {
        kluczUjemny = true;

        str_klucz = str_klucz.substr( 1, str_klucz.length() );
    }


    /*while( klucz < 0 )
    {
        klucz += R;
    }*/

    for( unsigned i = 0; i < tekst.length(); i++ )
    {
        int znak = tekst[ i ];

        znak -= ' ';

        int klucz = i % str_klucz.length();

        if( kluczUjemny == false )
        {
            znak += str_klucz[ klucz ];
        }
        else
        {
            znak -= str_klucz[ klucz ];

            while( znak < 0 )
            {
                znak += R;
            }
        }

        znak %= R;

        znak += ' ';

        tekst[ i ] = znak;
    }

    return tekst;
}

int main()
{
    //int klucz;
    string zdanie;
    string str_klucz;

    cout << "Podaj klucz: ";
    //cin  >> klucz;
    getline( cin, str_klucz );
    cerr << str_klucz << "\n";

    //cin.ignore( 1 );

    cout << "Podaj zdanie: ";

    while( true )
    {
        getline( cin, zdanie );

        if( zdanie == "~~" )
        {
            cerr << "~~\n";
            break;
        }

        //string szyfr = Szyfruj( zdanie, klucz );
        //string szyfr = Szyfruj_dynamicznie( zdanie, klucz );
        string szyfr = Szyfruj_kluczem_tekstowym( zdanie, str_klucz );

        cerr << szyfr << "\n";
    }

    return 0;
}
