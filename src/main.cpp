#include "Debug.hpp"
#include <iostream>
#include "Move.hpp"
//#include <SFML/Graphics.hpp>
#include "MoveGen.hpp"
#include <bitset>
int main()
{
    //Debug::print_bb(BitBoard::piece_masks[0][0],0);
    //Debug::print_bb(0x6F0000,true);
   // Debug::print_bb(0x6F0000 * 2,true);
    Debug::print_bb(BitBoard::SLIDING_PIECE_MASKS[44][5]& ~(BitBoard::SLIDING_PIECE_MASKS[44][5] & 0x20000),44,true);
    Debug::print_bb(BitBoard::SLIDING_PIECE_MASKS[44][5]& ~(BitBoard::SLIDING_PIECE_MASKS[44][5] & 0x4000000),44,true);
    //Debug::print_bb(BitBoard::SLIDING_PIECE_MASKS[0][0],0,true);
    //Debug::print_bb(BitBoard::pop_lsb(BitBoard::SLIDING_PIECE_MASKS[0][0]),true);
    // MoveGen::init();
    //FullBoard instance;
    //instance.load_from_fen(STARTING_FEN);
    //instance.boards.bp = 0x0F00000000FF0000;
    //MoveGen::update_data(instance.boards);
    //Debug::print_entire_board(instance.boards);
    //std::vector<move_t> pawn_moves = MoveGen::white_pawn_moves(BitBoard::RANK_2,17);
    //Debug::print_all_gen_moves(pawn_moves,false);
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