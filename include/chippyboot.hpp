#include <vector>
#include <cstdint>
#include <string>

class ChippyBoot{

    public:
        struct screentext{
            std::string text;
            int size;
            std::string location;
            int letter_index = 0;
        };


        /**
         * @brief Formats desired text, size, and location to be displayed on bootup
         * @param text The desired text to be displayed
         * @param size The height of the text to be displayed (currently 3x3 pixels and 4x4 pixels)
         * @param location The location the text will be in. 
         * top_left, top_right, bottom_left, bottom_right, middle, sub_middle, bottom_middle 
         * @return screentext object to be put in a list with other screentext objects and inputted in createBootupText
         */
        static screentext createScreentext(std::string text, int size, std::string location);

        /**
         * @brief Creates the screen data to be used on bootup, waiting for a delay before reading ROM
         * @param texts An array of textloc objects containing text and their desired locations
         * @param delay The amount of cycles before bootup ends and the actual ROM executess (0-255)
         * @return An array of 8 bit integers and of size 4096 (currently) that holds the data to be executed to show bootup screen 
         */
        static std::vector<uint8_t> createBootupText(std::vector<screentext> texts, uint8_t delay);
        /**
         * @brief Creates the screen data to be used on bootup, waiting for button press before reading ROM
         * @param texts An array of textloc objects containing text and their desired locations
         * @param button The button that, when pressed, exits out of the bootup screen
         * @return An array of 8 bit integers and of size 4096 (currently) that holds the data to be executed to show bootup screen 
         */
        static std::vector<uint8_t> createBootupText(std::vector<screentext> texts, std::string button);
        /**
         * @brief Define custom starting location for ROM
         * @param location Location in memory where ROM data begins
         */
        static void defineRomLocation(uint16_t location);
        /**
         * @brief Loads data made from createBootupText into chip8 memory
         * @warning SPRITE DATA MUST END AT OR BEFORE 0x0A0 IN MEMORY. DATA MAY BE OVERWRITTEN OTHERWISE
         * @param memory The chip8 memory that contains sprites and the rom
         * @param bootup_text Data created by createBootupText()  
         */
        static void loadBootupScreen(uint8_t memory[4096], std::vector<uint8_t> bootup_text);
        /**
         * @brief Displays the Bootup screen when execution starts and handles exiting
         * @param program_counter Chip8 program counter to be able to transition from bootup screen to a chip8 game
         */
        static void runBootup(uint16_t* program_counter);


    private:


        static uint16_t rom_start;
        static uint16_t memory_start;

        struct letterloc {
            char letter;
            uint16_t location;
            int size;
        };
        
        struct charsizes {
            std::string text;
            std::vector<int> letter_size_array;
        };
        

        static charsizes createCharsizes(std::string text, int size);

        static void addToCharsizes(charsizes* input_charsizes, std::string input_text, int input_size);
        /**
         * @brief Removes letters from the input if there are other letters like it of the same size
         * @param input_charsizes the input charsize to be trimmed
         */
        static void removeCharsizeRedundancies(charsizes* input_charsizes);

        static void incrementCharsizeIndex(charsizes* charsizes);
    
        static letterloc createLetterloc(char letter_input, uint16_t location, int size);

        const static uint8_t rep_digits = 37;
        const static uint8_t num_fonts = 2;
        const static uint16_t drawing_location = 0x012C;
        
        static std::vector<std::vector<uint8_t>> bitfont3x3;

        static std::vector<std::vector<uint8_t>> bitfont4x4;
        //uint8_t bitfont5x5[36][5] = {};

        /**
         * @brief Returns a series of hex numbers corresponding to the bitmap for a given character
         * @param letter The desired letter you want to turn into hex
         * @param bitfont The bitmap size you want the letter to be outputted to
         */
        static std::vector<uint8_t> letterToHex(char letter, std::vector<std::vector<uint8_t>>);
        /**
         * @brief breaks up words into only their unique characters
         * @param text text to be broken up into one of each of its unique letters
         */
        static std::string lettersInString(std::string text);

        /**
         * @brief Transitions from bootup to regular chip8 program memory
         */
        static void startProgram(uint16_t program_counter);


        /**
         * @brief Returns the Y coord from a string location
         * @param location string location defined when a screentext object is made
         */
        static uint8_t xGet(screentext* text);

        /**
         * @brief Returns the Y coord from a string location 
         * @param location string location defined when a screentext object is made
         */
        static uint8_t yGet(screentext* text);

        /**
         * @brief Increments a screentext object's letter index by 1 to keep track of what letter has been printed
         */
        static void incrementLetterIndex(screentext* text);
        /**
         * @brief Returns upper 8 bits of jump command from a certain drawing location
         * @param drawing_location The starting point of bootup assembly code
         */
        static uint8_t getFirstDrawingByte(uint16_t drawing_location);
        /**
         * @brief Returns lower 8 bits of jump command from a certain drawing location
         * @param drawing_location The starting point of bootup assembly code
         */
        static uint8_t getSecondDrawingByte(uint16_t drawing_location);

        /**
         * @brief Returns the bitmap corresponding to the designated text size
         * @param size The user-designated size of the bitfont
         */
        static std::vector<std::vector<uint8_t>> sizeToBitmap(int size);

        /**
         * @brief Returns the memory address of a specific character
         * @param text the specific screentext
         * @param letterloc_array the array of letter and their respective locations
         */
        static uint16_t getLetterAddress(screentext* text, std::vector<letterloc> letterloc_array);

        static void debug_printBootupText(std::vector<uint8_t> bootup_text);

};
