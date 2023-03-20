#ifndef MOVE_HPP
#define MOVE_HPP
#include <cstdint>

typedef uint32_t piece_type_t; 
/*
move storage: 
from right to left:
6 bits - start index
6 bits - end index
3 bits - piece type 
1 bit  - capture (true = 1/false = 0)
*/
typedef uint32_t move_t;
namespace Moves{
    constexpr piece_type_t KING         = 0b00000001;
    constexpr piece_type_t QUEEN        = 0b00000010;
    constexpr piece_type_t BISHOP       = 0b00000011;
    constexpr piece_type_t KNIGHT       = 0b00000100;
    constexpr piece_type_t ROOK         = 0b00000101;
    constexpr piece_type_t PAWN         = 0b00000110;
    constexpr uint32_t START_SQ_MASK    = 0x0000003F;
    constexpr uint32_t END_SQ_MASK      = 0x00000FC0;
    constexpr uint32_t PIECE_TYPE_MASK  = 0x00007000;
    constexpr uint32_t CAPTURE_MASK     = 0x00008000;
    constexpr uint16_t END_SQ_SHIFT     = 6;
    constexpr uint16_t PIECE_TYPE_SHIFT = 12;
    constexpr uint16_t CAPTURED_SHIFT   = 15;
    [[nodiscard]] constexpr move_t encode_move(const int start_index, const int end_index,const int piece_type,const bool capture)
    {
        move_t move{0};
        move |= start_index & START_SQ_MASK;
        move |= (end_index & START_SQ_MASK) << END_SQ_SHIFT;
        move |= (piece_type << PIECE_TYPE_SHIFT) & PIECE_TYPE_MASK ;
        move |= (capture ? 1ull : 0ull) << CAPTURED_SHIFT;
        return move;
    }
    constexpr void decode_move(const move_t move,int& start_index, int& end_index,int& piece_type,bool& capture){
        start_index = move & START_SQ_MASK;
        end_index =  (move & END_SQ_MASK) >> END_SQ_SHIFT;
        piece_type = (move & PIECE_TYPE_MASK) >> PIECE_TYPE_SHIFT;
        capture = ((move & CAPTURE_MASK) >> CAPTURED_SHIFT) == 1;
    }
}
#endif