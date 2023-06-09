#include "MoveGen.hpp"
namespace MoveGen
{
    bit_board BLACK_PIECES = 0;
    bit_board WHITE_PIECES = 0;
    bit_board EMPTY = 0;
    void init(){
        BLACK_PIECES = 0;
        WHITE_PIECES = 0;
        EMPTY = ~(BLACK_PIECES | WHITE_PIECES);
    }
    void update_data(const CBoard& cb){
        BLACK_PIECES = cb.bk | cb.bq | cb.bb | cb.bn | cb.br | cb.bp;
        WHITE_PIECES = cb.wk | cb.wq | cb.wb | cb.wn | cb.wr | cb.wp;
        EMPTY = ~(WHITE_PIECES | BLACK_PIECES);
    }
    std::vector<move_t> white_pawn_moves(bit_board pawns,int en_pesant_target_sq)
    {
        std::vector<move_t> possible_moves{};
        bit_board pawn_move{0};

        //generating 1 sq forward moves
        pawn_move = (pawns << 8) & EMPTY; 
        for(int index = __builtin_ctzll(pawns);index< 64;++index)
        {
            if (((pawn_move >> index) & 1) == 1)
            {
                possible_moves.push_back(Moves::encode_move((index-8),index,Moves::PAWN,0));
            }
        }
        //generating 2 sq forawrd moves
        pawn_move = (pawns << 16) & EMPTY & (EMPTY << 8) & BitBoard::RANK_4; 
        for(int index = __builtin_ctzll(pawns);index< 64;++index)
        {
            if (((pawn_move >> index) & 1) == 1)
            {
                possible_moves.push_back(Moves::encode_move((index-16),index,Moves::PAWN,0));
            }
        }
        //generating all right capturing moves
        pawn_move = (pawns << 7) & BLACK_PIECES & ~BitBoard::FILE_H;
        for(int index = __builtin_ctzll(pawns);index< 64;++index)
        {
            if (((pawn_move >> index) & 1) == 1)
            {
                possible_moves.push_back(Moves::encode_move((index-7),index,Moves::PAWN,1));
            }
        }
        //generating all the left capturing moves
        pawn_move = (pawns << 9) & BLACK_PIECES & ~BitBoard::FILE_A;
        for(int index = __builtin_ctzll(pawns);index< 64;++index)
        {
            if (((pawn_move >> index) & 1) == 1)
            {
                possible_moves.push_back(Moves::encode_move((index-9),index,Moves::PAWN,1));
            }
        }
        //generating the en_pesant_move
        if(en_pesant_target_sq == -1)
            return possible_moves;
        pawn_move = ((pawns << 9) & ~BitBoard::FILE_A);
        pawn_move &= 1ull << en_pesant_target_sq;
        if(pawn_move != 0)
        {
            const int en_pesant_index = __builtin_ctzll(pawn_move);
            possible_moves.push_back(Moves::encode_move(en_pesant_index-9,en_pesant_index,Moves::PAWN,1));
            return possible_moves;
        }
        pawn_move = ((pawns << 7) & ~BitBoard::FILE_H);
        pawn_move &= 1ull << en_pesant_target_sq;
        if(pawn_move != 0)
        {
            const int en_pesant_index = __builtin_ctzll(pawn_move);
            possible_moves.push_back(Moves::encode_move(en_pesant_index-7,en_pesant_index,Moves::PAWN,1));
        }
        return possible_moves;
    }

    std::vector<move_t> black_pawn_moves(bit_board pawns,int en_pesant_target_sq)
    {
        std::vector<move_t> possible_moves{};
        bit_board pawn_move{0};

        //generating 1 sq forward moves
        pawn_move = (pawns >> 8) & EMPTY; 
        for(int index = __builtin_ctzll(pawns);index< 64;++index)
        {
            if (((pawn_move >> index) & 1) == 1)
            {
                possible_moves.push_back(Moves::encode_move((index-8),index,Moves::PAWN,0));
            }
        }
        //generating 2 sq forawrd moves
        pawn_move = (pawns >> 16) & EMPTY & (EMPTY >> 8) & BitBoard::RANK_5; 
        for(int index = __builtin_ctzll(pawns);index< 64;++index)
        {
            if (((pawn_move >> index) & 1) == 1)
            {
                possible_moves.push_back(Moves::encode_move((index-16),index,Moves::PAWN,0));
            }
        }
        //generating all right capturing moves
        pawn_move = (pawns >> 7) & WHITE_PIECES & ~BitBoard::FILE_A;
        for(int index = __builtin_ctzll(pawns);index< 64;++index)
        {
            if (((pawn_move >> index) & 1) == 1)
            {
                possible_moves.push_back(Moves::encode_move((index-7),index,Moves::PAWN,1));
            }
        }
        //generating all the left capturing moves
        pawn_move = (pawns >> 9) & WHITE_PIECES & ~BitBoard::FILE_H;
        for(int index = __builtin_ctzll(pawns);index< 64;++index)
        {
            if (((pawn_move >> index) & 1) == 1)
            {
                possible_moves.push_back(Moves::encode_move((index-9),index,Moves::PAWN,1));
            }
        }
        //generating the en_pesant_move
        if(en_pesant_target_sq == -1)
            return possible_moves;
        pawn_move = ((pawns >> 9) & ~BitBoard::FILE_H);
        pawn_move &= 1ull << en_pesant_target_sq;
        if(pawn_move != 0)
        {
            const int en_pesant_index = __builtin_ctzll(pawn_move);
            possible_moves.push_back(Moves::encode_move(en_pesant_index-9,en_pesant_index,Moves::PAWN,1));
            return possible_moves;
        }
        pawn_move = ((pawns >> 7) & ~BitBoard::FILE_A);
        pawn_move &= 1ull << en_pesant_target_sq;
        if(pawn_move != 0)
        {
            const int en_pesant_index = __builtin_ctzll(pawn_move);
            possible_moves.push_back(Moves::encode_move(en_pesant_index-7,en_pesant_index,Moves::PAWN,1));
        }
        return possible_moves;
    }
    
    
    std::vector<move_t> bishop_moves(bit_board bishops, bool is_white){
        return std::vector<move_t>{};
        for(int i = __builtin_ctzll(bishops);i < 64;++i){
            if(!(((bishops >> i) & 1) == 1))
                continue;
            for(int j = 0; j < 4;++j){
                if(BitBoard::SLIDING_PIECE_MASKS[i][j] == 0) continue;
                //generates a mask with possible moves removing any occupied
                //with the same colour
                const bit_board moves = 
                    BitBoard::SLIDING_PIECE_MASKS[i][j]&
                    ~(BitBoard::SLIDING_PIECE_MASKS[i][j]&
                    (is_white ? WHITE_PIECES : BLACK_PIECES));
                

            }
        }
    }
 
}