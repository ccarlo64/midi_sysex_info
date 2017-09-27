
unsigned char   LoadMem_Wavestation_4d( int NUMERO_PERFORMANCE, HANDLE hFile, HWND htext, struct s_performance1 *pperf1)
{
char nomemio[50],string_comodo[120];
int cp;
int i;
char a[2];
unsigned char b;
DWORD dwRead;

    for(x=0;x<NUMERO_PERFORMANCE;x++)
    {
        for(i=0;i<sizeof(s_performance1);i++)
        {
            ReadFile(hFile, &a, sizeof(a), &dwRead, NULL);         
            b = Nibble_Decode( a[1], a[0] );
            (pperf1+x)->Perf_Name[i]= b;
        }
    }
    for(x=0;x<NUMERO_PERFORMANCE;x++)
    {
        ii=0;
        for(i=0;i<16;i++)
        {
            sprintf(&nomemio[ii++],"%c", (pperf1+x)->Perf_Name[i]);
        }
        nomemio[ii]='\0';
        sprintf(string_comodo,"%2.2d %s",x,nomemio);
        SendMessage(htext, LB_ADDSTRING, 0, (LPARAM)string_comodo);
    }
    cp = 0;
    
    //for(i=0;i<tot_byte;i++)
    //cp = cp + pperf->Perf_Name[i];
    
    return cp;
}
   
   
unsigned char   LoadMem_Wavestation_4c( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_patch1 *ppatch1)
{
char nomemio[50],string_comodo[120];
int cp;
int i;
char a[2];
unsigned char b;
DWORD dwRead;


    for(x=0;x<NUMERO_PATCH;x++)
    {
        for(i=0;i<sizeof(s_patch1);i++)
        {
            ReadFile(hFile, &a, sizeof(a), &dwRead, NULL);         
            b = Nibble_Decode( a[1], a[0] );
            (ppatch1+x)->Patch_Name[i]= b;
        }
    }
    for(x=0;x<NUMERO_PATCH;x++)
    {
        ii=0;
        for(i=0;i<16;i++)
        {
            sprintf(&nomemio[ii++],"%c", (ppatch1+x)->Patch_Name[i]);
        }
        nomemio[ii]='\0';
        sprintf(string_comodo,"%2.2d %s",x,nomemio);
        SendMessage(htext, LB_ADDSTRING, 0, (LPARAM)string_comodo);
    }
    cp = 0;
    /*
    for(i=0;i<tot_byte;i++)
    cp = cp + pperf->Perf_Name[i];
    */
    return cp;
}
     
unsigned char   LoadMem_Wavestation_54( int nn, HANDLE hFile, HWND htext, struct s_ws_block ws_block)
{
char nomemio[50],string_comodo[120];
unsigned char cp;
int tot_byte;
DWORD dwRead;

ReadFile(hFile, &ws_block, sizeof(ws_block), &dwRead, NULL);         
cp = 0;
for(i=0;i<sizeof(ws_block);i++)
    cp = cp + (unsigned char)ws_block.waveseq_block[0].WS_Link[i];

for(x=0;x<NUMERO_WAVE;x++)
{
    ii=0;
    for(i=0;i<NAME_SIZE_WAVE;i=i+2)
    {
        sprintf(&nomemio[ii++],"%c", Nibble_Decode( ws_block.ws_name_block[x].Wave_Seq_Name[i+1], ws_block.ws_name_block[x].Wave_Seq_Name[i] ));
    }
    nomemio[ii]='\0';

    sprintf(string_comodo,"%2.2d %s",x,nomemio);
    SendMessage(htext, LB_ADDSTRING, 0, (LPARAM)string_comodo);
}
return cp;
}


void Patch_print_detail(struct s_patch1 *ppatch1, int x, char *string_comodo)
{
Insert_text(hDetail, string_comodo, true);
}

void Performance_print_detail(struct s_performance1 *pperf, int x, char *string_comodo)
{
Insert_text(hDetail, "PATCH ========> ", false);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - normal bank number %3.3d",(pperf+x)->pp[i].Bank_Num);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - volume level %d", (pperf+x)->pp[i].Level);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - output chan for this patch %d", (pperf+x)->pp[i].Output);
Insert_text(hDetail, string_comodo, true);
unsigned char carattere = (pperf+x)->pp[i].Part_Mode;
sprintf(string_comodo," - part mode %s%s %s%s %s%s %s%s",
            ( ((carattere & 0x80) == 0 )? "0" : "1" ),
            ( ((carattere & 0x40) == 0 )? "0" : "1" ),
            ( ((carattere & 0x20) == 0 )? "0" : "1" ),
            ( ((carattere & 0x10) == 0 )? "0" : "1" ),
            ( ((carattere & 0x08) == 0 )? "0" : "1" ),
            ( ((carattere & 0x04) == 0 )? "0" : "1" ),
            ( ((carattere & 0x02) == 0 )? "0" : "1" ),
            ( ((carattere & 0x01) == 0 )? "0" : "1" )
            );                                                                                    
Insert_text(hDetail, string_comodo, true);

            unsigned char pm[4];
            pm[0] = (carattere >> 6) & 0x03;
            pm[1] = (carattere >> 4) & 0x03;
            pm[2] = (carattere >> 2) & 0x03;
            pm[3] = carattere & 0x03;            
sprintf(string_comodo," --- %s%s %s", ( ((carattere & 0x80) == 0 )? "0" : "1" ),
                                    ( ((carattere & 0x40) == 0 )? "0" : "1" ),
                                    bit_6_7[pm[0]]);
Insert_text(hDetail, string_comodo, false);
unsigned char altro = (pperf+x)->pp[i].Bank_Num;
sprintf(string_comodo," ** %s", bank_decode( pm[0]*4 + altro ));
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," --- %s%s %s",   ( ((carattere & 0x20) == 0 )? "0" : "1" ),
                                ( ((carattere & 0x10) == 0 )? "0" : "1" ),
                                bit_5_4[pm[1]]);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," --- %s%s %s",   ( ((carattere & 0x08) == 0 )? "0" : "1" ),
                                ( ((carattere & 0x04) == 0 )? "0" : "1" ),
                                bit_3_2[pm[2]]);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," --- %s%s %s",   ( ((carattere & 0x02) == 0 )? "0" : "1" ),
                                ( ((carattere & 0x01) == 0 )? "0" : "1" ),
                                bit_1_0[pm[3]]);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Note Lower/Upper %d/%d", (pperf+x)->pp[i].Lo_Key, (pperf+x)->pp[i].Hi_Key);
Insert_text(hDetail, string_comodo, true);
            
sprintf(string_comodo," - Velocity Lower/Upper %d/%d", (pperf+x)->pp[i].Lo_Vel, (pperf+x)->pp[i].Hi_Vel);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Transpose in semitones %d", (pperf+x)->pp[i].Trans);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Detune %d", (pperf+x)->pp[i].Detune);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Micro tuning table %d", (pperf+x)->pp[i].Tunetab);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Root key %d", (pperf+x)->pp[i].Micro_Tune_Key);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Midi out %d", (pperf+x)->pp[i].Midi_Out_Chan);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Midi prog %d", (pperf+x)->pp[i].Midi_Prog_Num);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Sustain pedal %d", (pperf+x)->pp[i].Sus_Enable);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Delay (ms) %d", (pperf+x)->pp[i].Delay[0]*256 + (pperf+x)->pp[i].Delay[1]);
Insert_text(hDetail, string_comodo, true);

}
