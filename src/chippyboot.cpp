#include <iostream>
#include <cstdint>
#include <string>
#include <chippyboot.hpp>

//bitmap fonts
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9 [space]
//one hex digit wide
const uint8_t rep_digits = 37;


uint8_t bitfont3x3[rep_digits][3] = {
    {0x40, 0xE0, 0xA0},  
    {0xC0, 0xE0, 0xE0}, 
    {0xE0, 0x80, 0xE0},
    {0xC0, 0xA0, 0xC0},
    {0xE0, 0xC0, 0xE0},
    {0xE0, 0xC0, 0x80},
    {0xC0, 0xA0, 0xE0},
    {0xA0, 0xE0, 0xA0},
    {0xE0, 0x40, 0xE0},
    {0x20, 0xA0, 0xE0},
    {0xA0, 0xC0, 0xA0},
    {0x80, 0x80, 0xE0},
    {0xE0, 0xE0, 0xA0},
    {0xE0, 0xA0, 0xA0},
    {0xE0, 0xA0, 0xE0},
    {0xE0, 0xE0, 0x80},
    {0xE0, 0xE0, 0x20},
    {0xE0, 0x80, 0x80},
    {0x60, 0x40, 0xC0},
    {0xE0, 0x40, 0x40},
    {0xA0, 0xA0, 0xE0},
    {0xA0, 0xA0,0x40},
    {0xA0, 0xE0, 0xE0},
    {0xA0, 0x40, 0xA0},
    {0xA0, 0x40, 0x40},
    {0xC0, 0x40, 0x60},
    {0xE0, 0xA0, 0xE0},
    {0xC0, 0x40, 0xE0},
    {0xC0, 0x40, 0x60},
    {0xE0, 0x60, 0xE0},
    {0xA0, 0xE0, 0x20},
    {0x60, 0x40, 0xC0},
    {0x80, 0xE0, 0xE0},
    {0xE0, 0x20, 0x20},
    {0x60, 0xE0, 0xE0},
    {0xE0, 0xE0, 0x20},
    {0x00, 0x00, 0x00}};

uint8_t bitfont4x4[rep_digits][4] = {
    {0x60, 0x90, 0xF0, 0x90},
    {0xE0, 0xF0, 0x90, 0xE0},
    {0x60, 0x90, 0x80, 0x70},
    {0xE0, 0x90, 0x90, 0xE0},
    {0xF0, 0xE0, 0x80, 0xF0},
    {0xF0, 0x80, 0xE0, 0x80},
    {0x70, 0xB0, 0x90, 0x70},
    {0x90, 0xF0, 0x90, 0x90},
    {0xE0, 0x40, 0x40, 0xE0},
    {0x10, 0x10, 0x90, 0x60},
    {0x90, 0xE0, 0xE0, 0x90},
    {0x80, 0x80, 0x80, 0xF0},
    {0xF0, 0xF0, 0x90, 0x90},
    {0x90, 0xD0, 0xB0, 0x90},
    {0x60, 0x90, 0x90, 0x60},
    {0xE0, 0x90, 0xE0, 0x80},
    {0x60, 0x90, 0xA0, 0x50},
    {0xE0, 0x90, 0xE0, 0x90},
    {0x70, 0xE0, 0x10, 0xE0},
    {0xE0, 0x40, 0x40, 0x40},
    {0x90, 0x90, 0x90, 0x60},
    {0x90, 0x90, 0x60, 0x60},
    {0x90, 0x90, 0xF0, 0x90},
    {0x90, 0x60, 0x60, 0x90},
    {0xA0, 0xE0, 0x40, 0x40},
    {0xF0, 0x20, 0x40, 0xF0},
    {0x60, 0xB0, 0xD0, 0x60},
    {0x40, 0x40, 0x40, 0x40},
    {0xC0, 0x20, 0x40, 0xE0},
    {0xC0, 0x60, 0x20, 0xC0},
    {0x90, 0x90, 0xF0, 0x10},
    {0xF0, 0xE0, 0x10, 0xE0},
    {0x80, 0xE0, 0x90, 0x60},
    {0x70, 0x90, 0x10, 0x10},
    {0x60, 0xF0, 0x90, 0x60},
    {0x60, 0x90, 0x70, 0x10},
    {0x00, 0x00, 0x00, 0x00}};

//uint8_t bitfont5x5[36][5] = {};


uint8_t* letterToHex(char letter, uint8_t** bitfont){
    switch(letter){
        case 'A':
            return bitfont[0];
            break;
        case 'a':
            return bitfont[0];
            break;
        case 'B':
            return bitfont[1];
            break;
        case 'b':
            return bitfont[1];
            break;
        case 'C':
            return bitfont[2];
            break;
        case 'c':
            return bitfont[2];
            break;
        case 'D':
            return bitfont[3];
            break;
        case 'd':
            return bitfont[4];
            break;
        case 'E':
            return bitfont[5];
            break;
        case 'e':
            return bitfont[5];
            break;
        case 'F':
            return bitfont[6];
            break;
        case 'f':
            return bitfont[6];
            break;
        case 'G':
            return bitfont[7];
            break;
        case 'g':
            return bitfont[7];
            break;
        case 'H':
            return bitfont[8];
            break;
        case 'h':
            return bitfont[8];
            break;
        case 'I':
            return bitfont[9];
            break;
        case 'i':
            return bitfont[9];
            break;
        case 'J':
            return bitfont[10];
            break;
        case 'j':
            return bitfont[10];
            break;
        case 'K':
            return bitfont[11];
            break;
        case 'k':
            return bitfont[11];
            break;
        case 'L':
            return bitfont[12];
            break;
        case 'l':
            return bitfont[12];
            break;
        case 'M':
            return bitfont[13];
            break;
        case 'm':
            return bitfont[13];
            break;
        case 'N':
            return bitfont[14];
            break;
        case 'n':
            return bitfont[14];
            break;
        case 'O':
            return bitfont[15];
            break;
        case 'o':
            return bitfont[15];
            break;
        case 'P':
            return bitfont[16];
            break;
        case 'p':
            return bitfont[16];
            break;
        case 'Q':
            return bitfont[17];
            break;
        case 'q':
            return bitfont[17];
            break;
        case 'R':
            return bitfont[18];
            break;
        case 'r':
            return bitfont[18];
            break;
        case 'S':
            return bitfont[19];
            break;
        case 's':
            return bitfont[19];
            break;
        case 'T':
            return bitfont[20];
            break;
        case 't':
            return bitfont[20];
            break;
        case 'U':
            return bitfont[21];
            break;
        case 'u':
            return bitfont[21];
            break;
        case 'V':
            return bitfont[22];
            break;
        case 'v':
            return bitfont[22];
            break;
        case 'W':
            return bitfont[23];
            break;
        case 'w':
            return bitfont[23];
            break;
        case 'X':
            return bitfont[24];
            break;
        case 'x':
            return bitfont[24];
            break;
        case 'Y':
            return bitfont[25];
            break;
        case 'y':
            return bitfont[25];
            break;
        case 'Z':
            return bitfont[26];
            break;
        case 'z':
            return bitfont[26];
            break;
        case '0':
            return bitfont[27];
            break;
        case '1':
            return bitfont[28];
            break;
        case '2':
            return bitfont[29];
            break;
        case '3':
            return bitfont[30];
            break;
        case '4':
            return bitfont[31];
            break;
        case '5':
            return bitfont[32];
            break;
        case '6':
            return bitfont[33];
            break;
        case '7':
            return bitfont[34];
            break;
        case '8':
            return bitfont[35];
            break;
        case '9':
            return bitfont[36];
            break;
        case ' ':
            return bitfont[37];
            break;
    }

char* lettersInString(std::string text){
    char* letters_used = {};
    bool letter_used_flag = False;
    for(char letter : text){
        if(strlen(strlenletters_used) == 0){
            letters_used.push_back(letter);
        }
        else{
            for(char used_letter : letters_used){
                if(strcmp(letter, used_letter) == 0){
                    letter_used_flag = True
                }
            }
            if(!letter_used_flag){
                letters_used.push_back(letter);
            }

        }
    }




}

}