#include "Bitboard.hpp"
std::array<std::string,6> FullBoard::split(std::string fen){
    std::array<std::string, 6> str_chunks{};
	size_t pos{};
	for (int i = 0; (pos = fen.find(' ')) != std::string::npos; ++i)
	{
		str_chunks[i] = fen.substr(0, pos); // store the substring   
		fen.erase(0, pos + 1);
	}
	str_chunks[5] = fen[0];
	return str_chunks;
}
bit_board FullBoard::board_cord_to_bit(int board_x, int board_y){
    board_x = std::abs(board_x-9);
    const int index = (((board_x - 1) % 8) + (8*(board_y-1)));
    return static_cast<bit_board>(1ull << index);
}
void FullBoard::init_piece(char type, int board_x, int board_y){
    switch (type)
	{
	case 'k':
		boards.bk |= board_cord_to_bit(board_x,board_y);
		break;
	case 'q':
		boards.bq |= board_cord_to_bit(board_x,board_y);
		break;
	case 'b':
		boards.bb |= board_cord_to_bit(board_x,board_y);
		break;
	case 'n':
		boards.bn |= board_cord_to_bit(board_x,board_y);
		break;
	case 'r':
		boards.br |= board_cord_to_bit(board_x,board_y);
		break;
	case 'p':
		boards.bp |= board_cord_to_bit(board_x,board_y);
		break;
	case 'K':
		boards.wk |= board_cord_to_bit(board_x,board_y);
		break;
	case 'Q':
		boards.wq |= board_cord_to_bit(board_x,board_y);
		break;
	case 'B':
		boards.wb |= board_cord_to_bit(board_x,board_y);
		break;
	case 'N':
		boards.wn |= board_cord_to_bit(board_x,board_y);
		break;
	case 'R':
		boards.wr |= board_cord_to_bit(board_x,board_y);
		break;
	case 'P':
		boards.wp |= board_cord_to_bit(board_x,board_y);
		break;
	default:
		break;
	}
}
void FullBoard::load_from_fen(const std::string& fen){
    const std::array<std::string,6> fen_blocks = split(fen);

	int board_y = 8;
	int board_x = 8;
	for (const auto& i : fen_blocks[0])
	{
		if (isdigit(i))
		{
			board_x -= i - '0';
		}
		else if (i == '/')
		{
			--board_y;
			board_x = 8;
		}
		else
		{
			init_piece(i,board_x,board_y);
			--board_x;
		}
	}
	this->is_whites_turn = fen_blocks[1].at(0) == 'w';
    this->castling[0] = false;
    this->castling[1] = false;
    this->castling[2] = false;
    this->castling[3] = false;
	for (const auto& i : fen_blocks[2])
	{
		switch (i)
		{
		case 'K':
			this->castling[0] = true;
			break;
		case 'k':
			this->castling[2] = true;
			break;
		case 'Q':
			this->castling[1] = true;
			break;
		case 'q':
			this->castling[3] = true;
			break;
		default:
			break;
		}
	}
	if (fen_blocks[3][0] == '-')
	{
		this->en_pesant_target_sq = 255;
	}
	else
	{
		const uint8_t colour_index = (fen_blocks[3][1] == 2) ? 8 : 48;
		switch (fen_blocks[3][0])
		{
		case 'a':
			this->en_pesant_target_sq = colour_index;
			break;
		case 'b':
			this->en_pesant_target_sq = colour_index + 1;
			break;
		case 'c':
			this->en_pesant_target_sq = colour_index + 2;
			break;
		case 'd':
			this->en_pesant_target_sq = colour_index + 3;
			break;
		case 'e':
			this->en_pesant_target_sq = colour_index + 4;
			break;
		case 'f':
			this->en_pesant_target_sq = colour_index + 5;
			break;
		case 'g':
			this->en_pesant_target_sq = colour_index + 6;
			break;
		case 'h':
			this->en_pesant_target_sq = colour_index + 7;
			break;
		default:
			this->en_pesant_target_sq = 255;
		}
	}
	this->num_half_moves = static_cast<uint8_t>(std::stoi(fen_blocks.at(4)));
	this->num_full_moves = static_cast<short>(std::stoi(fen_blocks.at(5)));
}
namespace BitBoard
{
    //bottom right is A1

    //will be used to look up where a bishop can move to from any give inde


} 
