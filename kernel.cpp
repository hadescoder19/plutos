#include "types.h"

void printf(char* str)
{
    static unsigned short* VideoMemory=(unsigned short*)0xb8000;
    
    for(int i=0; str[i]!='\0';++i){
        VideoMemory[i]=(VideoMemory[i] & 0xFF00)|str[i];
    }
    
}

typedef void (*constructor)();
extern "C" constructor* start_ctors;
extern "C" constructor* end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i=start_ctors;i!=end_ctors;i++){
        (*i)();
    }
}


extern "C" void kernelMain(void* multiboot_structure, uint32_t magicnumber)
{ 
    printf("This os is still under development. planned release is march 1, 2020. times subject to change. current version: beta 0.2.2");
    while(1);
}