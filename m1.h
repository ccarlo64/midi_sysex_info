// m1 effect parameter type (33 tipi) start
struct s_e1_2_3_4_5_6
{
    unsigned char Reverb_time;
    unsigned char nulla_1;
    unsigned char High_damp;
    unsigned char Pre_delay;
    unsigned char ER_level;
    unsigned char nulla_2;
    unsigned char EQ_high;
    unsigned char EQ_low;
};
struct s_e7_8_9
{
    unsigned char ER_time;
    unsigned char Pre_delay;
    unsigned char nulla_1;
    unsigned char nulla_2;
    unsigned char nulla_3;
    unsigned char nulla_4;
    unsigned char EQ_high;
    unsigned char EQ_low;
};
struct s_e10_11
{
    unsigned char Delay_time_left_l;
    unsigned char Delay_time_left_h;
    unsigned char Feedback;
    unsigned char High_damp;
    unsigned char Delay_time_right_l;
    unsigned char Delay_time_right_h;
    unsigned char EQ_high;
    unsigned char EQ_low;
};
struct s_e12_13_14_15
{
    unsigned char Depth;
    unsigned char Speed;
    unsigned char MG_status;
    unsigned char Feedback;
    unsigned char Delay_time;
    unsigned char nulla_1;
    unsigned char EQ_high;
    unsigned char EQ_low;
};
struct s_e16_17
{
    unsigned char Depth;
    unsigned char Speed;
    unsigned char MG_status;
    unsigned char Feedback;
    unsigned char Manual;
    unsigned char nulla_1;
    unsigned char nulla_2;
    unsigned char nulla_3;
};
struct s_e18_19
{
    unsigned char Depth;
    unsigned char Speed;
    unsigned char MG_status;
    unsigned char Shape;
    unsigned char nulla_1;
    unsigned char nulla_2;
    unsigned char EQ_high;
    unsigned char EQ_low;
};
struct s_e20
{
    unsigned char Mid_fc;
    unsigned char Mid_Gain;
    unsigned char nulla_1;
    unsigned char nulla_2;
    unsigned char Low_fc;
    unsigned char High_fc;
    unsigned char High_gain;
    unsigned char Low_gain;
};
struct s_e21
{
    unsigned char EQ_Mid_fc;
    unsigned char EQ_Mid_Gain;
    unsigned char Drive;
    unsigned char Level;
    unsigned char nulla_1;
    unsigned char nulla_2;
    unsigned char EQ_high;
    unsigned char EQ_low;
};
struct s_e22
{
    unsigned char nulla_1;
    unsigned char nulla_2;
    unsigned char Distorsion;
    unsigned char Level;
    unsigned char nulla_3;
    unsigned char nulla_4;
    unsigned char nulla_5;
    unsigned char EQ_low_gain;
};
struct s_e23
{
    unsigned char Blend;
    unsigned char Emphatic_point;
    unsigned char nulla_1;
    unsigned char nulla_2;
    unsigned char nulla_3;
    unsigned char nulla_4;
    unsigned char EQ_high;
    unsigned char EQ_low;
};
struct s_e24
{
    unsigned char Depth;
    unsigned char nulla_1;
    unsigned char nulla_2;
    unsigned char nulla_3;
    unsigned char nulla_4;
    unsigned char nulla_5;
    unsigned char EQ_high;
    unsigned char EQ_low;
};
struct s_e25
{
    unsigned char Depth;
    unsigned char nulla_1;
    unsigned char Speed_rate;
    unsigned char nulla_3;
    unsigned char nulla_4;
    unsigned char nulla_5;
    unsigned char nulla_6;
    unsigned char nulla_7;
};
struct s_e26
{
    unsigned char Delay_time_left_l;
    unsigned char Delay_time_left_h;
    unsigned char Feedback;
    unsigned char High_damp;
    unsigned char Reverber_time;
    unsigned char nulla_1;
    unsigned char High_damp1;
    unsigned char Pre_delay;
};
struct s_e27
{
    unsigned char Delay_time_left_l;
    unsigned char Delay_time_left_h;
    unsigned char Feedback;
    unsigned char High_damp;
    unsigned char Reverber_time;
    unsigned char nulla_1;
    unsigned char High_damp1;
    unsigned char Pre_delay;
};
struct s_e28
{
    unsigned char Delay_time_left_l;
    unsigned char Delay_time_left_h;
    unsigned char Feedback;
    unsigned char High_damp;
    unsigned char ER_time;
    unsigned char Pre_delay;
    unsigned char nulla_1;
    unsigned char nulla_2;
};

struct s_e29
{
    unsigned char Delay_time_left_l;
    unsigned char Delay_time_left_h;
    unsigned char Feedback_left;
    unsigned char High_damp_left;
    unsigned char Delay_time_right_l;
    unsigned char Delay_time_right_h;
    unsigned char Feedback_right;
    unsigned char High_damp_right;

};
struct s_e30_31
{
    unsigned char Delay_time_left_l;
    unsigned char Delay_time_left_h;
    unsigned char Feedback;
    unsigned char High_damp;
    unsigned char Depth;
    unsigned char Speed;
    unsigned char MS_status;
    unsigned char Feedback1;
};
struct s_e32
{
    unsigned char Delay_time_left_l;
    unsigned char Delay_time_left_h;
    unsigned char Feedback;
    unsigned char High_damp;
    unsigned char Depth;
    unsigned char Speed;
    unsigned char Feedback1;
    unsigned char nulla_1;
};
struct s_e33
{
    unsigned char Delay_time_left_l;
    unsigned char Delay_time_left_h;
    unsigned char Feedback;
    unsigned char High_damp;
    unsigned char Depth;
    unsigned char Speed;
    unsigned char Shape;
    unsigned char nulla_1;
};

// m1
struct s_timbre
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
// m1 effect parameter type (33 tipi) end

union u_parameters
{
    struct s_e1_2_3_4_5_6   e1_2_3_4_5_6;
    struct s_e7_8_9         e7_8_9;
    struct s_e10_11         e10_11;
    struct s_e12_13_14_15   e12_13_14_15;
    struct s_e16_17         e16_17;
    struct s_e18_19         e18_19; 
    struct s_e20            e20;            
    struct s_e21            e21;
    struct s_e22            e22;
    struct s_e23            e23;
    struct s_e24            e24;
    struct s_e25            e25;
    struct s_e26            e26;
    struct s_e27            e27;
    struct s_e28            e28;
    struct s_e29            e29;
    struct s_e30_31         e30_31;
    struct s_e32            e32;
    struct s_e33            e33;
} ;

struct s_effect
{
    unsigned char e_1_pattern;
    unsigned char e_2_pattern;
    unsigned char e_1_left_ch_bal;
    unsigned char e_1_right_ch_bal;
    unsigned char e_2_left_ch_bal;
    unsigned char e_2_right_ch_bal;
    unsigned char output_3_pan;
    unsigned char output_4_pan;
    unsigned char e_i_o;
    union u_parameters p1;
    union u_parameters p2;
    };
    
struct s_m1
{
    unsigned char Name[10];
    unsigned char Type;
    struct s_effect Effect;
    struct s_timbre Timbre[8];
} ;

//--------------------------- programs -------------

struct s_oscillator
{
    unsigned char a[9];
};

struct s_pitch_mg
{
    unsigned char a[4];
};

struct s_cutoff_mg
{
    unsigned char a[4];
};

struct s_after_touch
{
    unsigned char a[5];
};

struct s_joystick
{
    unsigned char a[6];
};

struct s_effect_parameter
{
    unsigned char a[25];
};
// dati oscilator
struct s_pitch_eg
{
    unsigned char a[8];
};
struct s_vdf_1
{
    unsigned char a[7];
};
struct s_vdf_1_eg
{
    unsigned char a[8];
};
struct s_vda_1
{
    unsigned char a[6];
};
struct s_vda_1_eg
{
    unsigned char a[7];
};
struct s_other
{
    unsigned char a[4];
};
struct s_osc
{
    struct s_pitch_eg pitch_eg;
    struct s_vdf_1 vdf_1;
    struct s_vdf_1_eg vdf_1_eg;
    struct s_vda_1 vda_1;
    struct s_vda_1_eg vda_1_eg;
    struct s_other other;
};

struct s_m14c
{
    unsigned char Name[10];
    struct s_oscillator oscillator;
    struct s_pitch_mg pitch_mg;
    struct s_cutoff_mg cutoff_mg;
    struct s_after_touch after_touch;
    struct s_joystick joystick;
    struct s_effect_parameter effect_parameter;
    struct s_osc oscillator_1;
    struct s_osc oscillator_2;
} ;
/*
struct s_m14c
{
    unsigned char Name[10];
    unsigned char altro[133];
} ;
*/


// ----------------------- global --------------------

struct s_m150
{
    unsigned char global[861]; // 6a5
    struct s_m1 combi[100]; //5cd0
    struct s_m14c progra[100];
    unsigned char altro[1522+2];
    unsigned char vuoto[5000];
    unsigned char vuoto1[5000];
    unsigned char vuoto2[5000];
    };





