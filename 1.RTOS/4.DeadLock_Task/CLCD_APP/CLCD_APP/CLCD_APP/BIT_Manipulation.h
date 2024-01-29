/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: LIB                ****************/
/*************       Component: BitManipulation****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef BitManipulation_H_
#define BitManipulation_H_

#define Register_Size                                     8
										              
#define Mask(Bit)                                            (1<<Bit) 
#define SET_BIT(Reg,Bit)                                 Reg|=Mask(Bit)                        
#define CLEAR_BIT(Reg,Bit)                               Reg&= (~Mask(Bit))  
#define TOGGLE_BIT(Reg,Bit)                              Reg^=Mask(Bit)    
										              
										              
#define GET_BIT(Reg,Bit)                                 (Reg&Mask(Bit))>>Bit                    
#define READ_BIT(Reg,Bit)                                Reg&Mask(Bit) 
#define ASSIGN_BIT(Reg,Bit,value)                        Reg=(Reg & (~Mask(Bit)))|(value<<Bit)    

#define BitManipulationSetBits(Reg,offset,width,value)    (Reg & (~((Mask(width)-1)<<offset)))|(value<<offset)

           
#define BIT_IS_SET(Reg,Bit)                   ((Reg&Mask(Bit)) >>Bit)                      
#define BIT_IS_CLEAR(Reg,Bit)                 (!((Reg&Mask(Bit)) >>Bit))    
               
#define ROR(Reg,NUM)                          Reg=(Reg>>NUM)|(Reg<<(Register_Size))
#define ROL(Reg,NUM)                          Reg=(Reg<<NUM)|(Reg>>(Register_Size))

/*****************************************************************************************************/

#define Set_Reg(Reg)                          Reg= 0xff
#define Clr_Reg(Reg)                          Reg = 0x00
#define Toogle_Reg(Reg)                       Reg^=0xff
#define Assign_Reg(Reg,value)                 Reg=value



#endif