

char bit_6_7[4][50]={"Use normal bank num","Use expanded banks as below","Use expanded banks as below","**** reserved for future use"};
char bit_5_4[4][50]={"**** reserved for future use","Local play mode","MIDI play mode","Both"};
char bit_3_2[4][50]={"**** reserved for future use","polyphonic","unison re-trigger","unison legato"};
char bit_1_0[4][50]={"low note","high note","last note","**** reserved for future use"};

//char be[12][6]={"RAM1","RAM2","ROM11","CARD","ROM4","ROM5","ROM6","ROM7","ROM8","ROM9","ROM10"};




// -------------------- h e a d e r  s y s e x -------------- //

struct s_header_sysex
{
    unsigned char   status_byte;
    unsigned char   korg_id;
    unsigned char   channel_number;
    unsigned char   device_id;
    unsigned char   message_type;
} header_sysex;

struct s_bn
{
    unsigned char   bank_number;
} parameter_bank_number;

// -------------------------- e n d  o f  f i l e --------------- //


struct s_finefile
{
    unsigned char check;
    unsigned char fine; //f7
} finefile;      










