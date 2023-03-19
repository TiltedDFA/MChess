#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
typedef unsigned long long bit_board;
namespace BitBoard{

    constexpr bit_board KNIGHT_EIGHTEEN= 0x00003C3C3C3C0000;
    constexpr bit_board FILE_A = 0x0101010101010101;
    constexpr bit_board FILE_B = 0x0202020202020202;
    constexpr bit_board FILE_H = 0x8080808080808080;
    constexpr bit_board RANK_1 = 0x00000000000000FF;
    constexpr bit_board RANK_8 = 0xFF00000000000000;
    constexpr bit_board KNIGHT_EIGHTEENTH_POS=0b00000000000000000000101000010001000000000001000100001010;
    inline constexpr std::array<bit_board, 64> compute_knight_moves()
    {
        std::array<bit_board,64> returnVal{};
        for(int i =0; i < 64; ++i){
            const int dif = i - 18;
            if(dif > -1){
                returnVal[i] = KNIGHT_EIGHTEENTH_POS << dif;
            }
            else{
                returnVal[i] = KNIGHT_EIGHTEENTH_POS >> std::abs(dif);
            }
        }
        return returnVal;
    }
    inline constexpr std::array<std::array<bit_board,8>,64> compute_sliding_masks(){
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
            for(int r = row + 1, c = col - 1; r < 8 && c >= 0;++r,--c){
                north_east |= 1ull << ((r * 8) + c);
            }
            for(int r = row - 1, c = col - 1; r >= 0 && c >= 0;--r,--c){
                south_east |= 1ull << ((r * 8) + c);
            }
            for(int r = row - 1, c = col + 1; r >= 0 && c < 8;--r,++c){
                south_east |= 1ull << ((r * 8) + c);
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
    
    constexpr std::array<std::array<bit_board,8>,64> piece_masks = compute_sliding_masks();
    constexpr std::array<bit_board,64> knight_move_masks = compute_knight_moves();
}