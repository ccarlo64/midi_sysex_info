#include <cstdlib.h>
#include <iostream.h>


#define  NAME_SIZE      32
#define  NAME_SIZE_WAVE      16

unsigned char    Nibble_Decode( unsigned char byte_h, unsigned char byte_l );

struct a
{
    unsigned char   status_byte;
    unsigned char   korg_id;
    unsigned char   channel_number;
    unsigned char   device_id;
    unsigned char   message_type;
} header_sysex;

struct aaa
{
    unsigned char   bank_number;
} parameter_bank_number;

struct d
{
    unsigned char check;
    unsigned char fine; //f7
} finefile;      

int main(int argc, char *argv[])
{

    int      i;
    unsigned char carattere;
    int x;

    size_t   n_byte;
    FILE     *fp,*fpr;

    if (argc != 2)
       {
       printf("\nVersion 0\nUse: %s filename.ext\n", argv[0]);
       exit(0);
       }

    n_byte = 0;

    fpr = fopen(argv[1],"rb");   
    if (fpr!=NULL)
    {
         printf("\nreading file.... < %s >\n", argv[1]);
    }
    else
    {
        printf("\nfile not found...");
        return 1;
    }

    
      

    int np;
    np=0;
    char filen[12];
    
//    while (!feof(fpr))
//    {
    np++;
    sprintf(filen,"t3_%3.3d.syx", np);
    fp = fopen(filen,"wb");    
        
    printf("\n");
    
    header_sysex.status_byte = 0xf0;
    header_sysex.korg_id = 0x42;
    header_sysex.channel_number = 0x30; 
    header_sysex.device_id = 0x26;
    header_sysex.message_type = 0x4d;
    n_byte = fwrite(&header_sysex, sizeof(header_sysex), 1, fp);
    printf("\nscritti ... %5.5d", n_byte);

    parameter_bank_number.bank_number = 0x00;
    n_byte = fwrite(&parameter_bank_number, sizeof(parameter_bank_number), 1, fp);
    printf("\nscritti ... %5.5d", n_byte);
    

    unsigned char nib;
    unsigned char dumm[2];
//    while (!feof(fpr))
    unsigned char cp;
    cp = 0;
    int cc;
    fseek(fpr, 8, SEEK_SET);
// 14179
    int ii=0;
    unsigned char bitti;
      fread(&bitti, 1, 1, fpr);      
cc=0;
//for(cc=0;cc<100;cc++)
//{
    while (!feof(fpr))
    {                       
//        for(ii=0;ii<1771;ii++)
    //    {      
          ii++;
            printf("\nblocco %d > ",ii);  
            int c7=0;
            for(c7=0;c7<7;c7++)
            {

                fread(&nib, 1, 1, fpr);
                cp=nib;        
cp = cp | ( (bitti<<(7-c7)) & 0x80);
                fwrite(&cp, sizeof(cp), 1, fp);  
                printf("%2.2x ", cp);              
            }
            n_byte = fread(&bitti, 1, 1, fpr);
        } 
      printf("\n");              
 //   }

   
    cp = 0xf7;
    
    printf("\n");
    n_byte = fwrite(&cp, sizeof(cp), 1, fp);        
    printf("\nscritti ... %5.5d", n_byte);        

        n_byte = fread(&nib, 1, 1, fpr);
        n_byte = fread(&nib, 1, 1, fpr);
/*
        n_byte = fread(&nib, 1, 1, fpr);
        n_byte = fread(&nib, 1, 1, fpr);
        n_byte = fread(&nib, 1, 1, fpr);
        n_byte = fread(&nib, 1, 1, fpr);
*/

    fclose(fp);
//    }

    if (fpr!=NULL)
    {
         fclose(fpr);

    }

    return EXIT_SUCCESS;
}

unsigned char    Nibble_Decode( unsigned char byte_h, unsigned char byte_l )
{
    unsigned char carattere;
    carattere = 16*(byte_h & 0x0f) + (byte_l & 0x0f);    
    return carattere;
}   

