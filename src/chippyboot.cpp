#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include <chippyboot.hpp>

//bitmap fonts
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9 [space]
//one hex digit wide

uint16_t ChippyBoot::rom_start = 0x200;

std::vector<std::vector<uint8_t>> ChippyBoot::bitfont3x3 {
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
std::vector<std::vector<uint8_t>> ChippyBoot::bitfont4x4 {
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


std::vector<uint8_t> ChippyBoot::letterToHex(char letter, std::vector<std::vector<uint8_t>> bitfont){
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
}
std::string ChippyBoot::lettersInString(std::string text){
    std::string letters_used;
    bool letter_used_flag = false;
    for(char letter_reg : text){
        char letter = toupper(letter_reg);
        if(letters_used.length() == 0){
            letters_used.push_back(letter);
        }
        else{
            for(char used_letter : letters_used){
                if(letter == used_letter){
                    letter_used_flag = true;
                }
            }
            if(!letter_used_flag){
                letters_used.push_back(letter);
            }

        }
    }
    return letters_used;
}

ChippyBoot::screentext ChippyBoot::createScreentext(std::string text, int size, std::string location){
    ChippyBoot::screentext new_screentext;
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
    new_screentext.text = text;
    new_screentext.size = size;
    new_screentext.location = location;
    return new_screentext;

}

uint8_t ChippyBoot::xGet(screentext* text){
    uint8_t xloc;
    if((text->location == "top_left") || (text->location == "bottom_left")){
        //shifts x coordinate to print multiple letters with a 1 pixel gap
        xloc = 0x01 + (text->letter_index * text->size) + 1;
    }else if((text->location == "top_right") || (text->location == "bottom_right")){
        xloc = 0x28 + (text->letter_index * text->size) + 1;
    } else{
        xloc = 0x18 + (text->letter_index * text->size) + 1;
    }
    return xloc;
}


uint8_t ChippyBoot::yGet(screentext* text){
    uint8_t yloc;
    if((text->location == "top_left") || (text->location == "top_right")){
        yloc = 0x01;
    }else if((text->location == "bottom_left") || (text->location == "bottom_right") || (text->location == "bottom_middle")){
        yloc = 0x1E;
    } else if(text->location == "middle"){
        yloc = 0x0E;
    }else{
        yloc = 0x14;
    }
    return yloc;
}

void ChippyBoot::incrementLetterIndex(screentext* text){
    text->letter_index++;
}

uint8_t ChippyBoot::getFirstDrawingByte(uint16_t drawing_location){
    //Adds the 1 to specify a jump command
    return((drawing_location | 0x1000) >> 8);
}

uint8_t ChippyBoot::getSecondDrawingByte(uint16_t drawing_location){
    return(drawing_location & 0x00FF);
}

std::vector<std::vector<uint8_t>> ChippyBoot::sizeToBitmap(int size){
    switch(size){
        case 3:
            return bitfont3x3;
            break;
        case 4:
            return bitfont4x4;
            break;
    }
}

ChippyBoot::letterloc ChippyBoot::createLetterloc(char letter_input, uint16_t location){
    letterloc new_letterloc;
    char letter = toupper(letter_input);
    new_letterloc.letter = letter;
    new_letterloc.location = location;
    return new_letterloc;
}

uint16_t ChippyBoot::getLetterAddress(screentext* text, std::vector<letterloc> letterloc_array){
    uint16_t return_address;
    //Goes through each item in letterloc array
    for(int i = 0; i < letterloc_array.size(); i++){
        //If the letter specified by the index equals the letter in letterloc, set return address to the letter's program counter
        if((text->text[text->letter_index]) == letterloc_array[i].letter){
            return_address = letterloc_array[i].location;
        }
    }
    incrementLetterIndex(text);
    return return_address;
}

void ChippyBoot::defineRomLocation(uint16_t location){
    rom_start = location;
}

uint8_t* ChippyBoot::createBootupText(screentext* texts, uint8_t delay){
    //initialize vars
    uint8_t bootup_memory[4096];
    uint16_t PC = 0;
    int size = sizeof(texts) / sizeof(texts[0]);
    std::vector<letterloc> letterloc_array;
    //initialize jump point as first instruction
    bootup_memory[PC++] = getFirstDrawingByte(drawing_location);
    bootup_memory[PC++] = getSecondDrawingByte(drawing_location);
    //Put characters in memory
    for(int i = 0; i < size; i++){
        //contains all letters to be put in memory
        std::string letters = lettersInString(texts[i].text);
        for(char letter : letters){
            letterloc_array.push_back(createLetterloc(letter,PC));
            //Gets the letter's corresponding hex characters
            std::vector<uint8_t> letter_hex_array = letterToHex(letter, sizeToBitmap(texts[i].size));
            //writes every byte to the memory
            for(uint8_t row : letter_hex_array){
                bootup_memory[PC++] = row;
            }
        }
    }
    //Writes drawing code 
    PC = drawing_location;
    for(int i = 0; i < size; i++){
        //Iterate through all letters in a string
        while(texts[i].letter_index < texts[i].text.size()){
            //writes coordinates
            bootup_memory[PC++] = 0x60;
            bootup_memory[PC++] = xGet(&texts[i]);
            bootup_memory[PC++] = 0x61;
            bootup_memory[PC++] = yGet(&texts[i]);
            //writes I register setting
            uint16_t char_address = getLetterAddress(&texts[i], letterloc_array); 
            bootup_memory[PC++] = ((0xA000 | char_address) >> 8);
            bootup_memory[PC++] = (char_address & 0x00FF);
            //writes Draw command
            bootup_memory[PC++] = 0xD0;
            bootup_memory[PC++] = 0x10 + texts[i].size;
            



        }
    }
    //Writes delay code
    bootup_memory[PC++] = 0x65;
    bootup_memory[PC++] = delay;
    //Set delay timer to whats in register 5
    bootup_memory[PC++] = 0xF5;
    bootup_memory[PC++] = 0x15;
    //Set register 5 to be whats the delay_register
    uint16_t jump_point = PC;
    bootup_memory[PC++] = 0xF5;
    bootup_memory[PC++] = 0x07;
    // Skip next instruction if delay timer runs out
    bootup_memory[PC++] = 0x35;
    bootup_memory[PC++] = 0x00;
    //Defines jump point when delay isn't done
    bootup_memory[PC++] = ((0x1000 | jump_point) >> 8);
    bootup_memory[PC++] = (jump_point & 0x00FF);
    //Clear register 5
    bootup_memory[PC++] = 0x65;
    bootup_memory[PC++] = 0x00;
    //Clear screen
    bootup_memory[PC++] = 0x00;
    bootup_memory[PC++] = 0xE0;
    //Go to actual program
    bootup_memory[PC++] = ((0x1000 | rom_start) >> 8);
    bootup_memory[PC++] = (rom_start & 0x00FF);

    return bootup_memory;
}

