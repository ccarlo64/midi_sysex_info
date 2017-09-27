struct s_m3r
{
    unsigned char Name[10];
    unsigned char Type;
    struct s_effect Effect;
    struct s_timbre Timbre[8];
    unsigned char altro[2]; // 112
} ;

//--------------------------- programs -------------

struct s_oscillator_m3r
{
    unsigned char a[5];
};

struct s_pitch_mg_m3r
{
    unsigned char a[4];
};

struct s_cutoff_mg_m3r
{
    unsigned char a[4];
};

struct s_after_touch_m3r
{
    unsigned char a[5];
};

struct s_joystick_m3r
{
    unsigned char a[6];
};


// dati oscilator
struct s_pitch_eg_m3r
{
    unsigned char a[8];
};
struct s_vdf_1_m3r
{
    unsigned char a[7];
};
struct s_vdf_1_eg_m3r
{
    unsigned char a[8];
};
struct s_vda_1_m3r
{
    unsigned char a[6];
};
struct s_vda_1_eg_m3r
{
    unsigned char a[7];
};
struct s_other_m3r
{
    unsigned char a[4];
};
struct s_osc_m3r
{
    struct s_pitch_eg_m3r pitch_eg;
    struct s_vdf_1_m3r vdf_1;
    struct s_vdf_1_eg_m3r vdf_1_eg;
    struct s_vda_1_m3r vda_1;
    struct s_vda_1_eg_m3r vda_1_eg;
    struct s_other_m3r other;
    unsigned char nulla;
};

struct s_m3r4c
{
    unsigned char Name[10];
    struct s_oscillator_m3r oscillator;
    struct s_pitch_mg_m3r pitch_mg;
    struct s_cutoff_mg_m3r cutoff_mg;
    struct s_after_touch_m3r after_touch;
    struct s_joystick_m3r joystick;
    struct s_osc_m3r oscillator_1;
} ;

