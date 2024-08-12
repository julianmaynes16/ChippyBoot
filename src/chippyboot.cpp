#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <filesystem>
#include <chippyboot.hpp>

//bitmap fonts
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9 [space]
//one hex digit wide

uint16_t ChippyBoot::rom_start = 0x200;
uint16_t ChippyBoot::memory_start = 0x0A0;

std::vector<std::vector<uint8_t>> ChippyBoot::bitfont3x3 {
        {0x40, 0xE0, 0xA0},  //a
        {0xC0, 0xE0, 0xE0},  //b
        {0xE0, 0x80, 0xE0},  //c
        {0xC0, 0xA0, 0xC0},  //d
        {0xE0, 0xC0, 0xE0},  //e
        {0xE0, 0xC0, 0x80},  //f
        {0xC0, 0xA0, 0xE0},  //g
        {0xA0, 0xE0, 0xA0},  //h
        {0xE0, 0x40, 0xE0},  //i
        {0x20, 0xA0, 0xE0},  //j
        {0xA0, 0xC0, 0xA0},  //k
        {0x80, 0x80, 0xE0},  //l
        {0xE0, 0xE0, 0xA0},  //m
        {0xE0, 0xA0, 0xA0},  //n
        {0xE0, 0xA0, 0xE0},  //o
        {0xE0, 0xE0, 0x80},  //p
        {0xE0, 0xE0, 0x20},  //q
        {0xE0, 0x80, 0x80},  //r
        {0x60, 0x40, 0xC0},  //s
        {0xE0, 0x40, 0x40},  //t
        {0xA0, 0xA0, 0xE0},  //u
        {0xA0, 0xA0, 0x40},  //v
        {0xA0, 0xE0, 0xE0},  //w
        {0xA0, 0x40, 0xA0},  //x
        {0xA0, 0x40, 0x40},  //y
        {0xC0, 0x40, 0x60},  //z
        {0xE0, 0xA0, 0xE0},  //0
        {0xC0, 0x40, 0xE0},  //1
        {0xC0, 0x40, 0x60},  //2
        {0xE0, 0x60, 0xE0},  //3
        {0xA0, 0xE0, 0x20},  //4
        {0x60, 0x40, 0xC0},  //5
        {0x80, 0xE0, 0xE0},  //6
        {0xE0, 0x20, 0x20},  //7
        {0x60, 0xE0, 0xE0},  //8
        {0xE0, 0xE0, 0x20},  //9
        {0x00, 0x00, 0x00}}; //space
std::vector<std::vector<uint8_t>> ChippyBoot::bitfont4x4 {
        {0x60, 0x90, 0xF0, 0x90}, //a
        {0xE0, 0xF0, 0x90, 0xE0}, //b
        {0x60, 0x90, 0x80, 0x70}, //c
        {0xE0, 0x90, 0x90, 0xE0}, //d
        {0xF0, 0xE0, 0x80, 0xF0}, //e
        {0xF0, 0x80, 0xE0, 0x80}, //f
        {0x70, 0xB0, 0x90, 0x70}, //g
        {0x90, 0xF0, 0x90, 0x90}, //h
        {0xE0, 0x40, 0x40, 0xE0}, //i
        {0x10, 0x10, 0x90, 0x60}, //j
        {0x90, 0xE0, 0xE0, 0x90}, //k
        {0x80, 0x80, 0x80, 0xF0}, //l
        {0xF0, 0xF0, 0x90, 0x90}, //m
        {0x90, 0xD0, 0xB0, 0x90}, //n
        {0x60, 0x90, 0x90, 0x60}, //o
        {0xE0, 0x90, 0xE0, 0x80}, //p
        {0x60, 0x90, 0xA0, 0x50}, //q
        {0xE0, 0x90, 0xE0, 0x90}, //r
        {0x70, 0xE0, 0x10, 0xE0}, //s
        {0xE0, 0x40, 0x40, 0x40}, //t
        {0x90, 0x90, 0x90, 0x60}, //u
        {0x90, 0x90, 0x60, 0x60}, //v
        {0x90, 0x90, 0xF0, 0x90}, //w
        {0x90, 0x60, 0x60, 0x90}, //x
        {0xA0, 0xE0, 0x40, 0x40}, //y
        {0xF0, 0x20, 0x40, 0xF0}, //z
        {0x60, 0xB0, 0xD0, 0x60}, //0
        {0x40, 0x40, 0x40, 0x40}, //1
        {0xC0, 0x20, 0x40, 0xE0}, //2
        {0xC0, 0x60, 0x20, 0xC0}, //3
        {0x90, 0x90, 0xF0, 0x10}, //4
        {0xF0, 0xE0, 0x10, 0xE0}, //5
        {0x80, 0xE0, 0x90, 0x60}, //6
        {0x70, 0x90, 0x10, 0x10}, //7
        {0x60, 0xF0, 0x90, 0x60}, //8
        {0x60, 0x90, 0x70, 0x10}, //9
        {0x00, 0x00, 0x00, 0x00}}; //space


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
            return bitfont[3];
            break;
        case 'E':
            return bitfont[4];
            break;
        case 'e':
            return bitfont[4];
            break;
        case 'F':
            return bitfont[5];
            break;
        case 'f':
            return bitfont[5];
            break;
        case 'G':
            return bitfont[6];
            break;
        case 'g':
            return bitfont[6];
            break;
        case 'H':
            return bitfont[7];
            break;
        case 'h':
            return bitfont[7];
            break;
        case 'I':
            return bitfont[8];
            break;
        case 'i':
            return bitfont[8];
            break;
        case 'J':
            return bitfont[9];
            break;
        case 'j':
            return bitfont[9];
            break;
        case 'K':
            return bitfont[10];
            break;
        case 'k':
            return bitfont[10];
            break;
        case 'L':
            return bitfont[11];
            break;
        case 'l':
            return bitfont[11];
            break;
        case 'M':
            return bitfont[12];
            break;
        case 'm':
            return bitfont[12];
            break;
        case 'N':
            return bitfont[13];
            break;
        case 'n':
            return bitfont[13];
            break;
        case 'O':
            return bitfont[14];
            break;
        case 'o':
            return bitfont[14];
            break;
        case 'P':
            return bitfont[15];
            break;
        case 'p':
            return bitfont[15];
            break;
        case 'Q':
            return bitfont[16];
            break;
        case 'q':
            return bitfont[16];
            break;
        case 'R':
            return bitfont[17];
            break;
        case 'r':
            return bitfont[17];
            break;
        case 'S':
            return bitfont[18];
            break;
        case 's':
            return bitfont[18];
            break;
        case 'T':
            return bitfont[19];
            break;
        case 't':
            return bitfont[19];
            break;
        case 'U':
            return bitfont[20];
            break;
        case 'u':
            return bitfont[20];
            break;
        case 'V':
            return bitfont[21];
            break;
        case 'v':
            return bitfont[21];
            break;
        case 'W':
            return bitfont[22];
            break;
        case 'w':
            return bitfont[22];
            break;
        case 'X':
            return bitfont[23];
            break;
        case 'x':
            return bitfont[23];
            break;
        case 'Y':
            return bitfont[24];
            break;
        case 'y':
            return bitfont[24];
            break;
        case 'Z':
            return bitfont[25];
            break;
        case 'z':
            return bitfont[25];
            break;
        case '0':
            return bitfont[26];
            break;
        case '1':
            return bitfont[27];
            break;
        case '2':
            return bitfont[28];
            break;
        case '3':
            return bitfont[29];
            break;
        case '4':
            return bitfont[30];
            break;
        case '5':
            return bitfont[31];
            break;
        case '6':
            return bitfont[32];
            break;
        case '7':
            return bitfont[33];
            break;
        case '8':
            return bitfont[34];
            break;
        case '9':
            return bitfont[35];
            break;
        case ' ':
            return bitfont[36];
            break;
    }
}
std::string ChippyBoot::lettersInString(std::string text){
    std::string letters_used;
    
    //For every letter in the given text
    for(char letter_reg : text){
        bool letter_used_flag = false;
        //make letter uppercase
        char letter = toupper(letter_reg);
        //First letter
        if(letters_used.length() == 0){
            letters_used.push_back(letter);
        }
        //Letters after 1st one
        else{
            //Check every letters that have currently been used
            for(char used_letter : letters_used){
                //If letter has been used
                if(letter == used_letter){
                    letter_used_flag = true;
                }
            }
            //If letter hasn't been used, add it to letters used
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
        xloc = 0x01 + (text->letter_index * text->size) + (1 + text->letter_index);
    }else if((text->location == "top_right") || (text->location == "bottom_right")){
        xloc = 0x28 + (text->letter_index * text->size) + (1 + text->letter_index);
    } else{
        if((text->size % 2) == 0){ // even font size 
            xloc = std::round((-2.547 * text->text.length()) + 32.6) + (text->letter_index * text->size) + (1 + text->letter_index);
        }else{ // odd font size
            xloc = (32 - std::ceil(text->size / 3) - ((text->text.length() - 1) * (std::ceil(text->size / 3) + 1)) + (text->letter_index * text->size) + (1 + text->letter_index));
        }
    }
    return xloc;
}


uint8_t ChippyBoot::yGet(screentext* text){
    uint8_t yloc;
    if((text->location == "top_left") || (text->location == "top_right")){
        yloc = 0x01;
    }else if((text->location == "bottom_left") || (text->location == "bottom_right") || (text->location == "bottom_middle")){
        yloc = 0x1C;
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

 /**
  * @brief Uses letter, size, and location data to make an object
  * @param letter_input letter to be used
  * @param location location in memory the letter will be
  * @param size the size of the letter
  */
ChippyBoot::letterloc ChippyBoot::createLetterloc(char letter_input, uint16_t location, int size){
    letterloc new_letterloc;
    char letter = toupper(letter_input);
    //unique letter
    new_letterloc.letter = letter;
    //location in memory
    new_letterloc.location = location;
    //size of letter
    new_letterloc.size = size;
    return new_letterloc;
}

uint16_t ChippyBoot::getLetterAddress(screentext* text, std::vector<letterloc> letterloc_array){
    uint16_t return_address;
    //Goes through each item in letterloc array
    for(int i = 0; i < letterloc_array.size(); i++){
        //If the letter specified by the index equals the letter in letterloc, set return address to the letter's program counter
        if(((text->text[text->letter_index]) == letterloc_array[i].letter) && (text->size == letterloc_array[i].size)){
            return_address = letterloc_array[i].location + memory_start;
        }
    }
    //increments the letter index to allow the next letter to be printed
    incrementLetterIndex(text);
    return return_address;
}

void ChippyBoot::defineRomLocation(uint16_t location){
    rom_start = location;
}

ChippyBoot::charsizes ChippyBoot::createCharsizes(std::string text, int size){
    charsizes new_charsize;
    new_charsize.text = text;

    for(char letter : text){
        new_charsize.letter_size_array.push_back(size);
    }

    return new_charsize;
}

void ChippyBoot::addToCharsizes(charsizes* input_charsizes, std::string input_text, int input_size){
    //Adds new text onto the old
    input_charsizes->text += input_text;
    //Adds new numbers in the old vector
    for(char letter : input_text){
        input_charsizes->letter_size_array.push_back(input_size);
    }

}

void ChippyBoot::removeCharsizeRedundancies(charsizes* input_charsizes){
    std::string new_string = "";
    std::vector<int> new_letter_size_array;
    
    for(int i = 0; i < input_charsizes->text.size(); i++){
        bool unique_num_size = true;
        
        for(int j = 0; j < input_charsizes->text.size(); j++){
            if(j > i){
                if((input_charsizes->text[i] == input_charsizes->text[j]) && (input_charsizes->letter_size_array[i] == input_charsizes->letter_size_array[j]) && (i != j)){
                    unique_num_size = false;
                }
            }
        }
        if(unique_num_size){
            new_string += input_charsizes->text[i];
            new_letter_size_array.push_back(input_charsizes->letter_size_array[i]);
        }
    }

    input_charsizes->text = new_string;
    input_charsizes->letter_size_array = new_letter_size_array;
}

//void ChippyBoot::incrementCharsizeIndex(charsizes* charsizes){
 //   charsizes->index++;
//}

std::vector<uint8_t> ChippyBoot::createBootupText(std::vector<screentext> texts, uint8_t delay){
    //initialize vars
    std::vector<uint8_t> bootup_memory;
    uint16_t PC = 0;
    std::vector<letterloc> letterloc_array;
    charsizes charsizes;
    //initialize jump point at default point
    bootup_memory.insert(bootup_memory.begin() + PC++, getFirstDrawingByte(drawing_location));
    bootup_memory.insert(bootup_memory.begin() + PC++, getSecondDrawingByte(drawing_location));

    
    //Put characters in memory
    for(int i = 0; i < texts.size(); i++){
        //contains all letters to be put in memory
        //all_letters += texts[i].text;
        
        if(i == 0){
            charsizes = createCharsizes(lettersInString(texts[i].text), texts[i].size);
        } else {
            addToCharsizes(&charsizes, lettersInString(texts[i].text), texts[i].size);
        }
        
    }
    //TODO: Make system that will remove redundancies in shared letters across the same size
    //std::cout << "Before: " << charsizes.text << std::endl;
    removeCharsizeRedundancies(&charsizes);
    //std::cout << "After: " << charsizes.text << std::endl;
    //TODO: Also make sizing automatic

    //Hello(4) and World(3) would be Helo World
    
    //for(int i = 0; i < charsizes.letter_size_array.size(); i++){
    //    std::cout << charsizes.letter_size_array[i] << std::endl;
    //}
    //isolate all unique characters
    //std::string letters = lettersInString(all_letters);
    //removeCharsizeRedundancies(&charsizes);

    //For all unique letters
    //std::cout << "Size: " << charsizes.text.size() << std::endl;
    for(int i = 0; i < charsizes.text.size(); i++){
        //Connect a letter and its size to a location in memory
        letterloc_array.push_back(createLetterloc(charsizes.text[i], PC, charsizes.letter_size_array[i]));
        //std::cout << letterloc_array[i].letter << std::endl;
        //std::cout << letterloc_array[i].size << std::endl;
        //Gets the letter's corresponding hex characters
        std::vector<uint8_t> letter_hex_array = letterToHex(charsizes.text[i], sizeToBitmap(charsizes.letter_size_array[i]));
        
        //writes every byte to the memory
        for(uint8_t row : letter_hex_array){
            bootup_memory.insert(bootup_memory.begin() + PC++, row);
        }
    }
    
    //Writes drawing code 
    //while(PC < drawing_location){
    //    bootup_memory.insert(bootup_memory.begin() + PC++, 0x00);
    //}
    //Replace first jump now to where the rest of the data will be. Used to account for many characters
    bootup_memory[0x00] = getFirstDrawingByte(PC + memory_start);
    bootup_memory[0x01] = getSecondDrawingByte(PC + memory_start);

    //Go through each text
    for(int i = 0; i < texts.size(); i++){
        //Iterate through all letters in a string
        while(texts[i].letter_index < texts[i].text.size()){
            //writes coordinates
            bootup_memory.insert(bootup_memory.begin() + PC++, 0x60);
            bootup_memory.insert(bootup_memory.begin() + PC++, xGet(&texts[i]));
            bootup_memory.insert(bootup_memory.begin() + PC++, 0x61);
            bootup_memory.insert(bootup_memory.begin() + PC++, yGet(&texts[i]));
            //writes I register setting
            uint16_t char_address = getLetterAddress(&texts[i], letterloc_array); 
            bootup_memory.insert(bootup_memory.begin() + PC++, ((0xA000 | char_address) >> 8));
            bootup_memory.insert(bootup_memory.begin() + PC++, (char_address & 0x00FF));
            //writes Draw command
            bootup_memory.insert(bootup_memory.begin() + PC++, 0xD0);
            bootup_memory.insert(bootup_memory.begin() + PC++, 0x10 + texts[i].size);
        }
    }
    //Writes delay code
    bootup_memory.insert(bootup_memory.begin() + PC++, 0x65);
    bootup_memory.insert(bootup_memory.begin() + PC++, delay);
    //Set delay timer to whats in register 5
    bootup_memory.insert(bootup_memory.begin() + PC++, 0xF5);
    bootup_memory.insert(bootup_memory.begin() + PC++, 0x15);
    //Set register 5 to be whats the delay_register
    uint16_t jump_point = PC + memory_start;
    bootup_memory.insert(bootup_memory.begin() + PC++, 0xF5);
    bootup_memory.insert(bootup_memory.begin() + PC++, 0x07);
    // Skip next instruction if delay timer runs out
    bootup_memory.insert(bootup_memory.begin() + PC++, 0x35);
    bootup_memory.insert(bootup_memory.begin() + PC++, 0x00);
    //Defines jump point when delay isn't done
    bootup_memory.insert(bootup_memory.begin() + PC++, ((0x1000 | jump_point) >> 8));
    bootup_memory.insert(bootup_memory.begin() + PC++, (jump_point & 0x00FF));
    //Clear register 5
    bootup_memory.insert(bootup_memory.begin() + PC++, 0x65);
    bootup_memory.insert(bootup_memory.begin() + PC++, 0x00);
    //Clear screen
    bootup_memory.insert(bootup_memory.begin() + PC++, 0x00);
    bootup_memory.insert(bootup_memory.begin() + PC++, 0xE0);
    //Go to actual program
    bootup_memory.insert(bootup_memory.begin() + PC++, ((0x1000 | rom_start) >> 8));
    bootup_memory.insert(bootup_memory.begin() + PC++, (rom_start & 0x00FF));

    debug_printBootupText(bootup_memory);

    return bootup_memory;
}

void ChippyBoot::loadBootupScreen(uint8_t memory[4096], std::vector<uint8_t> bootup_text){
    for(int i = 0; i < bootup_text.size(); i++){
        memory[memory_start + i] = bootup_text[i];
    }
}

void ChippyBoot::runBootup(uint16_t* program_counter){
    *program_counter = memory_start;
}

void ChippyBoot::debug_printBootupText(std::vector<uint8_t> bootup_text){
    int row_count = 0;
    for(uint8_t byte : bootup_text){
        std::cout << std::setw(2) << std::setfill('0') << std::hex << int(byte) << " ";
        if(!(++row_count % 16)){
            std::cout << " " << std::endl;
        }
    }
}
