#include "Debug.hpp"
#include <iostream>
#include "Move.hpp"
#include <SFML/Graphics.hpp>
#include "MoveGen.hpp"
#include <bitset>
int main()
{
    //Debug::print_bb(BitBoard::piece_masks[0][0],0);
    //Debug::print_bb(BitBoard::normal_knight_zone);
    MoveGen::init();
    std::vector<move_t> pawn_moves = MoveGen::white_pawn_moves(BitBoard::RANK_2,-1);
    for(const auto i : pawn_moves)
    {
        Debug::print_encoded_move_str(i);  
        std::cout << "\n" <<  std::endl;
    }
    //Debug::print_bb(BitBoard::KNIGHT_EIGHTEENTH_POS,18,false);
    //Debug::print_bb(BitBoard::FILE_H);
    //Debug::print_bb(BitBoard::FILE_A);
    /*
    std::cout << "File A\n";
    Debug::print_bb(BitBoard::FILE_A,true);
    std::cout << "1\n";
    Debug::print_bb(bit_board{1},false);
    */
    return 0;
}