QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    campfire.cpp \
    cardbutton.cpp \
    cardgroupwidget.cpp \
    cardwidget.cpp \
    combatroom.cpp \
    creaturewidget.cpp \
    game/cards/AbstractCard.cpp \
    game/cards/CardGroup.cpp \
    game/cards/DamageInfo.cpp \
    game/cards/RandomCard.cpp \
    game/cards/colorless/Burn.cpp \
    game/cards/colorless/Dazed.cpp \
    game/cards/colorless/Slimed.cpp \
    game/cards/colorless/Void.cpp \
    game/cards/colorless/Wound.cpp \
    game/cards/red/Armaments.cpp \
    game/cards/red/Barricade.cpp \
    game/cards/red/Bash.cpp \
    game/cards/red/BattleTrance.cpp \
    game/cards/red/BodySlam.cpp \
    game/cards/red/BurningPact.cpp \
    game/cards/red/Corruption.cpp \
    game/cards/red/DarkEmbrace.cpp \
    game/cards/red/Defend_Red.cpp \
    game/cards/red/DemonForm.cpp \
    game/cards/red/Exhume.cpp \
    game/cards/red/FeelNoPain.cpp \
    game/cards/red/Finesse.cpp \
    game/cards/red/Inflame.cpp \
    game/cards/red/LimitBreak.cpp \
    game/cards/red/Offering.cpp \
    game/cards/red/PommelStrike.cpp \
    game/cards/red/SecondWind.cpp \
    game/cards/red/ShrugItOff.cpp \
    game/cards/red/SpotWeakness.cpp \
    game/cards/red/Strike_Red.cpp \
    game/cards/red/TrueGrit.cpp \
    game/cards/red/Whirlwind.cpp \
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
    game/powers/Barricade_.cpp \
    game/powers/BeatOfDeath.cpp \
    game/powers/Corruption_.cpp \
    game/powers/DarkEmbrace_.cpp \
    game/powers/DemonForm_.cpp \
    game/powers/FeelNoPain_.cpp \
    game/powers/Frail.cpp \
    game/powers/Invincible.cpp \
    game/powers/NoDraw.cpp \
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
    cardgroupwidget.h \
    cardwidget.h \
    combatroom.h \
    creaturewidget.h \
    game/cards/AbstractCard.h \
    game/cards/CardGroup.h \
    game/cards/DamageInfo.h \
    game/cards/RandomCard.h \
    game/cards/colorless/Burn.h \
    game/cards/colorless/Dazed.h \
    game/cards/colorless/Slimed.h \
    game/cards/colorless/Void.h \
    game/cards/colorless/Wound.h \
    game/cards/red/Armaments.h \
    game/cards/red/Barricade.h \
    game/cards/red/Bash.h \
    game/cards/red/BattleTrance.h \
    game/cards/red/BodySlam.h \
    game/cards/red/BurningPact.h \
    game/cards/red/Corruption.h \
    game/cards/red/DarkEmbrace.h \
    game/cards/red/Defend_Red.h \
    game/cards/red/DemonForm.h \
    game/cards/red/Exhume.h \
    game/cards/red/FeelNoPain.h \
    game/cards/red/Finesse.h \
    game/cards/red/Inflame.h \
    game/cards/red/LimitBreak.h \
    game/cards/red/Offering.h \
    game/cards/red/PommelStrike.h \
    game/cards/red/SecondWind.h \
    game/cards/red/ShrugItOff.h \
    game/cards/red/SpotWeakness.h \
    game/cards/red/Strike_Red.h \
    game/cards/red/TrueGrit.h \
    game/cards/red/Whirlwind.h \
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
    game/powers/Artifact.h \
    game/powers/BackAttackLeft.h \
    game/powers/BackAttackRight.h \
    game/powers/Barricade_.h \
    game/powers/BeatOfDeath.h \
    game/powers/Corruption_.h \
    game/powers/DarkEmbrace_.h \
    game/powers/DemonForm_.h \
    game/powers/FeelNoPain_.h \
    game/powers/Frail.h \
    game/powers/Invincible.h \
    game/powers/NoDraw.h \
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
    cardgroupwidget.ui \
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

DISTFILES +=
