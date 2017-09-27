//t3
struct s_t3_timbre
{
    unsigned char Program_n;
    unsigned char OutputLevel;
    unsigned char KeyTraspose;
    unsigned char Detune;
    unsigned char TimbreInst;
    unsigned char KeyWindowTop;
    unsigned char KeyWindowBottom;
    unsigned char VelWindowTop;
    unsigned char VelWindowBottom;
    unsigned char ControlFilter;
    unsigned char TimbreOnOff;
} ;

struct s_t34d
{
    unsigned char Name[10];
    unsigned char Type;
    struct s_effect Effect;    
    struct s_timbre Timbre[8];    
    unsigned char altro[116];
} ;

struct s_t34c
{
    unsigned char Name[10];
    unsigned char altro[150];
} ;
struct s_t350
{
    unsigned char global[1701]; 
    struct s_t34d combi[100];
    struct s_t34c progra[200];
    unsigned char altro[1522+2];
    unsigned char vuoto[5000];
    unsigned char vuoto1[5000];
    unsigned char vuoto2[5000];
};

