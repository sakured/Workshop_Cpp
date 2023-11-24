# 🐣 S1 | Prog : Workshop | Anne & Justine


- [🐣 S1 | Prog : Workshop | Anne \& Justine](#-s1--prog--workshop--anne--justine)
  - [⭐ Ne garder que le vert](#-ne-garder-que-le-vert)
  - [⭐ Échanger les canaux](#-échanger-les-canaux)
  - [⭐ Noir \& blanc](#-noir--blanc)
  - [⭐ Négatif](#-négatif)
  - [⭐ Dégradé](#-dégradé)
  - [⭐⭐ Miroir](#-miroir)
  - [⭐⭐ Image bruitée](#-image-bruitée)
  - [⭐⭐ Rotation de 90°](#-rotation-de-90)
  - [⭐⭐ RGB split](#-rgb-split)
  - [⭐⭐ Luminosité](#-luminosité)
  - [⭐⭐ Disque](#-disque)
  - [⭐ Cercle](#-cercle)
  - [⭐⭐⭐ Rosace](#-rosace)
  - [⭐⭐ Mosaïque](#-mosaïque)
  - [⭐⭐⭐ Mosaïque miroir](#-mosaïque-miroir)
  - [⭐⭐⭐ Glitch](#-glitch)
  - [⭐⭐⭐ Fractale de Mandelbrot](#-fractale-de-mandelbrot)
  - [⭐⭐⭐(⭐) Vortex](#-vortex)
  - [⭐⭐⭐(⭐) Tramage](#-tramage)
  - [⭐⭐⭐(⭐) Normalisation de l'histogramme](#-normalisation-de-lhistogramme)
  - [⭐⭐⭐⭐ Convolutions](#-convolutions)
    - [⭐ Netteté, Contours, etc.](#-netteté-contours-etc)
    - [⭐⭐ Différence de gaussiennes](#-différence-de-gaussiennes)
  - [Échecs esthétiques](#échecs-esthétiques)


## ⭐ Ne garder que le vert  

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC tout vert](./output/greenOnly.png)


## ⭐ Échanger les canaux 

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC canaux inversés](./output/changeColors.png)


## ⭐ Noir & blanc

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC noir et blanc](./output/blackAndWhite.png)


## ⭐ Négatif

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC négatif](./output/negative.png)


## ⭐ Dégradé
 
![dégradé noir et blanc](./output/gradient.png)

Nous avons eu un petit peu de difficulté à prendre en main la double boucle `for` car c'était la première fois qu'on l'utilisait. 

<details><summary>Voir le code</summary>

```cpp
  void gradient() {
    sil::Image gradient{300, 200};
    float light {0.f};
    for (int x{0}; x < gradient.height(); x++)
    {
        for (int y{0}; y < gradient.width(); y++)
        {
            gradient.pixel(y, x).r += light;
            gradient.pixel(y, x).g += light;
            gradient.pixel(y, x).b += light;
            light += (1.f / 300.f);
        }
        light = 0.f;
    }
    gradient.save("output/gradient.png");
}
```
</details>

## ⭐⭐ Miroir

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC avec sylétrie verticale](./output/miror.png)


## ⭐⭐ Image bruitée

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC avec du bruit](./output/noise.png)


## ⭐⭐ Rotation de 90°

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC avec une rotation à 90°](./output/rotation.png)


## ⭐⭐ RGB split

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC avec RGB split](./output/rgbSplit.png)


## ⭐⭐ Luminosité

Image de base : 
![photo de base](./images/photo.jpg)
Plus lumineux : 
![photo plus lumineuse](./output/moreLight.jpg)
Moins lumineux : 
![logo moins lumineuse](./output/lessLight.jpg)


## ⭐⭐ Disque

![disque](./output/disk.png)


## ⭐ Cercle

![cercle](./output/circle.png)


## ⭐⭐⭐ Rosace

![rosace](./output/rosace.png)


## ⭐⭐ Mosaïque

![mosaïque du logo IMAC](./output/mosaic.png)


## ⭐⭐⭐ Mosaïque miroir

![mosaïque miroir du logo IMAC](./output/mirrorMosaic.png)


## ⭐⭐⭐ Glitch

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC avec glitch](./output/glitch.png)


## ⭐⭐⭐ Fractale de Mandelbrot

![fractale de Mandelbrot](./output/fractale.png)


## ⭐⭐⭐(⭐) Vortex

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC avec vortex](./output/vortex.png)


## ⭐⭐⭐(⭐) Tramage

Avant : 
![photo de base](./images/photo.jpg)
Après: 
![photo avec tramage](./output/dithering.jpg)


## ⭐⭐⭐(⭐) Normalisation de l'histogramme

Avant : 
![photo avec un faible contraste](./images/photo_faible_contraste.jpg)
Après: 
![photo avec un meilleur contraste](./output/betterContrast.jpg)


## ⭐⭐⭐⭐ Convolutions

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC flou](./output/blur.png)


### ⭐ Netteté, Contours, etc.

**Emboss** : 
![logo IMAC avec effet emboss](./output/emboss.png)
**Outline** : 
![logo IMAC avec effet outline](./output/outline.png)
**Sharpen** : 
![logo IMAC avec effet sharpen](./output/sharpen.png)


### ⭐⭐ Différence de gaussiennes

![photo avec différence de gaussiennes](./output/differenceOfGaussians.png)
![échec photo avec différence de gaussiennes](./output/bonus_2.png)


## Échecs esthétiques

En essayant de faire la mosaïque, nous avons accidentellement créé une image très originale et jolie. Nous la joignons à la fin de ce rapport en petit bonus.

![échec esthétique](./output/bonus_1.png)