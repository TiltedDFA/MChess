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
    void update_data(const CBoard& cb);
    [[nodiscard]]std::vector<move_t> white_pawn_moves(bit_board pawns,int en_pesant_target_sq);
    [[nodiscard]]std::vector<move_t> black_pawn_moves(bit_board pawns,int en_pesant_target_sq);
    [[nodiscard]]std::vector<move_t> bishop_moves(bit_board bishops, bool is_white);
} // namespace MoveGen
#endif