#ifndef DEBUG_HPP
#define DEBUG_HPP
#include "BitBoard.hpp"
#include "Move.hpp"
#include <bitset>
namespace Debug{
    std::string piece_type_to_str(piece_type_t piece){
        switch (piece)
        {
        case 0b00000001:
            return "King";
        case 0b00000010:
            return "Queen";
        case 0b00000011:
            return "Bishop";
        case 0b00000100:
            return "Knight";
        case 0b00000101:
            return "Rook";
        case 0b00000110:
            return "Pawn";
        default:
            return "Error with piece type to string";
        }
    }
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
                else if((((board >> (col + row*8)))&1ull)== 1ull)
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
                if((((board >> (col + row*8)))&1ull) == 1ull)
                {
                    someLine = mirrored ?   someLine + "1 " : "1 " + someLine;
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
    void print_encoded_move_str(move_t move){
        std::string move_str{""};
        move_str += "The start index is: " + std::to_string(move & Moves::START_SQ_MASK) + "\n";
        move_str += "The end index is: " + std::to_string((move & Moves::END_SQ_MASK) >> Moves::END_SQ_SHIFT) + "\n";
        move_str += "THe piece moved was: " + piece_type_to_str((move & Moves::PIECE_TYPE_MASK) >> Moves::PIECE_TYPE_SHIFT) + "\n";
        move_str += (((move & Moves::CAPTURE_MASK) >> Moves::CAPTURED_SHIFT) == 1) ? "The move was a capture" : "The move was not a capture";
        std::cout << move_str;
    }
    void print_encoded_move_bin(move_t move){
        std::cout << std::bitset<32>(move) << std::endl;
    }
}
#endif