#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <iostream>
#include <array>
#include <cmath>
#include <cstdint>
typedef uint64_t bit_board;
struct CBoard{
    constexpr CBoard():
        wk(0),wq(0),wb(0),wn(0),wr(0),wp(0),
        bk(0),bq(0),bb(0),bn(0),br(0),bp(0)
    {};
    
    bit_board wk;
    bit_board wq;
    bit_board wb;
    bit_board wn;
    bit_board wr;
    bit_board wp;
    bit_board bk;
    bit_board bq;
    bit_board bb;
    bit_board bn;
    bit_board br;
    bit_board bp;
};
struct FullBoard
{
    constexpr FullBoard():
        boards(),castling(true,true,true,true),en_pesant_target_sq(-1),
        is_whites_turn(true),num_half_moves(0),num_full_moves(0)
    {};
    std::array<std::string,6> split(std::string fen);
    void load_from_fen(const std::string& fen);
    void init_piece(char type, int board_x, int board_y);
    static bit_board board_cord_to_bit(int board_x, int board_y);

    CBoard boards;
    //wk, wq, bk, bq
    bool castling[4];
    int en_pesant_target_sq;
    bool is_whites_turn;
    int num_half_moves;
    int num_full_moves;
};
namespace BitBoard{
    constexpr bit_board FILE_A = 0x0101010101010101;
    constexpr bit_board FILE_B = 0x0202020202020202;
    constexpr bit_board FILE_F = 0x2020202020202020;
    constexpr bit_board FILE_G = 0x4040404040404040;
    constexpr bit_board FILE_H = 0x8080808080808080;

    constexpr bit_board RANK_1 = 0x00000000000000FF;
    constexpr bit_board RANK_2 = 0x000000000000FF00;
    constexpr bit_board RANK_3 = 0x0000000000FF0000;
    constexpr bit_board RANK_4 = 0x00000000FF000000;
    constexpr bit_board RANK_5 = 0x000000FF00000000;
    constexpr bit_board RANK_8 = 0xFF00000000000000;

    constexpr std::array<int,8> MOVE_DIRECTIONS = {8,1,-8,-1,9,-7,-9,7};//n,e,s,w,ne,se,sw,nw
    constexpr bit_board KNIGHT_EIGHTEENTH_POS=0b00000000000000000000101000010001000000000001000100001010;
    constexpr std::array<bit_board, 64> compute_knight_moves()
    {
        std::array<bit_board,64> returnVal{};
        for(int i =0; i < 64; ++i){
            const int dif = i - 18;
            bit_board mask{0};
            if(dif > -1)
            {
                mask = KNIGHT_EIGHTEENTH_POS << dif;
            }
            else
            {
                mask = KNIGHT_EIGHTEENTH_POS >> std::abs(dif);
            }
            if(((1ull << i) | FILE_B) == FILE_B)
            {
                mask = (~FILE_H) & mask;
            }
            else if (((1ull << i) | FILE_A) == FILE_A)
            {
                mask = ~(FILE_H | FILE_G) & mask;
            }
            else if(((1ull << i) | FILE_G) == FIL   E_G)
            {
                mask = (~FILE_A) & mask;
            }
            else if (((1ull << i) | FILE_H) == FILE_H)
            {
                mask = (~(FILE_A | FILE_B)) & mask;
            }
           returnVal[i] = mask;
        }
        return returnVal;
    }
    constexpr std::array<std::array<bit_board,8>,64> compute_sliding_masks(){
        std::array<std::array<bit_board,8>,64> temp_arry{};
        for(int sq = 0; sq < 64;++sq){
            bit_board north{0};
            bit_board east{0};
            bit_board south{0};
            bit_board west{0};
            bit_board north_east{0};
            bit_board south_east{0};
            bit_board south_west{0};
            bit_board north_west{0};
            int row = static_cast<int>(__builtin_floor(sq/8)), col = sq % 8;
            for(int r = row+1; r < 8;++r){
                north |= 1ull << (8*r + col);
            }
            for(int c = col+1; c < 8;++c){
                east |= 1ull << (c + row*8);
            }
            for(int r = row-1; r >= 0;--r){
                south |= 1ull << (8*r+ col);
            }
            for(int c = col-1; c >= 0;--c){
                west |= 1ull << (c + row*8);
            }
            for(int r = row + 1, c = col - 1; r < 8 && c > 0;++r,--c){
                north_east |= 1ull << ((r * 8) + c);
            }
            for(int r = row - 1, c = col - 1; r > -1 && c > -1;--r,--c){
                south_east |= 1ull << ((r * 8) + c);
            }
            for(int r = row - 1, c = col + 1; r >= 0 && c < 8;--r,++c){
                south_west |= 1ull << ((r * 8) + c);
            }
            for(int r = row + 1, c = col + 1; r < 8 && c <8;++r,++c){
                north_west |= 1ull << ((r * 8) + c);
            }
            temp_arry[sq] = {
                north,
                east,
                south,
                west,
                north_east,
                south_east,
                south_west,
                north_west
            };
        }
        return temp_arry;
    }
    [[nodiscard]]inline constexpr bool in_board(int index){
        return index < 64 && index > 0;
    }
    constexpr std::array<bit_board, 64> compute_king_moves(){
        std::array<bit_board,64> returnVal{};
        for(int i = 0; i < 64;++i)
        {
            bit_board mask{0};
            for(const int direction : MOVE_DIRECTIONS)
            {
                if(in_board(i+direction))
                    mask |= 1ull << (i+direction);
                }
                if(((1ull << i) | FILE_H) == FILE_H)
                mask &= ~FILE_A;
            else if(((1ull << i) | FILE_A) == FILE_A)
                mask &= ~FILE_H;
            returnVal[i] = mask;
        }
        return returnVal;
    }
    constexpr std::array<std::array<bit_board,8>,64> SLIDING_PIECE_MASKS = compute_sliding_masks();
    constexpr std::array<bit_board,64> KNIGHT_MOVE_MASKS = compute_knight_moves();
    constexpr std::array<bit_board,64> KING_MOVE_MASKS = compute_king_moves();
}
#endif