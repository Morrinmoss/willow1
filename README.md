# IC705SMeter

Le projet IC7505SMeter permet de doter l'extraordinaire IC705 produit par ICOM d'un S-Mètre à aiguille.

![IC705SMeter](https://github.com/armel/IC705SMeter/blob/main/img/IC750SMeter.jpeg)

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

Ce QSJ est à comparer à celui d'un écran Nextion type NX4832K035, neurasthénique, dépourvu de connectivité Wifi ou GPIO, programmable sous un environnement totalement propriétaire, impliquant un cablage et incapable de fonctionner en standalone. Bref, pour reprendre une des formules du fabriquant, un écran Nextion **_est la meilleure solution pour remplacer les tubes LED classiques Nixie_**. Et nous sommes d'accord, HI ;) 
