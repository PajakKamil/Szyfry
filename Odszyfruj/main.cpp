#include "Global_header.h"

std::string Szyfr_01(std::string tekst, int klucz, char begin, char end);
std::string Szyfr_02(std::string tekst);
std::string Szyfr_03(std::string tekst, int klucz, char begin, char end);
std::string Szyfr_04(std::string tekst, char begin, char end);

//abcdefghijklmnopqrstuvwxyz
// Od 'a' do 'z' 26 albo 25?? coœ takiego :)

int main()
{
	std::cout << "Szyfr 1: " << Szyfr_01("qrurezveldviavuvelurcfjzvqifsztsvqgifscvdfn", -17, 'a', 'z') << std::endl;
    std::cout << "Szyfr 2: " << Szyfr_02("meinaworfyzsedmytzawabazimeizdijeipelzaroc") << std::endl;;
    std::cout << "Szyfr 3: " << Szyfr_03("qmbjnlrhgetzxuwaacorbygdncfuvsdfentcjrrzmkt", -7, 'a', 'z') << std::endl;;
    std::cout << "Szyfr 4: " << Szyfr_04("zagabqieznijxzdlnawdbafjatqdbiqspzgzqawafjatqgwdtd", 'a', 'z') << std::endl;;

    return 0;
}

std::string Szyfr_01(std::string tekst, int klucz, char begin, char end)
{
    
    while (klucz < 0)
    {
        klucz += 26;
    }
    for (int i = 0; i < tekst.length(); i++)
    {
        unsigned znak = tekst[i];
        znak += klucz;
        if(znak > end)
        { 
            znak = znak % end;
            znak += begin - 1;
        }
        tekst[i] = znak;
    }


    return tekst;
}

std::string Szyfr_02(std::string tekst)
{
    std::string dobry;

    for (int i = tekst.length() - 1; i >= 0; i--)
    {
        dobry += tekst[i];
    }
    tekst = dobry;
    return tekst;
}

std::string Szyfr_03(std::string tekst, int klucz, char begin, char end)
{
    while (klucz < 0)
    {
        klucz += 26;
    }
    for (int i = 0; i < tekst.length(); i++)
    {
        unsigned znak = tekst[i];
        znak += klucz;
        for (int j = 0; j < tekst.length(); j++)
        {
            if (znak > end)
            {
                znak = znak % end;
                znak += begin - 1;
            }
            else
            {
                break;
            }
        }
        klucz--;
        while (klucz < 0)
        {
            klucz += 26;
        }
        tekst[i] = znak;
    }


    return tekst;
}

std::string Szyfr_04(std::string tekst, char begin, char end)
{
    std::string ascii;
    std::string alfabet;

    for (int i = 0; i < end; i++)
    {
        ascii += begin + i;
        alfabet += begin + i;
    }
    for (int i = 0; i < ascii.length(); i++)
    {
        unsigned znak = ascii[i];
        znak += i;
        for (int j = 0; j < tekst.length(); j++)
        {
            if (znak > end)
            {
                znak = znak % end;
                znak += begin;
            }
        }
        ascii[i] = znak;
    }
    for (int i = 0; i < tekst.length(); i++)
    {
        unsigned znak{};
        for (int j = 0; j < ascii.length(); j++)
        {  
            if (ascii[j] == tekst[i])
            {
                znak = alfabet[j];
                break;
            }
        }
        tekst[i] = znak;
    }
    return tekst;
}