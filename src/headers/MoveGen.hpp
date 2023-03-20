#ifndef MOVEGEN_HPP
#define MOVEGEN_HPP
#include "Move.hpp"
#include "BitBoard.hpp"
#include <cstdint>
#include <vector>
namespace MoveGen
{ 
    extern bit_board BLACK_PIECES;
    extern bit_board WHITE_PIECES;
    extern bit_board EMPTY;
    void init();
    std::vector<move_t> white_pawn_moves(bit_board pawns,int en_pesant_target_sq);
    
} // namespace MoveGen
#endif