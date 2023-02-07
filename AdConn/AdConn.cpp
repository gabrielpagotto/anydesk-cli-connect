#include<map>
#include<string>
#include <list>
#include <iostream>
#include <windows.h>

#pragma execution_character_set( "utf-8" )

constexpr auto AD_EXE = "\"C://Program Files (x86)//AnyDesk//AnyDesk.exe\"";

class Conn {
    
    public:
        std::string name;
        std::string anydesk_id;
        std::string selection_option;

        int connect()
        {
            std::string c_exe = (std::string)AD_EXE;
            std::string command = c_exe.append(((std::string)" ").append((anydesk_id)));
            return std::system(command.c_str());
        }
};

int main(int argc, char** argv)
{
    SetConsoleOutputCP(65001);

    Conn alex_conn;
    alex_conn.name = "Alex";
    alex_conn.anydesk_id = "761515821";
    alex_conn.selection_option = "A";

    Conn gabriel_conn;
    gabriel_conn.name = "Gabriel";
    gabriel_conn.anydesk_id = "249558384";
    gabriel_conn.selection_option = "G";

    Conn victor_conn;
    victor_conn.name = "Victor";
    victor_conn.anydesk_id = "686573251";
    victor_conn.selection_option = "V";

    std::list<Conn> conns = { alex_conn, gabriel_conn, victor_conn };

    std::cout << "Em qual computador deseja se conectar?" << std::endl << std::endl;

    for (auto conn : conns)
    {
        std::cout << conn.selection_option + ". ";
        std::cout << conn.name << std::endl;
    }

    std::cout << std::endl << "Infome a opcao desejada: ";

    std::string opc;
    std::cin >> opc;

    for (int i = 0; i < opc.size(); i++)
    {
        char c_str = opc[i];
        opc[i] = std::toupper(c_str);
    }

    for (auto conn : conns)
    {
        if (conn.selection_option == opc)
        {
            return conn.connect();
        }
    }

    std::cout << std::endl << "Selecao invalida.";
    return 0;
}
