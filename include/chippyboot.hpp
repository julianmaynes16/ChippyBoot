#include <cstdint>
#include <string>

class ChippyBoot{

    public:
        struct textloc{
            std::string text;
            std::string location;
        };
        /**
         * @brief Creates the screen data to be used on bootup, waiting for a delay before reading ROM
         * @param texts An array of textloc objects containing text and their desired locations
         * @param delay The amount of cycles before bootup ends and the actual ROM executess (0-255)
         */
        static void createBootupText(textloc* texts, uint8_t delay);
        /**
         * @brief Creates the screen data to be used on bootup, waiting for button press before reading ROM
         * @param texts An array of textloc objects containing text and their desired locations
         * @param button The button that, when pressed, exits out of the bootup screen
         */
        static void createBootupText(textloc* texts, char button);
        /**
         * @brief Define custom starting location for ROM
         * @param location Location in memory where ROM data begins
         */
        static void defineRomLocation(int location);


    private:

       

        /**
         * @brief Returns a series of hex numbers corresponding to the bitmap for a given character
         * @param letter The desired letter you want to turn into hex
         * @param bitfont The bitmap size you want the letter to be outputted to
         */
        static uint8_t* letterToHex(char letter, uint8_t** bitfont);
        /**
         * @brief breaks up words into only their unique characters
         * @param text text to be broken up into one of each of its unique letters
         */
        static std::string lettersInString(std::string text);



};
