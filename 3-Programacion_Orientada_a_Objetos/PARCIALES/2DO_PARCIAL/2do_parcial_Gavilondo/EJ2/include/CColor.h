#ifndef CCOLOR_H_INCLUDED
#define CCOLOR_H_INCLUDED

#include <ostream>
#include <cstdint>

using namespace std;

class CColor
{
    public:
        CColor();
        CColor(uint32_t);
        uint8_t getRed();
        uint8_t getGreen();
        uint8_t getBlue();
        uint8_t getAlpha();
        uint32_t getColor();
        void setRed(uint8_t);
        void setGreen(uint8_t);
        void setBlue(uint8_t);
        void setAlpha(uint8_t);
        void setColor(uint32_t);
        friend ostream& operator<< (ostream&, CColor&);
    private:
        uint32_t color;      // color = 0x AA RR GG BB
};


#endif // CCOLOR_H_INCLUDED
