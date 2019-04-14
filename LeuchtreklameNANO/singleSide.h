#define D_ENABLEOUTPUT 4
#define D_SHIFTREGCLR 5
#define D_SERIN 8 //D8
#define D_SERCLR 7 // nicht beim singleside
#define D_SHIFTREGCLK 3
#define D_REGCLK 2
#define D_BUTTON 11
#define D_LDR A3

// Reihenfolge:
// 2,4,6,7,5,3,1,0
inline int reorderBits(int value) {
  return  ((value>>2)&1)    | ((value>>4)&1)<<1 | 
          ((value>>6)&1)<<2 | ((value>>7)&1)<<3 | 
          ((value>>5)&1)<<4 | ((value>>3)&1)<<5 | 
          ((value>>1)&1)<<6 | ((value>>0)&1)<<7; 
}
