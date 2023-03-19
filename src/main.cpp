
#include "Debug.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
int main()
{
    //Debug::print_bb(BitBoard::piece_masks[0][0],0);
    //Debug::print_bb(BitBoard::normal_knight_zone);
    
    for(int i =0; i < 64; ++i){
        Debug::print_bb(BitBoard::knight_move_masks[i],i,false);
    }
    
    //Debug::print_bb(BitBoard::KNIGHT_EIGHTEENTH_POS,18,false);
    //Debug::print_bb(BitBoard::FILE_B);
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