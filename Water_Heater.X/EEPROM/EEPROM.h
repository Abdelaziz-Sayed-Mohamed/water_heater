
#define EEPROM

#define IS_Flag_Was_Seted         Flag==1
#define EEPROM_DATA_ADDR          0xa
#define IS_Store_Set_Temp_Ready   Temperature.Store_Set_Temp_Flag==1
#define Start_EEPROM_Connection   while( e2pext_r(0))
void Get_EEPROM_Data(void);
void Set_EEPROM_Data(void);
unsigned char e2pext_r(unsigned int addr);
void e2pext_w(unsigned int addr, unsigned char val);
