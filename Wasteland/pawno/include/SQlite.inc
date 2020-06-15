/*
        SA-MP "rBits" Include
        Copyright © 2011 RyDeR`
*/
 
#if defined _Included_rBits
        #endinput
#endif
 
#define _Included_rBits
 
#define BIT_TAGS \
        { Bit1, Bit2, Bit4, Bit8, Bit16 }
        
enum e_Bits
{
        Bit1,
        Bit2,
        Bit4,
        Bit8,
        Bit16,
        Bit32
};
 
#define Bit1:%0<%1> \
        Bit1: %0[((%1) + 31) >>> _: Bit32]
        
#define Bit1_Set(%0,%1,%2) \
        Bit_Set(%0, (%1), (%2), Bit1)
        
#define Bit1_Get(%0,%1) \
        Bit_Get(%0, (%1), Bit1)
 
#define Bit2:%0<%1> \
        Bit2: %0[((%1) + 15) >>> _: (Bit32 - Bit2)]
        
#define Bit2_Set(%0,%1,%2) \
        Bit_Set(%0, (%1), (%2), Bit2)
        
#define Bit2_Get(%0,%1) \
        Bit_Get(%0, (%1), Bit2)
 
#define Bit4:%0<%1> \
        Bit4: %0[((%1) + 7) >>> _: (Bit32 - Bit4)]
        
#define Bit4_Set(%0,%1,%2) \
        Bit_Set(%0, (%1), (%2), Bit4)
        
#define Bit4_Get(%0,%1) \
        Bit_Get(%0, (%1), Bit4)
 
#define Bit8:%0<%1> \
        Bit8: %0[(%1) char]
        
#define Bit8_Set(%0,%1,%2) \
        (_: %0{(%1)} = (%2))
        
#define Bit8_Get(%0,%1) \
        (_: %0{(%1)})
 
#define Bit16:%0<%1> \
        Bit16: %0[((%1) + 1) >>> _: (Bit32 - Bit16)]
        
#define Bit16_Set(%0,%1,%2) \
        Bit_Set(%0, (%1), (%2), Bit16)
        
#define Bit16_Get(%0,%1) \
        Bit_Get(%0, (%1), Bit16)
        
stock Bit_Set(BIT_TAGS: bitArr[], arrIdx, value, e_Bits: bitShift, arrSize = sizeof(bitArr))
{
        new
                bitVar = ((arrIdx & ((1 << _: (Bit32 - bitShift)) - 1)) << _: bitShift),
                bitLim = ((1 << (1 << _: bitShift)) - 1)
        ;
        if(!(0 <= (arrIdx >>>= _: (Bit32 - bitShift)) < arrSize))
                return 0;
        
        (_: bitArr[arrIdx]) &= ~(bitLim << bitVar);
        (_: bitArr[arrIdx]) |= ((bitLim & value) << bitVar);
        
        return 1;
}
 
stock Bit_Get(BIT_TAGS: bitArr[], arrIdx, e_Bits: bitShift, arrSize = sizeof(bitArr))
{
        new
                bitVar = ((arrIdx & ((1 << _: (Bit32 - bitShift)) - 1)) << _: bitShift),
                bitLim = ((1 << (1 << _: bitShift)) - 1)
        ;
        if(!(0 <= (arrIdx >>>= _: (Bit32 - bitShift)) < arrSize))
                return 0;
        
        return ((_: bitArr[arrIdx] >>> bitVar) & bitLim);
}