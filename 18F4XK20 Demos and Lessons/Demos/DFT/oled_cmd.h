#define ON 1
#define OFF 0
#define ALTERNATE 1
#define SEQUENTIAL 0

void SetLowerColumnAddress(char x);
void SetHigherColumnAddress(char x);
void SetupHorizontalScroll(char a,char b,char c,char d);
void ActivateHorizontalScroll(void);
void DeactivateHorizontalScroll(void);
void SetDisplayStartLine(char x);
void SetContrastControlRegister(char a);
void SetBrightness(char a);
void SetLUT(char x,char a,char b,char c);
void SetBankColorA(char a,char b,char c,char d);
void SetBankColorB(char a,char b,char c,char d);
void SetSegmentReMap(char x);
void EntireDisplayOnOff(char x);
void SetInverse(char x);
void SetMultiplexRatio(char a);
void DCDCOnOff(char x);
void SetDisplayOnOff(char x);
void SetPageAddress(char x);
void SetCOMScan(char x);
void SetDisplayOffset(char a);
void SetDisplayClockDivider(char a);
void SetAreaColorPowerMode(char c,char p);
void SetPrechargePeriod(char a);
void SetCOMHWConfig(char x);
void SetVCOMDeselectLevel(char a);

