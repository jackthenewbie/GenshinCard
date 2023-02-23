#ifndef GLOBALVALUE_H
#define GLOBALVALUE_H
#include <set>
#include <string>
#include <map>
#include <vector>
#include <utility> 
#include "str.h"
#define FONT_SIZE 26
#define FONT "Times-New-Roman"
const std::map<std::string, std::map<int, double>> artifact5_main_stats ={
  //7.0	9.0	11.0	12.9	14.9	16.9	18.9	20.9	22.8	24.8	26.8	28.8	30.8	32.8	34.7	36.7	38.7	40.7	42.7	44.6	46.6
  {"hp_", {
  {0,7}, {1,9}, {2,11}, {3,12.9}, {4,14.9}, {5,16.9}, 
  {6,18.9}, {7,20.9}, {8,22.8}, {9,24.8}, {10,26.8}, 
  {11,28.8}, {12,30.8}, {13,32.8}, {14,34.7}, {15,36.7}, 
  {16,38.7}, {17,40.7}, {18,42.7}, {19,44.6}, {20,46.6},}},
  //717.0	920.0	1123.0	1326.0	1530.0	1733.0	1936.0	2139.0	2342.0	2545.0	2749.0	2952.0	3155.0	3358.0	3561.0	3764.0	3967.0	4171.0	4374.0	4577.0	4780.0
  {"hp", 
  {{0,717}, {1,920}, {2,1123}, {3,1326}, {4,1530}, {5,1733}, 
  {6,1936}, {7,2139}, {8,2342}, {9,2545}, {10,2749}, 
  {11,2952}, {12,3155}, {13,3358}, {14,3561}, {15,3764}, 
  {16,3967}, {17,4171}, {18,4374}, {19,4577}, {20,4780},}},
  //7.0	9.0	11.0	12.9	14.9	16.9	18.9	20.9	22.8	24.8	26.8	28.8	30.8	32.8	34.7	36.7	38.7	40.7	42.7	44.6	46.6
  {"atk_",
  {{0,7}, {1,9}, {2,11}, {3,12.9}, {4,14.9}, {5,16.9}, 
  {6,18.9}, {7,20.9}, {8,22.8}, {9,24.8}, {10,26.8}, 
  {11,28.8}, {12,30.8}, {13,32.8}, {14,34.7}, {15,36.7}, 
  {16,38.7}, {17,40.7}, {18,42.7}, {19,44.6}, {20,46.6},}},
  //47	60	73	86	100	113	126	139	152	166	179	192	205	219	232	245	258	272	285	298	311
  {"atk",
  {{0,47}, {1,60}, {2,73}, {3,86}, {4,100}, {5,113}, 
  {6,126}, {7,139}, {8,152}, {9,166}, {10,179}, 
  {11,192}, {12,205}, {13,219}, {14,232}, {15,245}, 
  {16,258}, {17,272}, {18,285}, {19,298}, {20,311},}},
  //8.7	11.2	13.7	16.2	18.6	21.1	23.6	26.1	28.6	31	33.5	36	38.5	40.9	43.4	45.9	48.4	50.8	53.3	55.8	58.3
  {"def_",
  {{0,8.7}, {1,11.2}, {2,13.7}, {3,16.2}, {4,18.6}, {5,21.1}, 
  {6,23.6}, {7,26.1}, {8,28.6}, {9,31}, {10,33.5}, 
  {11,36}, {12,38.5}, {13,40.9}, {14,43.4}, {15,45.9}, 
  {16,48.4}, {17,50.8}, {18,53.3}, {19,55.8}, {20,58.3},}},
  //28.0	35.9	43.8	51.8	59.7	67.6	75.5	83.5	91.4	99.3	107.2	115.2	123.1	131.0	138.9	146.9	154.8	162.7	170.6	178.6	186.5
  {"eleMas",
  {{0,28}, {1,35.9}, {2,43.8}, {3,51.8}, {4,59.7}, {5,67.6}, 
  {6,75.5}, {7,83.5}, {8,91.4}, {9,99.3}, {10,107.2}, 
  {11,115.2}, {12,123.1}, {13,131}, {14,138.9}, {15,146.9}, 
  {16,154.8}, {17,162.7}, {18,170.6}, {19,178.6}, {20,186.5},}},
  //5.4	6.9	8.4	10.0	11.5	13.0	14.5	16.1	17.6	19.1	20.6	22.1	23.7	25.2	26.7	28.2	29.8	31.3	32.8	34.3	35.9
  {"heal_",
  {{0,5.4}, {1,6.9}, {2,8.4}, {3,10}, {4,11.5}, {5,13}, 
  {6,14.5}, {7,16.1}, {8,17.6}, {9,19.1}, {10,20.6}, 
  {11,22.1}, {12,23.7}, {13,25.2}, {14,26.7}, {15,28.2}, 
  {16,29.8}, {17,31.3}, {18,32.8}, {19,34.3}, {20,35.9},}},
  //7.8	10.0	12.2	14.4	16.6	18.8	21.0	23.2	25.4	27.6	29.8	32.0	34.2	36.4	38.6	40.8	43.0	45.2	47.4	49.6	51.8
  {"enerRech_",
  {{0,7.8}, {1,10}, {2,12.2}, {3,14.4}, {4,16.6}, {5,18.8}, 
  {6,21}, {7,23.2}, {8,25.4}, {9,27.6}, {10,29.8}, 
  {11,32}, {12,34.2}, {13,36.4}, {14,38.6}, {15,40.8}, 
  {16,43}, {17,45.2}, {18,47.4}, {19,49.6}, {20,51.8},}},
  //4.7	6.0	7.3	8.6	9.9	11.3	12.6	13.9	15.2	16.6	17.9	19.2	20.5	21.8	23.2	24.5	25.8	27.1	28.4	29.8	31.1
  {"critRate_",
  {{0,4.7}, {1,6}, {2,7.3}, {3,8.6}, {4,9.9}, {5,11.3}, 
  {6,12.6}, {7,13.9}, {8,15.2}, {9,16.6}, {10,17.9}, 
  {11,19.2}, {12,20.5}, {13,21.8}, {14,23.2}, {15,24.5}, 
  {16,25.8}, {17,27.1}, {18,28.4}, {19,29.8}, {20,31.1},}},
  //9.3	12.0	14.6	17.3	19.9	22.5	25.2	27.8	30.5	33.1	35.7	38.4	41.0	43.7	46.3	49.0	51.6	54.2	56.9	59.6	62.2
  {"critDMG_",
  {{0,9.3}, {1,12}, {2,14.6}, {3,17.3}, {4,19.9}, {5,22.5}, 
  {6,25.2}, {7,27.8}, {8,30.5}, {9,33.1}, {10,35.7}, 
  {11,38.4}, {12,41}, {13,43.7}, {14,46.3}, {15,49}, 
  {16,51.6}, {17,54.2}, {18,56.9}, {19,59.6}, {20,62.2},}},
  {"physical_dmg_",
  {{0,7}, {1,9}, {2,11}, {3,12.9}, {4,14.9}, {5,16.9}, 
  {6,18.9}, {7,20.9}, {8,22.8}, {9,24.8}, {10,26.8}, 
  {11,28.8}, {12,30.8}, {13,32.8}, {14,34.7}, {15,36.7}, 
  {16,38.7}, {17,40.7}, {18,42.7}, {19,44.6}, {20,46.6},}},
  {"anemo_dmg_",
  {{0,7}, {1,9}, {2,11}, {3,12.9}, {4,14.9}, {5,16.9}, 
  {6,18.9}, {7,20.9}, {8,22.8}, {9,24.8}, {10,26.8}, 
  {11,28.8}, {12,30.8}, {13,32.8}, {14,34.7}, {15,36.7}, 
  {16,38.7}, {17,40.7}, {18,42.7}, {19,44.6}, {20,46.6},}},
  {"electro_dmg_",
  {{0,7}, {1,9}, {2,11}, {3,12.9}, {4,14.9}, {5,16.9}, 
  {6,18.9}, {7,20.9}, {8,22.8}, {9,24.8}, {10,26.8}, 
  {11,28.8}, {12,30.8}, {13,32.8}, {14,34.7}, {15,36.7}, 
  {16,38.7}, {17,40.7}, {18,42.7}, {19,44.6}, {20,46.6},}},
  {"hydro_dmg_",
  {{0,7}, {1,9}, {2,11}, {3,12.9}, {4,14.9}, {5,16.9}, 
  {6,18.9}, {7,20.9}, {8,22.8}, {9,24.8}, {10,26.8}, 
  {11,28.8}, {12,30.8}, {13,32.8}, {14,34.7}, {15,36.7}, 
  {16,38.7}, {17,40.7}, {18,42.7}, {19,44.6}, {20,46.6},}},
  {"pyro_dmg_",
  {{0,7}, {1,9}, {2,11}, {3,12.9}, {4,14.9}, {5,16.9}, 
  {6,18.9}, {7,20.9}, {8,22.8}, {9,24.8}, {10,26.8}, 
  {11,28.8}, {12,30.8}, {13,32.8}, {14,34.7}, {15,36.7}, 
  {16,38.7}, {17,40.7}, {18,42.7}, {19,44.6}, {20,46.6},}},
  {"geo_dmg_",
  {{0,7}, {1,9}, {2,11}, {3,12.9}, {4,14.9}, {5,16.9}, 
  {6,18.9}, {7,20.9}, {8,22.8}, {9,24.8}, {10,26.8}, 
  {11,28.8}, {12,30.8}, {13,32.8}, {14,34.7}, {15,36.7}, 
  {16,38.7}, {17,40.7}, {18,42.7}, {19,44.6}, {20,46.6},}},
  {"cryo_dmg_",
  {{0,7}, {1,9}, {2,11}, {3,12.9}, {4,14.9}, {5,16.9}, 
  {6,18.9}, {7,20.9}, {8,22.8}, {9,24.8}, {10,26.8}, 
  {11,28.8}, {12,30.8}, {13,32.8}, {14,34.7}, {15,36.7}, 
  {16,38.7}, {17,40.7}, {18,42.7}, {19,44.6}, {20,46.6},}},
  {"dendro_dmg_",
  {{0,7}, {1,9}, {2,11}, {3,12.9}, {4,14.9}, {5,16.9}, 
  {6,18.9}, {7,20.9}, {8,22.8}, {9,24.8}, {10,26.8}, 
  {11,28.8}, {12,30.8}, {13,32.8}, {14,34.7}, {15,36.7}, 
  {16,38.7}, {17,40.7}, {18,42.7}, {19,44.6}, {20,46.6},}},
  
};
const std::set<std::string> artifact_types= 
{"flower" //Flower
  ,"plume" //Plume
  ,"sands" //Sands
  ,"goblet" //Goblet
  ,"circlet"} //Circlet
  ;
const std::set<std::string> characters={
    "Albedo" //Albedo
  , "Aloy" //Aloy
  , "Amber" //Amber
  , "AratakiItto" //Arataki Itto
  , "Barbara" //Barbara
  , "Beidou" //Beidou
  , "Bennett" //Bennett
  , "Candace" //Candace
  , "Chongyun" //Chongyun
  , "Collei" //Collei
  , "Cyno" //Cyno
  , "Diluc" //Diluc
  , "Diona" //Diona
  , "Dori" //Dori
  , "Eula" //Eula
  , "Faruzan" //Faruzan
  , "Fischl" //Fischl
  , "Ganyu" //Ganyu
  , "Gorou" //Gorou
  , "HuTao" //Hu Tao
  , "Jean" //Jean
  , "KaedeharaKazuha" //Kaedehara Kazuha
  , "Kaeya" //Kaeya
  , "KamisatoAyaka" //Kamisato Ayaka
  , "KamisatoAyato" //Kamisato Ayato
  , "Keqing" //Keqing
  , "Klee" //Klee
  , "KujouSara" //Kujou Sara
  , "KukiShinobu" //Kuki Shinobu
  , "Layla" //Layla
  , "Lisa" //Lisa
  , "Mona" //Mona
  , "Nahida" //Nahida
  , "Nilou" //Nilou
  , "Ningguang" //Ningguang
  , "Noelle" //Noelle
  , "Qiqi" //Qiqi
  , "RaidenShogun" //Raiden Shogun
  , "Razor" //Razor
  , "Rosaria" //Rosaria
  , "SangonomiyaKokomi" //Sangonomiya Kokomi
  , "Sayu" //Sayu
  , "Shenhe" //Shenhe
  , "ShikanoinHeizou" //Shikanoin Heizou
  , "Sucrose" //Sucrose
  , "Tartaglia" //Tartaglia
  , "Thoma" //Thoma
  , "Tighnari" //Tighnari
  , "Traveler" //Lumine
  , "Venti" //Venti
  , "Wanderer" //Wanderer
  , "Xiangling" //Xiangling
  , "Xiao" //Xiao
  , "Xingqiu" //Xingqiu
  , "Xinyan" //Xinyan
  , "YaeMiko" //Yae Miko
  , "Yanfei" //Yanfei
  , "Yelan" //Yelan
  , "Yoimiya" //Yoimiya
  , "YunJin" //Yun Jin
  , "Zhongli" //Zhongli
};
const std::set<std::string> artifact_sets= 
{  "Adventurer" //Adventurer
  ,"ArchaicPetra" //Archaic Petra
  ,"Berserker" //Berserker
  ,"BlizzardStrayer" //Blizzard Strayer
  ,"BloodstainedChivalry" //Bloodstained Chivalry
  ,"BraveHeart" //Brave Heart
  ,"CrimsonWitchOfFlames" //Crimson Witch of Flames
  ,"DeepwoodMemories" //Deepwood Memories
  ,"DefendersWill" //Defender's Will
  ,"EchoesOfAnOffering" //Echoes of an Offering
  ,"EmblemOfSeveredFate" //Emblem of Severed Fate
  ,"Gambler" //Gambler
  ,"GildedDreams" //Gilded Dreams
  ,"GladiatorsFinale" //Gladiator's Finale
  ,"HeartOfDepth" //Heart of Depth
  ,"HuskOfOpulentDreams" //Husk of Opulent Dreams
  ,"Instructor" //Instructor
  ,"Lavawalker" //Lavawalker
  ,"LuckyDog" //Lucky Dog
  ,"MaidenBeloved" //Maiden Beloved
  ,"MartialArtist" //Martial Artist
  ,"NoblesseOblige" //Noblesse Oblige
  ,"OceanHuedClam" //Ocean-Hued Clam
  ,"PaleFlame" //Pale Flame
  ,"PrayersForDestiny" //Prayers for Destiny
  ,"PrayersForIllumination" //Prayers for Illumination
  ,"PrayersForWisdom" //Prayers for Wisdom
  ,"PrayersToSpringtime" //Prayers to Springtime
  ,"ResolutionOfSojourner" //Resolution of Sojourner
  ,"RetracingBolide" //Retracing Bolide
  ,"Scholar" //Scholar
  ,"ShimenawasReminiscence" //Shimenawa's Reminiscence
  ,"TenacityOfTheMillelith" //Tenacity of the Millelith
  ,"TheExile" //The Exile
  ,"ThunderingFury" //Thundering Fury
  ,"Thundersoother" //Thundersoother
  ,"TinyMiracle" //Tiny Miracle
  ,"TravelingDoctor" //Traveling Doctor
  ,"VermillionHereafter" //Vermillion Hereafter
  ,"ViridescentVenerer" //Viridescent Venerer
  ,"WanderersTroupe"
  
};
const std::set<std::string> Weapons = {
  "AThousandFloatingDreams" //A Thousand Floating Dreams
  , "Akuoumaru" //Akuoumaru
  , "AlleyHunter" //Alley Hunter
  , "AmenomaKageuchi" //Amenoma Kageuchi
  , "AmosBow" //Amos' Bow
  , "ApprenticesNotes" //Apprentice's Notes
  , "AquaSimulacra" //Aqua Simulacra
  , "AquilaFavonia" //Aquila Favonia
  , "BeginnersProtector" //Beginner's Protector
  , "BlackTassel" //Black Tassel
  , "BlackcliffAgate" //Blackcliff Agate
  , "BlackcliffLongsword" //Blackcliff Longsword
  , "BlackcliffPole" //Blackcliff Pole
  , "BlackcliffSlasher" //Blackcliff Slasher
  , "BlackcliffWarbow" //Blackcliff Warbow
  , "BloodtaintedGreatsword" //Bloodtainted Greatsword
  , "CalamityQueller" //Calamity Queller
  , "CinnabarSpindle" //Cinnabar Spindle
  , "CompoundBow" //Compound Bow
  , "CoolSteel" //Cool Steel
  , "CrescentPike" //Crescent Pike
  , "DarkIronSword" //Dark Iron Sword
  , "Deathmatch" //Deathmatch
  , "DebateClub" //Debate Club
  , "DodocoTales" //Dodoco Tales
  , "DragonsBane" //Dragon's Bane
  , "DragonspineSpear" //Dragonspine Spear
  , "DullBlade" //Dull Blade
  , "ElegyForTheEnd" //Elegy for the End
  , "EmeraldOrb" //Emerald Orb
  , "EndOfTheLine" //End of the Line
  , "EngulfingLightning" //Engulfing Lightning
  , "EverlastingMoonglow" //Everlasting Moonglow
  , "EyeOfPerception" //Eye of Perception
  , "FadingTwilight" //Fading Twilight
  , "FavoniusCodex" //Favonius Codex
  , "FavoniusGreatsword" //Favonius Greatsword
  , "FavoniusLance" //Favonius Lance
  , "FavoniusSword" //Favonius Sword
  , "FavoniusWarbow" //Favonius Warbow
  , "FerrousShadow" //Ferrous Shadow
  , "FesteringDesire" //Festering Desire
  , "FilletBlade" //Fillet Blade
  , "ForestRegalia" //Forest Regalia
  , "FreedomSworn" //Freedom-Sworn
  , "Frostbearer" //Frostbearer
  , "FruitOfFulfillment" //Fruit of Fulfillment
  , "HakushinRing" //Hakushin Ring
  , "Halberd" //Halberd
  , "Hamayumi" //Hamayumi
  , "HaranGeppakuFutsu" //Haran Geppaku Futsu
  , "HarbingerOfDawn" //Harbinger of Dawn
  , "HuntersBow" //Hunter's Bow
  , "HuntersPath" //Hunter's Path
  , "IronPoint" //Iron Point
  , "IronSting" //Iron Sting
  , "KagotsurubeIsshin" //Kagotsurube Isshin
  , "KagurasVerity" //Kagura's Verity
  , "KatsuragikiriNagamasa" //Katsuragikiri Nagamasa
  , "KeyOfKhajNisut" //Key of Khaj-Nisut
  , "KingsSquire" //King's Squire
  , "KitainCrossSpear" //Kitain Cross Spear
  , "LionsRoar" //Lion's Roar
  , "LithicBlade" //Lithic Blade
  , "LithicSpear" //Lithic Spear
  , "LostPrayerToTheSacredWinds" //Lost Prayer to the Sacred Winds
  , "LuxuriousSeaLord" //Luxurious Sea-Lord
  , "MagicGuide" //Magic Guide
  , "MakhairaAquamarine" //Makhaira Aquamarine
  , "MappaMare" //Mappa Mare
  , "MemoryOfDust" //Memory of Dust
  , "Messenger" //Messenger
  , "MissiveWindspear" //Missive Windspear
  , "MistsplitterReforged" //Mistsplitter Reforged
  , "MitternachtsWaltz" //Mitternachts Waltz
  , "Moonpiercer" //Moonpiercer
  , "MouunsMoon" //Mouun's Moon
  , "OathswornEye" //Oathsworn Eye
  , "OldMercsPal" //Old Merc's Pal
  , "OtherworldlyStory" //Otherworldly Story
  , "PocketGrimoire" //Pocket Grimoire
  , "PolarStar" //Polar Star
  , "Predator" //Predator
  , "PrimordialJadeCutter" //Primordial Jade Cutter
  , "PrimordialJadeWingedSpear" //Primordial Jade Winged-Spear
  , "PrototypeAmber" //Prototype Amber
  , "PrototypeArchaic" //Prototype Archaic
  , "PrototypeCrescent" //Prototype Crescent
  , "PrototypeRancour" //Prototype Rancour
  , "PrototypeStarglitter" //Prototype Starglitter
  , "Rainslasher" //Rainslasher
  , "RavenBow" //Raven Bow
  , "RecurveBow" //Recurve Bow
  , "RedhornStonethresher" //Redhorn Stonethresher
  , "RoyalBow" //Royal Bow
  , "RoyalGreatsword" //Royal Greatsword
  , "RoyalGrimoire" //Royal Grimoire
  , "RoyalLongsword" //Royal Longsword
  , "RoyalSpear" //Royal Spear
  , "Rust" //Rust
  , "SacrificialBow" //Sacrificial Bow
  , "SacrificialFragments" //Sacrificial Fragments
  , "SacrificialGreatsword" //Sacrificial Greatsword
  , "SacrificialSword" //Sacrificial Sword
  , "SapwoodBlade" //Sapwood Blade
  , "SeasonedHuntersBow" //Seasoned Hunter's Bow
  , "SerpentSpine" //Serpent Spine
  , "SharpshootersOath" //Sharpshooter's Oath
  , "SilverSword" //Silver Sword
  , "SkyriderGreatsword" //Skyrider Greatsword
  , "SkyriderSword" //Skyrider Sword
  , "SkywardAtlas" //Skyward Atlas
  , "SkywardBlade" //Skyward Blade
  , "SkywardHarp" //Skyward Harp
  , "SkywardPride" //Skyward Pride
  , "SkywardSpine" //Skyward Spine
  , "Slingshot" //Slingshot
  , "SnowTombedStarsilver" //Snow-Tombed Starsilver
  , "SolarPearl" //Solar Pearl
  , "SongOfBrokenPines" //Song of Broken Pines
  , "StaffOfHoma" //Staff of Homa
  , "StaffOfTheScarletSands" //Staff of the Scarlet Sands
  , "SummitShaper" //Summit Shaper
  , "SwordOfDescension" //Sword of Descension
  , "TheAlleyFlash" //The Alley Flash
  , "TheBell" //The Bell
  , "TheBlackSword" //The Black Sword
  , "TheCatch" //"The Catch"
  , "TheFlute" //The Flute
  , "TheStringless" //The Stringless
  , "TheUnforged" //The Unforged
  , "TheViridescentHunt" //The Viridescent Hunt
  , "TheWidsith" //The Widsith
  , "ThrillingTalesOfDragonSlayers" //Thrilling Tales of Dragon Slayers
  , "ThunderingPulse" //Thundering Pulse
  , "ToukabouShigure" //Toukabou Shigure
  , "TravelersHandySword" //Traveler's Handy Sword
  , "TulaytullahsRemembrance" //Tulaytullah's Remembrance
  , "TwinNephrite" //Twin Nephrite
  , "VortexVanquisher" //Vortex Vanquisher
  , "WanderingEvenstar" //Wandering Evenstar
  , "WasterGreatsword" //Waster Greatsword
  , "WavebreakersFin" //Wavebreaker's Fin
  , "WhiteIronGreatsword" //White Iron Greatsword
  , "WhiteTassel" //White Tassel
  , "Whiteblind" //Whiteblind
  , "WindblumeOde" //Windblume Ode
  , "WineAndSong" //Wine and Song
  , "WolfsGravestone" //Wolf's Gravestone
  , "XiphosMoonlight" //Xiphos' Moonlight
};
const std::vector<std::string> verbose_stat_api = { //must has the same length as verbose_stat_GOOD
  "Anemo DMG Bonus",
  "Cryo DMG Bonus",
  "Dendro DMG Bonus",
  "Electro DMG Bonus",
  "Geo DMG Bonus",
  "Hydro DMG Bonus",
  "Pyro DMG Bonus",
  "Physical DMG",
  "CRIT Rate",
  "CRIT DMG",
  "Elemental Mastery",
  "Energy Recharge",
  "HP",
  "ATK",
  "DEF",
  "Healing Bonus",
  "hp",
  "attack",
  "defense",
};
const std::vector<std::string> verbose_stat_GOOD ={ //must has the same length as verbose_stat_api
  "anemo_dmg_",
  "cryo_dmg_",
  "dendro_dmg_",
  "electro_dmg_",
  "geo_dmg_",
  "hydro_dmg_",
  "pyro_dmg_",
  "physical_dmg_",
  "critRate_",
  "critDMG_",
  "eleMas",
  "enerRech_",
  "hp_",
  "atk_",
  "def_",
  "heal_",
  "hp",
  "atk",
  "def",

};
const std::vector<std::string> verbose_stat_display = {
  "Anemo DMG Bonus",
  "Cryo DMG Bonus",
  "Dendro DMG Bonus",
  "Electro DMG Bonus",
  "Geo DMG Bonus",
  "Hydro DMG Bonus",
  "Pyro DMG Bonus",
  "Physical DMG Bonus",
  "Crit Rate",
  "Crit DMG",
  "Elemental Mastery",
  "Energy Recharge",
  "HP bonus",
  "ATK bonus",
  "DEF bonus",
  "Healing Bonus",
  "Max HP",
  "ATK",
  "DEF",
};
std::string get_bonus(std::string);
std::string display(std::string);
std::string verbose(std::string, std::vector<std::string>, std::vector<std::string>);
const std::string root = "https://genshin-impact.fandom.com/wiki/";
#endif