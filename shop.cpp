#include "shop.h"
#include "ui_shop.h"
#include "mainwindow.h"
#include "map.h"
#include "stdlib.h"
#include "time.h"
#include "cardbutton.h"
#include "game/cards/red/Armaments.h"
#include "game/cards/red/Strike_Red.h"
#include "game/cards/red/Bash.h"
#include "game/cards/red/Pommel_strike_Red.h"
#include "game/cards/red/Shrug_it_off_Red.h"
#include "game/cards/red/True_grit_Red.h"
#include "game/cards/red/Armaments.h"
#include "game/cards/red/Body_slam.h"
#include "game/cards/red/Battle_trance.h"
#include "game/cards/red/Burning_pact.h"
#include "game/cards/red/Inflame_Red.h"
#include "game/cards/red/Spot_weakness_Red.h"
#include "game/cards/red/Dark_embrace.h"
#include "game/cards/red/Second_wind_Red.h".h"
#include "game/cards/red/Feel_no_pain.h"
#include "game/cards/red/Whirlwind_Red.h"
#include "game/cards/red/Corruption.h"
#include "game/cards/red/Demon_form.h"
#include "game/cards/red/Offering_Red.h"
#include "game/cards/red/Barricade.h"
#include "game/cards/red/Limit_break_Red.h"
#include "game/cards/red/Exhume.h"

using namespace std;
int cardinsells[7];
Shop::Shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
    move(0,50);

    mw = (MainWindow*)parentWidget();
    int trynum1=((rand()%45)+7)%44;
    if(trynum1>=0&&trynum1<=3){
            CardButton* strike1=new CardButton(new Strike_Red,this);
        }
    if(trynum1>=4&&trynum1<=7){
            CardButton* bash1=new CardButton(new Bash,this);
        }
    if(trynum1>=8&&trynum1<=10){
            CardButton* pommel1=new CardButton(new Pommel_strike_Red,this);
        }
    if(trynum1>=11&&trynum1<=13){
            CardButton* shrug1=new CardButton(new Shrug_it_off_Red,this);
        }
    if(trynum1>=14&&trynum1<=16){
            CardButton* true1=new CardButton(new True_grit_Red,this);
        }
    if(trynum1>=17&&trynum1<=19){
            CardButton* armaments1=new CardButton(new Armaments,this);
        }
    if(trynum1>=20&&trynum1<=22){
            CardButton* bodyslam1=new CardButton(new Body_slam,this);
        }
    if(trynum1==23||trynum1==24){
            CardButton* battletrance1=new CardButton(new Battle_trance,this);
        }
    if(trynum1==25||trynum1==26){
            CardButton* Burning_pact1=new CardButton(new Burning_pact,this);
        }
    if(trynum1==27||trynum1==28){
            CardButton* Inflame_Red1=new CardButton(new Inflame_Red,this);
        }
    if(trynum1==29||trynum1==30){
            CardButton* Spot_weakness1=new CardButton(new Spot_weakness_Red,this);
        }
    if(trynum1==31||trynum1==32){
            CardButton* Dark_embrace1=new CardButton(new Dark_embrace,this);
        }
    if(trynum1==33||trynum1==34){
            CardButton* Second_wind_Red1=new CardButton(new Second_wind_Red,this);
        }
    if(trynum1==35||trynum1==36){
            CardButton* feel_no_pain1=new CardButton(new Feel_no_pain,this);
        }
    if(trynum1==37||trynum1==38){
            CardButton* Whirlwind_Red1=new CardButton(new Whirlwind_Red,this);
        }
    if(trynum1==39){
            CardButton* Corruption1=new CardButton(new Corruption,this);
        }
    if(trynum1==40){
            CardButton* Demon_form1=new CardButton(new Demon_form,this);
        }
    if(trynum1==41){
            CardButton* Offering_Red1=new CardButton(new Offering_Red,this);
        }
    if(trynum1==42){
            CardButton* Barricade1=new CardButton(new Barricade,this);
        }
    if(trynum1==43){
            CardButton* Limit_break_Red1=new CardButton(new Limit_break_Red,this);
        }
    if(trynum1==44){
            CardButton* Exhume1=new CardButton(new Exhume,this);
        }
    ///////////////////////此处添加第一个位置的其他代码
    ///
    ///
    ///
        trynum1=((rand()%45)+7)%44;
        if(trynum1>=0&&trynum1<=3){
            CardButton* strike2=new CardButton(new Strike_Red,this);
            strike2->move(220,0);
        }
        if(trynum1>=4&&trynum1<=7){
            CardButton* bash2=new CardButton(new Bash,this);
            bash2->move(220,0);
        }
        if(trynum1>=8&&trynum1<=10){
            CardButton* pommel2=new CardButton(new Pommel_strike_Red,this);
            pommel2->move(220,0);
        }
        if(trynum1>=11&&trynum1<=13){
            CardButton* shrug2=new CardButton(new Shrug_it_off_Red,this);
            shrug2->move(220,0);
        }
        if(trynum1>=14&&trynum1<=16){
            CardButton* true2=new CardButton(new True_grit_Red,this);
            true2->move(220,0);
        }
        if(trynum1>=17&&trynum1<=19){
            CardButton* armaments2=new CardButton(new Armaments,this);
            armaments2->move(220,0);
        }
        if(trynum1>=20&&trynum1<=22){
            CardButton* bodyslam2=new CardButton(new Body_slam,this);
            bodyslam2->move(220,0);
        }
        if(trynum1==23||trynum1==24){
            CardButton* battletrance2=new CardButton(new Battle_trance,this);
            battletrance2->move(220,0);
        }
        if(trynum1==25||trynum1==26){
            CardButton* Burning_pact2=new CardButton(new Burning_pact,this);
            Burning_pact2->move(220,0);
        }
        if(trynum1==27||trynum1==28){
            CardButton* Inflame_Red2=new CardButton(new Inflame_Red,this);
            Inflame_Red2->move(220,0);
        }
        if(trynum1==29||trynum1==30){
            CardButton* Spot_weakness2=new CardButton(new Spot_weakness_Red,this);
            Spot_weakness2->move(220,0);
        }
        if(trynum1==31||trynum1==32){
            CardButton* Dark_embrace2=new CardButton(new Dark_embrace,this);
            Dark_embrace2->move(220,0);
        }
        if(trynum1==33||trynum1==34){
            CardButton* Second_wind_Red2=new CardButton(new Second_wind_Red,this);
            Second_wind_Red2->move(220,0);
        }
        if(trynum1==35||trynum1==36){
            CardButton* feel_no_pain2=new CardButton(new Feel_no_pain,this);
            feel_no_pain2->move(220,0);
        }
        if(trynum1==37||trynum1==38){
            CardButton* Whirlwind_Red2=new CardButton(new Whirlwind_Red,this);
            Whirlwind_Red2->move(220,0);
        }
        if(trynum1==39){
            CardButton* Corruption2=new CardButton(new Corruption,this);
            Corruption2->move(220,0);
        }
        if(trynum1==40){
            CardButton* Demon_form2=new CardButton(new Demon_form,this);
            Demon_form2->move(220,0);
        }
        if(trynum1==41){
            CardButton* Offering_Red2=new CardButton(new Offering_Red,this);
            Offering_Red2->move(220,0);
        }
        if(trynum1==42){
            CardButton* Barricade2=new CardButton(new Barricade,this);
            Barricade2->move(220,0);
        }
        if(trynum1==43){
            CardButton* Limit_break_Red2=new CardButton(new Limit_break_Red,this);
            Limit_break_Red2->move(220,0);
        }
        if(trynum1==44){
            CardButton* Exhume2=new CardButton(new Exhume,this);
            Exhume2->move(220,0);
        }
        ///////////////////////此处添加第二个位置的其他代码
        ///
        ///
        ///

        trynum1=((rand()%45)+7)%44;
        if(trynum1>=0&&trynum1<=3){
            CardButton* strike3=new CardButton(new Strike_Red,this);
            strike3->move(440,0);
        }
        if(trynum1>=4&&trynum1<=7){
            CardButton* bash3=new CardButton(new Bash,this);
            bash3->move(440,0);
        }
        if(trynum1>=8&&trynum1<=10){
            CardButton* pommel3=new CardButton(new Pommel_strike_Red,this);
            pommel3->move(440,0);
        }
        if(trynum1>=11&&trynum1<=13){
            CardButton* shrug3=new CardButton(new Shrug_it_off_Red,this);
            shrug3->move(440,0);
        }
        if(trynum1>=14&&trynum1<=16){
            CardButton* true3=new CardButton(new True_grit_Red,this);
            true3->move(440,0);
        }
        if(trynum1>=17&&trynum1<=19){
            CardButton* armaments3=new CardButton(new Armaments,this);
            armaments3->move(440,0);
        }
        if(trynum1>=20&&trynum1<=22){
            CardButton* bodyslam3=new CardButton(new Body_slam,this);
            bodyslam3->move(440,0);
        }
        if(trynum1==23||trynum1==24){
            CardButton* battletrance3=new CardButton(new Battle_trance,this);
            battletrance3->move(440,0);
        }
        if(trynum1==25||trynum1==26){
            CardButton* Burning_pact3=new CardButton(new Burning_pact,this);
            Burning_pact3->move(440,0);
        }
        if(trynum1==27||trynum1==28){
            CardButton* Inflame_Red3=new CardButton(new Inflame_Red,this);
            Inflame_Red3->move(440,0);
        }
        if(trynum1==29||trynum1==30){
            CardButton* Spot_weakness3=new CardButton(new Spot_weakness_Red,this);
            Spot_weakness3->move(440,0);
        }
        if(trynum1==31||trynum1==32){
            CardButton* Dark_embrace3=new CardButton(new Dark_embrace,this);
            Dark_embrace3->move(440,0);
        }
        if(trynum1==33||trynum1==34){
            CardButton* Second_wind_Red3=new CardButton(new Second_wind_Red,this);
            Second_wind_Red3->move(440,0);
        }
        if(trynum1==35||trynum1==36){
            CardButton* feel_no_pain3=new CardButton(new Feel_no_pain,this);
            feel_no_pain3->move(440,0);
        }
        if(trynum1==37||trynum1==38){
            CardButton* Whirlwind_Red3=new CardButton(new Whirlwind_Red,this);
            Whirlwind_Red3->move(440,0);
        }
        if(trynum1==39){
            CardButton* Corruption3=new CardButton(new Corruption,this);
            Corruption3->move(440,0);
        }
        if(trynum1==40){
            CardButton* Demon_form3=new CardButton(new Demon_form,this);
            Demon_form3->move(440,0);
        }
        if(trynum1==41){
            CardButton* Offering_Red3=new CardButton(new Offering_Red,this);
            Offering_Red3->move(440,0);
        }
        if(trynum1==42){
            CardButton* Barricade3=new CardButton(new Barricade,this);
            Barricade3->move(440,0);
        }
        if(trynum1==43){
            CardButton* Limit_break_Red3=new CardButton(new Limit_break_Red,this);
            Limit_break_Red3->move(440,0);
        }
        if(trynum1==44){
            CardButton* Exhume3=new CardButton(new Exhume,this);
            Exhume3->move(440,0);
        }
        ///////////////////////此处添加第三个位置的其他代码
        ///
        ///
        ///
        trynum1=((rand()%45)+7)%44;
        if(trynum1>=0&&trynum1<=3){
            CardButton* strike4=new CardButton(new Strike_Red,this);
            strike4->move(660,0);
        }
        if(trynum1>=4&&trynum1<=7){
            CardButton* bash4=new CardButton(new Bash,this);
            bash4->move(660,0);
        }
        if(trynum1>=8&&trynum1<=10){
            CardButton* pommel4=new CardButton(new Pommel_strike_Red,this);
            pommel4->move(660,0);
        }
        if(trynum1>=11&&trynum1<=13){
            CardButton* shrug4=new CardButton(new Shrug_it_off_Red,this);
            shrug4->move(660,0);
        }
        if(trynum1>=14&&trynum1<=16){
            CardButton* true4=new CardButton(new True_grit_Red,this);
            true4->move(660,0);
        }
        if(trynum1>=17&&trynum1<=19){
            CardButton* armaments4=new CardButton(new Armaments,this);
            armaments4->move(660,0);
        }
        if(trynum1>=20&&trynum1<=22){
            CardButton* bodyslam4=new CardButton(new Body_slam,this);
            bodyslam4->move(660,0);
        }
        if(trynum1==23||trynum1==24){
            CardButton* battletrance4=new CardButton(new Battle_trance,this);
            battletrance4->move(660,0);
        }
        if(trynum1==25||trynum1==26){
            CardButton* Burning_pact4=new CardButton(new Burning_pact,this);
            Burning_pact4->move(660,0);
        }
        if(trynum1==27||trynum1==28){
            CardButton* Inflame_Red4=new CardButton(new Inflame_Red,this);
            Inflame_Red4->move(660,0);
        }
        if(trynum1==29||trynum1==30){
            CardButton* Spot_weakness4=new CardButton(new Spot_weakness_Red,this);
            Spot_weakness4->move(660,0);
        }
        if(trynum1==31||trynum1==32){
            CardButton* Dark_embrace4=new CardButton(new Dark_embrace,this);
            Dark_embrace4->move(660,0);
        }
        if(trynum1==33||trynum1==34){
            CardButton* Second_wind_Red4=new CardButton(new Second_wind_Red,this);
            Second_wind_Red4->move(660,0);
        }
        if(trynum1==35||trynum1==36){
            CardButton* feel_no_pain4=new CardButton(new Feel_no_pain,this);
            feel_no_pain4->move(660,0);
        }
        if(trynum1==37||trynum1==38){
            CardButton* Whirlwind_Red4=new CardButton(new Whirlwind_Red,this);
            Whirlwind_Red4->move(660,0);
        }
        if(trynum1==39){
            CardButton* Corruption4=new CardButton(new Corruption,this);
            Corruption4->move(660,0);
        }
        if(trynum1==40){
            CardButton* Demon_form4=new CardButton(new Demon_form,this);
            Demon_form4->move(660,0);
        }
        if(trynum1==41){
            CardButton* Offering_Red4=new CardButton(new Offering_Red,this);
            Offering_Red4->move(660,0);
        }
        if(trynum1==42){
            CardButton* Barricade4=new CardButton(new Barricade,this);
            Barricade4->move(660,0);
        }
        if(trynum1==43){
            CardButton* Limit_break_Red4=new CardButton(new Limit_break_Red,this);
            Limit_break_Red4->move(660,0);
        }
        if(trynum1==44){
            CardButton* Exhume4=new CardButton(new Exhume,this);
            Exhume4->move(660,0);
        }
        ///////////////////////此处添加第四个位置的其他代码
        ///
        ///
        ///
        trynum1=((rand()%45)+7)%44;
        if(trynum1>=0&&trynum1<=3){
            CardButton* strike5=new CardButton(new Strike_Red,this);
            strike5->move(880,0);
        }
        if(trynum1>=4&&trynum1<=7){
            CardButton* bash5=new CardButton(new Bash,this);
            bash5->move(880,0);
        }
        if(trynum1>=8&&trynum1<=10){
            CardButton* pommel5=new CardButton(new Pommel_strike_Red,this);
            pommel5->move(880,0);
        }
        if(trynum1>=11&&trynum1<=13){
            CardButton* shrug5=new CardButton(new Shrug_it_off_Red,this);
            shrug5->move(880,0);
        }
        if(trynum1>=14&&trynum1<=16){
            CardButton* true5=new CardButton(new True_grit_Red,this);
            true5->move(880,0);
        }
        if(trynum1>=17&&trynum1<=19){
            CardButton* armaments5=new CardButton(new Armaments,this);
            armaments5->move(880,0);
        }
        if(trynum1>=20&&trynum1<=22){
            CardButton* bodyslam5=new CardButton(new Body_slam,this);
            bodyslam5->move(880,0);
        }
        if(trynum1==23||trynum1==24){
            CardButton* battletrance5=new CardButton(new Battle_trance,this);
            battletrance5->move(880,0);
        }
        if(trynum1==25||trynum1==26){
            CardButton* Burning_pact5=new CardButton(new Burning_pact,this);
            Burning_pact5->move(880,0);
        }
        if(trynum1==27||trynum1==28){
            CardButton* Inflame_Red5=new CardButton(new Inflame_Red,this);
            Inflame_Red5->move(880,0);
        }
        if(trynum1==29||trynum1==30){
            CardButton* Spot_weakness5=new CardButton(new Spot_weakness_Red,this);
            Spot_weakness5->move(880,0);
        }
        if(trynum1==31||trynum1==32){
            CardButton* Dark_embrace5=new CardButton(new Dark_embrace,this);
            Dark_embrace5->move(880,0);
        }
        if(trynum1==33||trynum1==34){
            CardButton* Second_wind_Red5=new CardButton(new Second_wind_Red,this);
            Second_wind_Red5->move(880,0);
        }
        if(trynum1==35||trynum1==36){
            CardButton* feel_no_pain5=new CardButton(new Feel_no_pain,this);
            feel_no_pain5->move(880,0);
        }
        if(trynum1==37||trynum1==38){
            CardButton* Whirlwind_Red5=new CardButton(new Whirlwind_Red,this);
            Whirlwind_Red5->move(880,0);
        }
        if(trynum1==39){
            CardButton* Corruption5=new CardButton(new Corruption,this);
            Corruption5->move(880,0);
        }
        if(trynum1==40){
            CardButton* Demon_form5=new CardButton(new Demon_form,this);
            Demon_form5->move(880,0);
        }
        if(trynum1==41){
            CardButton* Offering_Red5=new CardButton(new Offering_Red,this);
            Offering_Red5->move(880,0);
        }
        if(trynum1==42){
            CardButton* Barricade5=new CardButton(new Barricade,this);
            Barricade5->move(880,0);
        }
        if(trynum1==43){
            CardButton* Limit_break_Red5=new CardButton(new Limit_break_Red,this);
            Limit_break_Red5->move(880,0);
        }
        if(trynum1==44){
            CardButton* Exhume5=new CardButton(new Exhume,this);
            Exhume5->move(880,0);
        }
        ///////////////////////此处添加第五个位置的其他代码
        ///
        ///
        ///
        trynum1=((rand()%45)+7)%44;
        if(trynum1>=0&&trynum1<=3){
            CardButton* strike6=new CardButton(new Strike_Red,this);
            strike6->move(0,330);
        }
        if(trynum1>=4&&trynum1<=7){
            CardButton* bash6=new CardButton(new Bash,this);
            bash6->move(0,330);
        }
        if(trynum1>=8&&trynum1<=10){
            CardButton* pommel6=new CardButton(new Pommel_strike_Red,this);
            pommel6->move(0,330);
        }
        if(trynum1>=11&&trynum1<=13){
            CardButton* shrug6=new CardButton(new Shrug_it_off_Red,this);
            shrug6->move(0,330);
        }
        if(trynum1>=14&&trynum1<=16){
            CardButton* true6=new CardButton(new True_grit_Red,this);
            true6->move(0,330);
        }
        if(trynum1>=17&&trynum1<=19){
            CardButton* armaments6=new CardButton(new Armaments,this);
            armaments6->move(0,330);
        }
        if(trynum1>=20&&trynum1<=22){
            CardButton* bodyslam6=new CardButton(new Body_slam,this);
            bodyslam6->move(0,330);
        }
        if(trynum1==23||trynum1==24){
            CardButton* battletrance6=new CardButton(new Battle_trance,this);
            battletrance6->move(0,330);
        }
        if(trynum1==25||trynum1==26){
            CardButton* Burning_pact6=new CardButton(new Burning_pact,this);
            Burning_pact6->move(0,330);
        }
        if(trynum1==27||trynum1==28){
            CardButton* Inflame_Red6=new CardButton(new Inflame_Red,this);
            Inflame_Red6->move(0,330);
        }
        if(trynum1==29||trynum1==30){
            CardButton* Spot_weakness6=new CardButton(new Spot_weakness_Red,this);
            Spot_weakness6->move(0,330);
        }
        if(trynum1==31||trynum1==32){
            CardButton* Dark_embrace6=new CardButton(new Dark_embrace,this);
            Dark_embrace6->move(0,330);
        }
        if(trynum1==33||trynum1==34){
            CardButton* Second_wind_Red6=new CardButton(new Second_wind_Red,this);
            Second_wind_Red6->move(0,330);
        }
        if(trynum1==35||trynum1==36){
            CardButton* feel_no_pain6=new CardButton(new Feel_no_pain,this);
            feel_no_pain6->move(0,330);
        }
        if(trynum1==37||trynum1==38){
            CardButton* Whirlwind_Red6=new CardButton(new Whirlwind_Red,this);
            Whirlwind_Red6->move(0,330);
        }
        if(trynum1==39){
            CardButton* Corruption6=new CardButton(new Corruption,this);
            Corruption6->move(0,330);
        }
        if(trynum1==40){
            CardButton* Demon_form6=new CardButton(new Demon_form,this);
            Demon_form6->move(0,330);
        }
        if(trynum1==41){
            CardButton* Offering_Red6=new CardButton(new Offering_Red,this);
            Offering_Red6->move(0,330);
        }
        if(trynum1==42){
            CardButton* Barricade6=new CardButton(new Barricade,this);
            Barricade6->move(0,330);
        }
        if(trynum1==43){
            CardButton* Limit_break_Red6=new CardButton(new Limit_break_Red,this);
            Limit_break_Red6->move(0,330);
        }
        if(trynum1==44){
            CardButton* Exhume6=new CardButton(new Exhume,this);
            Exhume6->move(0,330);
        }
        ///////////////////////此处添加第六个位置的其他代码
        ///
        ///
        ///
        trynum1=((rand()%45)+7)%44;
        if(trynum1>=0&&trynum1<=3){
            CardButton* strike7=new CardButton(new Strike_Red,this);
            strike7->move(220,330);
        }
        if(trynum1>=4&&trynum1<=7){
            CardButton* bash7=new CardButton(new Bash,this);
            bash7->move(220,330);
        }
        if(trynum1>=8&&trynum1<=10){
            CardButton* pommel7=new CardButton(new Pommel_strike_Red,this);
            pommel7->move(220,330);
        }
        if(trynum1>=11&&trynum1<=13){
            CardButton* shrug7=new CardButton(new Shrug_it_off_Red,this);
            shrug7->move(220,330);
        }
        if(trynum1>=14&&trynum1<=16){
            CardButton* true7=new CardButton(new True_grit_Red,this);
            true7->move(220,330);
        }
        if(trynum1>=17&&trynum1<=19){
            CardButton* armaments7=new CardButton(new Armaments,this);
            armaments7->move(220,330);
        }
        if(trynum1>=20&&trynum1<=22){
            CardButton* bodyslam7=new CardButton(new Body_slam,this);
            bodyslam7->move(220,330);
        }
        if(trynum1==23||trynum1==24){
            CardButton* battletrance7=new CardButton(new Battle_trance,this);
            battletrance7->move(220,330);
        }
        if(trynum1==25||trynum1==26){
            CardButton* Burning_pact7=new CardButton(new Burning_pact,this);
            Burning_pact7->move(220,330);
        }
        if(trynum1==27||trynum1==28){
            CardButton* Inflame_Red7=new CardButton(new Inflame_Red,this);
            Inflame_Red7->move(220,330);
        }
        if(trynum1==29||trynum1==30){
            CardButton* Spot_weakness7=new CardButton(new Spot_weakness_Red,this);
            Spot_weakness7->move(220,330);
        }
        if(trynum1==31||trynum1==32){
            CardButton* Dark_embrace7=new CardButton(new Dark_embrace,this);
            Dark_embrace7->move(220,330);
        }
        if(trynum1==33||trynum1==34){
            CardButton* Second_wind_Red7=new CardButton(new Second_wind_Red,this);
            Second_wind_Red7->move(220,330);
        }
        if(trynum1==35||trynum1==36){
            CardButton* feel_no_pain7=new CardButton(new Feel_no_pain,this);
            feel_no_pain7->move(220,330);
        }
        if(trynum1==37||trynum1==38){
            CardButton* Whirlwind_Red7=new CardButton(new Whirlwind_Red,this);
            Whirlwind_Red7->move(220,330);
        }
        if(trynum1==39){
            CardButton* Corruption7=new CardButton(new Corruption,this);
            Corruption7->move(220,330);
        }
        if(trynum1==40){
            CardButton* Demon_form7=new CardButton(new Demon_form,this);
            Demon_form7->move(220,330);
        }
        if(trynum1==41){
            CardButton* Offering_Red7=new CardButton(new Offering_Red,this);
            Offering_Red7->move(220,330);
        }
        if(trynum1==42){
            CardButton* Barricade7=new CardButton(new Barricade,this);
            Barricade7->move(220,330);
        }
        if(trynum1==43){
            CardButton* Limit_break_Red7=new CardButton(new Limit_break_Red,this);
            Limit_break_Red7->move(220,330);
        }
        if(trynum1==44){
            CardButton* Exhume7=new CardButton(new Exhume,this);
            Exhume7->move(220,330);
        }
        ///////////////////////此处添加第七个位置的其他代码
        ///
        ///
        ///

}

Shop::~Shop()
{
    delete ui;
}

void Shop::on_continue_2_clicked()
{
    mw->d.floor = 2;
    Map *map = new Map(true,this);
    map->show();
}
