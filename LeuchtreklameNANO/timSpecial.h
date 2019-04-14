#define D_ENABLEOUTPUT 11
#define D_SHIFTREGCLR 5 // nicht genutzt
#define D_SERIN 12 
#define D_SERCLR 7 // nicht genutzt
#define D_SHIFTREGCLK 9
#define D_REGCLK 10
#define D_BUTTON 2 // nicht genutzt
#define D_LDR A3 // nicht genutzt

inline int reorderBits(int value) {
  return value;
}
