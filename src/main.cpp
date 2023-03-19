
#include "Debug.hpp"
#include <iostream>
#include "Move.hpp"
#include <SFML/Graphics.hpp>
int main()
{
    //Debug::print_bb(BitBoard::piece_masks[0][0],0);
    //Debug::print_bb(BitBoard::normal_knight_zone);
    
    for(int i =0; i < 64; ++i)
    {
        Debug::print_bb(BitBoard::KING_MOVE_MASKS[i],i,false);
    }
    std::cout << Moves::encode_move(5,13,1,0) << std::endl;
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

/*
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
*/