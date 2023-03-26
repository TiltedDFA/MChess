::set COMPILER_FLAGS=-m64 -O3 -std=c++20
::set SFML_INCLUDE_DIR=./../dep/SFML/include
::set SFML_LIB_DIR=./../dep/SFML/lib
::cd ./build/
::g++ -c -I%SFML_INCLUDE_DIR% ./../src/*.cpp %COMPILER_FLAGS%
::cd ./../bin
::g++ -o MChess ./../build/*.o -L./../dep/SFML/lib/ -l:D:/coding/MChess/dep/SFML/lib/libsfml-graphics-s
::ld -o MChess ./../build/*.o D:/coding/MChess/dep/SFML/lib/libsfml-graphics-s.a D:/coding/MChess/dep/SFML/lib/libsfml-graphics-s.a
::start MChess.exe
cd ./build/
cls
ninja
.\Mchess.exe