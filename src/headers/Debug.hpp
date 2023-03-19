#pragma once
#include "BitBoard.hpp"
#include <String>
#include <Algorithm>
namespace Debug{
    void print_bb(bit_board board, int board_center,bool mirrored=true)
    {
        std::string output{},someLine{};
        for(int row = 0; row < 8; ++row)
        {
            for(int col = 0; col < 8;++col)
            {
                if((col + row*8) == board_center)
                {
                    someLine = mirrored ?   someLine + "X " : "X " + someLine;
                }
                else if(((board >> col + row*8))&1ull== 1ull)
                {
                    someLine = mirrored ?   someLine + "1 " : "1 " + someLine ;
                }
                else
                {
                    someLine = mirrored ?   someLine + "0 " : "0 " + someLine;
                }
            }
            someLine += "|" + std::to_string(row + 1) + " \n";
            output = someLine + output;
            someLine = "";
        }                    
        output += "----------------\n";
        output += mirrored ? "A B C D E F G H" : "H G F E D C B A";
        std::cout << output << std::endl;
    }
    void print_bb(bit_board board, bool mirrored=true)
    {
        std::string output{},someLine{};
        for(int row = 0; row < 8; ++row)
        {
            for(int col = 0; col < 8;++col)
            {
                if(((board >> col + row*8))&1ull== 1ull)
                {
                    someLine = mirrored ?   someLine + "1 " : "1 " + someLine ;
                }
                else
                {
                    someLine = mirrored ?   someLine + "0 " : "0 " + someLine;
                }
            }
            someLine += "|" + std::to_string(row + 1) + " \n";
            output = someLine + output;
            someLine = "";
        }                    
        output += "----------------\n";
        output += mirrored ? "A B C D E F G H" : "H G F E D C B A";
        std::cout << output << std::endl;
    }
}