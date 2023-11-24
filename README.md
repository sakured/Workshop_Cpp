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

Utilisation de `random` pour choisir un pixel au hazard, puis  pour choisir une couleur au hazard. 

```cpp
int rand {random_int(0, 4)};
if (rand == 1) { // 1 chance sur 5 de brouiller mon pixel
    color.r = random_float(0.0f, 1.0f);
    color.g = random_float(0.0f, 1.0f);
    color.b = random_float(0.0f, 1.0f);
}
```

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

Echec :
![échec esthétique](./output/bonus_1.png)
résultat :
![mosaïque du logo IMAC](./output/mosaic.png)

En essayant de faire la mosaïque, nous avons accidentellement créé une image très originale et jolie.


## ⭐⭐⭐ Mosaïque miroir

![mosaïque miroir du logo IMAC](./output/mirrorMosaic.png)


## ⭐⭐⭐ Glitch

Avant : 
![logo IMAC de base](./images/logo.png)
Après : 
![logo IMAC avec glitch](./output/glitch.png)

On a reprit le code du bruitage, avec le même principe d'utilisation de `random`. Mais il faut en plus créer des rectangle de taille aléatoire, qui représente une partie de l'image, et pas juste prendre un pixel. Pour échanger deux rectangles on a utilisé la fonction `swap`.

```cpp
  for (int x{0}; x < rand_x1; x++)
  {
      for (int y{0}; y < rand_y1; y++)
      {
          std::swap(image.pixel(x, y).r, image.pixel((x+rand_x2)%image.width(), (y+rand_y2)%image.height()).r); // modulo pour eviter de sortir de l'image
          std::swap(image.pixel(x, y).g, image.pixel((x+rand_x2)%image.width(), (y+rand_y2)%image.height()).g);
          std::swap(image.pixel(x, y).b, image.pixel((x+rand_x2)%image.width(), (y+rand_y2)%image.height()).b);
      }
  }
```


## ⭐⭐⭐ Fractale de Mandelbrot

![fractale de Mandelbrot](./output/fractale.png)


## ⭐⭐⭐(⭐) Vortex

Avant : 
![logo IMAC de base](./images/logo.png)
Intermédiare :
![logo IMAC avec une trop grosse rotation](./images/vortex_echec.png)
Après : 
![logo IMAC avec vortex](./output/vortex.png)

Exercice assez compliqué. On a eu du mal a comprendre comment marchait la fonction `rotated`. Une fois cela compris on a voulu tester une simple rotation d'image a 90° en gérant les pixels qui se retrouvaient à l'exterieur du cadre de l'image. 
```cpp
glm::vec2 point{x, y};
glm::vec2 center_of_rotation{image.width()/2, image.height()/2};
glm::vec2 new_point{rotated(point, center_of_rotation , 90)};

if(new_point.y<vortex.height() && new_point.x<vortex.width() && new_point.y>0 && new_point.x>0) { 
    vortex.pixel(x, y) = image.pixel(new_point.x, new_point.y);
}
```

Ensuite il a fallut faire une rotation en fonction de la distance par rapport au centre de l'image. Le resultat obtenu est celui de l'image intermediaire. On a essayer de comprendre pourquoi on obtenait l'image intermédiaire : c'est simplement car on faisait une rotation trop importante. 
```cpp
glm::vec2 point{x, y};
glm::vec2 center_of_rotation{image.width()/2, image.height()/2};
glm::vec2 new_point{rotated(point, center_of_rotation ,pow((pow((x-image.width()/2),2)+pow((y-image.height()/2),2)),0.5))};

if(new_point.y<vortex.height() && new_point.x<vortex.width() && new_point.y>0 && new_point.x>0) { 
    vortex.pixel(x, y) = image.pixel(new_point.x, new_point.y);
}
```

Il fallait donc reduire l'angle de rotation, on a décidé de le diviser par 10, mais on peut choisir ce que l'on veut en fonction du résultat que l'on souhaite.
```cpp
glm::vec2 point{x, y};
glm::vec2 center_of_rotation{image.width()/2, image.height()/2};
glm::vec2 new_point{rotated(point, center_of_rotation ,pow((pow((x-image.width()/2),2)+pow((y-image.height()/2),2)),0.5)/10) };

if(new_point.y<vortex.height() && new_point.x<vortex.width() && new_point.y>0 && new_point.x>0) { 
    vortex.pixel(x, y) = image.pixel(new_point.x, new_point.y);
}
```


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

Sur cet exercice, il fallait parcourir les pixels autour du pixels de base puis faire la moyenne des couleurs de chaque pixel. Au début on a essayé de faire un flou léger en prennant une matrice de 1px autour du px de base. 
Après il a fallut essayer de faire avec une matrice qui pouvait prendre n'importe quelle taille. 
Le piège principale dans lequel on est tombé c'est qu'on modifiait la variable `x_offset` et `y_offset` qui etaient mes variables d'entrée de mes boucles for : donc je faisais une boucle infinit. C'est por cela qu'on a créer deux nouvelles variables `real_x_offset` et `real_y_offset`.

```cpp
sil::Image blur(sil::Image image, int level) {
    sil::Image new_image{image.width(), image.height()};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec3 sum {0.f};
            int size {level}; //taille de la matrice 
            for (int x_offset{-size}; x_offset < size; x_offset++)
            {
                for (int y_offset{-size}; y_offset < size; y_offset++)
                {
                    int real_x_offset{x_offset};
                    int real_y_offset{y_offset};
                    if (x+real_x_offset<0 || x+real_x_offset>=image.width())
                    {
                        real_x_offset = 0; //si le pixel de la matrice est en dehors de l'image alors le décalage par rapport a x est nul.
                    }
                    if (y+real_y_offset<0 || y+real_y_offset>=image.height())
                    {
                        real_y_offset = 0;//si le pixel de la matrice est en dehors de l'image alors le décalage par rapport a y est nul.
                    }
                    sum += image.pixel(x+real_x_offset,y+real_y_offset);
                }
            }
            sum /= pow(2*size+1,2);//moyenne
            new_image.pixel(x,y)=sum;
        }
    }
    new_image.save("output/blur.png"); 
    return new_image;
}
```

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


