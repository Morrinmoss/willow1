# IC705SMeter
![basic](https://img.shields.io/badge/M5Stack-BASIC-blue)
![grey](https://img.shields.io/badge/M5Stack-GREY-blue)
![fire](https://img.shields.io/badge/M5Stack-FIRE-orange)
![core2](https://img.shields.io/badge/M5Stack-CORE2-green)
![aws](https://img.shields.io/badge/M5Stack-AWS-orange)

![licence](https://img.shields.io/github/license/armel/IC705SMeter)
![language](https://img.shields.io/github/languages/top/armel/IC705SMeter)
![size](https://img.shields.io/github/repo-size/armel/IC705SMeter)
![version](https://img.shields.io/github/v/release/armel/IC705SMeter)
![activity](https://img.shields.io/github/commit-activity/y/armel/IC705SMeter)


Le projet IC7505SMeter permet de doter l'extraordinaire IC705 produit par ICOM, d'un S-Mètre à aiguille !
Le S-Mètre permet de mesurer le signal S, la puissance RF et le SWR.

![IC705SMeter S](https://github.com/armel/IC705SMeter/blob/main/img/S.jpeg)
![IC705SMeter PWR](https://github.com/armel/IC705SMeter/blob/main/img/PWR.jpeg)
![IC705SMeter SWR](https://github.com/armel/IC705SMeter/blob/main/img/SWR.jpeg)

# Architecture technique

## Présentation rapide

[M5Stack](https://m5stack.com/) est basé sur un ESP-32, dual core, pouvant être cadencé jusqu'à 240 MHz.  Néanmoins, le RRFRemote fonctionne parfaitement à 80 MHz. M5Stack dispose de 16 MB de mémoire flash. Comme tous les ESP, le Wifi est évidement intégré. L'écran 2 pouces IPS couleur, basé sur le chipset ILI9342C, affiche une résolution confortable de 320 x 240 pixels. Il est hyper lumineux. La batterie intégrée fait 110 mAh. Il est possible d'ajouter une batterie supplémentaire (de 700 ou 800mAh) si besoin. 

En terme de dimensions et de masse, c'est très compact : 54 x 54 x 18mm pour 47,2g. Se trimbale dans la poche sans problème ;) 

## Specs techniques détaillées :

Voici les specs techniques détaillées, pour les curieux :

| Resources |	Description |
| --------- | ------------ |
|ESP32| 240MHz dual core, 600 DMIPS, 520KB SRAM, Wi-Fi, dual mode Bluetooth
Flash| Memory	16MB|
|Power| Input	5V @ 500mA|
|Port|	TypeC x 1, GROVE(I2C+I/0+UART) x 1|
|Core|Bottom Port	PIN (G1，G2，G3，G16, G17, G18, G19, G21, G22, G23, G25, G26, G35, G36)|
|IPS Screen|	2 inch, 320x240 Colorful TFT LCD, ILI9342C, max brightness 853nit|
|Button|	Custom button x 3|
|Speaker|	1W-0928|
|Battery|	110mAh @ 3.7V|
|Antenna|	2.4G 3D Antenna|
|Operating Temperature|	32°F to 104°F ( 0°C to 40°C )|
|Net weight|	47.2g|
|Gross weight|	93g|
|Product Size|	54 x 54 x 18mm|
|Package Size	|95 x 65 x 25mm|
|Case Material|	Plastic ( PC )|

## En complément

Coté QSJ, compter autour de 25€. Vous disposez alors d'une plateforme de développement complète, totalement autonome, programmable en C et C++, MicroPython et UIFlow, depuis Linux, Windows ou MacOS, le tout dans un boitier compact et ultra ergonomique.


# Installation

## Pré-ambule

Le plus simple est d'installer [PlateformIO for VSCode](https://platformio.org/install/ide?install=vscode) sur votre PC (Linux ou Windows) ou sur votre Mac (Intel ou M1). C'est un environnement de développement multiplateforme et multilangage performant, en plus d'être agréable à utiliser.

Ensuite, toujours sur votre PC ou Mac, cloner le projet IC705SMeter via la commande :

`https://github.com/armel/IC705SMeter.git`

## Configuration

Ouvrez le projet IC705SMeter avec PlateformIO for VSCode.

### Fichier `src/settings.h`

#### Type de carte

Ligne 5, vérifier que la constante `BOARD` correspond bien à votre type de M5Stack (par défaut, la constante est initialisée à `BASIC`). Donc, indiquer : 

- `BASIC` si vous avez un M5Stack BASIC

```
#define BOARD BASIC
```

- `GREY` si vous avez un M5Stack GREY

```
#define BOARD GREY
```

- `CORE2` si vous avez un M5Stack CORE2

```
#define BOARD CORE2
```

#### Adresse de votre IC705
Ligne 8, modifier l'adresse de votre IC705 si nécessaire. J'ai indiqué la valeur par défaut.


#### Configuration Wifi 
Ligne 11 et 12, indiquer éventuellement votre SSID et votre mot de passe Wifi. Vous pourrez visualiser votre IC705SMeter depuis un simple navigateur. Il est même possible de le piloter par ce biais, dans la mesure ou les boutons sont cliquables. Afin d'afficher votre IC705SMeter dans votre navigateur, il suffit d'aller sur `http://adresse_ip_de_votre_ic705smeter/`. Pour rappel, l'adresse IP que récupère votre IC705SMeter s'affiche sur l'écran.

> Attention : c'est lent ! Et il n'y a pas de rafraîchissement automatique. Il faut cliquer sur le fond de l'image de l'écran pour faire une nouvelle capture. Et sinon, comme dit, les boutons sont fonctionnels.

### Fichier `platformio.ini`

Si et seulement si __vous utilisez le M5Stack Core2__, éditer le fichier `platformio.ini` et modifier les lignes,

```
default_envs = m5stack-basic-grey
;default_envs = m5stack-core2
```

Par,

```
;default_envs = m5stack-basic-grey
default_envs = m5stack-core2
```

Cela revient à changer la plate-forme cible, le point-virgule étant un commentaire.

## Compilation et flashage du M5Stack

Compiler et uploader le projet sur votre M5Stack. C'est terminé.
