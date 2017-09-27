
// ------------------------ p e r f o r m a n c e ---------------- //
// normali


/*Patch data structure*/
struct s_indiv1 {
unsigned char Wave_Coarse;/* Wave detuning in semitones*/
unsigned char Wave_Fine;/* Wave detuning in cents */
unsigned char Wave_Bank;/* Wave bank */
unsigned char Wave_Num[2];/* Wave number unsigned short*/
unsigned char Wave_Scale;/* Wave pitch scaling slope */
unsigned char Lfo1_Rate;/* LFO 1 Rate */
unsigned char Lfo1_Amt;/* LFO 1 Amount*/
unsigned char Lfo1_Delay;/* LFO 1 Delay*/
unsigned char Lfo1_Fade;/* LFO 1 Fade in*/
unsigned char Lfo1_Shape;/* LFO 1 Shape (bits 0-6)1-127*/
                            /* LFO 1 Sync (bit 7) */
                            /*1 = Sync on */
                            /*0 = Sync off*/
unsigned char S1_Lfo1_R;/* Mod Source to LFO 1 Rate pointer*/
unsigned char S1_Lfo1_R_Amt; /* Mod Source to LFO 1 Rate amount*/
unsigned char S1_Lfo1_A;/* Mod Source to LFO 1 Amt pointer*/
unsigned char S1_Lfo1_A_Amt;/* Mod Source to LFO 1 Amt amount*/
unsigned char Lfo2_Rate;/* LFO 2 Rate*/
unsigned char Lfo2_Amt;/* LFO 2 Amount*/
unsigned char Lfo2_Delay;/* LFO 2-Delay*/
unsigned char Lfo2_Fade;/* LFO 2-Fade in*/
unsigned char Lfo2_Shape;/* LFO 2-Shape (bits 0-6)1-127*/
                            /* LFO 2 Sync (bit 7) */
                            /* 1 = Sync on */
                            /* 0 = Sync off*/
unsigned char S1_Lfo2_R;/* Mod Source to LFO 1 Rate pointer*/
unsigned char S1_Lfo2_R_Amt;/* Mod Source to LFO 2 Rate amount*/
unsigned char S1_Lfo2_A;/* Mod Source to LFO 2 Amt pointer*/
unsigned char S1_Lfo2_A_Amt;/* Mod Source to LFO 1 Amt amount*/
unsigned char EG_Rate1;/* Envelope 1 Rate 1 */
unsigned char EG_Rate2;/* Envelope 1 Rate 2 */
unsigned char EG_Rate3;/* Envelope 1 Rate 3 */
unsigned char EG_Rate4;/* Envelope 1 Rate 4 */
unsigned char EG_Level0;/* Envelope 1 Level 0 */
unsigned char EG_Level1;/* Envelope 1 Level 1 */
unsigned char EG_Level2;/* Envelope 1 Level 2 */
unsigned char EG_Level3;/* Envelope 1 Level 3 */
unsigned char EG_Level4;/* Envelope 1 Level 4 */
unsigned char Vel_EG_A;/* Velocity to Env1 Amount Amt */
unsigned char AEG_Rate1;/* Amplitude Envelope Rate 1 */
unsigned char AEG_Rate2;/* Amplitude Envelope Rate 2 */
unsigned char AEG_Rate3;/* Amplitude Envelope Rate 3 */
unsigned char AEG_Rate4;/* Amplitude Envelope Rate 4 */
unsigned char AEG_Level0;/* Amplitude Envelope Level 0 */
unsigned char AEG_Level1;/* Amplitude Envelope Level 1 */
unsigned char AEG_Level2;/* Amplitude Envelope Level 2 */
unsigned char AEG_Level3;/* Amplitude Envelope Level 3 */
unsigned char Pitch_Mac;/* Pitch Macro number*/
unsigned char Fil_Mac;/* Filter Macro number*/
unsigned char Amp_Mac;/* Amplitude Envelope Macro number*/
unsigned char Pan_Mac;/* Pan Macro number*/
unsigned char Env_Mac;/* Envelope 1 macro number*/
unsigned char Pw_Range;/* Pitchwheel Range */
unsigned char S1_Pitch;/* Modulation Source 1 to Pitch pointer*/
unsigned char S1_Pitch_Amt;/* Modulation Source 1 to Pitch Amount*/
unsigned char S2_Pitch;/* Modulation Source 2 to Pitch pointer*/
unsigned char S2_Pitch_Amt;/* Modulation Source 2 to Pitch Amount*/
unsigned char Key_Filter;/* Keyboard to Filter Cutoff Amount*/
unsigned char S1_Filter;/* Modulation Source 1 to Filter pointer*/
unsigned char S1_Filter_Amt;/* Modulation Source 1 to Filter Amount*/
unsigned char S2_Filter;/* Modulation Source 2 to Filter pointer*/
unsigned char S2_Filter_Amt;/* Modulation Source 2 to Filter Amount*/
unsigned char Vel_AEG_A;/* Velocity to Amp Env Amount Amount*/
unsigned char Vel_AEG_R;/* Velocity To Amp Env Attack Rate Amt*/
unsigned char Key_AEG_R;/* Keyboard to Amp Env Decay Rate Amt*/
unsigned char S1_Amp;/* Modulation Source 1 to Amp pointer*/
unsigned char S1_Amp_Amt;/* Modulation Source 1 to Amp Amount*/
unsigned char S2_Amp;/* Modulation Source 2 to Amp pointer*/
unsigned char S2_Amp_Amt;/* Modulation Source 2 to Amp Amount*/
unsigned char Key_Pan_Amt;/* Keyboard to Pan Amount*/
unsigned char Vel_Pan_Amt;/* Velocity to Pan Amount*/
unsigned char Cutoff;/* Filter Cutoff value */
unsigned char Filter_Exciter;/* Filter Exciter value */
unsigned char Vel_EG_R;/* Velocity to ENV1 rate amount*/
unsigned char Key_EG_R;/* Keyboard to ENV1 rate amount*/
unsigned char PEG_Amt;/* Pitch Ramp amount*/
unsigned char PEG_Rate;/* Pitch Ramp rate*/
unsigned char Vel_PEG_A;/* Velocity to pitch ramp amount */
unsigned char Indiv_Level;/* Velocity to pitch ramp rate amount*/
unsigned char   Lfo1_Inc[4];/* Lfo fade in amount increment*/
unsigned char   Lfo2_Inc[4];/* Lfo fade in amount increment*/
unsigned char Patch_Output;/* Individual output routing */
unsigned char Wave_Num_Exp;/* Wave number expansion to access 
      Expansion PCM data (Waves numbered 397 and over). This number is added 
      to the value of Wave_Num to determine the actual wave number.*/
} ;



struct s_patch1
{
char Patch_Name[16];/* Patch name up to 16 characters*/
unsigned char Mix_Rate1;/* Mix envelope rate for segment 1 */ 
unsigned char Mix_Rate2; /* Mix envelope rate for segment 2 */ 
unsigned char Mix_Rate3; /* Mix envelope rate for segment 3 */ 
unsigned char Mix_Rate4; /* Mix envelope rate for segment 4 */ 
unsigned char Mix_Count1[2]; /* Number of update cycles for env seg*/ 
unsigned char Mix_Count2[2]; /* Number of update cycles for env seg*/ 
unsigned char Mix_Count3[2]; /* Number of update cycles for env seg*/ 
unsigned char Mix_Count3B[2];/* Number of update cycles for env seg*/ 
unsigned char Mix_Count2B[2];/* Number of update cycles for env seg*/ 
unsigned char Mix_Count1B[2];/* Number of update cycles for env seg*/ 
unsigned char Mix_Count4[2]; /* Number of update cycles for env seg*/
unsigned char    Mix_XSlope1[4];/* Increment size for env seg 1 */ 
unsigned char    Mix_XSlope2[4];/* Increment size for env seg 2 */ 
unsigned char    Mix_XSlope3[4];/* Increment size for env seg 3 */
unsigned char    Mix_XSlope4[4];/* Increment size for env seg 4 */
unsigned char    Mix_YSlope1[4];/* Increment size for env seg 1 */
unsigned char    Mix_YSlope2[4];/* Increment size for env seg 2 */
unsigned char    Mix_YSlope3[4];/* Increment size for env seg 3 */ 
unsigned char    Mix_YSlope4[4];/* Increment size for env seg 4 */
unsigned char Mix_X0;/* Mix Envelope Point 0 level */
unsigned char Mix_X1;/* Mix Envelope Point 1 level */
unsigned char Mix_X2;/* Mix Envelope Point 2 level */
unsigned char Mix_X3;/* Mix Envelope Point 3 level */
unsigned char Mix_X4;/* Mix Envelope Point 4 level */
unsigned char Mix_Y0;/* Mix Envelope Point 0 level */
unsigned char Mix_Y1;/* Mix Envelope Point 1 level */
unsigned char Mix_Y2;/* Mix Envelope Point 2 level */
unsigned char Mix_Y3;/* Mix Envelope Point 3 level */
unsigned char Mix_Y4;/* Mix Envelope Point 4 level */
unsigned char Mix_Repeats;/* Number of repeats of mix envelope*/
unsigned char Mix_Env_Loop;/* Start segment of Mix Envelope loops*/
unsigned char S1_MixAC;/* Modulation Source 1 to MixAC pointer*/
unsigned char S1_MixAC_Amt;/* Modulation Source 1 to MixAC Amount*/
unsigned char S2_MixAC; /* Modulation Source 2 to MixAC pointer*/
unsigned char S2_MixAC_Amt;/* Modulation Source 2 to MixAC Amount*/
unsigned char S1_MixBD; /* Modulation Source 1 to MixBD pointer*/
unsigned char S1_MixBD_Amt;/* Modulation Source 1 to MixBD Amount*/
unsigned char S2_MixBD; /* Modulation Source 2 to MixBD pointer*/
unsigned char S2_MixBD_Amt;/* Modulation Source 2 to MixBD Amount*/
unsigned char Number_Of_Waves;/* Number of WAVES/WAVESEQS in Patch*/
unsigned char Hard_Sync; /* Hard Sync Flag*/
unsigned char Bank_Exp; /* Bit 7 = 1[2]; Second Exp Bit set for Wave D 
                                  if Wave_Bank = 0 --> Wave D uses ROM7 wseq
                                  if Wave_Bank = 1 --> Wave D uses ROM8 wseq
                                  if Wave_Bank = 2 --> Wave D uses ROM9 wseq
                                  if Wave_Bank = 3 --> Wave D uses ROM10 wseq*
                      /* Bit 6 = 1[2];  Second Exp Bit set for Wave C 
                                  if Wave_Bank = 0 --> Wave C uses ROM7 wseq
                                  if Wave_Bank = 1 --> Wave C uses ROM8 wseq
                                  if Wave_Bank = 2 --> Wave C uses ROM9 wseq
                                  if Wave_Bank = 3 --> Wave C uses ROM10 wseq*
                      /* Bit 5 = 1[2];  Second Exp Bit set for Wave B 
                                  if Wave_Bank = 0 --> Wave B uses ROM7 wseq
                                  if Wave_Bank = 1 --> Wave B uses ROM8 wseq
                                  if Wave_Bank = 2 --> Wave B uses ROM9 wseq
                                  if Wave_Bank = 3 --> Wave B uses ROM10 wseq*
                      /* Bit 4 = 1[2];  Second Exp Bit set for Wave A 
                                  if Wave_Bank = 0 --> Wave A uses ROM7 wseq
                                  if Wave_Bank = 1 --> Wave A uses ROM8 wseq
                                  if Wave_Bank = 2 --> Wave A uses ROM9 wseq
                                  if Wave_Bank = 3 --> Wave A uses ROM10 wseq*
                      /* Bit 3 = 1[2];  First Exp Bit set for Wave D 
                                  if Wave_Bank = 0 --> Wave D uses ROM4 wseq
                                  if Wave_Bank = 1 --> Wave D uses ROM5 wseq
                                  if Wave_Bank = 2 --> Wave D uses RAM3 wseq
                                  if Wave_Bank = 3 --> Wave D uses ROM6 wseq *
                      /* Bit 2 = 1[2];  First Exp Bit set for Wave C 
                                  if Wave_Bank = 0 --> Wave C uses ROM4 wseq
                                  if Wave_Bank = 1 --> Wave C uses ROM5 wseq
                                  if Wave_Bank = 2 --> Wave C uses RAM3 wseq
                                  if Wave_Bank = 3 --> Wave C uses ROM6 wseq*/
                      /* Bit 1 = 1[2];  First Exp Bit set for Wave B 
                                  if Wave_Bank = 0 --> Wave B uses ROM4 wseq
                                  if Wave_Bank = 1 --> Wave B uses ROM5 wseq
                                  if Wave_Bank = 2 --> Wave B uses RAM3 wseq
                                  if Wave_Bank = 3 --> Wave B uses ROM6 wseq *
                      /* Bit 0 = 1[2];  First Exp Bit set for Wave A 
                                  if Wave_Bank = 0 --> Wave A uses ROM4 wseq
                                  if Wave_Bank = 1 --> Wave A uses ROM5 wseq
                                  if Wave_Bank = 2 --> Wave A uses RAM3 wseq
                                  if Wave_Bank = 3 --> Wave A uses ROM6 wseq */
		
unsigned char Dummy141; /* Extra for future use */
struct s_indiv1 waveA;/* Individual parameters for WAVE A */
struct s_indiv1 waveB;/* Individual parameters for WAVE B */
struct s_indiv1 waveC;/* Individual parameters for WAVE C */
struct s_indiv1 waveD;/* Individual parameters for WAVE D */
};





struct s_part1
{
unsigned char Bank_Num;  /* Bank number this PART is playing */
unsigned char Patch_Num; /* Patch number this PART is playing */
unsigned char Level; /* Volume for this part */
unsigned char Output;/* OUTPUT CHAN FOR THIS Part */
unsigned char Part_Mode; /* KEYBOARD ASSIGN MODE (Polyphonic,UNI) */
                            /* bit 6-7 */
                            /* Bank Expansion */        
                            /* 00= Use normal bank num: 
                                    if Bank_Num = 0 --> RAM1
                                    if Bank_Num = 1 --> RAM2
                                    if Bank_Num = 2 --> ROM11
                                    if Bank_Num = 3 --> CARD */
                            /* 01= Use expanded banks as below:
                                    if Bank_Num = 0 --> ROM4
                                    if Bank_Num = 1 --> ROM5
                                    if Bank_Num = 2 --> RAM3
                                    if Bank_Num = 3 --> ROM6 */
                            /* 10= Use expanded banks as below:
                                    if Bank_Num = 0 --> ROM7
                                    if Bank_Num = 1 --> ROM8
                                    if Bank_Num = 2 --> ROM9
                                    if Bank_Num = 3 --> ROM10 */
                            /* 11= **** reserved for future use */
                            /* bit 5-4 */
                            /* 00= **** reserved for future use */
                            /* 01= Local play mode*/
                            /* 10= MIDI play mode*/
                            /* 11 = Both */
                            /* bit 3-2 */
                            /* 00= **** reserved for future use */
                            /* 01= polyphonic*/
                            /* 10= unison re-trigger*/
                            /* 11= unison legato*/
                            /* bit 1-0 */
                            /* 00= low note*/
                            /* 01= high note*/
                            /* 10= last note*/
                            /* 11 = **** reserved for future use */
unsigned char Lo_Key; /* Lower note of keyboard range*/
unsigned char Hi_Key; /* Upper note of keyboard range*/
unsigned char Lo_Vel; /* Lower limit of velocity range*/
unsigned char Hi_Vel; /* Upper limit of velocity range */
unsigned char Trans; /* Transpose value in semitones */
unsigned char Detune; /* Detune value in cents*/
unsigned char Tunetab;  /* Micro tuning table for this PART */
unsigned char Micro_Tune_Key; /* Root key for pure major/minor and USER scales */
unsigned char Midi_Out_Chan; /* MIDI transmit channel for this PART */
unsigned char Midi_Prog_Num; /* MIDI prog# to xmit when PART selected, -1 =off) */
unsigned char Sus_Enable; /* Sustain Pedal enable/disable */
unsigned char Delay[2]; /* Delay value in milliseconds */
} ;

struct s_performance1
{
unsigned char Perf_Name[16];/* Performance name - up to 16 characters */
unsigned char Fx_Perf_Block[21]; /* Leave space for effects parameters */
                                    /* This is where the PART blocks start, of which 8 
                                       can be appended to the performance */
struct s_part1 pp[8];
} ;


// ------------------------ p e r f o r m a n c e ---------------- //
// doppie

struct s_part
{
unsigned char Bank_Num[2];  /* Bank number this PART is playing */
unsigned char Patch_Num[2]; /* Patch number this PART is playing */
unsigned char Level[2]; /* Volume for this part */
unsigned char Output[2];/* OUTPUT CHAN FOR THIS Part */
unsigned char Part_Mode[2]; /* KEYBOARD ASSIGN MODE (Polyphonic,UNI) */
                            /* bit 6-7 */
                            /* Bank Expansion */        
                            /* 00= Use normal bank num: 
                                    if Bank_Num = 0 --> RAM1
                                    if Bank_Num = 1 --> RAM2
                                    if Bank_Num = 2 --> ROM11
                                    if Bank_Num = 3 --> CARD */
                            /* 01= Use expanded banks as below:
                                    if Bank_Num = 0 --> ROM4
                                    if Bank_Num = 1 --> ROM5
                                    if Bank_Num = 2 --> RAM3
                                    if Bank_Num = 3 --> ROM6 */
                            /* 10= Use expanded banks as below:
                                    if Bank_Num = 0 --> ROM7
                                    if Bank_Num = 1 --> ROM8
                                    if Bank_Num = 2 --> ROM9
                                    if Bank_Num = 3 --> ROM10 */
                            /* 11= **** reserved for future use */
                            /* bit 5-4 */
                            /* 00= **** reserved for future use */
                            /* 01= Local play mode*/
                            /* 10= MIDI play mode*/
                            /* 11 = Both */
                            /* bit 3-2 */
                            /* 00= **** reserved for future use */
                            /* 01= polyphonic*/
                            /* 10= unison re-trigger*/
                            /* 11= unison legato*/
                            /* bit 1-0 */
                            /* 00= low note*/
                            /* 01= high note*/
                            /* 10= last note*/
                            /* 11 = **** reserved for future use */
unsigned char Lo_Key[2]; /* Lower note of keyboard range*/
unsigned char Hi_Key[2]; /* Upper note of keyboard range*/
unsigned char Lo_Vel[2]; /* Lower limit of velocity range*/
unsigned char Hi_Vel[2]; /* Upper limit of velocity range */
unsigned char Trans[2]; /* Transpose value in semitones */
unsigned char Detune[2]; /* Detune value in cents*/
unsigned char Tunetab[2];  /* Micro tuning table for this PART */
unsigned char Micro_Tune_Key[2]; /* Root key for pure major/minor and USER scales */
unsigned char Midi_Out_Chan[2]; /* MIDI transmit channel for this PART */
unsigned char Midi_Prog_Num[2]; /* MIDI prog# to xmit when PART selected, -1 =off) */
unsigned char Sus_Enable[2]; /* Sustain Pedal enable/disable */
unsigned short Delay[2]; /* Delay value in milliseconds */
} ;

struct s_performance
{
unsigned char Perf_Name[NAME_SIZE];/* Performance name - up to 16 characters */
unsigned char Fx_Perf_Block[21*2]; /* Leave space for effects parameters */
                                    /* This is where the PART blocks start, of which 8 
                                       can be appended to the performance */
struct s_part pp[8];
} performance;


// -------------------- p a t c h -------------------- //


/*        Individual Patch Data Structure */
/* This is the structure for data that is individual to the */
/* 1, 2, or 4 oscillators that make up a Patch.*/
/* Four of these structures are included in a Patch.*/
struct s_indiv {
unsigned char Wave_Coarse[2];/* Wave detuning in semitones*/
unsigned char Wave_Fine[2];/* Wave detuning in cents */
unsigned char Wave_Bank[2];/* Wave bank */
unsigned char Wave_Num[4];/* Wave number unsigned short*/
unsigned char Wave_Scale[2];/* Wave pitch scaling slope */
unsigned char Lfo1_Rate[2];/* LFO 1 Rate */
unsigned char Lfo1_Amt[2];/* LFO 1 Amount*/
unsigned char Lfo1_Delay[2];/* LFO 1 Delay*/
unsigned char Lfo1_Fade[2];/* LFO 1 Fade in*/
unsigned char Lfo1_Shape[2];/* LFO 1 Shape (bits 0-6)1-127*/
                            /* LFO 1 Sync (bit 7) */
                            /*1 = Sync on */
                            /*0 = Sync off*/
unsigned char S1_Lfo1_R[2];/* Mod Source to LFO 1 Rate pointer*/
unsigned char S1_Lfo1_R_Amt[2]; /* Mod Source to LFO 1 Rate amount*/
unsigned char S1_Lfo1_A[2];/* Mod Source to LFO 1 Amt pointer*/
unsigned char S1_Lfo1_A_Amt[2];/* Mod Source to LFO 1 Amt amount*/
unsigned char Lfo2_Rate[2];/* LFO 2 Rate*/
unsigned char Lfo2_Amt[2];/* LFO 2 Amount*/
unsigned char Lfo2_Delay[2];/* LFO 2-Delay*/
unsigned char Lfo2_Fade[2];/* LFO 2-Fade in*/
unsigned char Lfo2_Shape[2];/* LFO 2-Shape (bits 0-6)1-127*/
                            /* LFO 2 Sync (bit 7) */
                            /* 1 = Sync on */
                            /* 0 = Sync off*/
unsigned char S1_Lfo2_R[2];/* Mod Source to LFO 1 Rate pointer*/
unsigned char S1_Lfo2_R_Amt[2];/* Mod Source to LFO 2 Rate amount*/
unsigned char S1_Lfo2_A[2];/* Mod Source to LFO 2 Amt pointer*/
unsigned char S1_Lfo2_A_Amt[2];/* Mod Source to LFO 1 Amt amount*/
unsigned char EG_Rate1[2];/* Envelope 1 Rate 1 */
unsigned char EG_Rate2[2];/* Envelope 1 Rate 2 */
unsigned char EG_Rate3[2];/* Envelope 1 Rate 3 */
unsigned char EG_Rate4[2];/* Envelope 1 Rate 4 */
unsigned char EG_Level0[2];/* Envelope 1 Level 0 */
unsigned char EG_Level1[2];/* Envelope 1 Level 1 */
unsigned char EG_Level2[2];/* Envelope 1 Level 2 */
unsigned char EG_Level3[2];/* Envelope 1 Level 3 */
unsigned char EG_Level4[2];/* Envelope 1 Level 4 */
unsigned char Vel_EG_A[2];/* Velocity to Env1 Amount Amt */
unsigned char AEG_Rate1[2];/* Amplitude Envelope Rate 1 */
unsigned char AEG_Rate2[2];/* Amplitude Envelope Rate 2 */
unsigned char AEG_Rate3[2];/* Amplitude Envelope Rate 3 */
unsigned char AEG_Rate4[2];/* Amplitude Envelope Rate 4 */
unsigned char AEG_Level0[2];/* Amplitude Envelope Level 0 */
unsigned char AEG_Level1[2];/* Amplitude Envelope Level 1 */
unsigned char AEG_Level2[2];/* Amplitude Envelope Level 2 */
unsigned char AEG_Level3[2];/* Amplitude Envelope Level 3 */
unsigned char Pitch_Mac[2];/* Pitch Macro number*/
unsigned char Fil_Mac[2];/* Filter Macro number*/
unsigned char Amp_Mac[2];/* Amplitude Envelope Macro number*/
unsigned char Pan_Mac[2];/* Pan Macro number*/
unsigned char Env_Mac[2];/* Envelope 1 macro number*/
unsigned char Pw_Range[2];/* Pitchwheel Range */
unsigned char S1_Pitch[2];/* Modulation Source 1 to Pitch pointer*/
unsigned char S1_Pitch_Amt[2];/* Modulation Source 1 to Pitch Amount*/
unsigned char S2_Pitch[2];/* Modulation Source 2 to Pitch pointer*/
unsigned char S2_Pitch_Amt[2];/* Modulation Source 2 to Pitch Amount*/
unsigned char Key_Filter[2];/* Keyboard to Filter Cutoff Amount*/
unsigned char S1_Filter[2];/* Modulation Source 1 to Filter pointer*/
unsigned char S1_Filter_Amt[2];/* Modulation Source 1 to Filter Amount*/
unsigned char S2_Filter[2];/* Modulation Source 2 to Filter pointer*/
unsigned char S2_Filter_Amt[2];/* Modulation Source 2 to Filter Amount*/
unsigned char Vel_AEG_A[2];/* Velocity to Amp Env Amount Amount*/
unsigned char Vel_AEG_R[2];/* Velocity To Amp Env Attack Rate Amt*/
unsigned char Key_AEG_R[2];/* Keyboard to Amp Env Decay Rate Amt*/
unsigned char S1_Amp[2];/* Modulation Source 1 to Amp pointer*/
unsigned char S1_Amp_Amt[2];/* Modulation Source 1 to Amp Amount*/
unsigned char S2_Amp[2];/* Modulation Source 2 to Amp pointer*/
unsigned char S2_Amp_Amt[2];/* Modulation Source 2 to Amp Amount*/
unsigned char Key_Pan_Amt[2];/* Keyboard to Pan Amount*/
unsigned char Vel_Pan_Amt[2];/* Velocity to Pan Amount*/
unsigned char Cutoff[2];/* Filter Cutoff value */
unsigned char Filter_Exciter[2];/* Filter Exciter value */
unsigned char Vel_EG_R[2];/* Velocity to ENV1 rate amount*/
unsigned char Key_EG_R[2];/* Keyboard to ENV1 rate amount*/
unsigned char PEG_Amt[2];/* Pitch Ramp amount*/
unsigned char PEG_Rate[2];/* Pitch Ramp rate*/
unsigned char Vel_PEG_A[2];/* Velocity to pitch ramp amount */
unsigned char Indiv_Level[2];/* Velocity to pitch ramp rate amount*/
long   Lfo1_Inc[2];/* Lfo fade in amount increment*/
long   Lfo2_Inc[2];/* Lfo fade in amount increment*/
unsigned char Patch_Output[2];/* Individual output routing */
unsigned char Wave_Num_Exp[2];/* Wave number expansion to access 
      Expansion PCM data (Waves numbered 397 and over). This number is added 
      to the value of Wave_Num to determine the actual wave number.*/
} ;


/*Patch data structure*/
struct s_patch
{
char Patch_Name[NAME_SIZE];/* Patch name up to 16 characters*/
unsigned char Mix_Rate1[2];/* Mix envelope rate for segment 1 */ 
unsigned char Mix_Rate2[2]; /* Mix envelope rate for segment 2 */ 
unsigned char Mix_Rate3[2]; /* Mix envelope rate for segment 3 */ 
unsigned char Mix_Rate4[2]; /* Mix envelope rate for segment 4 */ 
unsigned short Mix_Count1[2]; /* Number of update cycles for env seg*/ 
unsigned short Mix_Count2[2]; /* Number of update cycles for env seg*/ 
unsigned short Mix_Count3[2]; /* Number of update cycles for env seg*/ 
unsigned short Mix_Count3B[2];/* Number of update cycles for env seg*/ 
unsigned short Mix_Count2B[2];/* Number of update cycles for env seg*/ 
unsigned short Mix_Count1B[2];/* Number of update cycles for env seg*/ 
unsigned short Mix_Count4[2]; /* Number of update cycles for env seg*/
long   Mix_XSlope1[2];/* Increment size for env seg 1 */ 
long   Mix_XSlope2[2];/* Increment size for env seg 2 */ 
long   Mix_XSlope3[2];/* Increment size for env seg 3 */
long   Mix_XSlope4[2];/* Increment size for env seg 4 */
long   Mix_YSlope1[2];/* Increment size for env seg 1 */
long   Mix_YSlope2[2];/* Increment size for env seg 2 */
long   Mix_YSlope3[2];/* Increment size for env seg 3 */ 
long   Mix_YSlope4[2];/* Increment size for env seg 4 */
unsigned char Mix_X0[2];/* Mix Envelope Point 0 level */
unsigned char Mix_X1[2];/* Mix Envelope Point 1 level */
unsigned char Mix_X2[2];/* Mix Envelope Point 2 level */
unsigned char Mix_X3[2];/* Mix Envelope Point 3 level */
unsigned char Mix_X4[2];/* Mix Envelope Point 4 level */
unsigned char Mix_Y0[2];/* Mix Envelope Point 0 level */
unsigned char Mix_Y1[2];/* Mix Envelope Point 1 level */
unsigned char Mix_Y2[2];/* Mix Envelope Point 2 level */
unsigned char Mix_Y3[2];/* Mix Envelope Point 3 level */
unsigned char Mix_Y4[2];/* Mix Envelope Point 4 level */
unsigned char Mix_Repeats[2];/* Number of repeats of mix envelope*/
unsigned char Mix_Env_Loop[2];/* Start segment of Mix Envelope loops*/
unsigned char S1_MixAC[2];/* Modulation Source 1 to MixAC pointer*/
unsigned char S1_MixAC_Amt[2];/* Modulation Source 1 to MixAC Amount*/
unsigned char S2_MixAC[2]; /* Modulation Source 2 to MixAC pointer*/
unsigned char S2_MixAC_Amt[2];/* Modulation Source 2 to MixAC Amount*/
unsigned char S1_MixBD[2]; /* Modulation Source 1 to MixBD pointer*/
unsigned char S1_MixBD_Amt[2];/* Modulation Source 1 to MixBD Amount*/
unsigned char S2_MixBD[2]; /* Modulation Source 2 to MixBD pointer*/
unsigned char S2_MixBD_Amt[2];/* Modulation Source 2 to MixBD Amount*/
unsigned char Number_Of_Waves[2];/* Number of WAVES/WAVESEQS in Patch*/
unsigned char Hard_Sync[2]; /* Hard Sync Flag*/
unsigned char Bank_Exp[2]; /* Bit 7 = 1[2]; Second Exp Bit set for Wave D 
                                  if Wave_Bank = 0 --> Wave D uses ROM7 wseq
                                  if Wave_Bank = 1 --> Wave D uses ROM8 wseq
                                  if Wave_Bank = 2 --> Wave D uses ROM9 wseq
                                  if Wave_Bank = 3 --> Wave D uses ROM10 wseq*
                      /* Bit 6 = 1[2];  Second Exp Bit set for Wave C 
                                  if Wave_Bank = 0 --> Wave C uses ROM7 wseq
                                  if Wave_Bank = 1 --> Wave C uses ROM8 wseq
                                  if Wave_Bank = 2 --> Wave C uses ROM9 wseq
                                  if Wave_Bank = 3 --> Wave C uses ROM10 wseq*
                      /* Bit 5 = 1[2];  Second Exp Bit set for Wave B 
                                  if Wave_Bank = 0 --> Wave B uses ROM7 wseq
                                  if Wave_Bank = 1 --> Wave B uses ROM8 wseq
                                  if Wave_Bank = 2 --> Wave B uses ROM9 wseq
                                  if Wave_Bank = 3 --> Wave B uses ROM10 wseq*
                      /* Bit 4 = 1[2];  Second Exp Bit set for Wave A 
                                  if Wave_Bank = 0 --> Wave A uses ROM7 wseq
                                  if Wave_Bank = 1 --> Wave A uses ROM8 wseq
                                  if Wave_Bank = 2 --> Wave A uses ROM9 wseq
                                  if Wave_Bank = 3 --> Wave A uses ROM10 wseq*
                      /* Bit 3 = 1[2];  First Exp Bit set for Wave D 
                                  if Wave_Bank = 0 --> Wave D uses ROM4 wseq
                                  if Wave_Bank = 1 --> Wave D uses ROM5 wseq
                                  if Wave_Bank = 2 --> Wave D uses RAM3 wseq
                                  if Wave_Bank = 3 --> Wave D uses ROM6 wseq *
                      /* Bit 2 = 1[2];  First Exp Bit set for Wave C 
                                  if Wave_Bank = 0 --> Wave C uses ROM4 wseq
                                  if Wave_Bank = 1 --> Wave C uses ROM5 wseq
                                  if Wave_Bank = 2 --> Wave C uses RAM3 wseq
                                  if Wave_Bank = 3 --> Wave C uses ROM6 wseq*/
                      /* Bit 1 = 1[2];  First Exp Bit set for Wave B 
                                  if Wave_Bank = 0 --> Wave B uses ROM4 wseq
                                  if Wave_Bank = 1 --> Wave B uses ROM5 wseq
                                  if Wave_Bank = 2 --> Wave B uses RAM3 wseq
                                  if Wave_Bank = 3 --> Wave B uses ROM6 wseq *
                      /* Bit 0 = 1[2];  First Exp Bit set for Wave A 
                                  if Wave_Bank = 0 --> Wave A uses ROM4 wseq
                                  if Wave_Bank = 1 --> Wave A uses ROM5 wseq
                                  if Wave_Bank = 2 --> Wave A uses RAM3 wseq
                                  if Wave_Bank = 3 --> Wave A uses ROM6 wseq */
		
unsigned char Dummy141[2]; /* Extra for future use */
struct s_indiv waveA;/* Individual parameters for WAVE A */
struct s_indiv waveB;/* Individual parameters for WAVE B */
struct s_indiv waveC;/* Individual parameters for WAVE C */
struct s_indiv waveD;/* Individual parameters for WAVE D */
} patch;


// ---------------------- w a v e --------------------------- //

/* This is repeated for the number of wave sequences in the bank. */
struct s_waveseq
{
unsigned char WS_Link[4]; /* Pointer to Wave Sequence Start Step unsigned short*/
unsigned char WS_Slink[4];/* Pointer to Startmod Start Step unsigned short*/
unsigned char WS_Loop_Start[2]; /* Step number of WAVESEQ Loop Start Point step*/
unsigned char WS_Loop_End[2];/* Step number of WAVESEQ Loop End Point step*/
unsigned char WS_Loop_Count[2];/* - Loop repeat count (bits 0-6)1-127*/
                        			/* O=OFF     */
                        			/* 127=1NF */
                        			/*Loop Direction (bit 7)*/
                        			/* O = FOR */
                        			/* 1 = B/F      */
unsigned char WS_Start_Step[2];/* Startmod starting step number*/
unsigned char WS_Mod_Src[2];/* Controller number to use for startmod */
unsigned char WS_Mod_Amt[2];/* Startmod sensitivity */
unsigned char WS_Dyno_Mod[4];/* (Total_Time * Mod_Amt)/255 unsigned short*/
unsigned char WS_Start_Time[4];/* Cumulative time up to start step unsigned short*/
unsigned char WS_Time[4];/* Total time of Wave Sequence unsigned short*/
} ;

/* Data structure of each STEP in a WAVE SEQUENCE  */
struct s_wavestep
{
unsigned short WS_Flink[2];/* Step number of step in WAVSEQ after this one unsigned short*/
unsigned short WS_Blink[2];/* Step number of step in WAVSEQ before this one */
unsigned short WS_Llink[2];/* Pointer to loop start (0xFFFF except last step) */
unsigned short WS_Wave_Num[2];/* Wave number of this step in wave sequence */
unsigned char WS_Coarse[2];/* -24 to 24: Coarse tuning of wave */
                    			/* 25 to 47: illegal values
                    			48 to 96: subtract 72 for actual coarse
                    			tuning and use expanded PCM, adding 365
                    			to WS_Wave_Num value for actual PCM wave
                    			number. */
unsigned char WS_Fine[2];/* Fine tuning of wave */
unsigned short WS_Xfade[2];/* Crossfade time of wave */
unsigned short WS_Duration[2];/* Duration of wave */
unsigned char WS_Level[2];/* Level of wave */
unsigned char WS_Mod_Index[2];/* Modulation Index */
} ;

struct s_ws_name
{
char Wave_Seq_Name[NAME_SIZE_WAVE];
} ;

/* This is the entire structure which is transmitted */
struct s_ws_block
{
struct s_waveseq waveseq_block[32];/* 32 waveseq locations */
struct s_wavestep wavestep_block[501];/* 501 wave seq steps */
struct s_ws_name ws_name_block[32];/* 32 wave seq names */
} ws_block;

