#include<map>
#include<string>
#include <iostream>
#include <windows.h>

#pragma execution_character_set( "utf-8" )

constexpr auto AD_EXE = "\"C://Program Files (x86)//AnyDesk//AnyDesk.exe\"";
constexpr auto AD_ID_ALEX = "761515821";
constexpr auto AD_ID_GABRIEL = "249558384";
constexpr auto AD_ID_VICTOR = "686573251";

const std::string C_VICTOR = "V";
const std::string C_ALEX = "A";
const std::string C_GABRIEL = "G";

int main()
{
    SetConsoleOutputCP(65001);

    std::cout << "Em qual computador deseja se conectar?" << std::endl << std::endl;
    std::map<std::string, std::string> conns;

    conns[C_ALEX] = "Alex";
    conns[C_GABRIEL] = "Gabriel";
    conns[C_VICTOR] = "Victor";

    for (auto conn : conns)
    {
        std::cout << conn.first + ". ";
        std::cout << conn.second << std::endl;
    }

    std::cout << std::endl << "Infome a opcao desejada: ";

    std::string c_exe = (std::string) AD_EXE;
    std::string c_id;
    std::string command;
    std::string opc;
    std::cin >> opc;

    if (opc == C_ALEX)
    {
        c_id = (std::string) AD_ID_ALEX;
    }
    else if (opc == C_GABRIEL)
    {
        c_id = (std::string) AD_ID_GABRIEL;
    }
    else if (opc == C_VICTOR)
    {
        c_id = (std::string) AD_ID_VICTOR;
    }
    else
    {
        std::cout << std::endl << "Selecao invalida.";
        return 1;
    }

    command = c_exe.append(((std::string)" ").append((c_id)));
    return std::system(command.c_str());
}