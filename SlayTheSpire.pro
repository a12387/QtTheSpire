QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    campfire.cpp \
    cardbutton.cpp \
    cardwidget.cpp \
    combatroom.cpp \
    creaturewidget.cpp \
    game/cards/AbstractCard.cpp \
    game/cards/CardGroup.cpp \
    game/cards/DamageInfo.cpp \
    game/cards/red/Armaments.cpp \
    game/cards/red/Barricade.cpp \
    game/cards/red/Bash.cpp \
    game/cards/red/Battle_trance.cpp \
    game/cards/red/Body_slam.cpp \
    game/cards/red/Burning_pact.cpp \
    game/cards/red/Corruption.cpp \
    game/cards/red/Dark_embrace.cpp \
    game/cards/red/Demon_form.cpp \
    game/cards/red/Feel_no_pain.cpp \
    game/cards/red/Finesse.cpp \
    game/cards/red/Inflame_Red.cpp \
    game/cards/red/Limit_break_Red.cpp \
    game/cards/red/Offering_Red.cpp \
    game/cards/red/Pommel_strike_Red.cpp \
    game/cards/red/Second_wind_Red.cpp \
    game/cards/red/Shrug_it_off_Red.cpp \
    game/cards/red/Spot_weakness_Red.cpp \
    game/cards/red/Strike_Red.cpp \
    game/cards/red/True_grit_Red.cpp \
    game/cards/red/Whirlwind_Red.cpp \
    game/characters/AbstractPlayer.cpp \
    game/characters/Ironclad.cpp \
    game/core/AbstractCreature.cpp \
    game/dungeon/Dungeon.cpp \
    game/monsters/AbstractMonster.cpp \
    game/monsters/CorruptHeart.cpp \
    game/monsters/MonsterGroup.cpp \
    game/monsters/SpireShield.cpp \
    game/monsters/SpireSpear.cpp \
    game/powers/AbstractPower.cpp \
    game/powers/Artifact.cpp \
    game/powers/BackAttackLeft.cpp \
    game/powers/BackAttackRight.cpp \
    game/powers/BeatOfDeath.cpp \
    game/powers/Frail.cpp \
    game/powers/Invincible.cpp \
    game/powers/PainfulStabs.cpp \
    game/powers/Strength.cpp \
    game/powers/Surrounded.cpp \
    game/powers/Vulnerable.cpp \
    game/powers/Weak.cpp \
    game/relics/AbstractRelic.cpp \
    game/rooms/AbstractRoom.cpp \
    game/rooms/BossRoom.cpp \
    game/rooms/CampfireRoom.cpp \
    game/rooms/EliteRoom.cpp \
    game/rooms/ShopRoom.cpp \
    getcard.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mapwidget.cpp \
    menu.cpp \
    powerwidget.cpp \
    shop.cpp \
    statebar.cpp \
    usecard.cpp

HEADERS += \
    campfire.h \
    cardbutton.h \
    cardwidget.h \
    combatroom.h \
    creaturewidget.h \
    game/cards/AbstractCard.h \
    game/cards/CardGroup.h \
    game/cards/DamageInfo.h \
    game/cards/red/Armaments.h \
    game/cards/red/Barricade.h \
    game/cards/red/Bash.h \
    game/cards/red/Battle_trance.h \
    game/cards/red/Body_slam.h \
    game/cards/red/Burning_pact.h \
    game/cards/red/Corruption.h \
    game/cards/red/Dark_embrace.h \
    game/cards/red/Demon_form.h \
    game/cards/red/Feel_no_pain.h \
    game/cards/red/Finesse.h \
    game/cards/red/Inflame_Red.h \
    game/cards/red/Limit_break_Red.h \
    game/cards/red/Offering_Red.h \
    game/cards/red/Pommel_strike_Red.h \
    game/cards/red/Second_wind_Red.h \
    game/cards/red/Shrug_it_off_Red.h \
    game/cards/red/Spot_weakness_Red.h \
    game/cards/red/Strike_Red.h \
    game/cards/red/True_grit_Red.h \
    game/cards/red/Whirlwind_Red.h \
    game/characters/AbstractPlayer.h \
    game/characters/Ironclad.h \
    game/core/AbstractCreature.h \
    game/dungeon/Dungeon.h \
    game/monsters/AbstractMonster.h \
    game/monsters/CorruptHeart.h \
    game/monsters/MonsterGroup.h \
    game/monsters/SpireShield.h \
    game/monsters/SpireSpear.h \
    game/powers/AbstractPower.h \
    game/powers/AbstractPower.h \
    game/powers/Artifact.h \
    game/powers/Artifact.h \
    game/powers/BackAttackLeft.h \
    game/powers/BackAttackLeft.h \
    game/powers/BackAttackRight.h \
    game/powers/BeatOfDeath.h \
    game/powers/BeatOfDeath.h \
    game/powers/Frail.h \
    game/powers/Invincible.h \
    game/powers/PainfulStabs.h \
    game/powers/Strength.h \
    game/powers/Surrounded.h \
    game/powers/Vulnerable.h \
    game/powers/Weak.h \
    game/relics/AbstractRelic.h \
    game/rooms/AbstractRoom.h \
    game/rooms/BossRoom.h \
    game/rooms/CampfireRoom.h \
    game/rooms/EliteRoom.h \
    game/rooms/ShopRoom.h \
    getcard.h \
    mainwindow.h \
    map.h \
    mapwidget.h \
    menu.h \
    powerwidget.h \
    shop.h \
    statebar.h \
    usecard.h

FORMS += \
    campfire.ui \
    cardwidget.ui \
    combatroom.ui \
    creaturewidget.ui \
    getcard.ui \
    mainwindow.ui \
    mapwidget.ui \
    menu.ui \
    powerwidget.ui \
    shop.ui \
    statebar.ui \
    usecard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc


HEADERS += \
    campfire.h \
    cardbutton.h \
    cardwidget.h \
    combatroom.h \
    creaturewidget.h \
    game/cards/AbstractCard.h \
    game/cards/CardGroup.h \
    game/cards/DamageInfo.h \
    game/cards/red/Armaments.h \
    game/cards/red/Barricade.h \
    game/cards/red/Bash.h \
    game/cards/red/Battle_trance.h \
    game/cards/red/Body_slam.h \
    game/cards/red/Burning_pact.h \
    game/cards/red/Corruption.h \
    game/cards/red/Dark_embrace.h \
    game/cards/red/Demon_form.h \
    game/cards/red/Feel_no_pain.h \
    game/cards/red/Finesse.h \
    game/cards/red/Inflame_Red.h \
    game/cards/red/Limit_break_Red.h \
    game/cards/red/Offering_Red.h \
    game/cards/red/Pommel_strike_Red.h \
    game/cards/red/Second_wind_Red.h \
    game/cards/red/Shrug_it_off_Red.h \
    game/cards/red/Spot_weakness_Red.h \
    game/cards/red/Strike_Red.h \
    game/cards/red/True_grit_Red.h \
    game/cards/red/Whirlwind_Red.h \
    game/characters/AbstractPlayer.h \
    game/characters/Ironclad.h \
    game/core/AbstractCreature.h \
    game/dungeon/Dungeon.h \
    game/monsters/AbstractMonster.h \
    game/monsters/CorruptHeart.h \
    game/monsters/MonsterGroup.h \
    game/monsters/SpireShield.h \
    game/monsters/SpireSpear.h \
    game/powers/AbstractPower.h \
    game/powers/AbstractPower.h \
    game/powers/Artifact.h \
    game/powers/Artifact.h \
    game/powers/BackAttackLeft.h \
    game/powers/BeatOfDeath.h \
    game/powers/BeatOfDeath.h \
    game/powers/Frail.h \
    game/powers/Invincible.h \
    game/powers/PainfulStabs.h \
    game/powers/Strength.h \
    game/powers/Surrounded.h \
    game/powers/Vulnerable.h \
    game/powers/Weak.h \
    game/relics/AbstractRelic.h \
    game/rooms/AbstractRoom.h \
    game/rooms/CampfireRoom.h \
    game/rooms/EliteRoom.h \
    game/rooms/ShopRoom.h \
    getcard.h \
    mainwindow.h \
    map.h \
    mapwidget.h \
    menu.h \
    powerwidget.h \
    shop.h \
    statebar.h \
    usecard.h

FORMS += \
    campfire.ui \
    cardwidget.ui \
    combatroom.ui \
    creaturewidget.ui \
    getcard.ui \
    mainwindow.ui \
    mapwidget.ui \
    menu.ui \
    powerwidget.ui \
    shop.ui \
    statebar.ui \
    usecard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
