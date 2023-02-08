#include<string>
#include <list>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdbool.h>

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1;
#include <experimental/filesystem>

#pragma execution_character_set( "utf-8" )

constexpr auto ANYDESK_CONN_F = "C:\\AnydeskConn";
constexpr auto CONF_F = "C:\\AnydeskConn\\config.txt";

std::string anydesk_exe;

class Conn {

public:
	std::string name;
	std::string anydesk_id;
	std::string selection_option;

	int connect()
	{
		std::string c_exe = (std::string)anydesk_exe;
		std::string command = c_exe.append(((std::string)" ").append((anydesk_id)));
		auto c_value = std::system(command.c_str());
		if (c_value == 1)
		{
			std::cout << "Caminho ou executavel AnyDesk invalido." << std::endl;
			std::cout << "verifique no arquivo localizado em \"" << (std::string)CONF_F << "\"" << std::endl;
		}
		return c_value;
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
	std::experimental::filesystem::create_directory(ANYDESK_CONN_F);
	bool has_anydesk_exe = false;
	std::fstream fconfig_f;
	fconfig_f.open(CONF_F);
	if (fconfig_f.is_open())
	{
		std::string line;
		auto line_c = 1;
		while (std::getline(fconfig_f, line))
		{
			if (line.rfind("AnydeskExe=", 0) == 0)
			{
				auto f_separator = false;
				std::string exe_v = "";
				for (auto i = 0; i < line.size(); i++)
				{
					if (!f_separator && line[i] == '=')
					{
						f_separator = true;
						continue;
					}
					if (f_separator)
					{
						exe_v += line[i];
					}
				}
				has_anydesk_exe = true;
				anydesk_exe = "\"" + exe_v + "\"";
			}
			else if (line.rfind("IConn=", 0) == 0)
			{

			}
			line_c++;
		}
	}
	fconfig_f.close();
	if (!has_anydesk_exe)
	{
		std::ofstream ofconfig_f;
		ofconfig_f.open(CONF_F);
		if (ofconfig_f.is_open())
		{
			ofconfig_f << "AnydeskExe=" << "Insira a localizacao do executavel do AnyDesk aqui" << std::endl;
		}
		ofconfig_f.close();
		std::cout << "Faltando configuracao do executavel AnyDesk, verifique no arquivo localizado em \"" << (std::string)CONF_F << "\"" << std::endl;
		return 0;
	}
	for (int i = 0; i < argc; ++i)
	{
		char* arg = argv[i];
		for (auto conn : conns)
		{
			if (arg == conn.anydesk_id || arg == conn.name || arg == conn.selection_option)
			{
				return conn.connect();
			}
		}
	}
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
