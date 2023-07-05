
#include "RandomCard.h"

RandomCard::RandomCard(QWidget*q)
{
    int trynum1=((rand()%45)+7)%44;
    if(trynum1>=0&&trynum1<=3){
        c=new CardButton(new Strike_Red,q);
    }
    if(trynum1>=4&&trynum1<=7){
        c=new CardButton(new Bash,q);
    }
    if(trynum1>=8&&trynum1<=10){
        c=new CardButton(new Pommel_strike_Red,q);
    }
    if(trynum1>=11&&trynum1<=13){
        c=new CardButton(new Shrug_it_off_Red,q);
    }
    if(trynum1>=14&&trynum1<=16){
        c=new CardButton(new True_grit_Red,q);
    }
    if(trynum1>=17&&trynum1<=19){
        c=new CardButton(new Armaments,q);
    }
    if(trynum1>=20&&trynum1<=22){
        c=new CardButton(new Body_slam,q);
    }
    if(trynum1==23||trynum1==24){
        c=new CardButton(new Battle_trance,q);
    }
    if(trynum1==25||trynum1==26){
        c=new CardButton(new Burning_pact,q);
    }
    if(trynum1==27||trynum1==28){
        c=new CardButton(new Inflame_Red,q);
    }
    if(trynum1==29||trynum1==30){
        c=new CardButton(new Spot_weakness_Red,q);
    }
    if(trynum1==31||trynum1==32){
        c=new CardButton(new Dark_embrace,q);
    }
    if(trynum1==33||trynum1==34){
        c=new CardButton(new Second_wind_Red,q);
    }
    if(trynum1==35||trynum1==36){
        c=new CardButton(new Feel_no_pain,q);
    }
    if(trynum1==37||trynum1==38){
        c=new CardButton(new Whirlwind_Red,q);
    }
    if(trynum1==39){
        c=new CardButton(new Corruption,q);
    }
    if(trynum1==40){
        c=new CardButton(new Demon_form,q);
    }
    if(trynum1==41){
        c=new CardButton(new Offering_Red,q);
    }
    if(trynum1==42){
        c=new CardButton(new Barricade,q);
    }
    if(trynum1==43){
        c=new CardButton(new Limit_break_Red,q);
    }
    if(trynum1==44){
        c=new CardButton(new Exhume,q);
    }
}

